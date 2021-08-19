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
		
*/	

			

void displayDigInValues(int deviceId, int displayType)
{
	int regId;
	const char *chMode[4];
				chMode[0] = "Level";
				chMode[1] = "Level";
				chMode[2] = "Pulse";
				chMode[3] = "PWM";


	// initialise these to zero or else we'll get nonsense readings shown if the chan/register 
	// is not enabled in the config.
	// You could initialise this to NaN or some other recognisable value to indicate "No reading available" 
	int chanLvl[9]={0};      // Values from index position 1 onwards
    int chanCount[9]={0};
    int chanPWM[9]={0};
    int chanPWMAvg[9]={0};
	int chanPWMMax[9]={0};
	int chanPWMMin[9]={0};
	

	for(regId=1 ; regId<(dataSource[deviceId].numRegisters+1) ; regId++)
	{	
		// Deals with chan 1 value registers
		if ( dataSource[deviceId].regAddress[regId] == 1  ) { chanLvl[1]   =dataSource[deviceId].value[regId]; }    // Level
		if ( dataSource[deviceId].regAddress[regId] == 9  ) { chanCount[1] =dataSource[deviceId].value[regId]; }    // Pulse
		if ( dataSource[deviceId].regAddress[regId] == 25 ) { chanPWM[1]   =dataSource[deviceId].value[regId]; }    // PWM
		if ( dataSource[deviceId].regAddress[regId] == 41 ) { chanPWMAvg[1]=dataSource[deviceId].value[regId]; }    // PWM AVG
		if ( dataSource[deviceId].regAddress[regId] == 57 ) { chanPWMMax[1]=dataSource[deviceId].value[regId]; }	  // PWM Max Peek	    
		if ( dataSource[deviceId].regAddress[regId] == 73 ) { chanPWMMin[1]=dataSource[deviceId].value[regId]; }    // PWM Min Peek


		// Deals with chan 2 value registers
		if ( dataSource[deviceId].regAddress[regId] == 2  ) { chanLvl[2]   =dataSource[deviceId].value[regId]; }    // Level
		if ( dataSource[deviceId].regAddress[regId] == 11 ) { chanCount[2] =dataSource[deviceId].value[regId]; }    // Pulse
		if ( dataSource[deviceId].regAddress[regId] == 27 ) { chanPWM[2]   =dataSource[deviceId].value[regId]; }    // PWM
		if ( dataSource[deviceId].regAddress[regId] == 43 ) { chanPWMAvg[2]=dataSource[deviceId].value[regId]; }    // PWM AVG
		if ( dataSource[deviceId].regAddress[regId] == 59 ) { chanPWMMax[2]=dataSource[deviceId].value[regId]; }	   // PWM Max Peek	    
		if ( dataSource[deviceId].regAddress[regId] == 75 ) { chanPWMMin[2]=dataSource[deviceId].value[regId]; }    // PWM Min Peek
		
		// Deals with chan 3 value registers
		if ( dataSource[deviceId].regAddress[regId] == 3  ) { chanLvl[3]   =dataSource[deviceId].value[regId]; }    // Level
		if ( dataSource[deviceId].regAddress[regId] == 13 ) { chanCount[3] =dataSource[deviceId].value[regId]; }    // Pulse
		if ( dataSource[deviceId].regAddress[regId] == 29 ) { chanPWM[3]   =dataSource[deviceId].value[regId]; }    // PWM
		if ( dataSource[deviceId].regAddress[regId] == 45 ) { chanPWMAvg[3]=dataSource[deviceId].value[regId]; }    // PWM AVG
		if ( dataSource[deviceId].regAddress[regId] == 61 ) { chanPWMMax[3]=dataSource[deviceId].value[regId]; }	   // PWM Max Peek	    
		if ( dataSource[deviceId].regAddress[regId] == 77 ) { chanPWMMin[3]=dataSource[deviceId].value[regId]; }    // PWM Min Peek

		// Deals with chan 4 value registers
		if ( dataSource[deviceId].regAddress[regId] == 4  ) { chanLvl[4]   =dataSource[deviceId].value[regId]; }    // Level
		if ( dataSource[deviceId].regAddress[regId] == 15 ) { chanCount[4] =dataSource[deviceId].value[regId]; }    // Pulse
		if ( dataSource[deviceId].regAddress[regId] == 31 ) { chanPWM[4]   =dataSource[deviceId].value[regId]; }    // PWM
		if ( dataSource[deviceId].regAddress[regId] == 47 ) { chanPWMAvg[4]=dataSource[deviceId].value[regId]; }    // PWM AVG
		if ( dataSource[deviceId].regAddress[regId] == 63 ) { chanPWMMax[4]=dataSource[deviceId].value[regId]; }	   // PWM Max Peek	    
		if ( dataSource[deviceId].regAddress[regId] == 79 ) { chanPWMMin[4]=dataSource[deviceId].value[regId]; }    // PWM Min Peek
		
		// Deals with chan 5 value registers
		if ( dataSource[deviceId].regAddress[regId] == 5  ) { chanLvl[5]   =dataSource[deviceId].value[regId]; }    // Level
		if ( dataSource[deviceId].regAddress[regId] == 17 ) { chanCount[5] =dataSource[deviceId].value[regId]; }    // Pulse
		if ( dataSource[deviceId].regAddress[regId] == 33 ) { chanPWM[5]   =dataSource[deviceId].value[regId]; }    // PWM
		if ( dataSource[deviceId].regAddress[regId] == 49 ) { chanPWMAvg[5]=dataSource[deviceId].value[regId]; }    // PWM AVG
		if ( dataSource[deviceId].regAddress[regId] == 65 ) { chanPWMMax[5]=dataSource[deviceId].value[regId]; }	   // PWM Max Peek	    
		if ( dataSource[deviceId].regAddress[regId] == 81 ) { chanPWMMin[5]=dataSource[deviceId].value[regId]; }    // PWM Min Peek

		// Deals with chan 6 value registers
		if ( dataSource[deviceId].regAddress[regId] == 6  ) { chanLvl[6]   =dataSource[deviceId].value[regId]; }    // Level
		if ( dataSource[deviceId].regAddress[regId] == 19 ) { chanCount[6] =dataSource[deviceId].value[regId]; }    // Pulse
		if ( dataSource[deviceId].regAddress[regId] == 35 ) { chanPWM[6]   =dataSource[deviceId].value[regId]; }    // PWM
		if ( dataSource[deviceId].regAddress[regId] == 51 ) { chanPWMAvg[6]=dataSource[deviceId].value[regId]; }    // PWM AVG
		if ( dataSource[deviceId].regAddress[regId] == 67 ) { chanPWMMax[6]=dataSource[deviceId].value[regId]; }	   // PWM Max Peek	    
		if ( dataSource[deviceId].regAddress[regId] == 83 ) { chanPWMMin[6]=dataSource[deviceId].value[regId]; }    // PWM Min Peek

		// Deals with chan 7 value registers
		if ( dataSource[deviceId].regAddress[regId] == 7  ) { chanLvl[7]   =dataSource[deviceId].value[regId]; }    // Level
		if ( dataSource[deviceId].regAddress[regId] == 21 ) { chanCount[7] =dataSource[deviceId].value[regId]; }    // Pulse
		if ( dataSource[deviceId].regAddress[regId] == 37 ) { chanPWM[7]   =dataSource[deviceId].value[regId]; }    // PWM
		if ( dataSource[deviceId].regAddress[regId] == 53 ) { chanPWMAvg[7]=dataSource[deviceId].value[regId]; }    // PWM AVG
		if ( dataSource[deviceId].regAddress[regId] == 69 ) { chanPWMMax[7]=dataSource[deviceId].value[regId]; }	   // PWM Max Peek	    
		if ( dataSource[deviceId].regAddress[regId] == 85 ) { chanPWMMin[7]=dataSource[deviceId].value[regId]; }    // PWM Min Peek

		// Deals with chan 8 value registers
		if ( dataSource[deviceId].regAddress[regId] == 8  ) { chanLvl[8]   =dataSource[deviceId].value[regId]; }    // Level
		if ( dataSource[deviceId].regAddress[regId] == 23 ) { chanCount[8] =dataSource[deviceId].value[regId]; }    // Pulse
		if ( dataSource[deviceId].regAddress[regId] == 39 ) { chanPWM[8]   =dataSource[deviceId].value[regId]; }    // PWM
		if ( dataSource[deviceId].regAddress[regId] == 55 ) { chanPWMAvg[8]=dataSource[deviceId].value[regId]; }    // PWM AVG
		if ( dataSource[deviceId].regAddress[regId] == 71 ) { chanPWMMax[8]=dataSource[deviceId].value[regId]; }	   // PWM Max Peek	    
		if ( dataSource[deviceId].regAddress[regId] == 87 ) { chanPWMMin[8]=dataSource[deviceId].value[regId]; }    // PWM Min Peek
	} 
	
	
	
	// present the output in the format desired by the command line option
	if (displayType == HUMANREAD)
	{			
		printf("_____| DI8 Modbus Address %i |______________________________________________________________________\n", dataSource[deviceId].modbusId);
		printf("Ch\tMode\tLevel\tCount\t\tPWM\t\tMin Pk\t\tAvg\t\tMax Pk\n");
       
        // see https://eecs.wsu.edu/~cs150/reading/printf.htm for futher information on printf formating 


        for(int chanNo=1 ; chanNo <9 ; chanNo++)
		{		
            printf("%i\t%s\t", chanNo,chMode[dataSource[deviceId].ChanMode[chanNo]]);

            if (dataSource[deviceId].ChanMode[chanNo]  < 2 )      // Level 
                printf("%-8i%-16s%-16s%-16s%-16s%-16s",chanLvl[chanNo],"-","-","-","-","-"); 
            else if (dataSource[deviceId].ChanMode[chanNo] == 2 )  // Pulse Count
                printf("%-8s%-16i%-16s%-16s%-16s%-16s","-", chanCount[chanNo],"-","-","-","-"); 
            else if (dataSource[deviceId].ChanMode[chanNo] == 3 )  // PWM
                printf("%-8s%-16s%-16i%-16i%-16i%-16i","-","-",chanPWM[chanNo],chanPWMMin[chanNo],chanPWMAvg[chanNo],chanPWMMax[chanNo]); 

            printf("\n");
        }
        printf("\n");

	}	


	if (displayType == JSONREAD)
	{				
		printf ("      \"name\":\"RTU-DI8\",\n");
		printf ("      \"type\": %i,\n",dataSource[deviceId].deviceType);
		printf ("      \"deviceId\":\"%i\",\n",deviceId);
		printf ("      \"modbusId\":\"%i\",\n",dataSource[deviceId].modbusId);	        
		printf ("      \"channels\": 8,\n");

		for(int chanNo=1 ; chanNo <9 ; chanNo++)
		{				
			printf ("      \"channel %i\": {\n",chanNo);
			printf ("         \"mode\": %i,\n",dataSource[deviceId].ChanMode[chanNo]);
            if (dataSource[deviceId].ChanMode[chanNo]  < 2 )                 
                printf ("         \"Level\": %i\n",chanLvl[chanNo]);
            else if (dataSource[deviceId].ChanMode[chanNo] == 2 )
                printf ("         \"Pulse Count\": %i\n",chanCount[chanNo]);
            else if (dataSource[deviceId].ChanMode[chanNo] == 3 ) 
            {
			    printf ("         \"PWM Live\": %i,\n",chanPWM[chanNo]);
			    printf ("         \"PWM min\": %i,\n",chanPWMMin[chanNo]);
			    printf ("         \"PWM avg\": %i,\n",chanPWMAvg[chanNo]);
			    printf ("         \"PWM max\": %i\n",chanPWMMax[chanNo]);
            }

			if (chanNo <8) { printf ("      },\n"); } else  { printf ("      }\n"); }			
		}
				
	}


	if (displayType == CPUREAD)
	{		

		//deviceId,deviceType,modbusId,ChansTotal,ChanMode[1], chanLvl[1], chanCount[1], chanPWM[1], chanPWMMin[1], chanPWMAvg[1], chanPWMMax[1]....ChansTotal,ChanMode[8], chanLvl[8], chanCount[8], chanPWM[8], chanPWMMin[8], chanPWMAvg[8], chanPWMMax[8] 
		printf("%i,%i,%i,8,",deviceId,dataSource[deviceId].deviceType,dataSource[deviceId].modbusId);
        
        for(int chanNo=1 ; chanNo <9 ; chanNo++)
		{				
		        printf ("%i,", dataSource[deviceId].ChanMode[chanNo]);
                printf ("%i,%i,%i,%i,%i", chanLvl[chanNo], chanCount[chanNo], chanPWM[chanNo], chanPWMMin[chanNo], chanPWMAvg[chanNo], chanPWMMax[chanNo] );
                
		}
        printf(";\n");
	}

}


