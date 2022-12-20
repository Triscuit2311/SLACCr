#pragma once
#include "PacketManager.h"

class Mouse
{
public:
	explicit Mouse(PacketManager* p_packet_manager, bool perform_calibration = true, bool enable_output = true)
		: UPacketManager(p_packet_manager)
	{
		if (!perform_calibration) return;

		Calibrate(10, enable_output);
	}

private:
	PacketManager* UPacketManager;
	std::unordered_map<unsigned int, int> XCalibrationData{};
	std::unordered_map<unsigned int, int> YCalibrationData{};
	const int CalibrationValues[8] = { 2, 5, 10, 25, 50, 75, 100, 127 };
	void Calibrate(int numberOfTests = 10,  bool enableOutput = true);
	void PrintCalibrationData() const;
	unsigned short Latency = 1;
	bool isCalibrated = false;
public:
	void SetLatency(const unsigned short newLatency) { Latency = newLatency; }
	void MovePercent(int x, int y) const;
	void MoveApprox(int x, int y, short threshold);
	void MoveRelative(int x, int y, short threshold);
	void MoveAbsolute(int x, int y, short threshold);
	void MouseClick(int b = Peripherals::MouseButton::Left, unsigned int downtime = 50) const;
	void MousePress(int b = Peripherals::MouseButton::Left) const;
	void MouseRelease(int b = Peripherals::MouseButton::Left) const;
	void MouseReleaseAll() const;
	void MouseScroll(int amount) const;
	void MoveValue(int x, int y) const;
};
