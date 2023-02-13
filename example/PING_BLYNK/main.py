# main.py -- put your code here!
import network
import wiznet_conf as wizchip
import pyb

board_led1 = pyb.LED(1)


def main():
    wizchip.w5300_init()
    pyb.delay(10)
    
    while True:
        board_led1.toggle()
        pyb.delay(100)
if __name__ == "__main__":
    main()