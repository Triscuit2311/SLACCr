/* Copyright (c) 2022 Dante Trisciuzzi */

#pragma once

namespace Peripherals
{
	enum MouseButton
	{
		Left = 1,
		Right = 2,
		Middle = 4,
		Prev = 8,
		Next = 16,
		All = 31
	};

	enum JoystickAxis
	{
		X,
		Y,
		Z,
		Zrotate,
		SliderLeft,
		SliderRight
	};

	enum ButtonID
	{
		UNUSED_BUFFER_BUTTON_ID,
		BUTTON_1,
		BUTTON_2,
		BUTTON_3,
		BUTTON_4,
		BUTTON_5,
		BUTTON_6,
		BUTTON_7,
		BUTTON_8,
		BUTTON_9,
		BUTTON_10,
		BUTTON_11,
		BUTTON_12,
		BUTTON_13,
		BUTTON_14,
		BUTTON_15,
		BUTTON_16,
		BUTTON_17,
		BUTTON_18,
		BUTTON_19,
		BUTTON_20,
		BUTTON_21,
		BUTTON_22,
		BUTTON_23,
		BUTTON_24,
		BUTTON_25,
		BUTTON_26,
		BUTTON_27,
		BUTTON_28,
		BUTTON_29,
		BUTTON_30,
		BUTTON_31,
		BUTTON_32,
	};

