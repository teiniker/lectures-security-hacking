# PlatformIO Setup


## PlatformIO Core (CLI)

PlatformIO Core (CLI tool) is the heart of the entire PlatformIO.
PlatformIO Core is written in Python and works on Windows, macOS, 
Linux, FreeBSD and ARM-based credit-card sized computers (Raspberry Pi, 
BeagleBone, CubieBoard, Samsung ARTIK, etc.).

PlatformIO operates without the need for administrative or sudo permissions.

### Python Package Manager

It’s best to stick with this method ONLY IF you’re dealing with Continuous Integration 
systems/containers or if you have complete permissions to set up PlatformIO Core across 
your entire operating system.

```
$ pip3 install -U platformio

$ pio pkg update
```

In Unix and Unix-like systems, you can create symbolic links (symlinks) in your 
$HOME/.local/bin/ directory to the necessary PlatformIO executables. This will allow you 
to execute platformio commands from any terminal emulator as long as you’re logged in as 
the user PlatformIO is installed and configured for.

```
export PATH=$PATH:$HOME/.local/bin
```

```
$ pio device list
/dev/ttyUSB0
------------
Hardware ID: USB VID:PID=10C4:EA60 SER=0001 LOCATION=2-2
Description: CP2102 USB to UART Bridge Controller - CP2102 USB to UART Bridge Controller

$ sudo usermod -a -G dialout $USER
```
Note: **Logout and login again !!!!**


## References
* [PlatformIO Core (CLI)](https://docs.platformio.org/en/stable/core/index.html)
