/* Copyright (c) 2022 Dante Trisciuzzi */

#pragma once
#include "Peripherals.h"

#ifdef SLACCRAPI_EXPORTS
#define SLACCR_API __declspec(dllexport)
#else
#define SLACCR_API __declspec(dllimport)
#endif


namespace Slaccr
{
	/**
	 * \brief Initializes the connection to the SLACCr hardware.
	 * \param calibrateMouse Determines whether to run the mouse calibration test upon connecting. Enables mouse approximate movement.
	 * \return True if connection succeeds.
	 */
	extern "C" SLACCR_API bool Init(bool calibrateMouse);

	/**
	 * \brief Cleans up peripherals and disconnects from the SLACCr hardware.
	 */
	extern "C" SLACCR_API void Disconnect();

	/**
	 * \brief Moves mouse via approximation based on calibration test.
	 * \param x Horizontal value in pixels.
	 * \param y Vertical value in pixels.
	 */
	extern "C" SLACCR_API void MouseApprox(int x, int y);

	/**
	 * \brief Moves mouse via percentage value (for full resolution, use MouseValue).
	 * \param x Horizontal value. -100 to 100%.
	 * \param y Vertical value. -100% to 100%.
	 */
	extern "C" SLACCR_API void MousePercent(int x, int y);

	/**
	 * \brief Moves mouse via true poll value.
	 * \param x Horizontal value. -127 to 127.
	 * \param y Vertical value. -127 to 127.
	 */
	extern "C" SLACCR_API void MouseValue(int x, int y);

	/**
	 * \brief Performs a Mouse click (Press-delay-release).
	 * \param button Peripherals::MouseButton code
	 */
	extern "C" SLACCR_API void MouseClick(int button = Peripherals::MouseButton::Left);

	/**
	 * \brief Performs a mouse press (down only).
	 * \param button Peripherals::MouseButton code
	 */
	extern "C" SLACCR_API void MousePress(int button = Peripherals::MouseButton::Left);

	/**
	 * \brief Performs a mouse release (up only).
	 * \param button Peripherals::MouseButton code
	 */
	extern "C" SLACCR_API void MouseRelease(int button = Peripherals::MouseButton::Left);

	/**
	 * \brief Releases all mouse buttons.
	 */
	extern "C" SLACCR_API void MouseReleaseAll();

	/**
	 * \brief Performs a mouse scroll.
	 * \param amount Amount to scroll (-127 to 127)
	 */
	extern "C" SLACCR_API void MouseScroll(int amount);


	/**
	 * \brief Performs a key press (down only).
	 * \param key Peripherals::Key Key code
	 */
	extern "C" SLACCR_API void KbKeyDown(int key);

	/**
	 * \brief Performs a key release (up only).
	 * \param key Peripherals::Key Key code
	 */
	extern "C" SLACCR_API void KbKeyUp(int key);

	/**
	 * \brief Performs a key stroke (down-delay-up).
	 * \param key Peripherals::Key Key code
	 * \param delay Key down time (in ms)
	 */
	extern "C" SLACCR_API void KbStroke(int key, int delay = 10);

	/**
	 * \brief Performs keystrokes to type a string.
	 * \param str String to type
	 */
	extern "C" SLACCR_API void KbType(const char* str);

	/**
	 * \brief Releases all keyboard keys.
	 */
	extern "C" SLACCR_API void KbReleaseAll();


	/**
	 * \brief Sets the state of a Gamepad button.
	 * \param id Peripherals::ButtonID Code (int 1-32) 
	 * \param state true/1 = Pressed false/0 = released
	 */
	extern "C" SLACCR_API void GamepadButtonState(int id, bool state);

	/**
	 * \brief Presses and releases a Gamepad Button.
	 * \param id id Peripherals::ButtonID Code (int 1-32) 
	 * \param delay Time in ms, delay performed on hardware
	 */
	extern "C" SLACCR_API void GamepadButtonPress(int id, int delay);

	/**
	 * \brief Sets Gamepad Axis position.
	 * \param axis Peripherals::JoystickAxis Axis
	 * \param amt Value to set (-127 to 127)
	 */
	extern "C" SLACCR_API void GamepadMoveAxis(int axis, int amt);

	/**
	 * \brief Sets Gamepad Hat position.
	 * \param angle Hat angle (0-360). -1 is released (use GamepadResetHat(...))
	 */
	extern "C" SLACCR_API void GamepadSetHat(int angle);

	/**
	 * \brief Resets the Gamepad Hat position.
	 */
	extern "C" SLACCR_API void GamepadResetHat();

	/**
	 * \brief Resets all Gamepad Buttons (released).
	 */
	extern "C" SLACCR_API void GamepadResetButtons();

	/**
	 * \brief Resets all Gamepad Axises (centered).
	 */
	extern "C" SLACCR_API void GamepadResetAxises();

	/**
	 * \brief Resets all Gamepad inputs.
	 */
	extern "C" SLACCR_API void GamepadResetAll();

}