int reconfigureRTU(int deviceId, int modbusBaudSetting, int chanModeSetting[], int pwmAverageSetting, int debouncePeriod)
{  

	int rc;	
	int regId;
	
	const char *chMode[5];
				chMode[0] = "Logic Level";
				chMode[1] = "Logic Level";
				chMode[2] = "Pulse Counter";
				chMode[3] = "PWM Measurement";


	const char *pwmAvg[4];
				pwmAvg[0] = "8 Readings";
				pwmAvg[1] = "4 Readings";
				pwmAvg[2] = "8 Readings";


	const char *rtuBaud[6];
				rtuBaud[0] = "19200";
				rtuBaud[1] = "9600";
				rtuBaud[2] = "14400";
				rtuBaud[3] = "19200";
				rtuBaud[4] = "38400";
				rtuBaud[5] = "57600";



	uint16_t tableRegisters[1]; // 1 element array for use with modbus write command 

	// modbus device handle
	modbus_t *mb;  
	
	// Defines storage for returned registers from modbus read, *must* equal or exceed maximum number of registers requested, ask me how I know...
	uint16_t mbdata_UI16[30]; 

	printf("Processing Config Changes...\n");	

	mb = modbus_new_rtu( dataSource[deviceId].interface, 
					 	 dataSource[deviceId].baudRate,
						 dataSource[deviceId].parity[0],
						 dataSource[deviceId].dataBits,
						 dataSource[deviceId].stopBit);
						
	   modbus_set_slave( mb, dataSource[deviceId].modbusId );


	// Set per-byte and total timeouts, this format has changed from the older libmodbus version.		
	// This could be useful if we've a latent RF-Link 
	// TODO : Don't hard code this, allow it to be configurable
	modbus_set_response_timeout(mb, 5, (5*1000000));
	modbus_set_byte_timeout(mb,5,(5*1000000));

	
	// Enable/Disable Modbus debug
	modbus_set_debug(mb, FALSE);

	// check we can connect (not sure if this is relevant on serial modbus)
	if(modbus_connect(mb) == -1)
	{
		printf("Connect Failed to Modbus ID [%i] on [%s]\n", dataSource[deviceId].modbusId, 
															 dataSource[deviceId].interface);
		modbus_flush(mb);
		modbus_close(mb); 
		modbus_free(mb);
		return -1;
	}


	// Due to the way modbus registers start at 1 and not 0, 64 = register address 65
	for (int i=1 ; i<9 ; i++)
	{
		 
		if (chanModeSetting[i] >0)  
		{  
			printf("Changing Chan %i mode to %s...\n",i,chMode[ chanModeSetting[i] ]);
			tableRegisters[0]=chanModeSetting[i];
			rc = modbus_write_registers(mb, (103+i) ,  1, tableRegisters);
			if (rc == -1)
			{
				printf("Modbus request Fail : Device Address [%i] Start Address [%i] For [1] Registers \n",deviceId,(103+i) );
				modbus_flush(mb);
				modbus_close(mb);
				modbus_free(mb);
				exit(1);
			}			
		}
	}

	if (pwmAverageSetting>0)	
	{	
		printf("Changing PWM Averaging to %s...\n",pwmAvg[pwmAverageSetting]);
		tableRegisters[0]=pwmAverageSetting;
		rc = modbus_write_registers(mb, 120,  1, tableRegisters);
		if (rc == -1)
		{
			printf("Modbus request Fail : Device Address [%i] Start Address [120] For [1] Registers \n",deviceId);
			modbus_flush(mb);
			modbus_close(mb);
			modbus_free(mb);
			exit(1);
		}			
	}

	if (debouncePeriod>0)	
	{	
		printf("Changing Pulse Count Debounce Setting %imS...\n", debouncePeriod);
		tableRegisters[0]=debouncePeriod;
		rc = modbus_write_registers(mb, 121,  1, tableRegisters);
		if (rc == -1)
		{
			printf("Modbus request Fail : Device Address [%i] Start Address [121] For [1] Registers \n",deviceId);
			modbus_flush(mb);
			modbus_close(mb);
			modbus_free(mb);
			exit(1);
		}			
	}

	if (modbusBaudSetting>0)	
	{	
		printf("Changing RTU Baud Rate to %s...\n",rtuBaud[modbusBaudSetting]);		
		tableRegisters[0]=modbusBaudSetting;
		rc = modbus_write_registers(mb, 122,  1, tableRegisters);
		if (rc == -1)
		{
			printf("Modbus request Fail : Device Address [%i] Start Address [123] For [1] Registers \n",deviceId);
			modbus_flush(mb);
			modbus_close(mb);
			modbus_free(mb);
			exit(1);
		}	
	}

    

	printf("Writing Config Register...\n");	
	tableRegisters[0]=255;
	rc = modbus_write_registers(mb, 123,  1, tableRegisters);
	if (rc == -1)
	{
		printf("Modbus request Fail : Device Address [%i] Start Address [123] For [1] Registers \n",deviceId);
		modbus_close(mb);
		modbus_free(mb);
		exit(1);
	}	

	modbus_flush(mb);
	modbus_close(mb);
	modbus_free(mb);
	return 0;

}