	enum Key
	{
		KEY_RESERVED_NUL,
		// NUL
		KEY_RESERVED_SOH,
		// SOH
		KEY_RESERVED_STX,
		// STX
		KEY_RESERVED_ETX,
		// ETX
		KEY_RESERVED_EOT,
		// EOT
		KEY_RESERVED_ENQ,
		// ENQ
		KEY_RESERVED_ACK,
		// ACK
		KEY_RESERVED_BEL,
		// BEL
		KEY_BACKSPACE,
		// Backspace
		KEY_TAB,
		// Tab
		KEY_ENTER,
		// Enter
		KEY_RESERVED_VT,
		// VT
		KEY_RESERVED_FF,
		// FF
		KEY_RESERVED_CR,
		// CR
		KEY_RESERVED_SO,
		// SO
		KEY_RESERVED_SI,
		// SI
		KEY_RESERVED_DEL,
		// DEL
		KEY_RESERVED_DC1,
		// DC1
		KEY_RESERVED_DC2,
		// DC2
		KEY_RESERVED_DC3,
		// DC3
		KEY_RESERVED_DC4,
		// DC4
		KEY_RESERVED_NAK,
		// NAK
		KEY_RESERVED_SYN,
		// SYN
		KEY_RESERVED_ETB,
		// ETB
		KEY_RESERVED_CAN,
		// CAN
		KEY_RESERVED_EM,
		// EM
		KEY_RESERVED_SUB,
		// SUB
		KEY_RESERVED_ESC,
		// ESC
		KEY_RESERVED_FS,
		// FS
		KEY_RESERVED_GS,
		// GS
		KEY_RESERVED_RS,
		// RS
		KEY_RESERVED_US,
		// US
		KEY_SPACE,
		// Space
		KEY_EXCLAIMATION,
		// !
		KEY_DQUOTE,
		// "
		KEY_POUND,
		// #
		KEY_DOLLAR,
		// $
		KEY_PERCENT,
		// %
		KEY_AMBERSAND,
		// &
		KEY_SQUOTE,
		// '
		KEY_OPENPARENTHESIS,
		// (
		KEY_CLOSEPARENTHESIS,
		// )
		KEY_ASTERISK,
		// *
		KEY_PLUS,
		// +
		KEY_COMMA,
		// ,
		KEY_MINUS,
		// -
		KEY_PERIOD,
		// .
		KEY_FSLASH,
		// /
		KEY_0,
		// 0
		KEY_1,
		// 1
		KEY_2,
		// 2
		KEY_3,
		// 3
		KEY_4,
		// 4
		KEY_5,
		// 5
		KEY_6,
		// 6
		KEY_7,
		// 7
		KEY_8,
		// 8
		KEY_9,
		// 9
		KEY_COLON,
		// :
		KEY_SEMICOLON,
		// ;
		KEY_LESSTHAN,
		// <
		KEY_EQUAL,
		// =
		KEY_GREATERTHAN,
		// >
		KEY_QUESTION,
		// ?
		KEY_AT,
		// @
		KEY_A_UPPER,
		// A
		KEY_B_UPPER,
		// B
		KEY_C_UPPER,
		// C
		KEY_D_UPPER,
		// D
		KEY_E_UPPER,
		// E
		KEY_F_UPPER,
		// F
		KEY_G_UPPER,
		// G
		KEY_H_UPPER,
		// H
		KEY_I_UPPER,
		// I
		KEY_J_UPPER,
		// J
		KEY_K_UPPER,
		// K
		KEY_L_UPPER,
		// L
		KEY_M_UPPER,
		// M
		KEY_N_UPPER,
		// N
		KEY_O_UPPER,
		// O
		KEY_P_UPPER,
		// P
		KEY_Q_UPPER,
		// Q
		KEY_R_UPPER,
		// R
		KEY_S_UPPER,
		// S
		KEY_T_UPPER,
		// T
		KEY_U_UPPER,
		// U
		KEY_V_UPPER,
		// V
		KEY_W_UPPER,
		// W
		KEY_X_UPPER,
		// X
		KEY_Y_UPPER,
		// Y
		KEY_Z_UPPER,
		// Z
		KEY_LEFT_BRACE,
		// [
		KEY_BACKSLASH,
		// bslash
		KEY_RIGHT_BRACE,
		// ]
		KEY_CARET,
		// ^
		KEY_UNDERSCORE,
		// _
		KEY_GRAVE,
		// `
		KEY_A,
		// a
		KEY_B,
		// b
		KEY_C,
		// c
		KEY_D,
		// d
		KEY_E,
		// e
		KEY_F,
		// f
		KEY_G,
		// g
		KEY_H,
		// h
		KEY_I,
		// i
		KEY_J,
		// j
		KEY_K,
		// k
		KEY_L,
		// l
		KEY_M,
		// m
		KEY_N,
		// n
		KEY_O,
		// o
		KEY_P,
		// p
		KEY_Q,
		// q
		KEY_R,
		// r
		KEY_S,
		// s
		KEY_T,
		// t
		KEY_U,
		// u
		KEY_V,
		// v
		KEY_W,
		// w
		KEY_X,
		// x
		KEY_Y,
		// y
		KEY_Z,
		// z
		KEY_LEFTCURLY,
		// {
		KEY_PIPE,
		// |
		KEY_RIGHTCURLY,
		// }
		KEY_TILDE,
		// ~
		KEY_DELETE,
		// DEL
		// 7-bit ASCII codes end here

