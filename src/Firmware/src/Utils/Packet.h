/* Copyright (c) 2022 Dante Trisciuzzi */

#pragma once
#include "../headers.h"

struct Packet
{
    SlaccrDefines::PacketType Type = SlaccrDefines::PacketType::Debug;
    uint8_t Command{0};
    int Val1{0};
    int Val2{0};
    SlaccrDefines::MouseButton MouseButton = SlaccrDefines::MouseButton::Left;
    uint8_t Key = 0x00;
    char Text[16]{};
};