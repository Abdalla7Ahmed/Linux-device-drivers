#!/bin/bash

case $1 in 
make)
make
;;
clean)
make clean
sudo dmesg -c >> /dev/null
;;
insert)
sudo insmod device_driver.ko
sudo chmod 777 /dev/test_device_file
;;
list)
lsmod | head -n 5
;;

remove)
sudo rmmod device_driver
make clean
sudo dmesg -c >> /dev/null
;;
print)
sudo dmesg
;;
test)
sudo rmmod device_driver
make clean
make
sudo dmesg -c >> /dev/null
sudo insmod device_driver.ko
sudo chmod 777 /dev/test_device_file
//echo "hello from user to kernel " > /dev/test_device_file
#cat /dev/test_device_file
sudo dmesg
;;
*)
echo "error parameter passed"
;;
esac