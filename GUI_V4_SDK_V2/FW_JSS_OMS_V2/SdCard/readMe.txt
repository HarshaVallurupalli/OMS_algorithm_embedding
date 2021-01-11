Copy the file "BOOT.bin" to the root of the SD card. This is the boot file of the system.


To set the ethernet configuration of the device create a file with the name "ethconfig.cfg" and put it into the folder "TOFCam_660" on the SD card.

This file must contain the following text:

ip=10.10.31.186
subnet=255.255.255.0
mac=10


The ip, subnet and mac values may be changed to the desired values. The mac is just the last byte of the MAC number of the device. This is used as long there is no mac number stored on the device. Be sure not to have two devices with the same ip or mac connected to the same net.