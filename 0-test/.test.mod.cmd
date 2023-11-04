cmd_/home/abdallah/Device_Drivers/0-test/test.mod := printf '%s\n'   test.o | awk '!x[$$0]++ { print("/home/abdallah/Device_Drivers/0-test/"$$0) }' > /home/abdallah/Device_Drivers/0-test/test.mod
