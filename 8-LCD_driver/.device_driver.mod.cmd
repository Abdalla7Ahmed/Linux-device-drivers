cmd_/home/abdallah/Device_Drivers/8-LCD_driver/device_driver.mod := printf '%s\n'   device_driver.o | awk '!x[$$0]++ { print("/home/abdallah/Device_Drivers/8-LCD_driver/"$$0) }' > /home/abdallah/Device_Drivers/8-LCD_driver/device_driver.mod