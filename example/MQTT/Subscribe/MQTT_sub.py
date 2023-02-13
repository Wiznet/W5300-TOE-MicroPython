from umqttsimple import MQTTClient
from usocket import socket
from wiznet_conf import wiznet5k_w5300
import network
import time

#mqtt config
mqtt_server = '192.168.11.100'
client_id = 'wiz'
topic_sub = b'hello'

last_message = 0
message_interval = 5
counter = 0

def sub_cb(topic, msg):
    print((topic.decode('utf-8'), msg.decode('utf-8')))

#MQTT connect
def mqtt_connect():
    client = MQTTClient(client_id, mqtt_server, keepalive=60)
    client.set_callback(sub_cb)
    client.connect()
    print('Connected to %s MQTT Broker'%(mqtt_server))
    return client

#reconnect & reset
def reconnect():
    print('Failed to connected to Broker. Reconnecting...')
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
        client.subscribe(topic_sub)
        time.sleep(1)

    client.disconnect()

if __name__ == "__main__":
    main()


