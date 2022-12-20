#pragma once
#include "Gamepad.h"
#include "Keyboard.h"
#include "Mouse.h"
#include "PacketManager.h"
#include "SerialIO.h"

class Slaccr_Controller  // NOLINT(cppcoreguidelines-special-member-functions)
{
	SerialIo* PSerialPort;
	PacketManager* PPacketManager;
	Mouse* PMouse;
	Keyboard* PKeyboard;
	Gamepad* PGamePad;

	bool Connect(int retries, bool performMouseCalibration);
	bool Connected = false;

	short MouseAccuracy = 5;
	short MouseClickTime = 50;

public:
	Slaccr_Controller();
	~Slaccr_Controller();

	void Init(bool calibrateMouse);
	static bool Disconnect();
	void MouseApprox(int x, int y) const;
	void MousePercent(int x, int y) const;
	void MouseValue(int x, int y) const;
	[[nodiscard]] bool IsConnected() const;
	void SetMouseAccuracy(const short accuracy) { MouseAccuracy = accuracy; }
	void SetMouseClickTime(const short time) { MouseClickTime = time; }

	void MouseRel(int x, int y) const;
	void MouseTo(int x, int y) const;
	void MouseClick(int button = Peripherals::MouseButton::Left) const;
	void MousePress(int button = Peripherals::MouseButton::Left) const;
	void MouseRelease(int button = Peripherals::MouseButton::Left) const;
	void MouseReleaseAll() const;
	void MouseScroll(int amount) const;

	void KbKeyDown(int key) const;
	void KbKeyUp(int key) const;
	void KbStroke(int key, int delay) const;
	void KbType(const std::string& str) const;
	void KbReleaseAll() const;


	void GamepadButtonState(int id, bool state) const;
	void GamepadButtonPress(int id, int time) const;
	void GamepadMoveAxis(int axis, int amt) const;
	void GamepadMoveHat(int angle) const;
	void GamepadResetHat() const;
	void GamepadResetAxises() const;
	void GamepadResetButtons() const;
	void GamepadResetAll() const;

	void Test() const
	{
	}
};