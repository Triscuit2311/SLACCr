#pragma once
#include "pch.h"
#include "Peripherals.h"
#include "SerialIO.h"



class PacketManager
{
	SerialIo* SerialPort;
public:
	explicit PacketManager(SerialIo* pSerialPort)
		: SerialPort(pSerialPort)
	{
		UPacket = Packet();
	}

private:
	enum PacketType
	{
		Debug,
		Command
	};

	enum DebugCommands
	{
		Identify
	};

	enum HIDCommand
	{
		Default,
		MouseMove,
		MouseClick,
		MousePress,
		MouseRelease,
		MouseReleaseAll,
		MouseScroll,
		KeyboardKeyDown,
		KeyboardKeyUp,
		KeyboardTypeString,
		KeyboardWakeUpHost,
		KeyboardReleaseAll,
		GamepadButtonState,
		GamepadButtonPress,
		GamepadMoveAxis,
		GamepadSetHat
	};

	struct Packet
	{
		uint8_t Type = PacketType::Debug;
		uint8_t Command{ 0 };
		int Val1{ 0 };
		int Val2{ 0 };
		uint8_t MouseButton = Peripherals::MouseButton::Left;
		uint8_t Key = 0x00;
		char Text[16]{};
	};

	Packet UPacket;
	const uint8_t StartMarker = 255;

	void ClearPacket();
	void SendPacket();

public:
	void SendIdentifyPacket();
	void SendMouseMove(int x, int y);
	void SendMousePress(int button = Peripherals::MouseButton::Left);
	void SendMouseRelease(int button = Peripherals::MouseButton::Left);
	void SendMouseReleaseAll();
	void SendMouseScroll(int amount);
	void SendKeyboardKeyDown(int key);
	void SendKeyboardKeyUp(int key);
	void SendKeyboardTypeString(const char text[16]);

	void SendKeyboardWakeUpHost();
	void SendKeyboardReleaseAll();

	void SendGamepadButtonState(int id, bool state);
	void SendGamepadButtonPress(int id, int time);
	void SendGamepadMoveAxis(int axis, int amt);
	void SendGamepadSetHat(int angle);

	void Test()
	{
	}


};
