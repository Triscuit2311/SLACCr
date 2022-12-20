#include "PacketManager.h"

Packet PacketManager::GetNextPacket(){
    while(!Serial.find(255)) delay(1);
    Packet p;
    Serial.readBytes(reinterpret_cast<byte*>(&p),sizeof(Packet));
    return p;
}