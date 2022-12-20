#pragma once
#include "../headers.h"

class HIDManager{

public:
    void Init(){
        Mouse.begin();
        Keyboard.begin();        
        Joystick.begin();
        Joystick.use8bit(true);
    }

    void ProcessPacket(Packet p);

private:
    void MouseMove(int x, int y);
    void MouseClick(SlaccrDefines::MouseButton btn);
    void MousePress(SlaccrDefines::MouseButton btn);
    void MouseRelease(SlaccrDefines::MouseButton btn);
    void MouseReleaseAll();
    void MouseScroll(int amt);
    void KeyboardKeyDown(uint8_t key);
    void KeyboardKeyUp(uint8_t key);
    void KeyboardTypeString(char text[16]);
    //void KeyboardWakeUpHost();
    void KeyboardReleaseAll();


    void JoyStickButtonState(uint8_t id, bool state);
    void JoyStickButtonPress(uint8_t id, int time);
    void JoyStickMoveAxis(uint8_t axis, int8_t amt);   
    void JoyStickSetHat(int angle); 
};