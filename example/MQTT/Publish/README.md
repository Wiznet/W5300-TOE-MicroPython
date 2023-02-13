# How to Test MQTT Publish Example

![][link-mqtt]

## Step 1: Prepare Software

> The following serial terminal program is required for **MQTT Publish** test, download and install from below links.

### &#10004;[**Thonny**][link-thonny]  or  &#10004; [**Mosquitto**][link-mosquitto]


## Step 2: Prepare hardware

1. Combine WIZnet W5300-TOE Ethernet Shield and NUCLEO-F429ZI STM Board
2. Connect ethernet cable to W5300-TOE ethernet port.
3. Connect NUCLEO-F429ZI to desktop or laptop using 5 pin micro USB cable.


## Step 3: Setup MQTT Publish Example

To test the **MQTT Publish example**, minor settings shall be done in code.

1. Check COMport in [‘Configure interpreter …] and then open **Thonny** Python IDE.

![][link-thonny_setup]

2. Create a new file by pressing the **New File** button. Copy the *umqttsimple* library code into it. You can access the *umqttsimple* library code in the following link:
> https://github.com/micropython/micropython-lib/blob/master/micropython/umqtt.simple/umqtt/simple.py

If [umqttsimple.py], which is officially open on MicroPython, does not work, use the code in the link below
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
topic_pub = b'hello'
topic_msg = b'Hello Wiznet'

last_message = 0
message_interval = 5
counter = 0

def mqtt_connect():
    client = MQTTClient(client_id, mqtt_server, keepalive=60)
    client.connect()
    print('Connected to %s MQTT Broker'%(mqtt_server))
    return client
```

5. going to use MQTT Publish.

```python
#MQTT Publish
def main():

    try:
        client = mqtt_connect()
    except OSError as e:
        reconnect()
    
    while True:
        client.publish(topic_pub, topic_msg)
        time.sleep(3)
        
    client.disconnect()
```



## Step 4: Upload and Run

1. Create broker using mosquitto by executing the following command. If the broker is created normally, the broker's IP address is the current IP of your desktop or laptop, and the port is 1883 by default.

```
mosquitto -c mosquitto.conf -p 1883 -v
```

![][link-mqtt_1]

2. If the MQTT publish example works normally on NUCLEO-F429ZI with W5300-TOE, you can see the network information of W5300-TOE, connecting to the broker and publishing the message.

![][link-mqtt_2]

3. Subscribe to the broker with the above command. Subscribe will receive a message from the broker.

```
mosquitto_sub -h 192.168.1.11 -t hello
```

![][link-mqtt_3]



## Appendix

- In Mosquitto versions earlier than 2.0 the default is to allow clients to connect without authentication. In 2.0 and up, you must choose your authentication options explicitly before clients can connect. Therefore, if you are using version 2.0 or later, refer to following link to setup 'mosquitto.conf' in the directory where Mosquitto is installed.

    - [**Authentication Methods**][link-authentication_methods]
    ![][link-mqtt_conf]


<!--
Link
-->

[link-thonny]: https://thonny.org/
[link-mosquitto]: https://mosquitto.org/download/
[link-thonny_setup]: https://github.com/Wiznet/W5300-TOE-MicroPython/blob/main/static/images/thonny-setup_example.png

[link-mqtt]:https://github.com/Wiznet/W5300-TOE-MicroPython/blob/main/static/images/MQTT/MQTT.png
[link-mqtt_1]: https://github.com/Wiznet/W5300-TOE-MicroPython/blob/main/static/images/MQTT/MQTT_pub1.png
[link-mqtt_2]: https://github.com/Wiznet/W5300-TOE-MicroPython/blob/main/static/images/MQTT/MQTT_pub2.png
[link-mqtt_3]:  https://github.com/Wiznet/W5300-TOE-MicroPython/blob/main/static/images/MQTT/MQTT_pub3.png

[link-mqtt_conf]: https://github.com/Wiznet/W5300-TOE-MicroPython/blob/main/static/images/MQTT/MQTT_conf.png

[link-authentication_methods]: https://mosquitto.org/documentation/authentication-methods/

