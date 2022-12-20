#pragma once
#include "PacketManager.h"

class Gamepad
{
public:
	explicit Gamepad(PacketManager* p_packet_manager)
		: UPacketManager(p_packet_manager)
	{}

private:
	PacketManager* UPacketManager;
public:
	void ButtonState(int id, bool state) const;
	void ButtonPress(int id, int time) const;
	void MoveAxis(int axis, int amt) const;
	void SetHat(int angle) const;
	void ResetHat() const;
	void ResetAllAxises() const;
	void ResetButtons() const;
	void ResetAll() const;
};
