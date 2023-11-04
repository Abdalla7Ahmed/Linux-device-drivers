fd=open("/dev/test_device_file",'w')
s=input("please enter the data ")
fd.write(s)
fd.close()

fd=open("/dev/test_device_file",'r')
print(fd.readline())
fd.close()