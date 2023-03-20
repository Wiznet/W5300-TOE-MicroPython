import uiperf3
from wiznet_conf import wiznet5k_w5300
from usocket import socket


w5300=wiznet5k_w5300()
w5300.w5300_set_ip('192.168.11.104','255.255.255.0','192.168.11.1','8.8.8.8')

uiperf3.client('192.168.11.100')


