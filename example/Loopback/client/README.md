# How to Test Loopback Client Example

![][link-loopback]

## Step 1: Prepare Software

> The following serial terminal program is required for **Loopback** test, download and install from below links.

### &#10004;[**Thonny**][link-thonny]  and  &#10004; [**ezterm**][link-ezterm]



## Step 2: Prepare hardware

1. Combine WIZnet W5300-TOE Ethernet Shield and NUCLEO-F429ZI STM Board
2. Connect ethernet cable to W5300-TOE ethernet port.
3. Connect NUCLEO-F429ZI to desktop or laptop using 5 pin micro USB cable.


## Step 3: Setup Loopback Example

> To test the **Loopback example**, minor settings shall be done in code.

1. Check COMport in [‘Configure interpreter …] and then open **Thonny** Python IDE.

![][link-thonny-setup]

3. Initialize ethernet interface and configuration. Open the example code to set **[Network Information]**

> nic.ifconfig(('IP Address', 'Netmask', 'Gateway', 'DNS'))

```python

from wiznet_conf import wiznet5k_w5300
		...

def main():
    w5300=wiznet5k_w5300()
    w5300.w5300_set_ip('192.168.11.104','255.255.255.0','192.168.11.1','8.8.8.8')
    ...

```

3. How to operate as a **Loopback Client**.

```python
ef client_loop():
    s = socket()
    s.connect(('192.168.1.11', 5000)) #Destination IP Address
    
    print("Loopback client Connect!")
    while True:
        data = s.recv(2048)
        print(data.decode('utf-8'))
        if data != 'NULL' :
            s.send(data)
```



## Step 4: Upload and Run

# **`Loopback Client Mode`**

1. Open the server in the ezterm program. If you put in the port number and press Listen, the server will open.

![][link-loopback_client_1]

2. When the Client function is retrieved from the loopback source and executed, it connects to the server normally.

![][link-loopback_client_2]

3. If you send the data from the server, you can receive the data you sent.

![][link-loopback_client_3]







<!--
Link
-->

[link-thonny]: https://thonny.org/
[link-ezterm]: https://www.eztcp.com/en/download/ezterm
[link-thonny-setup]:https://github.com/Wiznet/W5300-TOE-MicroPython/blob/main/static/images/thonny-setup_example.png

[link-loopback]: https://github.com/Wiznet/W5300-TOE-MicroPython/blob/main/static/images/LOOPBACK/Loopback.png


[link-loopback_client_1]:https://github.com/Wiznet/W5300-TOE-MicroPython/blob/main/static/images/LOOPBACK/Loopback_client_1.png
[link-loopback_client_2]:https://github.com/Wiznet/W5300-TOE-MicroPython/blob/main/static/images/LOOPBACK/Loopback_client_2.png
[link-loopback_client_3]:https://github.com/Wiznet/W5300-TOE-MicroPython/blob/main/static/images/LOOPBACK/Loopback_client_3.png

