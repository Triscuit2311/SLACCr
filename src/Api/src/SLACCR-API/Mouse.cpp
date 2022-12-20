#include "pch.h"
#include "Mouse.h"

void Mouse::Calibrate(int numberOfTests, bool enableOutput)
{
	POINT curPos;
	for (const auto n : CalibrationValues)
	{
		int xAvg = 0;
		int yAvg = 0;

		for (auto i = 0; i < numberOfTests; i++)
		{
			GetCursorPos(&curPos);

			const POINT lastCurPos = curPos;

			const int v = i % 2 == 0 ? n : -n;

			this->UPacketManager->SendMouseMove(v, v);

			Sleep(10);

			GetCursorPos(&curPos);

			if (i == 0) continue;

			xAvg += abs(curPos.x - lastCurPos.x);
			yAvg += abs(curPos.y - lastCurPos.y);
		}

		XCalibrationData.insert_or_assign(n, xAvg / (numberOfTests - 1));
		YCalibrationData.insert_or_assign(n, yAvg / (numberOfTests - 1));
	}
	isCalibrated = true;

	if (!enableOutput) return;

	PrintCalibrationData();
}

void Mouse::PrintCalibrationData() const
{
	std::cout << "\nMouse Calibration Table" << std::endl;
	std::cout << std::setw(15) << std::left << "Value"
		<< std::setw(15) << std::left << "X-Axis Px"
		<< std::setw(15) << std::left << "Y-Axis Px" << std::endl;

	for (unsigned int i = 0; i < XCalibrationData.size(); i++)
	{
		const auto v = CalibrationValues[i];
		std::cout << std::setw(15) << std::left << v <<
			std::setw(15) << std::left << XCalibrationData.at(v) <<
			std::setw(15) << std::left << YCalibrationData.at(v) << std::endl;

	}
	std::cout << std::endl;
}


void Mouse::MovePercent(const int x, const int y) const
{
	constexpr auto inc = 127 / 100;
	this->UPacketManager->SendMouseMove(inc * x, inc * y);
}

// Approximate Mouse movement in pixels based on calibration data
void Mouse::MoveApprox(int x, int y, const short threshold)
{
	if(!isCalibrated)
	{
		std::cout << "Mouse Not calibrated! Cannot use MoveApprox(...)." << std::endl;
		return;
	}

	while (abs(x) > threshold || abs(y) > threshold)
	{

		int moveX = 0;
		int moveY = 0;

		for (const auto v : CalibrationValues)
		{
			if (abs(x) >= XCalibrationData[v])
				moveX = x > 0 ? v : -v;

			if (abs(y) >= YCalibrationData[v])
				moveY = x > 0 ? v : -v;

		}

		this->UPacketManager->SendMouseMove(moveX, moveY);
		Sleep(Latency);

		x -= XCalibrationData[moveX];
		y -= YCalibrationData[moveY];
	}
}

void Mouse::MoveRelative(const int x, const int y, const short threshold)
{
	// TODO: Implement Move Absolute First
}

void Mouse::MoveAbsolute(const int x, const int y, const short threshold)
{
	// TODO: Implement half decent algorithm
}

// void Mouse::MoveRelative(const int x, const int y, const short threshold)
// {
// 	POINT curPos;
// 	GetCursorPos(&curPos);
// 	MoveAbsolute(curPos.x + x, curPos.y + y, threshold);
// }
//
// void Mouse::MoveAbsolute(const int x, const int y, const short threshold)
// {
// 	POINT curPos;
// 	GetCursorPos(&curPos);
//
// 	while(abs(curPos.x - x) > threshold || abs(curPos.y - y) > threshold)
// 	{
//
// 		int moveX = 0;
// 		int moveY = 0;
//
// 		for(const auto v : CalibrationValues)
// 		{
// 			if (abs(curPos.x - x) >= XCalibrationData[v])
// 				moveX = (curPos.x - x) > 0 ? -v : v;
//
// 			if (abs(curPos.y - y) >= YCalibrationData[v])
// 				moveY = (curPos.y - y) > 0 ? -v : v;
// 		}
//
// 		this->UPacketManager->SendMouseMove(moveX, moveY);
//
// 		Sleep(Latency);
// 		GetCursorPos(&curPos);
// 	}
// }

void Mouse::MouseClick(const int b, const unsigned int downtime) const
{
	this->UPacketManager->SendMousePress(b);
	Sleep(downtime);
	this->UPacketManager->SendMousePress(b);
}

void Mouse::MousePress(const int b) const
{
	this->UPacketManager->SendMousePress(b);
}

void Mouse::MouseRelease(const int b) const
{
	this->UPacketManager->SendMouseRelease(b);
}

void Mouse::MouseReleaseAll() const
{
	this->UPacketManager->SendMouseReleaseAll();
}

void Mouse::MouseScroll(const int amount) const
{
	this->UPacketManager->SendMouseScroll(amount);
}

void Mouse::MoveValue(const int x, const int y) const
{
	this->UPacketManager->SendMouseMove(x, y);
}