int getChanConfig(modbus_t *mb, int deviceId)
{
	// Defines storage for returned registers from modbus read, *must* equal or exceed maximum number of registers requested
	uint16_t mbdata_UI16[30]; 

	int rc;	

	// Get DI8 specific channel config registers
	rc = modbus_read_registers(mb, 104, 8, mbdata_UI16);		
	if (rc == -1)
	{
		printf("Modbus request Fail : Device Address [%i] Start Address [104] For [8] Registers \n",deviceId);
		modbus_flush(mb);
		modbus_close(mb);
		modbus_free(mb);
		exit(1);
	}	

	dataSource[deviceId].ChanMode[1] = mbdata_UI16[0];
	dataSource[deviceId].ChanMode[2] = mbdata_UI16[1];
	dataSource[deviceId].ChanMode[3] = mbdata_UI16[2];
	dataSource[deviceId].ChanMode[4] = mbdata_UI16[3];
	dataSource[deviceId].ChanMode[5] = mbdata_UI16[4];
	dataSource[deviceId].ChanMode[6] = mbdata_UI16[5];
	dataSource[deviceId].ChanMode[7] = mbdata_UI16[6];
	dataSource[deviceId].ChanMode[8] = mbdata_UI16[7];

	return 0;
}

// Uses modbus_write_registers (FC16) to reset max readings to 0 so current values always exceeds it
int resetCounter(int resetValue, int deviceId) 
{  

	int rc;	
	int regId;


	uint16_t tableRegisters[1] = {resetValue}; 

	// modbus device handle
	modbus_t *mb;  
	
	// Defines storage for returned registers from modbus read, *must* equal or exceed maximum number of registers requested, ask me how I know...
	uint16_t mbdata_UI16[30]; 

	
	mb = modbus_new_rtu( dataSource[deviceId].interface, 
					 	 dataSource[deviceId].baudRate,
						 dataSource[deviceId].parity[0],
						 dataSource[deviceId].dataBits,
						 dataSource[deviceId].stopBit);
						
	modbus_set_slave(mb, dataSource[deviceId].modbusId);


	// Set per-byte and total timeouts, this format has changed from the older libmodbus version.		
	// This could be useful if we've a latent RF-Link 
	// TODO : Don't hard code this, allow it to be configurable
	modbus_set_response_timeout(mb, 5, (5*1000000));
	modbus_set_byte_timeout(mb,5,(5*1000000));

	
	// Enable/Disable Modbus debug
	modbus_set_debug(mb, FALSE);

	// check we can connect (not sure if this is relevant on serial modbus)
	if(modbus_connect(mb) == -1)
	{
		printf("Connect Failed to Modbus ID [%i] on [%s]\n", dataSource[deviceId].modbusId, 
															 dataSource[deviceId].interface);
		modbus_flush(mb);
		modbus_close(mb);
		modbus_free(mb);
		return -1;
	}

	
	printf("Writing Counter reset value [%i]...\n\r", resetValue);
	// remember that modbus registers index from 0 so address 40001 = 0th register
	// reg 124 = address 123
	rc = modbus_write_registers(mb, 123,  1, tableRegisters);
	if (rc == -1)
	{
		printf("Modbus request Fail : Device Address [%i] Start Address [72] For [1] Registers \n",deviceId);
		modbus_close(mb);
		modbus_free(mb);
		exit(1);
	}			

	modbus_flush(mb);
	modbus_close(mb);
	modbus_free(mb);	
	exit(0);

}



