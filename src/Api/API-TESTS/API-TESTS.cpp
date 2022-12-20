#include <iostream>
#include <SLACCR_API.h>
#include <thread>

void GamePadTest();

int main()
{
    if(Slaccr::Init(false))
    {
        std::cout << "CONNECTED\n";

        while (true) {
            GamePadTest();
        }
    }
}






void GamePadTest()
{
    // Axises
    {
        auto moveAllAxises = [](auto i)
        {
            Slaccr::GamepadMoveAxis(Peripherals::JoystickAxis::X, i);
            Slaccr::GamepadMoveAxis(Peripherals::JoystickAxis::Y, i);
            Slaccr::GamepadMoveAxis(Peripherals::JoystickAxis::Z, i);
            Slaccr::GamepadMoveAxis(Peripherals::JoystickAxis::Zrotate, i);
            Slaccr::GamepadMoveAxis(Peripherals::JoystickAxis::SliderLeft, i);
            Slaccr::GamepadMoveAxis(Peripherals::JoystickAxis::SliderRight, i);
        };

        int axisMaxV = 127;
        for (auto n = 1; n < 5; n++) {
            auto i = -axisMaxV;
            for (i; i <= axisMaxV; i++) {
                moveAllAxises(i);
            }
            axisMaxV /= n;
            for (i; i >= -axisMaxV; i--) {
                moveAllAxises(i);
            }
        }
        Slaccr::GamepadResetAxises();
        std::this_thread::sleep_for(std::chrono::milliseconds(500));
    }

    // Hat
    {
        for (auto i = 0; i <= 361; i += 15) {
            Slaccr::GamepadSetHat(i);
            std::this_thread::sleep_for(std::chrono::milliseconds(20));
        }
        std::this_thread::sleep_for(std::chrono::milliseconds(250));
        Slaccr::GamepadResetHat();
        std::this_thread::sleep_for(std::chrono::milliseconds(250));
    }

    // Buttons
    {
        for (auto i = 1; i <= 32; i++) {
            Slaccr::GamepadButtonPress(i, 100);
            std::this_thread::sleep_for(std::chrono::milliseconds(150));
        }
        std::this_thread::sleep_for(std::chrono::milliseconds(500));

        for (auto i = 1; i <= 32; i++) {
            Slaccr::GamepadButtonState(i, true);
            std::this_thread::sleep_for(std::chrono::milliseconds(50));
        }
        std::this_thread::sleep_for(std::chrono::milliseconds(500));
        Slaccr::GamepadResetButtons();
    }
}
