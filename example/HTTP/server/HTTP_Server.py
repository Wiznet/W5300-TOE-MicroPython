from usocket import socket
from wiznet_conf import wiznet5k_w5300
import time
import pyb      
    
def web_page():
    global led_togle
    led_togle = 0
    
    if led_togle==1:
        led_state="OFF"
        led_togle=0
    else:
        led_state="ON"
        led_togle=1
        
        
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
    return html

def main():
    led= pyb.LED(1)
    
    w5300=wiznet5k_w5300()
    w5300.w5300_set_ip('192.168.11.104','255.255.255.0','192.168.11.1','8.8.8.8')
    
    s = socket()
    s.bind(('192.168.1.20', 80))
    s.listen(5)

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
            led.on()
        if led_off == 6:
            print("LED OFF")
            led.off()
        response = web_page()
        conn.send('HTTP/1.1 200 OK\n')
        conn.send('Connection: close\n')
        conn.send('Content-Type: text/html\n')
        conn.send('Content-Length: %s\n\n' % len(response))
        conn.send(response)
        conn.close()

if __name__ == "__main__":
    main()
