# How to Use uiperf3 Example

![][link-http]
This project is designed to measure network performance using uiperf3 client with Wiznet W5300 Ethernet Controller. It runs the uiperf3 client to measure the network performance.

## Step 1: Prepare Software

The following serial terminal program is required for **uIPerf3** test, download and install from below links.

### &#10004;[**Thonny**][link-thonny]
### &#10004;[**iPerf3**][link-iperf3]


## Step 2: Prepare hardware

1. Combine WIZnet W5300-TOE Ethernet Shield and NUCLEO STM Board
2. Connect ethernet cable to W5300-TOE ethernet port.
3. Connect NUCLEO STM Board to desktop or laptop using 5 pin micro USB cable.


## Step 3: Setup uIPerf3 Example

To test the **uIPerf3 example**, minor settings shall be done in code.

1. Check COMport in [‘Configure interpreter …] and then open **Thonny** Python IDE.

![][link-thonny_setup]

2. Create a new file by pressing the **New File** button. Copy the ***uiperf3.py*** library code into it. You can access the *uiperf3* library code in the following link.
> https://github.com/micropython/micropython-lib/blob/master/python-ecosys/iperf3/iperf3.py

 If **[uiperf3.py]**, which is officially open on MicroPython, does not work, **use the code in lib direcroty.** 
> https://github.com/Wiznet/W5300-TOE-MicroPython/blob/main/example/lib/uiperf3.py

3. Import the required packages:

```python
import uiperf3
from wiznet_conf import wiznet5k_w5300
```

4. Initialize the W5300 controller:
Set the IP address, subnet mask, gateway, and DNS server:

```python
w5300 = wiznet5k_w5300()
w5300.w5300_set_ip('192.168.11.104','255.255.255.0','192.168.11.1','8.8.8.8')
```

5. Run the uiperf3 client:
Set the Server IP address. and Get the results.

```python
uiperf3.client('192.168.11.100')

result = client.run()
```

## Step 4: Upload and Run

1. First, run the iperf 3 server. Open a command prompt and enter the following command.
> iperf3.exe -s

![][link-iperf3_server]

2. Afterwards, run the iPerf3 Client from the NUCLEO STM Board with W5300-TOE.

![][link-uiperf3_clinet]




<!--
Link
-->

[link-thonny]: https://thonny.org/
[link-iperf3]: https://iperf.fr/iperf-download.php

[link-thonny_setup]: https://github.com/Wiznet/W5300-TOE-MicroPython/blob/main/static/images/thonny-setup_example.png

[link-iperf3_server]: https://github.com/Wiznet/W5300-TOE-MicroPython/blob/main/static/images/uiPerf3/iperf3_server.png
[link-uiperf3_clinet]: https://github.com/Wiznet/W5300-TOE-MicroPython/blob/main/static/images/uiPerf3/uiperf3_client.png