// Uses modbus_write_registers (FC16) to reset max readings to 0 so current values always exceeds it
int writeoffset(int chanNo, int chanOffset, int deviceId)
{  

	int rc;	
	int regId;

	regId = ((87+(chanNo*2))-1);  // 87 +  2 =  89 -1 = 88  
								  // 87 + 16 = 103 -1 = 102

	uint16_t tableRegisters[2] = {0}; 

	tableRegisters[0] = chanOffset >> 16 & 0xffff;  // Upper 
    tableRegisters[1] = chanOffset & 0xffff;        // lower 



	// modbus device handle
	modbus_t *mb;  
	
	// Defines storage for returned registers from modbus read, *must* equal or exceed maximum number of registers requested, ask me how I know...
	uint16_t mbdata_UI16[30]; 

	
	mb = modbus_new_rtu( dataSource[deviceId].interface, 
					 	 dataSource[deviceId].baudRate,
						 dataSource[deviceId].parity[0],
						 dataSource[deviceId].dataBits,
						 dataSource[deviceId].stopBit);
						
	modbus_set_slave(mb, dataSource[deviceId].modbusId);


	// Set per-byte and total timeouts, this format has changed from the older libmodbus version.		
	// This could be useful if we've a latent RF-Link 
	// TODO : Don't hard code this, allow it to be configurable
	modbus_set_response_timeout(mb, 5, (5*1000000));
	modbus_set_byte_timeout(mb,5,(5*1000000));

	
	// Enable/Disable Modbus debug
	modbus_set_debug(mb, FALSE);

	// check we can connect (not sure if this is relevant on serial modbus)
	if(modbus_connect(mb) == -1)
	{
		printf("Connect Failed to Modbus ID [%i] on [%s]\n", dataSource[deviceId].modbusId, 
															 dataSource[deviceId].interface);
		modbus_flush(mb);															 
		modbus_close(mb);
		modbus_free(mb);
		return -1;
	}

	
	printf("Writing offset values [%i]+[%i] to registers [%i]+[%i]...\n\r",tableRegisters[0],tableRegisters[1], (regId+1),(regId+2));
	// remember that modbus registers index from 0 so address 40001 = 0th register
	// reg 124 = address 123
	rc = modbus_write_registers(mb, regId,  2, tableRegisters);
	if (rc == -1)
	{
		printf("Modbus request Fail : Device Address [%i] Start Address [%i] For [2] Registers \n",deviceId, regId);
		modbus_close(mb);
		modbus_free(mb);
		exit(1);
	}			
	
	modbus_flush(mb);
	modbus_close(mb);
	modbus_free(mb);
	exit(0);

}

