# How to Test MQTT Subscribe Example

![][link-mqtt]

## Step 1: Prepare Software

> The following serial terminal program is required for **MQTT subscribe** test, download and install from below links.

### &#10004;[**Thonny**][link-thonny]  or  &#10004; [**Mosquitto**][link-mosquitto]



## Step 2: Prepare hardware

1. Combine WIZnet W5300-TOE Ethernet Shield and NUCLEO-F429ZI STM Board
2. Connect ethernet cable to W5300-TOE ethernet port.
3. Connect NUCLEO-F429ZI to desktop or laptop using 5 pin micro USB cable.

## Step 3: Setup MQTT Subscribe Example

To test the **MQTT Subscribe example**, minor settings shall be done in code.

1. Check COMport in [‘Configure interpreter …] and then open **Thonny** Python IDE.

![][link-thonny_setup]

2. Create a new file by pressing the **New File** button. Copy the ***urequest.py*** library code into it. You can access the *urequest* library code in the following link.
>  https://github.com/micropython/micropython-lib/blob/master/micropython/umqtt.simple/umqtt/simple.py

 If **[umqttsimple.py]**, which is officially open on MicroPython, does not work, **use the code in lib direcroty.** 
> https://github.com/Wiznet/W5300-TOE-MicroPython/blob/main/example/lib/umqttsimple.py

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

4. In the MQTT configuration, the broker IP address is the IP of your desktop.

```python
#mqtt config
mqtt_server = '192.168.1.11'
client_id = 'wiz'
topic_sub = b'hello'

last_message = 0
message_interval = 5
counter = 0

#MQTT connect
def mqtt_connect():
    client = MQTTClient(client_id, mqtt_server, keepalive=60)
    client.set_callback(sub_cb)
    client.connect()
    print('Connected to %s MQTT Broker'%(mqtt_server))
    return client
```

5. going to use MQTT Subscribe.

```python
#subscribe
def main():

    try: 
        client = mqtt_connect()
    except OSError as e:
        reconnect()

    while True:
        client.subscribe(topic_sub)
        time.sleep(1)

    client.disconnect()
```



## Step 4: Upload and Run

1. Create broker using mosquitto by executing the following command. If the broker is created normally, the broker's IP address is the current IP of your desktop or laptop, and the port is 1883 by default.

```
mosquitto -c mosquitto.conf -p 1883 -v
```

![][link-mqtt_1]

2. If the MQTT publish example works normally on Raspberry Pi Pico, you can see the network information of Raspberry Pi Pico, connecting to the broker and publishing the message.

![][link-mqtt_2]

3. Subscribe to the broker with the above command. Subscribe will receive a message from the broker.

```
mosquitto_pub -h 192.168.1.20 -t hello -m "Hello Pico"
```

![][link-mqtt_3]



## Appendix

- In Mosquitto versions earlier than 2.0 the default is to allow clients to connect without authentication. In 2.0 and up, you must choose your authentication options explicitly before clients can connect. Therefore, if you are using version 2.0 or later, refer to following link to setup 'mosquitto.conf' in the directory where Mosquitto is installed.

    - [**Authentication Methods**][link-authentication_methods]

![][link-mqtt_conf]

- The following error might occur while running the MQTT_sub example: Disabling the "**setblocking**" function on the **180 line of mqttsimple.py** will work fine.

![][link-setblocking]



<!--
Link
-->

[link-thonny]: https://thonny.org/
[link-mosquitto]: https://mosquitto.org/download/
[link-thonny_setup]: https://github.com/Wiznet/W5300-TOE-MicroPython/blob/main/static/images/thonny-setup_example.png

[link-authentication_methods]: https://mosquitto.org/documentation/authentication-methods/

[link-mqtt]:https://github.com/Wiznet/W5300-TOE-MicroPython/blob/main/static/images/MQTT/MQTT.png

[link-mqtt_1]:https://github.com/Wiznet/W5300-TOE-MicroPython/blob/main/static/images/MQTT/MQTT_pub1.png
[link-mqtt_2]:https://github.com/Wiznet/W5300-TOE-MicroPython/blob/main/static/images/MQTT/MQTT_sub_2.png
[link-mqtt_3]:https://github.com/Wiznet/W5300-TOE-MicroPython/blob/main/static/images/MQTT/MQTT_sub_3.png

[link-mqtt_conf]: https://github.com/Wiznet/W5300-TOE-MicroPython/blob/main/static/images/MQTT/MQTT_conf.png
[link-setblocking]:https://github.com/Wiznet/W5300-TOE-MicroPython/blob/main/static/images/MQTT/setblocking.png
