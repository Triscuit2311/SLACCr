![SLACCr](https://socialify.git.ci/Triscuit2311/SLACCr/image?description=1&descriptionEditable=Not-So-Human%20Interface%20Device.&font=Source%20Code%20Pro&language=1&name=1&owner=1&pattern=Circuit%20Board&stargazers=1&theme=Dark)

### RP2040 hardware-based human interface device (HID) Emulator.
### License: [MIT](/LICENSE)

## Features
- USB Keyboard Emulation
- USB Mouse Emulation
- USB Gamepad Emulation
- Simple API interfaces for C++, C#, and Python
- Uses both cores of the RP2040, it's fast.


## What, Why?
- Firmware uses the community-driven arduino framework for the Raspberry Pi Pico, this makes it ewasy for end-users to setup with drag-and-drop firmware install.
- Accessibility is the name of the game! This project should serve as a resource for developers to create alternate interfaces for tech that does not support software input.


## Roadmap
- Aquire a Unique USB Vendor & Product ID
- Port firmware to bare metal
- Dynamic USB Descriptor Generation
- Split API into cross-platform and windows-specific versions

## API Reference (WIP)

### General
|Function|Parameters|Return|Description|
|:-|:-|:-|:-|
| Init | `calibrateMouse: bool` | `bool` | Initializes and attempts to connect to the hardware. |
| Disconnect|none|none|Cleans up peripherals and disconnects from the SLACCr hardware.|

### Mouse

###
|Function|Description|Parameters|
|:-|:-|:-|
| MouseApprox|Moves mouse via approximation based on calibration test.|`x: Horizontal value in pixels.`, `y: Vertical value in pixels.`|
| MousePercent|Moves mouse via percentage value (for full resolution, use MouseValue).|`x: Horizontal value. -100 to 100%.`, `y: Vertical value. -100% to 100%.`|
|MouseValue|Moves mouse via true poll value.|`x: Horizontal value. -127 to 127.`, `y: Vertical value. -127 to 127.`|
|MouseClick|Performs a Mouse click (Press-delay-release).|`button: Peripherals::MouseButton code`, `delay: downtime`|
|MousePress|Performs a mouse press (down only).|`button: Peripherals::MouseButton code`|
|MouseRelease|Performs a mouse release (up only).|`button: Peripherals::MouseButton code`|
|MouseReleaseAll|Releases all mouse buttons.|none|
|MouseScroll|Performs a mouse scroll.|`amount: Amount to scroll (-127 to 127)`|

### Keyboard

###
|Function|Description|Parameters|
|:-|:-|:-|
|KbKeyDown|Performs a key press (down only).|`key: Peripherals::Key Key code`|
|KbKeyUp|Performs a key release (up only).|`key: Peripherals::Key Key code`|
|KbStroke|Performs a key stroke (down-delay-up).|`key: Peripherals::Key Key code`,`delay: Key down time (in ms)`|
|KbType|Performs keystrokes to type a string.|`str: String to type`|
|KbReleaseAll|Releases all keyboard keys.|none|

### Gamepad

###
|Function|Description|Parameters|
|:-|:-|:-|
|GamepadButtonState|Sets the state of a Gamepad button.|`id: Peripherals::ButtonID Code (int 1-32)`, `state: up/down (true/false)`|
|GamepadButtonPress|Presses and releases a Gamepad Button.|`id: id Peripherals::ButtonID Code (int 1-32)`, `delay: Time in ms, delay performed on hardware`|
|GamepadMoveAxis|Sets Gamepad Axis position.|`axis: Peripherals::JoystickAxis Axis`, `amt: Value to set (-127 to 127)`|
|GamepadSetHat|Sets Gamepad Hat position.|`angle: Hat angle (0-360). -1 is released`|
|GamepadResetHat|Resets the Gamepad Hat position.|none|
|GamepadResetButtons|Resets all Gamepad Buttons (released).|none|
|GamepadResetAxises|Resets all Gamepad Axises (centered).|none|
|GamepadResetAll|Resets all Gamepad inputs.|none|


