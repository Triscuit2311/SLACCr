#pragma once
#include "PacketManager.h"

class Keyboard
{
public:
	explicit Keyboard(PacketManager* pPacketManager)
		: PPacketManager(pPacketManager)
	{
	}

private:
	PacketManager* PPacketManager;

public:
	void KeyDown(int key) const;
	void KeyUp(int key) const;
	void Stroke(int key, unsigned int downtime = 10) const;
	void Type(const std::string& str) const;
	void ReleaseAll() const;
};
