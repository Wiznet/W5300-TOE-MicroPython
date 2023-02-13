# How to WebClient Example

![][link-http]


## Step 1: Prepare Software

> The following serial terminal program is required for **Webclient** test, download and install from below links.

### &#10004;[**Thonny**][link-thonny]


## Step 2: Prepare hardware

1. Combine WIZnet W5300-TOE Ethernet Shield and NUCLEO-F429ZI STM Board
2. Connect ethernet cable to W5300-TOE ethernet port.
3. Connect NUCLEO-F429ZI to desktop or laptop using 5 pin micro USB cable.


## Step 3: Setup WebClinet Example

To test the **Webclient example**, minor settings shall be done in code.

1. Check COMport in [‘Configure interpreter …] and then open **Thonny** Python IDE.

![][link-thonny_setup]

2. Create a new file by pressing the **New File** button. Copy the ***urequest.py*** library code into it. You can access the *urequest* library code in the following link.
> https://github.com/micropython/micropython-lib/blob/master/python-ecosys/urequests/urequests.py

 If **[urequests.py]**, which is officially open on MicroPython, does not work, **use the code in lib direcroty.** 
> https://github.com/Wiznet/W5300-TOE-MicroPython/blob/main/example/lib/urequests.py

3. Initialize ethernet interface and configuration.
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

4. HTML request, Access **HTML**.

```python
def request():
    #get
    r = urequest.get("http://httpbin.org/get")
    print(r.status_code)
    print(r.text)
    
    #post
    r = urequest.post("http://httpbin.org/post", json={'Hello': 'WIZnet'})
    print(r.json())
```



## Step 4: Upload and Run

1. Use DNS to access the address of the server. After that, it accesses the server in each URL and prints the contents. The text of each URL is as follows.

![][link-webclient_1]

2. Text content in **HTML**.

![][link-webclient_2]

3. HTTP_Client **Get**, **Post** result

![][link-webclient_3]






<!--
Link
-->

[link-thonny]: https://thonny.org/

[link-http]: https://github.com/Wiznet/W5300-TOE-MicroPython/blob/main/static/images/HTTP/HTTP.png
[link-thonny_setup]: https://github.com/Wiznet/W5300-TOE-MicroPython/blob/main/static/images/thonny-setup_example.png

[link-webclient_1]: https://github.com/Wiznet/W5300-TOE-MicroPython/blob/main/static/images/HTTP/webclient_1.png
[link-webclient_2]: https://github.com/Wiznet/W5300-TOE-MicroPython/blob/main/static/images/HTTP/webclient_2.png
[link-webclient_3]: https://github.com/Wiznet/W5300-TOE-MicroPython/blob/main/static/images/HTTP/webclient_3.png

