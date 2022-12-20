#include "../headers.h"

MutexPacketQueue hidQueue;
PacketManager pm;
HIDManager hidManager;

void core_0_initialize(){
    pinMode(LED_BUILTIN, OUTPUT);
    digitalWrite(LED_BUILTIN, HIGH);
    Serial.begin(256000);
    Serial.write("SLACCR\n");
    delay(3000);
    digitalWrite(LED_BUILTIN, LOW);
}

void core_1_initialize(){
   delay(1000);
   hidManager.Init();
}

void core_0_tick(){
    Packet p = pm.GetNextPacket();

    switch(p.Type){
        case SlaccrDefines::PacketType::Command:
            hidQueue.push(p);
            break;
        case SlaccrDefines::PacketType::Debug:
            if(p.Command == SlaccrDefines::DebugCommands::Identify){
                Serial.write("SLACCR\n");
            }
            break;
        default: break;
    }
}


void core_1_tick(){
    while(!hidQueue.isEmpty()){
        hidManager.ProcessPacket(hidQueue.pop());
    }
}