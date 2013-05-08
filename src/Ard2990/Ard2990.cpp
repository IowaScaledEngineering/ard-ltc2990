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

#include <stdlib.h>
#include <string.h>
#include <util/delay.h>

#include "Ard2990.h"

Ard2990::Ard2990()
{
	init_status = ARD2499_EEPROM_ERR;
	i2cAddr_ltc2990_1 = 0;
	i2cAddr_ltc2990_2 = 0;	
	i2cAddr_eeprom = 0;
	strcpy(eui48, "Unknown");
}

const char* Ard2990::eui48Get()
{
	return(eui48);
}


byte Ard2990::begin(byte j11State)
{
	byte retval = 0;
	byte i;
	
	init_status = ARD2990_SUCCESS;
	strcpy(eui48, "Unknown");

	i2cAddr_ltc2990_u1 = 0x4E;
	i2cAddr_ltc2990_u2 = 0x4F;
	i2cAddr_eeprom = 0x52;

	if (ARD2990_J11_SHORTED == j11State)
	{
		i2cAddr_ltc2990_u1 = 0x4C;
		i2cAddr_ltc2990_u2 = 0x4D;
		i2cAddr_eeprom = 0x50;	
	}

	Wire.beginTransmission(i2cAddr_eeprom);
	Wire.write(ARD2990_EEPROM_ADDR_EUI48);
	retval = Wire.endTransmission(false);
	// Anything but zero means we couldn't initialize the LTC2499
	if (0 != retval)
	{
		// Make sure we send a stop bit
		Wire.endTransmission(true);
		i2cAddr_eeprom = 0;
		init_status |= ARD2990_EEPROM_ERR;
	}
	else
	{
		Wire.requestFrom(i2cAddr_eeprom, (uint8_t)6, (uint8_t)true);
		if (Wire.available() < 6)
		{
			i2cAddr_eeprom = 0;		
			init_status |= ARD2990_EEPROM_ERR;
		} else {
			memset(eui48, 0, sizeof(eui48));
			for(i=0; i<12; i+=2)
				sprintf(&eui48[i], "%02X", Wire.read());
		}
	}
	
	
	
	
	return(init_status);
}

byte Ard2990::eepromRead(int address, byte defaultOnError=0)
{
	byte retval = 0;
	
	// Our address range only goes to 0xFF
	if (address > 0xFF)
		return(defaultOnError);
	
	Wire.beginTransmission(i2cAddr_eeprom);
	Wire.write((uint8_t)address);
	retval = Wire.endTransmission(false);
	// Anything but zero means we couldn't initialize the LTC2499
	if (0 != retval)
	{
		// Make sure we send a stop bit
		Wire.endTransmission(true);
		return(0);
	}

	Wire.requestFrom((uint8_t)i2cAddr_eeprom, (uint8_t)1, (uint8_t)true);
	if (Wire.available() < 1)
		return(defaultOnError);
	return(Wire.read());
}

byte Ard2990::eepromWrite(int address, byte value, byte blocking=1)
{
	uint8_t waitLoop = 10;
	byte retval = 0;
	if (0 == i2cAddr_eeprom)
		return(ARD2499_EEPROM_ERR);

	// Our writable address range only goes to 0xFF
	if (address > 0x7F)
		return(ARD2499_EEPROM_ERR);
		
	Wire.beginTransmission(i2cAddr_eeprom);
	Wire.write(address);
	Wire.write(value);
	retval = Wire.endTransmission(true);
	// Anything but zero means we couldn't write to the LTC2499
	if (0 != retval)
	{
		return(ARD2499_EEPROM_ERR);
	}	
	
	if (0 != blocking)
	{
		while (0 != waitLoop--)
		{
			Wire.beginTransmission(i2cAddr_eeprom);
			Wire.write(address);
			if (0 == Wire.endTransmission(true))
				return(0);
			_delay_ms(1);
		}
		return(ARD2499_EEPROM_ERR);
	}
	return(ARD2499_SUCCESS);
}


