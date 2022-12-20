#include "pch.h"
#include "Slaccr_Controller.h"

#define MAXIMUM_COM_PORT_NUMBER 100


Slaccr_Controller::Slaccr_Controller() :
PSerialPort(nullptr),
PPacketManager(nullptr),
PMouse(nullptr),
PKeyboard(nullptr),
PGamePad(nullptr)
{
}

void Slaccr_Controller::Init(const bool calibrateMouse)
{
	Connected = Connect(10, calibrateMouse);
}

Slaccr_Controller::~Slaccr_Controller()
{
	PMouse->MouseReleaseAll();
	PKeyboard->ReleaseAll();
	PGamePad->ResetAll();
	delete PPacketManager;
	delete PMouse;
	delete PKeyboard;
	delete PGamePad;
}

bool Slaccr_Controller::Connect(const int retries, const bool performMouseCalibration)
{
	for (auto tries = 0; tries < retries; tries++)
	{
		for (auto i = 0; i < MAXIMUM_COM_PORT_NUMBER; i++)
		{
			Sleep(10);
			char lpTargetPath[5500];
			std::string comName = "COM" + std::to_string(i);


			const DWORD tPort = QueryDosDevice(comName.c_str(), lpTargetPath, 5000);
			if (tPort != 0)
			{
				const std::string portStr = R"(\\.\)" + comName;
				const char* portToCheck = const_cast<char*>(portStr.c_str());

				PSerialPort = new SerialIo(portToCheck);
				PPacketManager = new PacketManager(PSerialPort);
				std::cout << "Device found at: " << portToCheck << std::endl;
				std::cout << "Checking Device..." << std::endl;
				Sleep(1000);
				char msg[255];

				PPacketManager->SendIdentifyPacket();
				Sleep(100);
				PSerialPort->Read(msg, 255);
				std::cout << "Received: " << std::string(msg) << std::endl;

				if (std::string(msg) == "SLACCR\n")
				{
					std::cout << "Device Initializing at: " << portToCheck << std::endl;
					PMouse = new Mouse(PPacketManager, performMouseCalibration);
					PKeyboard = new Keyboard(PPacketManager);
					PGamePad = new Gamepad(PPacketManager);
					Sleep(1500);
					std::cout << "Device Initialized at: " << portToCheck << std::endl;
					return true;
				}
				PSerialPort->Close();

				if (GetLastError() == ERROR_INSUFFICIENT_BUFFER)
				{
				}
			}
		}
		Sleep(100);
	}
	std::cout << "No eligible device found, if your device is connected, reset or re-connect it." << std::endl;
	return false;
}

bool Slaccr_Controller::Disconnect()
{
	return true;
}

void Slaccr_Controller::MouseApprox(const int x, const int y) const
{
	PMouse->MoveApprox(x, y, MouseAccuracy);
}

void Slaccr_Controller::MousePercent(const int x, const int y) const
{
	PMouse->MovePercent(x, y);
}

void Slaccr_Controller::MouseValue(const int x, const int y) const
{
	PMouse->MoveValue(x, y);
}


bool Slaccr_Controller::IsConnected() const
{
	return Connected;
}


void Slaccr_Controller::MouseRel(const int x, const int y) const
{
	PMouse->MoveRelative(x, y, MouseAccuracy);
}

void Slaccr_Controller::MouseTo(const int x, const int y) const
{
	PMouse->MoveAbsolute(x, y, MouseAccuracy);
}

void Slaccr_Controller::MouseClick(const int button) const
{
	PMouse->MouseClick(button, MouseClickTime);
}

void Slaccr_Controller::MousePress(const int button) const
{
	PMouse->MousePress(button);
}

void Slaccr_Controller::MouseRelease(const int button) const
{
	PMouse->MouseRelease(button);
}

void Slaccr_Controller::MouseReleaseAll() const
{
	PMouse->MouseReleaseAll();
}

void Slaccr_Controller::MouseScroll(const int amount) const
{
	PMouse->MouseScroll(amount);
}

void Slaccr_Controller::KbKeyDown(const int key) const
{
	PKeyboard->KeyDown(key);
}

void Slaccr_Controller::KbKeyUp(const int key) const
{
	PKeyboard->KeyUp(key);
}

void Slaccr_Controller::KbStroke(const int key, const int delay) const
{
	PKeyboard->Stroke(key, delay);
}

void Slaccr_Controller::KbType(const std::string& str) const
{
	PKeyboard->Type(str);
}


void Slaccr_Controller::KbReleaseAll() const
{
	PKeyboard->ReleaseAll();
}

void Slaccr_Controller::GamepadButtonState(const int id, const bool state) const
{
	PGamePad->ButtonState(id, state);
}

void Slaccr_Controller::GamepadButtonPress(const int id, const int time) const
{
	PGamePad->ButtonPress(id, time);
}

void Slaccr_Controller::GamepadMoveAxis(const int axis, const int amt) const
{
	PGamePad->MoveAxis(axis, amt);
}

void Slaccr_Controller::GamepadMoveHat(const int angle) const
{
	PGamePad->SetHat(angle);
}

void Slaccr_Controller::GamepadResetHat() const
{
	PGamePad->ResetHat();
}

void Slaccr_Controller::GamepadResetAxises() const
{
	PGamePad->ResetAllAxises();
}

void Slaccr_Controller::GamepadResetButtons() const
{
	PGamePad->ResetButtons();
}

void Slaccr_Controller::GamepadResetAll() const
{
	PGamePad->ResetAll();
}
