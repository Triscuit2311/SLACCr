#include "pch.h"
#include "SLACCR_API.h"
#include "Slaccr_Controller.h"

Slaccr_Controller slaccr_device;

bool Slaccr::Init(bool calibrateMouse)
{
	if(!slaccr_device.IsConnected())
		slaccr_device.Init(calibrateMouse);

	if (!slaccr_device.IsConnected())
		return false;
		
	return true;
}

void Slaccr::Disconnect()
{
	slaccr_device.Disconnect();
}

void Slaccr::MouseApprox(const int x, const int y)
{
	slaccr_device.MouseApprox(x, y);
}

void Slaccr::MousePercent(const int x, const int y)
{
	slaccr_device.MousePercent(x, y);
}

void Slaccr::MouseValue(const int x, const int y)
{
	slaccr_device.MouseValue(x,y);
}

void Slaccr::MouseClick(const int button)
{
	slaccr_device.MouseClick(button);
}

void Slaccr::MousePress(const int button)
{
	slaccr_device.MousePress(button);
}

void Slaccr::MouseRelease(const int button)
{
	slaccr_device.MouseRelease(button);
}

void Slaccr::MouseReleaseAll()
{
	slaccr_device.MouseReleaseAll();
}

void Slaccr::MouseScroll(const int amount)
{
	slaccr_device.MouseScroll(amount);
}

void Slaccr::KbKeyDown(const int key)
{
	slaccr_device.KbKeyDown(key);
}

void Slaccr::KbKeyUp(const int key)
{
	slaccr_device.KbKeyUp(key);
}

void Slaccr::KbStroke(const int key, const int delay)
{
	slaccr_device.KbStroke(key, delay);
}

// void Slaccr::KbTypeStdStr(const std::string& str)
// {
// 	slaccr_device.KbType(str);
// }

void Slaccr::KbType(const char* str)
{
	slaccr_device.KbType(std::string(str));
}

void Slaccr::KbReleaseAll()
{
	slaccr_device.KbReleaseAll();
}

void Slaccr::GamepadButtonState(const int id, const bool state)
{
	slaccr_device.GamepadButtonState(id, state);
}

void Slaccr::GamepadButtonPress(const int id, const int delay)
{
	slaccr_device.GamepadButtonPress(id, delay);
}

void Slaccr::GamepadMoveAxis(const int axis, const int amt)
{
	slaccr_device.GamepadMoveAxis(axis, amt);
}

void Slaccr::GamepadSetHat(const int angle)
{
	slaccr_device.GamepadMoveHat(angle);
}

void Slaccr::GamepadResetHat()
{
	slaccr_device.GamepadMoveHat(-1);
}

void Slaccr::GamepadResetButtons()
{
	slaccr_device.GamepadResetButtons();
}

void Slaccr::GamepadResetAxises()
{
	slaccr_device.GamepadResetAxises();
}

void Slaccr::GamepadResetAll()
{
	slaccr_device.GamepadResetAll();
}


