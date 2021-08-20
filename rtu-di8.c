/*
        The MIT License (MIT)

        Copyright (c) 2021 Andrew O'Connell

        Permission is hereby granted, free of charge, to any person obtaining a copy
        of this software and associated documentation files (the "Software"), to deal
        in the Software without restriction, including without limitation the rights
        to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
        copies of the Software, and to permit persons to whom the Software is
        furnished to do so, subject to the following conditions:

        The above copyright notice and this permission notice shall be included in all
        copies or substantial portions of the Software.

        THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
        IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
        FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
        AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
        LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
        OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
        SOFTWARE.

        Dependancies :

        apt-get install libmodbus5 libmodbus-dev

        Compile as below or use 'make all' to allow program to use external system (.so) libraries
        gcc rtu-di8.c -o rtu-di8 -lmodbus 


*/

// System includes
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <errno.h>

// External Libs
#include <modbus/modbus.h> //LGPL 2.1

// Types & Variables
#include "Types.h"

// RTU Module Definitions
#include "digin.c"

// Functions
#include "config.c"
#include "modbus.c"
#include "rtudecode.c"

int main(int argc, char *argv[])
{

	int deviceId = 1;			 // there's only one device in the demo setup
	int displayType = HUMANREAD; // default
	int opt;
	int debugMode = 0;
	int configWrite = 0;
	int chanModeSetting[9] = {0};
	int modbusBaudSetting = 0;
	int pwmAverageSetting = 0;
	int debouncePeriod = 0;
	int resetValue=0;
	int chanNo=0;
	int chanOffset=-1;
	int showPWMstatus = 0;
	int resetMinValues = 0;
	int resetMaxValues = 0;
	int pwmCycleTime = 0;

	// Load Config, this is
	readConfig();

	// Command line options
	//
	// For reference see : https://azrael.digipen.edu/~mmead/www/Courses/CS180/getopt.html
	//
	// The colon after the letter tells getopt to expect an argument after the option
	// To disable the automatic error printing, put a colon as the first character
	while ((opt = getopt(argc, argv, ":hjcda:b:p:r:t:y:szxu:1:2:3:4:5:6:7:8:v:l:m:w")) != -1)
	{
		switch (opt)
		{
		case 'h': // Human Readable output
			displayType = HUMANREAD;
			break;
		case 'j': // JSON output
			displayType = JSONREAD;
			break;
		case 'c': // comma seperated output
			displayType = CPUREAD;
			break;
		case 'd': // Print Config
			debugMode = 1;
			break;
		case 'a': // Set modbus address for read
			if (atoi(optarg) > 0 && atoi(optarg) < 255)
			{
				dataSource[deviceId].modbusId = atoi(optarg);
			}
			break;
		case 'b': // Set baudrate for read
			if (atoi(optarg) == 9600 || atoi(optarg) == 14400 || atoi(optarg) == 19200 || atoi(optarg) == 38400 || atoi(optarg) == 57600)
			{
				dataSource[deviceId].baudRate = atoi(optarg);
			}
			break;
		case 'p': // Set serial interface for read
			strcpy(dataSource[deviceId].interface, optarg);
			break;
		case 'w': // Invoke write to RTU NVRAM
			displayType = HUMANREAD;
			configWrite = 1;
			break;
		case 'z': // Reset Min Peak Values 
			displayType = HUMANREAD;
			resetMinValues = 1;
			break;	
		case 'x': // Reset Max Peak Values 
			displayType = HUMANREAD;
			resetMaxValues = 1;
			break;	
		case 'r': // Write Pulse Count Totaliser Reset Value if valid value set
			if (atoi(optarg) > 879 && atoi(optarg) < 889)
			{
				displayType = HUMANREAD;
				resetValue = atoi(optarg);
				break;	
			}			
		case 't': // Channel to write offset value to 
			if (atoi(optarg) > 0 && atoi(optarg) < 9)
			{
				displayType = HUMANREAD;
				chanNo = atoi(optarg);
				break;	
			}				
		case 'y': // Offset value to write
			if (atoi(optarg) >= 0 && atoi(optarg) < 4294967295)
			{
				displayType = HUMANREAD;
				chanOffset = atoi(optarg);
				break;	
			}			
		case 'u': // Write new min PWM cycle time
			if (atoi(optarg) > 99 && atoi(optarg) < 10000)
			{
				displayType = HUMANREAD;
				pwmCycleTime = atoi(optarg);				
			}			
			break;	
		case 's': // show status of PWM channels
				displayType = HUMANREAD;
				showPWMstatus = 1;
				break;	
		case '1': // Configure RTU Channel 1 Mode setting
			if (atoi(optarg) < 4 && atoi(optarg) > 0)
			{
				chanModeSetting[1] = atoi(optarg);
			}
			break;
		case '2': // Configure RTU Channel 2 Mode setting
			if (atoi(optarg) < 4 && atoi(optarg) > 0)
			{
				chanModeSetting[2] = atoi(optarg);
			}
			break;
		case '3': // Configure RTU Channel 3 Mode setting
			if (atoi(optarg) < 4 && atoi(optarg) > 0)
			{
				chanModeSetting[3] = atoi(optarg);
			}
			break;
		case '4': // Configure RTU Channel 4 Mode setting
			if (atoi(optarg) < 4 && atoi(optarg) > 0)
			{
				chanModeSetting[4] = atoi(optarg);
			}
			break;
		case '5': // Configure RTU Channel 5 Mode setting
			if (atoi(optarg) < 4 && atoi(optarg) > 0)
			{
				chanModeSetting[5] = atoi(optarg);
			}
			break;
		case '6': // Configure RTU Channel 6 Mode setting
			if (atoi(optarg) < 4 && atoi(optarg) > 0)
			{
				chanModeSetting[6] = atoi(optarg);
			}
			break;
		case '7': // Configure RTU Channel 7 Mode setting
			if (atoi(optarg) < 4 && atoi(optarg) > 0)
			{
				chanModeSetting[7] = atoi(optarg);
			}
			break;
		case '8': // Configure RTU Channel 8 Mode setting
			if (atoi(optarg) < 4 && atoi(optarg) > 0)
			{
				chanModeSetting[8] = atoi(optarg);
			}
			break;
		case 'l': //
			if (atoi(optarg) < 1000 && atoi(optarg) > 0)
			{
				debouncePeriod = atoi(optarg);
			}
			break;
		case 'v': //
			if (atoi(optarg) < 3 && atoi(optarg) > 0)
			{
				pwmAverageSetting = atoi(optarg);
			}
			break;
		case 'm': // Set value for RTU Baud Rate register  (use in conjunction with -w flag)
			if (atoi(optarg) < 6 && atoi(optarg) > 0)
			{
				modbusBaudSetting = atoi(optarg);
			}
			break;
		case '?':
			printf("Synapse RTU-DI8 Reader - v1.0\n\n");
			printf("%s [-h|j|c] [-a] [-b] [-p] [-1] [-2] [-3] [-4] [-5] [-6] [-7] [-8] \n\r", argv[0]);
			printf("                   [-z] [-x] [-r] [-t] [-y] [-l] [-v] [-m] [-w] [-d]\n\n");
			printf("Syntax :\n\n");
			printf("-h = Human readable output (default)\n");
			printf("-j = JSON readable output\n");
			printf("-c = Comma delimited minimal output\n");
			printf("\n");
			printf("-a = Set Modbus device address (1-255)  default=1 \n");
			printf("-b = Set serial baud rate (9600/14400/19200/38400/57600)  default=19200 \n");
			printf("-p = Set serial interface to use e.g. /dev/ttyS0  default=/dev/ttyUSB0 \n");
			printf("\n");
			printf("-1 = Set Channel 1 mode register (1=Logic Level|2=Pulse Counter|3=PWM Measurement) - default=Logic Level\n");
			printf("-2 = Set Channel 2 mode register (1=Logic Level|2=Pulse Counter|3=PWM Measurement) - default=Logic Level\n");
			printf("-3 = Set Channel 3 mode register (1=Logic Level|2=Pulse Counter|3=PWM Measurement) - default=Logic Level\n");
			printf("-4 = Set Channel 4 mode register (1=Logic Level|2=Pulse Counter|3=PWM Measurement) - default=Logic Level\n");
			printf("-5 = Set Channel 5 mode register (1=Logic Level|2=Pulse Counter|3=PWM Measurement) - default=Logic Level\n");
			printf("-6 = Set Channel 6 mode register (1=Logic Level|2=Pulse Counter|3=PWM Measurement) - default=Logic Level\n");
			printf("-7 = Set Channel 7 mode register (1=Logic Level|2=Pulse Counter|3=PWM Measurement) - default=Logic Level\n");
			printf("-8 = Set Channel 8 mode register (1=Logic Level|2=Pulse Counter|3=PWM Measurement) - default=Logic Level\n");
			printf("\n");
			printf("-l = Set ms value for pulse count de-bounce setting register (1-1000)              - default=10ms\n");
			printf("-v = Select number of readings for PWM averaging (1=4|2=8)                         - default=8 readings\n");			
			printf("-m = Set value for RTU Baud Rate register (1=9600/2=14400/3=19200/4=38400/5=57600)  \n");
			printf("\n");
			printf("-r = Write pulse count reset value (880-887=CH1-CH8/888=All Channels)  \n");
			printf("-t = Set channel to write offset value to (1-8)  \n");
			printf("-y = Set offset value to write (0-4294967294)  \n");			
			printf("\n");
			printf("-z = Reset PWM Min Peak Value reading for all channels \n");
			printf("-x = Reset PWM Max Peak Value reading for all channels \n");
			printf("-u = Set New Minimum PWM cycle time  (100-10000ms)                                 - default=100ms\n");		
			printf("\n");			
			printf("-s = show Good/Dead status of PWM input channels  \n");
			printf("\n");
			printf("-w = Confirm writing configured setting registers to RTU NVRAM\n");
			printf("\n");
			printf("-d = debug mode\n");
			printf("\n");
			printf("Examples :\n");
			printf("Read RTU, address 12, Baud 38400, output in JSON format         :  %s -j -a 12 -b 38400 -p /dev/ttyS0\n", argv[0]);
			printf("Reconfigure RTU channel 1 into PWM measurement mode             :  %s -a 3 -1 3 -p /dev/ttyS0 -w\n", argv[0]);
			printf("\n");
			exit(1);
			break;
		}
	}

	if (displayType == HUMANREAD)
	{
		printf("\nSynapse RTU-DI8 Reader - v1.0\n\n");
	}

	if (showPWMstatus == 1)
	{	
		showPWMchanStatus(deviceId);
		exit(0);
	}

	if (pwmCycleTime >0)
	{	
		setPWMCycleTime(deviceId, pwmCycleTime);
		exit(0);
	}

	// Write
	
	// reset pulse counter totals, either by channel or all channels depending on value written
	if (resetValue >0)
	{
		resetCounter(resetValue, deviceId);
		exit(0);
	}

    // write an offset value for pulse counter channel
	if (chanOffset >-1 && chanNo >0)
	{
		writeoffset(chanNo, chanOffset, deviceId);
		exit(0);
	}

	// reset PWM min peak readings value, takes current reading as new value 
	if (resetMinValues >0)
	{
		resetMinReadings(deviceId);
		exit(0);
	}

	// reset PWM max peak readings value, takes current reading as new value 
	if (resetMaxValues >0)
	{
		resetMaxReadings(deviceId);
		exit(0);
	}

	if (configWrite == 1)
	{
		reconfigureRTU(deviceId, modbusBaudSetting, chanModeSetting, pwmAverageSetting, debouncePeriod);
		exit(0);
	}

	if (debugMode == 1)
	{
		printConfig();
	}

	// Read in Modbus registers
	if (displayType == HUMANREAD)
	{
		printf("Modbus Reads...\n");
	}
	if (getModbusValues() == 0)
	{
		if (displayType == HUMANREAD)
		{
			printf("Modbus reads OK\n\n");
		}
	}
	else
	{
		printf("..Fatal Error : Error Reading Modbus device(s) \n\n");
		exit(1);
	}

	// Print output in desired format
	for (deviceId = 1; deviceId < (config.dsTotal + 1); deviceId++)
	{
		if (displayType == JSONREAD)
		{
			if (deviceId == 1)
				printf("{\n   \"device 1\" : {\n");
			else
				printf("   \"device %i\" : {\n", deviceId);
		}

		displayDigInValues(deviceId, displayType);

		if (displayType == JSONREAD)
		{
			if (deviceId < (config.dsTotal))
				printf("   },\n");
			else
				printf("   }\n}\n", deviceId);
		}
	}
}
