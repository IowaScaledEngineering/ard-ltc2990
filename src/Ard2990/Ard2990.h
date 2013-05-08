/*************************************************************************
Title:    ARD-LTC2990 Driver Library
Authors:  Nathan D. Holmes <maverick@drgw.net>
File:     $Id: $
License:  GNU General Public License v3

LICENSE:
    Copyright (C) 2013 Nathan D. Holmes & Michael D. Petersen

    This program is free software; you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation; either version 2 of the License, or
    any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

*************************************************************************/
#ifndef ARD2990_H
#define ARD2990_H

#include <stdlib.h>
#include <string.h>
#include <avr/io.h>
#include "Arduino.h"
#include "Wire.h"

#define ARD2990_EUI48_STRLN  (6 * 2)

#define ARD2990_SUCCESS         0
#define ARD2990_LTC2499_U1_ERR  1
#define ARD2990_EEPROM_ERR      2
#define ARD2990_LTC2499_U2_ERR  4
#define ARD2990_FAIL            8

#define ARD2990_EEP_ADDR_00 0x50
#define ARD2990_EEP_ADDR_0Z 0x51
#define ARD2990_EEP_ADDR_Z0 0x52
#define ARD2990_EEP_ADDR_ZZ 0x53

#define ARD2990_LTC2990_SINGLE_ENDED         0x01
#define ARD2990_LTC2990_DIFFERENTIAL         0x02
#define ARD2990_LTC2990_TEMPERATURE          0x03


#define ARD2990_CHANNEL_A1                   0x01
#define ARD2990_CHANNEL_A2                   0x02
#define ARD2990_CHANNEL_B1                   0x03
#define ARD2990_CHANNEL_B2                   0x04
#define ARD2990_CHANNEL_C1                   0x05
#define ARD2990_CHANNEL_C2                   0x06
#define ARD2990_CHANNEL_D1                   0x07
#define ARD2990_CHANNEL_D2                   0x08
#define ARD2990_CHANNEL_U1_TEMP              0x09
#define ARD2990_CHANNEL_U1_VSUPPLY           0x0A
#define ARD2990_CHANNEL_U2_TEMP              0x0B
#define ARD2990_CHANNEL_U2_VSUPPLY           0x0C

#define ARD2990_J11_OPEN                     0x01
#define ARD2990_J11_SHORTED                  0x00

byte ltc2990ConfigSet(uint8_t whichLtc2990)
{
	

}



int channelRead()
{
	

}


byte channelSetup(byte channel, byte configuration)
{
	uint8_t retval, saveConfiguration;
	if (channel >= sizeof(channelConfig))
		return(ARD2990_FAIL);

	if (configuration > 0x07) // it's only three bits - anything greater is an error		
		return(ARD2990_FAIL);		

	saveConfiguration = channelConfig[channel];
	channelConfig[channel] = configuration;
	retval = ltc2990ConfigSend(channel / 2);

	if (ARD2990_SUCCESS != retval)
		channelConfig[channel] = saveConfiguration;

	return(retval);
}




#define ARD2990_EEPROM_ADDR_EUI48  0xFA

class Ard2990
{
	public:
		Ard2990();
		byte begin(byte ltc2499Address, byte eepromAddress);
		const char* eui48Get();
		byte eepromRead(int address, byte defaultOnError);
		byte eepromWrite(int address, byte value, byte blocking);
	private:
		uint8_t init_status;
		uint8_t i2cAddr_ltc2990_u1;
		uint8_t i2cAddr_ltc2990_u2;
		uint8_t i2cAddr_eeprom;
		uint8_t channelConfig[4];
		uint8_t currentLtc2990U2Config;
		char eui48[ARD2990_EUI48_STRLN+1];
};

#endif // ARD2990_H
