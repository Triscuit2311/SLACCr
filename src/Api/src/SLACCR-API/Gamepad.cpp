#include "pch.h"
#include "Gamepad.h"

void Gamepad::ButtonState(const int id, const bool state) const
{
	this->UPacketManager->SendGamepadButtonState(id, state);
}

void Gamepad::ButtonPress(const int id, const int time) const
{
	this->UPacketManager->SendGamepadButtonPress(id, time);
}

void Gamepad::MoveAxis(const int axis, const int amt) const
{
	this->UPacketManager->SendGamepadMoveAxis(axis, amt);
}

void Gamepad::SetHat(const int angle) const
{
	this->UPacketManager->SendGamepadSetHat(angle);
}

void Gamepad::ResetHat() const
{
	this->UPacketManager->SendGamepadSetHat(-1);
}

void Gamepad::ResetAllAxises() const
{
	for (auto i = 0; i <= 5; i++)
		this->UPacketManager->SendGamepadMoveAxis(i, 0);
}


void Gamepad::ResetButtons() const
{
	for (auto i = 1; i <= 32; i++)
		this->UPacketManager->SendGamepadButtonPress(i, false);
}


void Gamepad::ResetAll() const
{
	this->ResetHat();
	this->ResetAllAxises();
	this->ResetButtons();
}