// Uses modbus_write_registers (FC16) to reset max readings to 0 so current values always exceeds it
int showPWMchanStatus(int deviceId) 
{  

	int rc;	
	int regId;

	const char *chStatus[2];
				chStatus[0] = "Channel OK";
				chStatus[1] = "Channel Dead";


	// modbus device handle
	modbus_t *mb;  
	
	// Defines storage for returned registers from modbus read, *must* equal or exceed maximum number of registers requested, ask me how I know...
	uint16_t mbdata_UI16[30]; 

	
	mb = modbus_new_rtu( dataSource[deviceId].interface, 
					 	 dataSource[deviceId].baudRate,
						 dataSource[deviceId].parity[0],
						 dataSource[deviceId].dataBits,
						 dataSource[deviceId].stopBit);
						
	modbus_set_slave(mb, dataSource[deviceId].modbusId);


	// Set per-byte and total timeouts, this format has changed from the older libmodbus version.		
	// This could be useful if we've a latent RF-Link 
	// TODO : Don't hard code this, allow it to be configurable
	modbus_set_response_timeout(mb, 19, (10*1000000));
	modbus_set_byte_timeout(mb,10,(10*1000000));

	
	// Enable/Disable Modbus debug
	modbus_set_debug(mb, FALSE);

	// check we can connect (not sure if this is relevant on serial modbus)
	if(modbus_connect(mb) == -1)
	{
		printf("Connect Failed to Modbus ID [%i] on [%s]\n", dataSource[deviceId].modbusId, 
															 dataSource[deviceId].interface);
		modbus_flush(mb);															 
		modbus_close(mb);
		modbus_free(mb);
		return -1;
	}



	// Get DI8 specific PWM Status registers
	// 113-120 = Channel status
	printf("Getting PWM Channel Status flags...\r\n");
	rc = modbus_read_registers(mb, 112, 8, mbdata_UI16);		
	if (rc == -1)
	{
		printf("Modbus request Fail : Device Address [%i] Start Address [112] For [8] Registers \n",deviceId);
		modbus_flush(mb);			
		modbus_close(mb);
		modbus_free(mb);
		exit(1);
	}	
		printf("\n\r");
		printf ("Channel 1 PWM Status : %s\n\r",chStatus[mbdata_UI16[0]]);
		printf ("Channel 2 PWM Status : %s\n\r",chStatus[mbdata_UI16[1]]);
		printf ("Channel 3 PWM Status : %s\n\r",chStatus[mbdata_UI16[2]]);
		printf ("Channel 4 PWM Status : %s\n\r",chStatus[mbdata_UI16[3]]);
		printf ("Channel 5 PWM Status : %s\n\r",chStatus[mbdata_UI16[4]]);
		printf ("Channel 6 PWM Status : %s\n\r",chStatus[mbdata_UI16[5]]);
		printf ("Channel 7 PWM Status : %s\n\r",chStatus[mbdata_UI16[6]]);
		printf ("Channel 8 PWM Status : %s\n\r",chStatus[mbdata_UI16[7]]);
		printf("\n\r");

	modbus_flush(mb);
	modbus_close(mb);
	modbus_free(mb);	
	exit(0);

}
