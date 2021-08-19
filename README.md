# Synapse RTU-DI8 Tool

Dependancies :

```# apt-get install libmodbus5 libmodbus-dev```

Compile as below or use 'make all' 

```# gcc rtu-di8.c -o rtu-di8 -lmodbus```


Sample syntax 

```
Synapse RTU-DI8 Reader - v1.0

./rtu-di8 [-h|j|c] [-a] [-b] [-p] [-1] [-2] [-3] [-4] [-5] [-6] [-7] [-8] [-r] [-t] [-y] [-l] [-v] [-m] [-w] [-d]

Syntax :

-h = Human readable output (default)
-j = JSON readable output
-c = Comma delimited minimal output

-a = Set Modbus device address (1-255)  default=1
-b = Set serial baud rate (9600/14400/19200/38400/57600)  default=19200
-p = Set serial interface to use e.g. /dev/ttyS0  default=/dev/ttyUSB0

-1 = Set Channel 1 mode register (1=Logic Level|2=Pulse Counter|3=PWM Measurement) - default=Logic Level
-2 = Set Channel 2 mode register (1=Logic Level|2=Pulse Counter|3=PWM Measurement) - default=Logic Level
-3 = Set Channel 3 mode register (1=Logic Level|2=Pulse Counter|3=PWM Measurement) - default=Logic Level
-4 = Set Channel 4 mode register (1=Logic Level|2=Pulse Counter|3=PWM Measurement) - default=Logic Level
-5 = Set Channel 5 mode register (1=Logic Level|2=Pulse Counter|3=PWM Measurement) - default=Logic Level
-6 = Set Channel 6 mode register (1=Logic Level|2=Pulse Counter|3=PWM Measurement) - default=Logic Level
-7 = Set Channel 7 mode register (1=Logic Level|2=Pulse Counter|3=PWM Measurement) - default=Logic Level
-8 = Set Channel 8 mode register (1=Logic Level|2=Pulse Counter|3=PWM Measurement) - default=Logic Level

-l = Set ms value for pulse count de-bounce setting register (1-1000)              - default=10ms
-v = Select number of readings for PWM averaging (1=4|2=8)                         - default=8 readings
-m = Set value for RTU Baud Rate register (1=9600/2=14400/3=19200/4=38400/5=57600)

-r = Write pulse count reset value (880-887=CH1-CH8/888=All Channels)
-t = Set channel to write offset value to (1-8)
-y = Set offset value to write (1-4294967294)

-s = show Good/Dead status of PWM input channels

-w = Confirm writing configured setting registers to RTU NVRAM

-d = debug mode

Examples :
Read RTU, address 12, Baud 38400, output in JSON format         :  ./rtu-di8 -j -a 12 -b 38400 -p /dev/ttyS0
Reconfigure RTU channel 1 into PWM measurement mode             :  ./rtu-di8 -a 3 -1 3 -p /dev/ttyS0 -w


```