		// The following characters belong to ISO-8859-15
		KEY_RESERVED_128,
		// 128 - Unused
		KEY_RESERVED_129,
		// 129 - Unused
		KEY_RESERVED_130,
		// 130 - Unused
		KEY_RESERVED_131,
		// 131 - Unused
		KEY_RESERVED_132,
		// 132 - Unused
		KEY_RESERVED_133,
		// 133 - Unused
		KEY_RESERVED_134,
		// 134 - Unused
		KEY_RESERVED_135,
		// 135 - Unused
		KEY_RESERVED_136,
		// 136 - Unused
		KEY_RESERVED_137,
		// 137 - Unused
		KEY_RESERVED_138,
		// 138 - Unused
		KEY_RESERVED_139,
		// 139 - Unused
		KEY_RESERVED_140,
		// 140 - Unused
		KEY_RESERVED_141,
		// 141 - Unused
		KEY_RESERVED_142,
		// 142 - Unused
		KEY_RESERVED_143,
		// 143 - Unused
		KEY_RESERVED_144,
		// 144 - Unused
		KEY_RESERVED_145,
		// 145 - Unused
		KEY_RESERVED_146,
		// 146 - Unused
		KEY_RESERVED_147,
		// 147 - Unused
		KEY_RESERVED_148,
		// 148 - Unused
		KEY_RESERVED_149,
		// 149 - Unused
		KEY_RESERVED_150,
		// 150 - Unused
		KEY_RESERVED_151,
		// 151 - Unused
		KEY_RESERVED_152,
		// 152 - Unused
		KEY_RESERVED_153,
		// 153 - Unused
		KEY_RESERVED_154,
		// 154 - Unused
		KEY_RESERVED_155,
		// 155 - Unused
		KEY_RESERVED_156,
		// 156 - Unused
		KEY_RESERVED_157,
		// 157 - Unused
		KEY_RESERVED_158,
		// 158 - Unused
		KEY_RESERVED_159,
		// 159 - Unused
		KEY_RESERVED_160,
		// 160 - Non-breaking Space
		KEY_RESERVED_161,
		// 161 - Inverted Exclamation Mark
		KEY_RESERVED_162,
		// 162 - Cent
		KEY_RESERVED_163,
		// 163 - British Pound Sign
		KEY_RESERVED_164,
		// 164 - Euro Sign
		KEY_RESERVED_165,
		// 165 - Yen
		KEY_RESERVED_166,
		// 166 - Capital 's' Inverted Circumflex
		KEY_RESERVED_167,
		// 167 - Section Sign
		KEY_RESERVED_168,
		// 168 - 's' Inverted Circumflex
		KEY_RESERVED_169,
		// 169 - Copyright Sign
		KEY_RESERVED_170,
		// 170 - Superscript 'a'
		KEY_RESERVED_171,
		// 171 - Open Guillemet
		KEY_RESERVED_172,
		// 172 - Logic Negation
		KEY_RESERVED_173,
		// 173 - Soft Hypen
		KEY_RESERVED_174,
		// 174 - Registered Trademark
		KEY_RESERVED_175,
		// 175 - Macron
		KEY_RESERVED_176,
		// 176 - Degree Symbol
		KEY_RESERVED_177,
		// 177 - Plus-Minus
		KEY_RESERVED_178,
		// 178 - Superscript '2'
		KEY_RESERVED_179,
		// 179 - Superscript '3'
		KEY_RESERVED_180,
		// 180 - Capital 'z' Inverted Circumflex
		KEY_RESERVED_181,
		// 181 - Micro Symbol
		KEY_RESERVED_182,
		// 182 - Paragraph Mark
		KEY_RESERVED_183,
		// 183 - Interpunct
		KEY_RESERVED_184,
		// 184 - 'z' Inverted Circumflex
		KEY_RESERVED_185,
		// 185 - Superscript '1'
		KEY_RESERVED_186,
		// 186 - Ordinal Indicator
		KEY_RESERVED_187,
		// 187 - Closed Guillemet
		KEY_RESERVED_188,
		// 188 - Capital 'oe'
		KEY_RESERVED_189,
		// 189 - 'oe'
		KEY_RESERVED_190,
		// 190 - Capital 'y' Umlaut
		KEY_RESERVED_191,
		// 191 - Inverted Question Mark
		KEY_RESERVED_192,
		// 192 - Capital 'a' Grave
		KEY_RESERVED_193,
		// 193 - Capital 'a' Acute
		KEY_RESERVED_194,
		// 194 - Capital 'a' Circumflex
		KEY_RESERVED_195,
		// 195 - Capital 'a' Tilde
		KEY_RESERVED_196,
		// 196 - Capital 'a' Umlaut
		KEY_RESERVED_197,
		// 197 - Capital 'a' Circle
		KEY_RESERVED_198,
		// 198 - Capital 'ae'
		KEY_RESERVED_199,
		// 199 - Capital 'c' Cedilla
		KEY_RESERVED_200,
		// 200 - Capital 'e' Grave
		KEY_RESERVED_201,
		// 201 - Capital 'e' Acute
		KEY_RESERVED_202,
		// 202 - Capital 'e' Circumflex
		KEY_RESERVED_203,
		// 203 - Capital 'e' Umlaut
		KEY_RESERVED_204,
		// 204 - Capital 'i' Grave
		KEY_RESERVED_205,
		// 205 - Capital 'i' Acute
		KEY_RESERVED_206,
		// 206 - Capital 'i' Circumflex
		KEY_RESERVED_207,
		// 207 - Capital 'i' Umlaut
		KEY_RESERVED_208,
		// 208 - Capital Eth
		KEY_RESERVED_209,
		// 209 - Capital 'n' Tilde
		KEY_RESERVED_210,
		// 210 - Capital 'o' Grave
		KEY_RESERVED_211,
		// 211 - Capital 'o' Acute
		KEY_RESERVED_212,
		// 212 - Capital 'o' Circumflex
		KEY_RESERVED_213,
		// 213 - Capital 'o' Tilde
		KEY_RESERVED_214,
		// 214 - Capital 'o' Umlaut
		KEY_RESERVED_215,
		// 215 - Multiplication Sign
		KEY_RESERVED_216,
		// 216 - Capital 'o' Barred
		KEY_RESERVED_217,
		// 217 - Capital 'u' Grave
		KEY_RESERVED_218,
		// 218 - Capital 'u' Acute
		KEY_RESERVED_219,
		// 219 - Capital 'u' Circumflex
		KEY_RESERVED_220,
		// 220 - Capital 'u' Umlaut
		KEY_RESERVED_221,
		// 221 - Capital 'y' Acute
		KEY_RESERVED_222,
		// 222 - Capital Thorn
		KEY_RESERVED_223,
		// 223 - Eszett
		KEY_RESERVED_224,
		// 224 - 'a' Grave
		KEY_RESERVED_225,
		// 225 - 'a' Acute
		KEY_RESERVED_226,
		// 226 - 'a' Circumflex
		KEY_RESERVED_227,
		// 227 - 'a' Tilde
		KEY_RESERVED_228,
		// 228 - 'a' Umlaut
		KEY_RESERVED_229,
		// 229 - 'a' Circle
		KEY_RESERVED_230,
		// 230 - 'ae'
		KEY_RESERVED_231,
		// 231 - 'c' Cedilla
		KEY_RESERVED_232,
		// 232 - 'e' Grave
		KEY_RESERVED_233,
		// 233 - 'e' Acute
		KEY_RESERVED_234,
		// 234 - 'e' Circumflex
		KEY_RESERVED_235,
		// 235 - 'e' Umlaut
		KEY_RESERVED_236,
		// 236 - 'i' Grave
		KEY_RESERVED_237,
		// 237 - 'i' Acute
		KEY_RESERVED_238,
		// 238 - 'i' Circumflex
		KEY_RESERVED_239,
		// 239 - 'i' Umlaut
		KEY_RESERVED_240,
		// 240 - Eth
		KEY_RESERVED_241,
		// 241 - 'n' Tilde
		KEY_RESERVED_242,
		// 242 - 'o' Grave
		KEY_RESERVED_243,
		// 243 - 'o' Acute
		KEY_RESERVED_244,
		// 244 - 'o' Circumflex
		KEY_RESERVED_245,
		// 245 - 'o' Tilde
		KEY_RESERVED_246,
		// 246 - 'o' Umlaut
		KEY_RESERVED_247,
		// 247 - Multiplication Sign
		KEY_RESERVED_248,
		// 248 - 'o' Barred
		KEY_RESERVED_249,
		// 249 - 'u' Grave
		KEY_RESERVED_250,
		// 250 - 'u' Acute
		KEY_RESERVED_251,
		// 251 - 'u' Circumflex
		KEY_RESERVED_252,
		// 252 - 'u' Umlaut
		KEY_RESERVED_253,
		// 253 - 'y' Acute
		KEY_RESERVED_254,
		// 254 - Thorn
		KEY_RESERVED_255,
		// 255 - 'y' Umlaut
	};
}