![SLACCr](https://socialify.git.ci/Triscuit2311/SLACCr/image?description=1&descriptionEditable=Not-So-Human%20Interface%20Device.&font=Source%20Code%20Pro&language=1&name=1&owner=1&pattern=Circuit%20Board&stargazers=1&theme=Dark)

### RP2040 hardware-based human interface device (HID) Emulator.
### License: [MIT](/LICENSE)

## Features
- USB Keyboard Emulation
- USB Mouse Emulation
- USB Gamepad Emulation
- Simple API interfaces for C++, C#, and Python
- Uses both cores of the RP2040, it's fast.
## Roadmap

- Aquire a Unique USB Vendor & Product ID
- Port firmware to bare metal
- Dynamic USB Descriptor Generation


## API Reference (WIP)

|Function|Parameters|Return|Description|
|:-|:-|:-|:-|
| Init | `calibrateMouse: bool` | `bool` | Initializes and attempts to connect to the hardware. |
| DIsconnect|none|none|Cleans up peripherals and disconnects from the SLACCr hardware.|


