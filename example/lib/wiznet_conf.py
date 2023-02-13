import network

"""
    A class to configuration the W5300
"""
class wiznet5k_w5300:

    def __init__ (self):      
        self.nic = network.WIZNET5K() 
        self.nic.active(True)

    def w5300_set_ip (self, ip_addr, gw_addr, netmask, dns_svr):
        self.nic.ifconfig((ip_addr, gw_addr, netmask, dns_svr))
        print("device STATIC IP is:", self.nic.ifconfig())
        
    def w5300_set_dhcp (self):
        self.nic.ifconfig('dhcp')
        print("device DHCP IP is:", self.nic.ifconfig())
