#include "pch.h"
#include "PacketManager.h"

void PacketManager::ClearPacket()
{
	UPacket.Type = PacketType::Debug;
	UPacket.Command = HIDCommand::Default;
	UPacket.Val1 = 0;
	UPacket.Val2 = 0;
	UPacket.Key = 0x00;
	strcpy_s(UPacket.Text, "ABCDEFGHIJKLMNO");
}

void PacketManager::SendPacket()
{
	SerialPort->Write(&StartMarker, 1);
	SerialPort->Write(reinterpret_cast<uint8_t*>(&UPacket), sizeof(UPacket));
}

void PacketManager::SendIdentifyPacket()
{
	ClearPacket();
	UPacket.Type = PacketType::Debug;
	UPacket.Command = DebugCommands::Identify;
	SendPacket();
}

void PacketManager::SendMouseMove(const int x, const int y)
{
	ClearPacket();
	UPacket.Type = PacketType::Command;
	UPacket.Command = HIDCommand::MouseMove;
	UPacket.Val1 = x;
	UPacket.Val2 = y;
	SendPacket();
}

void PacketManager::SendMousePress(const int button)
{
	ClearPacket();
	UPacket.Type = PacketType::Command;
	UPacket.Command = HIDCommand::MousePress;
	UPacket.MouseButton = static_cast<uint8_t>(button);
	SendPacket();
}

void PacketManager::SendMouseRelease(const int button)
{
	ClearPacket();
	UPacket.Type = PacketType::Command;
	UPacket.Command = HIDCommand::MouseRelease;
	UPacket.MouseButton = static_cast<uint8_t>(button);
	SendPacket();
}

void PacketManager::SendMouseReleaseAll()
{
	ClearPacket();
	UPacket.Type = PacketType::Command;
	UPacket.Command = HIDCommand::MouseReleaseAll;
	SendPacket();
}

void PacketManager::SendMouseScroll(const int amount)
{
	ClearPacket();
	UPacket.Type = PacketType::Command;
	UPacket.Command = HIDCommand::MouseScroll;
	UPacket.Val1 = amount;
	SendPacket();
}

void PacketManager::SendKeyboardKeyDown(const int key)
{
	ClearPacket();
	UPacket.Type = PacketType::Command;
	UPacket.Command = HIDCommand::KeyboardKeyDown;
	UPacket.Key = static_cast<uint8_t>(key);
	SendPacket();
}

void PacketManager::SendKeyboardKeyUp(const int key)
{
	ClearPacket();
	UPacket.Type = PacketType::Command;
	UPacket.Command = HIDCommand::KeyboardKeyUp;
	UPacket.Key = static_cast<uint8_t>(key);
	SendPacket();
}

void PacketManager::SendKeyboardTypeString(const char text[16])
{
	ClearPacket();
	UPacket.Type = PacketType::Command;
	UPacket.Command = HIDCommand::KeyboardTypeString;
	strcpy_s(UPacket.Text, text);
	SendPacket();
}

void PacketManager::SendKeyboardWakeUpHost()
{
	ClearPacket();
	UPacket.Type = PacketType::Command;
	UPacket.Command = HIDCommand::KeyboardWakeUpHost;
	SendPacket();
}

void PacketManager::SendKeyboardReleaseAll()
{
	ClearPacket();
	UPacket.Type = PacketType::Command;
	UPacket.Command = HIDCommand::KeyboardReleaseAll;
	SendPacket();
}

void PacketManager::SendGamepadButtonState(const int id, const bool state)
{
	ClearPacket();
	UPacket.Type = PacketType::Command;
	UPacket.Command = HIDCommand::GamepadButtonState;
	UPacket.Key = static_cast<uint8_t>(id);
	UPacket.Val1 = state;
	SendPacket();
}

void PacketManager::SendGamepadButtonPress(const int id, const int time)
{
	ClearPacket();
	UPacket.Type = PacketType::Command;
	UPacket.Command = HIDCommand::GamepadButtonPress;
	UPacket.Key = static_cast<uint8_t>(id);
	UPacket.Val1 = time;
	SendPacket();
}

void PacketManager::SendGamepadMoveAxis(const int axis, const int amt)
{
	ClearPacket();
	UPacket.Type = PacketType::Command;
	UPacket.Command = HIDCommand::GamepadMoveAxis;
	UPacket.Key = static_cast<uint8_t>(axis);
	UPacket.Val1 = amt;
	SendPacket();
}

void PacketManager::SendGamepadSetHat(const int angle)
{
	ClearPacket();
	UPacket.Type = PacketType::Command;
	UPacket.Command = HIDCommand::GamepadSetHat;
	UPacket.Val1 = angle;
	SendPacket();
}
