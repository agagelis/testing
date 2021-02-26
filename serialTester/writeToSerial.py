import time
import serial
ser = serial.Serial('COM3')  # open serial port
ser.baudrate = 115200
print(ser.name)         # check which port was really used
##while True:
#ser.write(b'hello')     # write a string


i =0
while True:
    text = "hello "+ str(i)    
    time.sleep(1)
    ser.write(text.encode())
    print("Send : "+"hello") 
    i+=1
ser.close()