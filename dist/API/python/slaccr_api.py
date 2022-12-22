## Copyright (c) 2022 Dante Trisciuzzi ##

import os
import sys
import ctypes

class slaccr_instance:
    __imported_lib = None
    __is_initialized = False

    def __init__(self) -> None:
        self.__imported_lib = ctypes.cdll.LoadLibrary(os.getcwd()+"\\SLACCR-API.dll")

    
    def __init_check(self):
        if not self.__is_initialized:
            print("Slaccr class not initialized, call Init(...)")
        return self.__is_initialized

    def Init(self, calibrate_mouse: bool ) -> bool:
        """Initializes the connection to the SLACCr hardware.

        Args:
            calibrateMouse: Determines whether to run the mouse calibration test upon connecting. Enables mouse approximate movement.
        
        Returns:
            True if connection succeeds."""
        
        self.__is_initialized = self.__imported_lib.Init(calibrate_mouse)
        return self.__init_check

    def Disconnect(self):
        """Cleans up peripherals and disconnects from the SLACCr hardware."""
        if not self.__init_check():
            return
        self.__imported_lib.Disconnect()
    
    def MouseApprox( self, x, y):
        """Moves mouse via approximation based on calibration test.

        Args:
            x: Horizontal value in pixels.
            y: Vertical value in pixels."""
        if not self.__init_check():
                return
        self.__imported_lib.MouseApprox(x,y)

    def MousePercent( self, x, y):
            """Moves mouse via percentage value (for full resolution, use MouseValue).

            Args:
                    x: Horizontal value. -100 to 100%.
                    y: Vertical value. -100% to 100%."""
            if not self.__init_check():
                    return
            self.__imported_lib.MousePercent(x,y)

    def MouseValue( self, x, y):
            """Moves mouse via true poll value.

            Args:
                    x: Horizontal value. -127 to 127.
                    y: Vertical value. -127 to 127."""
            if not self.__init_check():
                    return
            self.__imported_lib.MouseValue(x,y)

    def MouseClick( self, button, delay):
            """Performs a Mouse click (Press-delay-release).

            Args:
                    button: Peripherals::MouseButton code
                    delay: downtime"""
            if not self.__init_check():
                    return
            self.__imported_lib.MouseClick(button, delay)

    def MousePress( self, button):
            """Performs a mouse press (down only).

            Args:
                    button: Peripherals::MouseButton code"""
            if not self.__init_check():
                    return
            self.__imported_lib.MousePress(button)

    def MouseRelease( self, button):
            """Performs a mouse release (up only).

            Args:
                    button: Peripherals::MouseButton code"""
            if not self.__init_check():
                    return
            self.__imported_lib.MouseRelease(button)

    def MouseReleaseAll( self ):
            """Releases all mouse buttons."""
            if not self.__init_check():
                    return
            self.__imported_lib.MouseReleaseAll()

    def MouseScroll( self, amount):
            """Performs a mouse scroll.

            Args:
                    amount: Amount to scroll (-127 to 127)"""
            if not self.__init_check():
                    return
            self.__imported_lib.MouseScroll(amount)

    def KbKeyDown( self, key):
            """Performs a key press (down only).

            Args:
                    key: Peripherals::Key Key code"""
            if not self.__init_check():
                    return
            self.__imported_lib.KbKeyDown(key)

    def KbKeyUp( self, key):
            """Performs a key release (up only).

            Args:
                    key: Peripherals::Key Key code"""
            if not self.__init_check():
                    return
            self.__imported_lib.KbKeyUp(key)

    def KbStroke( self, key, delay=10):
            """Performs a key stroke (down-delay-up).

            Args:
                    key: Peripherals::Key Key code
                    delay: Key down time (in ms)"""
            if not self.__init_check():
                    return
            self.__imported_lib.KbStroke(key,delay)

    def KbType( self, message):
            """Performs keystrokes to type a string.

            Args:
                    str: String to type"""
            if not self.__init_check():
                    return
            message = ctypes.create_string_buffer(bytes(map(ord, message)))
            self.__imported_lib.KbType(message)

    def KbReleaseAll( self ):
            """Releases all keyboard keys."""
            if not self.__init_check():
                    return
            self.__imported_lib.KbReleaseAll()

    def GamepadButtonState( self, id,state):
            """Sets the state of a Gamepad button.

            Args:
                    id: Peripherals::ButtonID Code (int 1-32)
                    state: true/1 = Pressed false/0 = released"""
            if not self.__init_check():
                    return
            self.__imported_lib.GamepadButtonState(id,state)

    def GamepadButtonPress( self, id, delay):
            """Presses and releases a Gamepad Button.

            Args:
                    id: id Peripherals::ButtonID Code (int 1-32)
                    delay: Time in ms, delay performed on hardware"""
            if not self.__init_check():
                    return
            self.__imported_lib.GamepadButtonPress(id, delay)

    def GamepadMoveAxis( self, axis,amt):
            """Sets Gamepad Axis position.

            Args:
                    axis: Peripherals::JoystickAxis Axis
                    amt: Value to set (-127 to 127)"""
            if not self.__init_check():
                    return
            self.__imported_lib.GamepadMoveAxis(axis,amt)

    def GamepadSetHat( self, angle):
            """Sets Gamepad Hat position.

            Args:
                    angle: Hat angle (0-360). -1 is released (use GamepadResetHat(...))"""
            if not self.__init_check():
                    return
            self.__imported_lib.GamepadSetHat(angle)

    def GamepadResetHat( self ):
            """Resets the Gamepad Hat position."""
            if not self.__init_check():
                    return
            self.__imported_lib.GamepadResetHat()

    def GamepadResetButtons( self ):
            """Resets all Gamepad Buttons (released)."""
            if not self.__init_check():
                    return
            self.__imported_lib.GamepadResetButtons()

    def GamepadResetAxises( self ):
            """Resets all Gamepad Axises (centered)."""
            if not self.__init_check():
                    return
            self.__imported_lib.GamepadResetAxises()

    def GamepadResetAll( self ):
            """Resets all Gamepad inputs."""
            if not self.__init_check():
                    return
            self.__imported_lib.GamepadResetAll()
    
