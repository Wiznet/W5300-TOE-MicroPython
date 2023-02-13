from umqttsimple import MQTTClient
from wiznet_conf import wiznet5k_w5300
from usocket import socket
import ustruct as struct
from ubinascii import hexlify
import time
#mqtt config
mqtt_server = '192.168.11.100'
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

#reconnect & reset
def reconnect():
    print('Failed to connected to MQTT Broker. Reconnecting...')
    time.sleep(5)
    machine.reset()
    
def main():
    w5300=wiznet5k_w5300()
    w5300.w5300_set_ip('192.168.11.104','255.255.255.0','192.168.11.1','8.8.8.8')
    
    try:
        client = mqtt_connect()
    except OSError as e:
        reconnect()
    
    while True:
        client.publish(topic_pub, topic_msg)
        time.sleep(3)
        
    client.disconnect()

if __name__ == "__main__":
    main()


