#pragma once
#include "pch.h"

class SerialIo  // NOLINT(cppcoreguidelines-special-member-functions)
{
private:
	HANDLE Handle;
	bool Connected;
	COMSTAT Status{};
	DWORD Err{};
public:
	explicit SerialIo(const char* portName);
	~SerialIo();

	int Read(const char* buffer, unsigned int bufSize);
	bool Write(const uint8_t buffer[], unsigned int bufSize);
	bool IsConnected();
	void Close() const;
};