class Peripherals:
    class JoystickAxis:
        X,Y,Z,Zrotate,SliderLeft,SliderRight = range(6)

    class MouseButton:
        Left = 1
        Right = 2
        Middle = 4
        Prev = 8
        Next = 16
        All = 31

    class ButtonID:
        UNUSED_BUFFER_BUTTON_ID,\
		BUTTON_1,\
		BUTTON_2,\
		BUTTON_3,\
		BUTTON_4,\
		BUTTON_5,\
		BUTTON_6,\
		BUTTON_7,\
		BUTTON_8,\
		BUTTON_9,\
		BUTTON_10,\
		BUTTON_11,\
		BUTTON_12,\
		BUTTON_13,\
		BUTTON_14,\
		BUTTON_15,\
		BUTTON_16,\
		BUTTON_17,\
		BUTTON_18,\
		BUTTON_19,\
		BUTTON_20,\
		BUTTON_21,\
		BUTTON_22,\
		BUTTON_23,\
		BUTTON_24,\
		BUTTON_25,\
		BUTTON_26,\
		BUTTON_27,\
		BUTTON_28,\
		BUTTON_29,\
		BUTTON_30,\
		BUTTON_31,\
		BUTTON_32 = range(33)
    
    class Keys:
        KEY_RESERVED_NUL,\
        KEY_RESERVED_SOH,\
        KEY_RESERVED_STX,\
        KEY_RESERVED_ETX,\
        KEY_RESERVED_EOT,\
        KEY_RESERVED_ENQ,\
        KEY_RESERVED_ACK,\
        KEY_RESERVED_BEL,\
        KEY_BACKSPACE,\
        KEY_TAB,\
        KEY_ENTER,\
        KEY_RESERVED_VT,\
        KEY_RESERVED_FF,\
        KEY_RESERVED_CR,\
        KEY_RESERVED_SO,\
        KEY_RESERVED_SI,\
        KEY_RESERVED_DEL,\
        KEY_RESERVED_DC1,\
        KEY_RESERVED_DC2,\
        KEY_RESERVED_DC3,\
        KEY_RESERVED_DC4,\
        KEY_RESERVED_NAK,\
        KEY_RESERVED_SYN,\
        KEY_RESERVED_ETB,\
        KEY_RESERVED_CAN,\
        KEY_RESERVED_EM,\
        KEY_RESERVED_SUB,\
        KEY_RESERVED_ESC,\
        KEY_RESERVED_FS,\
        KEY_RESERVED_GS,\
        KEY_RESERVED_RS,\
        KEY_RESERVED_US,\
        KEY_SPACE,\
        KEY_EXCLAIMATION,\
        KEY_DQUOTE,\
        KEY_POUND,\
        KEY_DOLLAR,\
        KEY_PERCENT,\
        KEY_AMBERSAND,\
        KEY_SQUOTE,\
        KEY_OPENPARENTHESIS,\
        KEY_CLOSEPARENTHESIS,\
        KEY_ASTERISK,\
        KEY_PLUS,\
        KEY_COMMA,\
        KEY_MINUS,\
        KEY_PERIOD,\
        KEY_FSLASH,\
        KEY_0,\
        KEY_1,\
        KEY_2,\
        KEY_3,\
        KEY_4,\
        KEY_5,\
        KEY_6,\
        KEY_7,\
        KEY_8,\
        KEY_9,\
        KEY_COLON,\
        KEY_SEMICOLON,\
        KEY_LESSTHAN,\
        KEY_EQUAL,\
        KEY_GREATERTHAN,\
        KEY_QUESTION,\
        KEY_AT,\
        KEY_A_UPPER,\
        KEY_B_UPPER,\
        KEY_C_UPPER,\
        KEY_D_UPPER,\
        KEY_E_UPPER,\
        KEY_F_UPPER,\
        KEY_G_UPPER,\
        KEY_H_UPPER,\
        KEY_I_UPPER,\
        KEY_J_UPPER,\
        KEY_K_UPPER,\
        KEY_L_UPPER,\
        KEY_M_UPPER,\
        KEY_N_UPPER,\
        KEY_O_UPPER,\
        KEY_P_UPPER,\
        KEY_Q_UPPER,\
        KEY_R_UPPER,\
        KEY_S_UPPER,\
        KEY_T_UPPER,\
        KEY_U_UPPER,\
        KEY_V_UPPER,\
        KEY_W_UPPER,\
        KEY_X_UPPER,\
        KEY_Y_UPPER,\
        KEY_Z_UPPER,\
        KEY_LEFT_BRACE,\
        KEY_BACKSLASH,\
        KEY_RIGHT_BRACE,\
        KEY_CARET,\
        KEY_UNDERSCORE,\
        KEY_GRAVE,\
        KEY_A,\
        KEY_B,\
        KEY_C,\
        KEY_D,\
        KEY_E,\
        KEY_F,\
        KEY_G,\
        KEY_H,\
        KEY_I,\
        KEY_J,\
        KEY_K,\
        KEY_L,\
        KEY_M,\
        KEY_N,\
        KEY_O,\
        KEY_P,\
        KEY_Q,\
        KEY_R,\
        KEY_S,\
        KEY_T,\
        KEY_U,\
        KEY_V,\
        KEY_W,\
        KEY_X,\
        KEY_Y,\
        KEY_Z,\
        KEY_LEFTCURLY,\
        KEY_PIPE,\
        KEY_RIGHTCURLY,\
        KEY_TILDE,\
        KEY_DELETE,\
        KEY_RESERVED_128,\
        KEY_RESERVED_129,\
        KEY_RESERVED_130,\
        KEY_RESERVED_131,\
        KEY_RESERVED_132,\
        KEY_RESERVED_133,\
        KEY_RESERVED_134,\
        KEY_RESERVED_135,\
        KEY_RESERVED_136,\
        KEY_RESERVED_137,\
        KEY_RESERVED_138,\
        KEY_RESERVED_139,\
        KEY_RESERVED_140,\
        KEY_RESERVED_141,\
        KEY_RESERVED_142,\
        KEY_RESERVED_143,\
        KEY_RESERVED_144,\
        KEY_RESERVED_145,\
        KEY_RESERVED_146,\
        KEY_RESERVED_147,\
        KEY_RESERVED_148,\
        KEY_RESERVED_149,\
        KEY_RESERVED_150,\
        KEY_RESERVED_151,\
        KEY_RESERVED_152,\
        KEY_RESERVED_153,\
        KEY_RESERVED_154,\
        KEY_RESERVED_155,\
        KEY_RESERVED_156,\
        KEY_RESERVED_157,\
        KEY_RESERVED_158,\
        KEY_RESERVED_159,\
        KEY_RESERVED_160,\
        KEY_RESERVED_161,\
        KEY_RESERVED_162,\
        KEY_RESERVED_163,\
        KEY_RESERVED_164,\
        KEY_RESERVED_165,\
        KEY_RESERVED_166,\
        KEY_RESERVED_167,\
        KEY_RESERVED_168,\
        KEY_RESERVED_169,\
        KEY_RESERVED_170,\
        KEY_RESERVED_171,\
        KEY_RESERVED_172,\
        KEY_RESERVED_173,\
        KEY_RESERVED_174,\
        KEY_RESERVED_175,\
        KEY_RESERVED_176,\
        KEY_RESERVED_177,\
        KEY_RESERVED_178,\
        KEY_RESERVED_179,\
        KEY_RESERVED_180,\
        KEY_RESERVED_181,\
        KEY_RESERVED_182,\
        KEY_RESERVED_183,\
        KEY_RESERVED_184,\
        KEY_RESERVED_185,\
        KEY_RESERVED_186,\
        KEY_RESERVED_187,\
        KEY_RESERVED_188,\
        KEY_RESERVED_189,\
        KEY_RESERVED_190,\
        KEY_RESERVED_191,\
        KEY_RESERVED_192,\
        KEY_RESERVED_193,\
        KEY_RESERVED_194,\
        KEY_RESERVED_195,\
        KEY_RESERVED_196,\
        KEY_RESERVED_197,\
        KEY_RESERVED_198,\
        KEY_RESERVED_199,\
        KEY_RESERVED_200,\
        KEY_RESERVED_201,\
        KEY_RESERVED_202,\
        KEY_RESERVED_203,\
        KEY_RESERVED_204,\
        KEY_RESERVED_205,\
        KEY_RESERVED_206,\
        KEY_RESERVED_207,\
        KEY_RESERVED_208,\
        KEY_RESERVED_209,\
        KEY_RESERVED_210,\
        KEY_RESERVED_211,\
        KEY_RESERVED_212,\
        KEY_RESERVED_213,\
        KEY_RESERVED_214,\
        KEY_RESERVED_215,\
        KEY_RESERVED_216,\
        KEY_RESERVED_217,\
        KEY_RESERVED_218,\
        KEY_RESERVED_219,\
        KEY_RESERVED_220,\
        KEY_RESERVED_221,\
        KEY_RESERVED_222,\
        KEY_RESERVED_223,\
        KEY_RESERVED_224,\
        KEY_RESERVED_225,\
        KEY_RESERVED_226,\
        KEY_RESERVED_227,\
        KEY_RESERVED_228,\
        KEY_RESERVED_229,\
        KEY_RESERVED_230,\
        KEY_RESERVED_231,\
        KEY_RESERVED_232,\
        KEY_RESERVED_233,\
        KEY_RESERVED_234,\
        KEY_RESERVED_235,\
        KEY_RESERVED_236,\
        KEY_RESERVED_237,\
        KEY_RESERVED_238,\
        KEY_RESERVED_239,\
        KEY_RESERVED_240,\
        KEY_RESERVED_241,\
        KEY_RESERVED_242,\
        KEY_RESERVED_243,\
        KEY_RESERVED_244,\
        KEY_RESERVED_245,\
        KEY_RESERVED_246,\
        KEY_RESERVED_247,\
        KEY_RESERVED_248,\
        KEY_RESERVED_249,\
        KEY_RESERVED_250,\
        KEY_RESERVED_251,\
        KEY_RESERVED_252,\
        KEY_RESERVED_253,\
        KEY_RESERVED_254,\
        KEY_RESERVED_255 = range(256)
