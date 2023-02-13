# How to WebServer Example

![][link-http]


## Step 1: Prepare Software

> The following serial terminal program is required for **Webserver** test, download and install from below links.

### &#10004;[**Thonny**][link-thonny]




## Step 2: Prepare hardware

1. Combine WIZnet W5300-TOE Ethernet Shield and NUCLEO-F429ZI STM Board
2. Connect ethernet cable to W5300-TOE ethernet port.
3. Connect NUCLEO-F429ZI to desktop or laptop using 5 pin micro USB cable.


## Step 3: Setup Webserver Example

To test the **Webserver example**, minor settings shall be done in code.

1. Check COMport in [‘Configure interpreter …] and then open **Thonny** Python IDE.

![][link-thonny_setup]

2. Initialize ethernet interface and configuration.
Open the example code to set **[Network Information]** 
> nic.ifconfig(('IP Address', 'Netmask', 'Gateway', 'DNS'))

```python

from wiznet_conf import wiznet5k_w5300
		...

def main():
    w5300=wiznet5k_w5300()
    w5300.w5300_set_ip('192.168.11.104','255.255.255.0','192.168.11.1','8.8.8.8')
    ...

```
3. HTML request

```python
html = """
    <!DOCTYPE html>
    <html lang="en">
    <head>
    <meta charset="UTF-8">
    <meta http-equiv="X-UA-Compatible" content="IE=edge">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Raspberry Pi Pico Web server - WIZnet W5100S</title>
    </head>
    <body>
    <div align="center">
    <H1>Raspberry Pi Pico Web server & WIZnet Ethernet HAT</H1>
    <h2>Control LED</h2>
    PICO LED state: <strong>""" + led_state + """</strong>
    <p><a href="/?led=on"><button class="button">ON</button></a><br>
    </p>
    <p><a href="/?led=off"><button class="button button2">OFF</button></a><br>
    </p>
    </div>
    </body>
    </html>
    """
```

4. Run Pico to open the web server.

```python
while True:
        conn, addr = s.accept()
        print('Connect from %s' % str(addr))
        request = conn.recv(1024)
        request = str(request)
        #print('Content = %s' % request)
        led_on = request.find('/?led=on')
        led_off = request.find('/?led=off')
        if led_on == 6:
            print("LED ON")
            led.value(1)
        if led_off == 6:
            print("LED OFF")
            led.value(0)
        response = web_page()
        conn.send('HTTP/1.1 200 OK\n')
        conn.send('Connection: close\n\n')
        conn.send(response)
        conn.close()
```



## Step 4: Upload and Run

1. When you execute the code, you open Websever and wait.

![][link-webserver_1]

2. If you open the HTML web page and enter 192.168.1.20 and you will see the server connected

![][link-webserver_2]



<!--
Link
-->

[link-thonny]: https://thonny.org/
[link-http]: https://github.com/Wiznet/RP2040-HAT-MicroPython/blob/main/static/images/HTTP/HTTP.png

[link-thonny_setup]: https://github.com/Wiznet/W5300-TOE-MicroPython/blob/main/static/images/thonny-setup_example.png

[link-webserver_1]: https://github.com/Wiznet/W5300-TOE-MicroPython/blob/main/static/images/HTTP/webserver_1.png
[link-webserver_2]: https://github.com/Wiznet/W5300-TOE-MicroPython/blob/main/static/images/HTTP/webserver_2.png

