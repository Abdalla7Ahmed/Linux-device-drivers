cmd_/home/abdallah/Device_Drivers/1-Hello_Kernel/hello.mod := printf '%s\n'   hello.o | awk '!x[$$0]++ { print("/home/abdallah/Device_Drivers/1-Hello_Kernel/"$$0) }' > /home/abdallah/Device_Drivers/1-Hello_Kernel/hello.mod