## Quick micropython Code

```python
from wiznet_conf import wiznet5k_w5300

def main():
    w5300=wiznet5k_w5300()
    w5300.w5300_set_dhcp()
    	...

```

you can see that you are DHCP IP 
<p align="center"><img src="https://github.com/Wiznet/W5300-TOE-MicroPython/blob/main/static/images/DHCP/dhcp_init.png"></p>
