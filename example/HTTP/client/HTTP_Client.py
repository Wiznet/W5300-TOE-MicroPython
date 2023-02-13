from usocket import socket
from wiznet_conf import wiznet5k_w5300
import urequests
import network
import time
    
def request():
    r = urequests.get('http://httpbin.org')
    #r.raise_for_status
    print(r.status_code)
    print(r.text)
    r= urequests.post('http://httpbin.org/post', json={'WIZnet Test'})
    if not r:
        print('spreadsheet: no response received')
    print(r.json())

def main():
    w5300=wiznet5k_w5300()
    w5300.w5300_set_ip('192.168.11.104','255.255.255.0','192.168.11.1','8.8.8.8')
    request()

if __name__ == "__main__":
    main()
