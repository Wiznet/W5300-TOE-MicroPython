from wiznet_conf import wiznet5k_w5300

def main():
    w5300=wiznet5k_w5300()
    w5300.w5300_set_dhcp()
    print("----------- done ------------")
    
if __name__ == "__main__":
    main()