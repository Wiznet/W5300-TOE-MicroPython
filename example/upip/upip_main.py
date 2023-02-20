import os
import upip
import ussl
from wiznet_conf import wiznet5k_w5300
from usocket import socket

INSTALL_PATH ='/flash'
INSTALL_LIB_MQTT ="micropython-umqtt.simple"
INSTALL_LIB_UIPERF3 ="uiperf3"
INSTALL_LIB_UREQUEST ="micropython-urequests"

w5300=wiznet5k_w5300()
w5300.w5300_set_ip('192.168.11.104','255.255.255.0','192.168.11.1','8.8.8.8')

print("---------- flash direcoty ----------")
os.listdir(INSTALL_PATH)
print("------------------------------------")
upip.install(INSTALL_LIB_MQTT, INSTALL_PATH)

os.listdir(INSTALL_PATH)


