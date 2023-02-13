
<a name="Getting_Started"></a>
# Getting Started

These sections will guide you through a series of steps from configuring development environment to running ethernet examples using the **W5300**.

- [Hardware requirements](#hardware-requirements)
- [Software requirements](#software-requirements)
- [Wiznet5K Library](#wiznet5k-library)
  - [Deploying firmware to the device](#deploying-firmware-to-the-device)
  - [Building](#building)
- [Thonny](#thonny)
- [Sample code](#sample-code)
- [Ethernet example structure](#ethernet-example-structure)
- [Documentation](#documentation)

-------

<a name="hardware_requirements"></a>

# Hardware requirements

 The ethernet examples use **NUCLEO-F429ZI** build on STM32 MCU with WIZnet's [**W5300**][link-w5300] ethernet chip.
If you use other STM board, supported board of STMicroelectronics micropython in [**LIST**][link-suppoted_stm]
and check that the board supports FMC 16bit data

## Pin Diagram

**`STM32F429ZI`**
This document is based on STM32F429ZI. If you use other STM board, Please edit it to your HW configuration.
![][link-stm_pinmap]
 - FMC Data pin (0-8 or 0-16)
 - FMC Address pin (0-10)
 - FMC Control GPIO pin (NE, NWE, NOE)
 - WIZChip Control GPIO pin (INT, RST)
 - UART3 pin(connect to ST-LINK) 
  -- Be changed for use the FMC on the Nucleoboard. Pin D8,D9 -> Pin C10,C11

------
<a name="software_requirements"></a>

# Software requirements

  The following program is required Install FW and test examples, download and install from below link.
  - [**STM32CubeProgrammer**][link-STM32CubeProgrammer]
  - [**Thonny**][link-thonny]

  If you use other HW configuration, Please edit it to your pin configuration.
   > micropython\ports\stm32\boards\NUCLEO_F429ZI\mpconfigboard.h
  
  ```cpp

  #define MICROPY_HW_UART3_TX     (pin_C10)//(pin_D8)
  #define MICROPY_HW_UART3_RX     (pin_C11)//(pin_D9)

  #define MICROPY_HW_FMC_A0     (pin_F0)
  #define MICROPY_HW_FMC_A1     (pin_F1)
  #define MICROPY_HW_FMC_A2 	  (pin_F2)
  #define MICROPY_HW_FMC_A3   	(pin_F3)
  #define MICROPY_HW_FMC_A4     (pin_F4)
  #define MICROPY_HW_FMC_A5     (pin_F5)
  #define MICROPY_HW_FMC_A6	    (pin_F12)
  #define MICROPY_HW_FMC_A7	    (pin_F13)
  #define MICROPY_HW_FMC_A8	    (pin_F14)
  #define MICROPY_HW_FMC_A9	    (pin_F15)

  #define MICROPY_HW_FMC_D0	    (pin_D14)
  #define MICROPY_HW_FMC_D1	    (pin_D15)
  #define MICROPY_HW_FMC_D2	    (pin_D0)
  #define MICROPY_HW_FMC_D3	    (pin_D1)
  #define MICROPY_HW_FMC_D4	    (pin_E7)
  #define MICROPY_HW_FMC_D5	    (pin_E8)
  #define MICROPY_HW_FMC_D6	    (pin_E9)
  #define MICROPY_HW_FMC_D7	    (pin_E10)
  #define MICROPY_HW_FMC_D8	    (pin_E11)
  #define MICROPY_HW_FMC_D9	    (pin_E12)
  #define MICROPY_HW_FMC_D10	  (pin_E13)
  #define MICROPY_HW_FMC_D11	  (pin_E14)
  #define MICROPY_HW_FMC_D12	  (pin_E15)
  #define MICROPY_HW_FMC_D13	  (pin_D8)
  #define MICROPY_HW_FMC_D14	  (pin_D9)
  #define MICROPY_HW_FMC_D15	  (pin_D10)

  #define MICROPY_HW_FMC_NO	    (pin_D4)
  #define MICROPY_HW_FMC_NW	    (pin_D5)
  #define MICROPY_HW_FMC_NE1	  (pin_D7)

  #define MICROPY_HW_WIZCHIP_RST	(pin_C8)
  #define MICROPY_HW_WIZCHIP_INT 	(pin_C9)
```
------

<a name="wiznet5k-library"></a>

# Wiznet5K Library

<a name="deploying-firmware-to-the-device"></a>

## Deploying firmware to the device
If you want to use the firmware without build, you can use the below firmware.
 - Latest Releases : [** Release 1.0**][link-fw_release_1]

For this, we will use STM32CubeProgrammer(choose STM32CubePrg-W64 for Windows(64Bits)).

(1) Click 'OpenFile'tap(or click '+' tap, select 'open file') and Open the "xxx.hex" a file in STM32CubeProgrammer and (2) connect the Nucleo board to the computer. On the software, click connect (3) then download. If you encounter an error while connecting, try reconnecting the cable or changing the USB port.
  ![][link-cube-programmer]

Open a serial terminal. Choose the serial port corresponding to your STM32 board with a speed of 115200.
 You should then see a similar message after pressing the black RESET button.
  ![][link-build_complete]

---

<a name="building"></a>

## Building
If you need to compile the micropython, your pc should be use Linux or Unix environment.

<details>
<summary>  How To Build on Linux </summary>

0. Set up Linux
From the Linux desktop, open a terminal by doing Right click, then “Open a terminal here”. Then enter the following commands, one by one, to install the required software.

```cpp

  sudo apt-get install git
  sudo apt-get install make
  sudo apt-get install gcc
  sudo apt-get install gcc-arm-none-eabi

```
Enter your password when prompted. Press the “y” (or “o” if the language is french) key to accept the installation when prompted. Once the pre-requisite software is installed, it is necessary to retrieve the MicroPython project from the Git tool by writing to a terminal the following commands (open from a folder where the MicroPython utility will be placed)

1. Download Code
If the ethernet examples are cloned, the library set as a submodule is an empty directory. Therefore, if you want to download the library set as a submodule together, clone the ethernet examples with the following Git command.

```cpp
/* make directory */
// make the new directory for clone
mkdir [user directory]
cd [user directory]

/* Clone */
git clone https://github.com/Wiznet/W5300-TOE-MicroPython.git

```

2. compile

```cpp
cd W5300-TOE-MicroPython/libraries/mpy-cross
  
make

cd ../ports/stm32

```
You can now perform the following command:

```cpp
make BOARD={your-board-model} MICROPY_PY_WIZNET5K=5300
```
It is necessary to replace {your-board-model} with the name of the STM32 board that is being used. For example, if you are using a NUCLEO F429ZI, you will need to write the command:

```cpp
make BOARD=NUCLEO_F429ZI MICROPY_PY_WIZNET5K=5300
```

The previous commands have generated a folder called build-{your– board–model} available in /micropython/ports/stm32 (the micropython folder is located in the folder in which you opened the terminal).

Open the file explorer to retrieve this folder. It contains a file with an extension .hex, that’s the MicroPython engine that we will be flashing in the STM32.

3. Deploying firmware to the device

For this, we will use STM32CubeProgrammer(choose STM32CubePrg-Lin for Linux).
Open a terminal and enter the following commands:

```cpp
sudo apt-get install libusb-1.0.0-dev
```

(1) Click 'OpenFile'tap(or click '+' tap, select 'open file') and Open the "xxx.hex" a file in STM32CubeProgrammer and (2) connect the Nucleo board to the computer. On the software, click connect (3) then download. If you encounter an error while connecting, try reconnecting the cable or changing the USB port.
 - ![][link-cube-programmer]

Open a serial terminal. Choose the serial port corresponding to your STM32 board with a speed of 115200.
 You should then see a similar message after pressing the black RESET button.
 - ![][link-build_complete]

</details>

---

<a name="thonny"></a>

# Thonny

<details>
<summary>  How To Use Thonny   </summary>

- The drive is already installed. 
- You can connect to device, if you click on ‘Configure interpreter …’.

![][link-setup_1]

- The interpreter settings will open. choose the code option and Port **Interpreter**. and click OK

![][link-setup_2]

- click Stop butten in thonny or press reset butten on your device. You should see something like this:

![][link-setup_3]

</details>


--- 
<a name="sample-code"></a>

# Sample code

The following samples can be easily run on the board, then cut-and-pasting the sample code into the Thonny Tool, then executing the code with **Ctrl-D** and **F5**.

1. This **ping** test is to check the network environment using static ip and wiznet chip.
> This is the code to set the IP of 192.168.1.20
>
> I hope that the PC also has an environment that communicates with 192.168.1.xxx.


```python
from machine import Pin,SPI
import network
import time

led = Pin(25, Pin.OUT)

#W5x00 chip init
def w5x00_init():
    nic = network.WIZNET5K()
    nic.active(True)
    nic.ifconfig(('192.168.1.20','255.255.255.0','192.168.1.1','8.8.8.8'))
    
    time.sleep(1)
    print(nic.ifconfig())
        
def main():
    w5x00_init()
    
    while True:

if __name__ == "__main__":
    main()
```

2. Press the `Win+R` key to enter cmd and press Enter or OK to execute the **command prompt**.

![][link-ping_1]

3. When the command prompt window appears, type the **ping command** and press Enter.

```
ping 192.168.1.20 (-option)
```

![][link-ping_2]

4. Ping tests begin as packets are exchanged between hosts. If you look at the time and loss rate among the statistical results, you can find out the status of the Internet network. 

![][link-ping_3]


<a name="ethernet_example_structure"></a>

# Ethernet example structure

Ethernet examples are available at [examples](https://github.com/Wiznet/W5300-TOE-MicroPython/blob/main/example)directory. As of now, following examples are provided.
- [**LIB**][link-lib]

- [**DHCP**][link-DHCP]
- [**Loopback**][link-Loopback]
  - [**Loopback_Server**][link-Loopback_Server]
  - [**Loopback_Client**][link-Loopback_Client]
- [**HTTP**][link-HTTP]
  - [**WebServer**][link-HTTP_Server]
  - [**WebClient**][link-HTTP_Client]
- [**MQTT**][link-MQTT]
  - [**Publish**][link-MQTT_Pub]
  - [**Subscribe**][link-MQTT_Sub]



Please refer to 'README.md' in each examples directory to find detail guide for testing ethernet examples.


------

<a name="Documentation"></a>

# Documentation

Documentation for WIZnet W5300 and Micropython
## STM32
 - [**Linux Quick Start Guide**](https://stm32python.gitlab.io/en/docs/Micropython/install_linux/)
   
   C/C++ development with Nucleo-F429ZI and other STM32 microcontroller boards

## MicroPython Ethernet W5x00
 - [**Wiznet5K library**](https://docs.micropython.org/en/latest/library/network.WIZNET5K.html)
 
## WIZnet Ethernet W5300
 - [**W5300 Product Page**](https://docs.wiznet.io/Product/iEthernet/W5300)
 - [**W5300 Data Sheet**](https://docs.wiznet.io/img/products/w5300/W5300_DS_V134E.pdf)







<!--

Link

-->

[link-w5300]:https://docs.wiznet.io/Product/iEthernet/W5300
[link-suppoted_stm]:https://micropython.org/stm32/
[link-stm_pinmap]:https://github.com/Wiznet/W5300-TOE-MicroPython/blob/main/static/images/stm_pimmap.png

[link-thonny]:https://thonny.org/
[link-STM32CubeProgrammer]:https://www.st.com/en/development-tools/stm32cubeprog.html

[link-fw_release_1]: https://github.com/Wiznet/W5300-TOE-MicroPython/releases
[link-cube-programmer]:https://github.com/Wiznet/W5300-TOE-MicroPython/blob/main/static/images/cube-programmer.png
[link-build_complete]:https://github.com/Wiznet/W5300-TOE-MicroPython/blob/main/static/images/build_complete.png


[link-setup_1]: https://github.com/Wiznet/W5300-TOE-MicroPython/blob/main/static/images/thonny-setup_1.png
[link-setup_2]: https://github.com/Wiznet/W5300-TOE-MicroPython/blob/main/static/images/thonny-setup_2.png
[link-setup_3]: https://github.com/Wiznet/W5300-TOE-MicroPython/blob/main/static/images/thonny-setup_3.png

[link-ping_1]:https://github.com/Wiznet/W5300-TOE-MicroPython/blob/main/static/images/test_ping1.png
[link-ping_2]:https://github.com/Wiznet/W5300-TOE-MicroPython/blob/main/static/images/test_ping2.png
[link-ping_3]:https://github.com/Wiznet/W5300-TOE-MicroPython/blob/main/static/images/test_ping3.png

[link-lib]:https://github.com/Wiznet/W5300-TOE-MicroPython/blob/main/example/lib
[link-Loopback]:https://github.com/Wiznet/W5300-TOE-MicroPython/blob/main/example/Loopback
[link-Loopback_Server]:https://github.com/Wiznet/W5300-TOE-MicroPython/blob/main/example/Loopback/server
[link-Loopback_Client]:https://github.com/Wiznet/W5300-TOE-MicroPython/blob/main/example/Loopback/client
[link-DHCP]:https://github.com/Wiznet/W5300-TOE-MicroPython/blob/main/example/DHCP
[link-HTTP]:https://github.com/Wiznet/W5300-TOE-MicroPython/blob/main/example/HTTP
[link-HTTP_Server]:https://github.com/Wiznet/W5300-TOE-MicroPython/blob/main/example/HTTP/server
[link-HTTP_Client]:https://github.com/Wiznet/W5300-TOE-MicroPython/blob/main/example/HTTP/client
[link-MQTT]:https://github.com/Wiznet/W5300-TOE-MicroPython/blob/main/example/MQTT
[link-MQTT_Pub]:https://github.com/Wiznet/W5300-TOE-MicroPython/blob/main/example/MQTT/Publish
[link-MQTT_Sub]:https://github.com/Wiznet/W5300-TOE-MicroPython/blob/main/example/MQTT/Subscribe



