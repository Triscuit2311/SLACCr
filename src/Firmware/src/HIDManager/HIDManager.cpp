#include "HIDManager.h"

void HIDManager::ProcessPacket(Packet p){
    switch(p.Command){
		case SlaccrDefines::HIDCommand::MouseMove:
            MouseMove(p.Val1, p.Val2);
            break;
		case SlaccrDefines::HIDCommand::MouseClick:
            MouseClick(p.MouseButton);
            break;
		case SlaccrDefines::HIDCommand::MousePress:
            MousePress(p.MouseButton);
            break;
		case SlaccrDefines::HIDCommand::MouseRelease:
            MouseRelease(p.MouseButton);
            break;
		case SlaccrDefines::HIDCommand::MouseReleaseAll:
            MouseReleaseAll();
            break;
		case SlaccrDefines::HIDCommand::MouseScroll:
            MouseScroll(p.Val1);
            break;
		case SlaccrDefines::HIDCommand::KeyboardKeyDown:
            KeyboardKeyDown(p.Key);
            break;
		case SlaccrDefines::HIDCommand::KeyboardKeyUp:
            KeyboardKeyUp(p.Key);
            break;
		case SlaccrDefines::HIDCommand::KeyboardTypeString:
            KeyboardTypeString(p.Text);
            break;
		case SlaccrDefines::HIDCommand::KeyboardReleaseAll:
            KeyboardReleaseAll();
            break;
        case SlaccrDefines::HIDCommand::GamepadButtonState:
            JoyStickButtonState(p.Key,p.Val1);
            break;
        case SlaccrDefines::HIDCommand::GamepadButtonPress:
            JoyStickButtonPress(p.Key,p.Val1);
            break;
        case SlaccrDefines::HIDCommand::GamepadMoveAxis:
            JoyStickMoveAxis(p.Key,p.Val1);
            break;
        case SlaccrDefines::HIDCommand::GamepadSetHat:
            JoyStickSetHat(p.Val1);
            break;
    }
}

void HIDManager::MouseMove(int x, int y){
    Mouse.move(x,y,0);
}

void HIDManager::MouseClick(SlaccrDefines::MouseButton btn){
    MousePress(btn);
    delay(5);
    MouseRelease(btn);
}

void HIDManager::MousePress(SlaccrDefines::MouseButton btn){
    Mouse.press(btn);
}

void HIDManager::MouseRelease(SlaccrDefines::MouseButton btn){
    Mouse.release(btn);
}

void HIDManager::MouseReleaseAll(){
    Mouse.release(SlaccrDefines::MouseButton::All);
}

void HIDManager::MouseScroll(int amt){
    Mouse.move(0,0,amt);
}

void HIDManager::KeyboardKeyDown(uint8_t key){
    Keyboard.press(key);
}

void HIDManager::KeyboardKeyUp(uint8_t key){
    Keyboard.release(key);
}

void HIDManager::KeyboardTypeString(char text[16]){
    Keyboard.print(text);
}

void HIDManager::KeyboardReleaseAll(){
    Keyboard.releaseAll();
}

void HIDManager::JoyStickButtonState(uint8_t id, bool state){
    Joystick.button(id, state);
}

void HIDManager::JoyStickButtonPress(uint8_t id, int time){
    Joystick.button(id, true);
    delay(time);
    Joystick.button(id, false);
}

void HIDManager::JoyStickSetHat(int angle){
    Joystick.hat(angle);
}

void HIDManager::JoyStickMoveAxis(uint8_t axis, int8_t amt){
    switch (axis)
    {
    case SlaccrDefines::JoystickAxis::X:
        Joystick.X(amt);
        break;
    case SlaccrDefines::JoystickAxis::Y:
        Joystick.Y(amt);
        break;
    case SlaccrDefines::JoystickAxis::Z:
        Joystick.Z(amt);
        break;
    case SlaccrDefines::JoystickAxis::Zrotate:
        Joystick.Zrotate(amt);
        break;
    case SlaccrDefines::JoystickAxis::SliderLeft:
        Joystick.sliderLeft(amt);
        break;
    case SlaccrDefines::JoystickAxis::SliderRight:
        Joystick.sliderRight(amt);
        break;
    default:
        break;
    }
}