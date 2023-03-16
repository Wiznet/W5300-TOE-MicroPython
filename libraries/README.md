[![CI badge](https://github.com/micropython/micropython/workflows/unix%20port/badge.svg)](https://github.com/micropython/micropython/actions?query=branch%3Amaster+event%3Apush) [![codecov](https://codecov.io/gh/micropython/micropython/branch/master/graph/badge.svg?token=I92PfD05sD)](https://codecov.io/gh/micropython/micropython)

The MicroPython project
=======================
<p align="center">
  <img src="https://raw.githubusercontent.com/micropython/micropython/master/logo/upython-with-micro.jpg" alt="MicroPython Logo"/>
</p>

This is the MicroPython project, which aims to put an implementation
of Python 3.x on microcontrollers and small embedded systems.
You can find the official website at [micropython.org](http://www.micropython.org).
and origin [git-hub](https://github.com/micropython/micropython)
WARNING: this project is in beta stage and is subject to changes of the
code-base, including project-wide name changes and API changes.

MicroPython implements the entire Python 3.4 syntax (including exceptions,
`with`, `yield from`, etc., and additionally `async`/`await` keywords from
Python 3.5 and some select features from later versions). The following core
datatypes are provided: `str`(including basic Unicode support), `bytes`,
`bytearray`, `tuple`, `list`, `dict`, `set`, `frozenset`, `array.array`,
`collections.namedtuple`, classes and instances. Builtin modules include
`os`, `sys`, `time`, `re`, and `struct`, etc. Select ports have support for
`_thread` module (multithreading), `socket` and `ssl` for networking, and
`asyncio`. Note that only a subset of Python 3 functionality is implemented
for the data types and modules.

MicroPython can execute scripts in textual source form (.py files) or from
precompiled bytecode (.mpy files), in both cases either from an on-device
filesystem or "frozen" into the MicroPython executable.

MicroPython also provides a set of MicroPython-specific modules to access
hardware-specific functionality and peripherals such as GPIO, Timers, ADC,
DAC, PWM, SPI, I2C, CAN, Bluetooth, and USB.


About this repository
---------------------

This repository contains the following components:
- [py/](py/) -- the core Python implementation, including compiler, runtime, and
  core library.
- [mpy-cross/](mpy-cross/) -- the MicroPython cross-compiler which is used to turn scripts
  into precompiled bytecode.
- [ports/](ports/) -- platform-specific code for the various ports and architectures that MicroPython runs on. This repository only supports stm32.
- [lib/](lib/) -- submodules for external dependencies.
- [tests/](tests/) -- test framework and test scripts.
- [docs/](docs/) -- user documentation in Sphinx reStructuredText format. This is used to generate the [online documentation](http://docs.micropython.org).
- [extmod/](extmod/) -- additional (non-core) modules implemented in C.
- [tools/](tools/) -- various tools, including the pyboard.py module.
- [examples/](examples/) -- a few example Python scripts.

"make" is used to build the components, or "gmake" on BSD-based systems.
You will also need bash, gcc, and Python 3.3+ available as the command `python3`
(if your system only has Python 2.7 then invoke make with the additional option
`PYTHON=python2`). Some ports (rp2 and esp32) additionally use CMake.

Supported platforms & architectures
-----------------------------------

MicroPython runs on a wide range of microcontrollers, as well as on Unix-like
(including Linux, BSD, macOS, WSL) and Windows systems.

Microcontroller targets can be as small as 256kiB flash + 16kiB RAM, although
devices with at least 512kiB flash + 128kiB RAM allow a much more
full-featured experience.

The [Unix](ports/unix) and [Windows](ports/windows) ports allow both
development and testing of MicroPython itself, as well as providing
lightweight alternative to CPython on these platforms (in particular on
embedded Linux systems).

The ["minimal"](ports/minimal) port provides an example of a very basic
MicroPython port and can be compiled as both a standalone Linux binary as
well as for ARM Cortex M4. Start with this if you want to port MicroPython to
another microcontroller. Additionally the ["bare-arm"](ports/bare-arm) port
is an example of the absolute minimum configuration, and is used to keep
track of the code size of the core runtime and VM.

In addition, the following ports are provided in this repository:
 - [stm32](ports/stm32) -- STMicroelectronics STM32-Nucleo family.
 > NUCLEO-F429ZI, NUCLEO-F439ZI, NUCLEO-F722ZE, NUCLEO-F756ZG, NUCLEO-F767ZI)

Setting up Pin for W5300 on STM32 board
-----------------------------------------
In order to use the W5300 on an STM32 board, it is necessary to adjust the FMC settings. Specifically, if using FMC 16-bit, it will be necessary to modify any pins that overlap with previously set pins
To make these changes, locate the file "mpconfigureboard.h" in the directory "port/stm32/Board/NUCLEO_Fxxx" and edit the pins as indicated below.

####Step1. FMC pin configuration for the W5300
When using the W5300, the FMC interface used by the SD card is also used, making it impossible to use both at the same time. Therefore, the SD card setting must be disabled.
```cpp
#define MICROPY_HW_ENABLE_SDCARD    (0)
```

Remove the RMII Ethernet defines and add the FMC defines.
```cpp
#if (MICROPY_PY_NETWORK_WIZNET5K == 5300)

#define MICROPY_HW_FMC_A0 (pin_F0)
#define MICROPY_HW_FMC_A1 (pin_F1)
 ...
#define MICROPY_HW_FMC_A9 (pin_F15)

#define MICROPY_HW_FMC_D0 (pin_D14)
#define MICROPY_HW_FMC_D1 (pin_D15)
 ...
#define MICROPY_HW_FMC_D15 (pin_D10)

#define MICROPY_HW_FMC_NO (pin_D4)
#define MICROPY_HW_FMC_NW (pin_D5)
#define MICROPY_HW_FMC_NE1 (pin_D7)

#define MICROPY_HW_WIZCHIP_RST (pin_C8)
#define MICROPY_HW_WIZCHIP_INT (pin_C9)

#else
// Ethernet via RMII
#define MICROPY_HW_ETH_MDC (pin_C1)
#define MICROPY_HW_ETH_MDIO (pin_A2)
#define MICROPY_HW_ETH_RMII_REF_CLK (pin_A1)
#define MICROPY_HW_ETH_RMII_CRS_DV (pin_A7)
#define MICROPY_HW_ETH_RMII_RXD0 (pin_C4)
#define MICROPY_HW_ETH_RMII_RXD1 (pin_C5)
#define MICROPY_HW_ETH_RMII_TX_EN (pin_G11)
#define MICROPY_HW_ETH_RMII_TXD0 (pin_G13)
#define MICROPY_HW_ETH_RMII_TXD1 (pin_B13)
#endif

```

####Step2. Change duplicate pin
In the example provided by WIZnet, redundant pin settings have been modified. If you use different settings than those provided, you will need to modify the 'mpconfigureboard.h' file accordingly.

Here is an example of how to modify the UART3 settings in the 'mpconfigureboard.h' file. Please refer to this example when making similar changes.

```cpp
// Before modification:
#define MICROPY_HW_UART3_TX (pin_D8)
#define MICROPY_HW_UART3_RX (pin_D9)

// After modification:
#define MICROPY_HW_UART3_TX (pin_C10)
#define MICROPY_HW_UART3_RX (pin_C11)
```

