#include "pch.h"
#include "SerialIO.h"

SerialIo::SerialIo(const char* portName)
{
    this->Connected = false;

    this->Handle = CreateFileA(portName,
        GENERIC_READ | GENERIC_WRITE,
        0,
        nullptr,
        OPEN_EXISTING,
        FILE_ATTRIBUTE_NORMAL,
        nullptr);
    if (this->Handle == INVALID_HANDLE_VALUE)
    {
        if (GetLastError() == ERROR_FILE_NOT_FOUND)
        {
            std::cerr << "ERROR: Handle was not attached. Reason : " << portName << " not available\n";
        }
        else
        {
            std::cerr << "ERROR: Undefined error during COM port connect: " << portName << '\n';
        }
    }
    else
    {
        DCB dcbSerialParameters = { 0 };  // NOLINT(clang-diagnostic-missing-field-initializers)

        if (!GetCommState(this->Handle, &dcbSerialParameters))
        {
            std::cerr << "Failed to get current serial parameters\n";
        }
        else
        {
            dcbSerialParameters.BaudRate = CBR_256000; //CBR_9600;
            dcbSerialParameters.ByteSize = 8;
            dcbSerialParameters.StopBits = ONESTOPBIT;
            dcbSerialParameters.Parity = NOPARITY;
            dcbSerialParameters.fDtrControl = DTR_CONTROL_ENABLE;

            if (!SetCommState(Handle, &dcbSerialParameters))
            {
                std::cout << "ALERT: could not set serial port parameters\n";
            }
            else
            {
                this->Connected = true;
                PurgeComm(this->Handle, PURGE_RXCLEAR | PURGE_TXCLEAR);
                Sleep(2000);
            }
        }
    }
}

SerialIo::~SerialIo()
{
    if (this->Connected)
    {
        this->Connected = false;

        if (this->Handle != nullptr)
            CloseHandle(this->Handle);
    }
}


int SerialIo::Read(const char* buffer, const unsigned bufSize)
{
    DWORD bytesRead{};
    unsigned int toRead = 0;

    ClearCommError(this->Handle, &this->Err, &this->Status);

    if (this->Status.cbInQue > 0)
    {
        if (this->Status.cbInQue > bufSize)
        {
            toRead = bufSize;
        }
        else
        {
            toRead = this->Status.cbInQue;
        }
    }

    // ReSharper disable CppCStyleCast
    memset((void*)buffer, 0, bufSize);


    if (ReadFile(this->Handle, (void*)buffer, toRead, &bytesRead, nullptr))
    {
        return bytesRead;  // NOLINT(bugprone-narrowing-conversions, cppcoreguidelines-narrowing-conversions)
    }
    // ReSharper restore CppCStyleCast

    return 0;
}

bool SerialIo::Write(const uint8_t buffer[], const unsigned bufSize)
{
    DWORD bytesSend;

    if (!WriteFile(this->Handle, (void*)buffer,
        bufSize, &bytesSend, nullptr))
    {
        ClearCommError(this->Handle, &this->Err, &this->Status);
        return false;
    }

    return true;
}

bool SerialIo::IsConnected()
{
    if (!ClearCommError(this->Handle, &this->Err, &this->Status))
    {
        this->Connected = false;
    }

    return this->Connected;
}

void SerialIo::Close() const
{
    CloseHandle(this->Handle);
}
