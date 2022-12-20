#pragma once
#include "../headers.h"

class PacketManager{
public:
    Packet GetNextPacket();

private:
    const byte StartMarker = 255;
};