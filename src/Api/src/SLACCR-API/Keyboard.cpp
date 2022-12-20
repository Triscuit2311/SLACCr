#include "pch.h"
#include "Keyboard.h"

void Keyboard::KeyDown(const int key) const
{
	this->PPacketManager->SendKeyboardKeyDown(key);
}

void Keyboard::KeyUp(const int key) const
{
	this->PPacketManager->SendKeyboardKeyUp(key);
}

void Keyboard::Stroke(const int key, const unsigned int downtime) const
{
	this->PPacketManager->SendKeyboardKeyDown(key);
	Sleep(downtime);
	this->PPacketManager->SendKeyboardKeyUp(key);
}

void Keyboard::Type(const std::string& str) const
{
	if (str.length() >= 16)
	{
		for (unsigned int i = 0; i < str.length(); i += 15)
		{
			auto s = str.substr(i, 15);
			this->PPacketManager->SendKeyboardTypeString(s.c_str());
		}
		return;
	}
	this->PPacketManager->SendKeyboardTypeString(str.c_str());
}

void Keyboard::ReleaseAll() const
{
	this->PPacketManager->SendKeyboardReleaseAll();
}