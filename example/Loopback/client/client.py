import network
from usocket import socket
from wiznet_conf import wiznet5k_w5300

def main():
    print("===============Start Loopback client=============")
    w5300=wiznet5k_w5300()
    w5300.w5300_set_ip('192.168.11.104','255.255.255.0','192.168.11.1','8.8.8.8')
      
    s = socket()
    s.connect(('192.168.11.100', 5000)) #Destination IP Address
    print("Loopback client Connect!")
    while True:
        data = s.recv(2048)
        print(data.decode('utf-8'))
        if data != 'NULL' :
            s.send(data)

if __name__ == "__main__":
    main()