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
	init_status = ARD2990_EEPROM_ERR;
	i2cAddr_ltc2990_u1 = 0;
	i2cAddr_ltc2990_u2 = 0;	
	i2cAddr_eeprom = 0;
	strcpy(eui48, "Unknown");
}

const char* Ard2990::eui48Get()
{
	return(eui48);
}

byte Ard2990::ltc2990SendControlByte(byte partNum)
{
	byte mode=0, i=0;
	if (partNum)
		i = 2;
	
	// Horrible logic tree for configuration byte
	if (channelConfig[i+0] == ARD2990_LTC2990_SINGLE_ENDED && channelConfig[i+1] == ARD2990_LTC2990_SINGLE_ENDED)
		mode = 0x07;
	else if (channelConfig[i+0] == ARD2990_LTC2990_DIFFERENTIAL && channelConfig[i+1] == ARD2990_LTC2990_DIFFERENTIAL)
		mode = 0x06;
	else if (channelConfig[i+0] == ARD2990_LTC2990_TEMPERATURE && channelConfig[i+1] == ARD2990_LTC2990_TEMPERATURE)
		mode = 0x05;
	else if (channelConfig[i+0] == ARD2990_LTC2990_TEMPERATURE && channelConfig[i+1] == ARD2990_LTC2990_DIFFERENTIAL)
		mode = 0x04;
	else if (channelConfig[i+0] == ARD2990_LTC2990_TEMPERATURE && channelConfig[i+1] == ARD2990_LTC2990_SINGLE_ENDED)
		mode = 0x03;
	else if (channelConfig[i+0] == ARD2990_LTC2990_DIFFERENTIAL && channelConfig[i+1] == ARD2990_LTC2990_SINGLE_ENDED)
		mode = 0x02;
	else if (channelConfig[i+0] == ARD2990_LTC2990_DIFFERENTIAL && channelConfig[i+1] == ARD2990_LTC2990_TEMPERATURE)
		mode = 0x01;
	else if (channelConfig[i+0] == ARD2990_LTC2990_SINGLE_ENDED && channelConfig[i+1] == ARD2990_LTC2990_TEMPERATURE)
		mode = 0x00;
	else
		// There's not a mode to express what you've done...
		return ARD2990_INVALID_CONFIG;

	// Select all measurements
	mode |= 0x18;

	// globalConfig carries along continuous/single and celsius/kelvin
	mode |= globalConfig;

	Wire.beginTransmission((0 == partNum)?i2cAddr_ltc2990_u1:i2cAddr_ltc2990_u2);
	Wire.write(LTC2990_REGISTER_CONFIG);
	Wire.write(mode);
	if (0 != Wire.endTransmission(true))
		return ARD2990_FAIL;

	return ARD2990_SUCCESS;
}

byte Ard2990::ltc2990ConfigSet(byte chanAConfig, byte chanBConfig, byte chanCConfig, byte chanDConfig)
{
	byte retval = 0;
	byte i;

	if (ARD2990_SUCCESS != init_status)
		return ARD2990_FAIL;

	globalConfig = ARD2990_LTC2990_KELVIN | ARD2990_LTC2990_CONTINUOUS;	
	
	for (i=0; i<4; i++)
	{
		switch(i)
		{
			case 0:
				channelConfig[0] = chanAConfig;
				break;
				
			case 1:
				channelConfig[1] = chanBConfig;
				break;
			
			case 2:
				channelConfig[2] = chanCConfig;
				break;
			
			case 3:
				channelConfig[3] = chanDConfig;
				break;
		}
		
		if (ARD2990_LTC2990_SINGLE_ENDED != channelConfig[i]
			&& ARD2990_LTC2990_DIFFERENTIAL != channelConfig[i]
			&& ARD2990_LTC2990_TEMPERATURE != channelConfig[i])
		{
			return ARD2990_INVALID_CONFIG;
		}
	}

	if (ARD2990_SUCCESS != (retval = ltc2990SendControlByte(ARD2990_PART_U1)))
		return retval;
	if (ARD2990_SUCCESS != (retval = ltc2990SendControlByte(ARD2990_PART_U2)))
		return retval;

	return ARD2990_SUCCESS;
}

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


#define LTC2990_REGISTER_TINT_MSB            0x04
#define LTC2990_REGISTER_TINT_LSB            0x05
#define LTC2990_REGISTER_V1_MSB              0x06
#define LTC2990_REGISTER_V1_LSB              0x07
#define LTC2990_REGISTER_V2_MSB              0x08
#define LTC2990_REGISTER_V2_LSB              0x09
#define LTC2990_REGISTER_V3_MSB              0x0A
#define LTC2990_REGISTER_V3_LSB              0x0B
#define LTC2990_REGISTER_V4_MSB              0x0C
#define LTC2990_REGISTER_V4_LSB              0x0D
#define LTC2990_REGISTER_VCC_MSB             0x0E
#define LTC2990_REGISTER_VCC_LSB             0x0F


uint16_t Ard2990::ltc2990ReadRaw(byte channel)
{
	uint8_t i2cAddr;
	uint8_t i2cRegister;
	uint8_t blockingCountdown = 40;
	uint16_t retval = 0;

	switch(channel)
	{
		case ARD2990_CHANNEL_A1:
			i2cAddr = i2cAddr_ltc2990_u1;
			i2cRegister = LTC2990_REGISTER_V1_MSB;
			break;

		case ARD2990_CHANNEL_A2:
			i2cAddr = i2cAddr_ltc2990_u1;
			i2cRegister = LTC2990_REGISTER_V2_MSB;
			break;

		case ARD2990_CHANNEL_B1:
			i2cAddr = i2cAddr_ltc2990_u1;
			i2cRegister = LTC2990_REGISTER_V3_MSB;
			break;
			
		case ARD2990_CHANNEL_B2:
			i2cAddr = i2cAddr_ltc2990_u1;
			i2cRegister = LTC2990_REGISTER_V4_MSB;
			break;

		case ARD2990_CHANNEL_U1_TEMP:
			i2cAddr = i2cAddr_ltc2990_u1;
			i2cRegister = LTC2990_REGISTER_TINT_MSB;
			break;
				
		case ARD2990_CHANNEL_U1_VSUPPLY:
			i2cAddr = i2cAddr_ltc2990_u1;
			i2cRegister = LTC2990_REGISTER_VCC_MSB;
			break;

		case ARD2990_CHANNEL_C1:		
			i2cAddr = i2cAddr_ltc2990_u2;
			i2cRegister = LTC2990_REGISTER_V1_MSB;
			break;

		case ARD2990_CHANNEL_C2:
			i2cAddr = i2cAddr_ltc2990_u2;
			i2cRegister = LTC2990_REGISTER_V2_MSB;
			break;

		case ARD2990_CHANNEL_D1:
			i2cAddr = i2cAddr_ltc2990_u2;
			i2cRegister = LTC2990_REGISTER_V3_MSB;
			break;

		case ARD2990_CHANNEL_D2:
			i2cAddr = i2cAddr_ltc2990_u2;
			i2cRegister = LTC2990_REGISTER_V4_MSB;
			break;

		case ARD2990_CHANNEL_U2_TEMP:
			i2cAddr = i2cAddr_ltc2990_u2;
			i2cRegister = LTC2990_REGISTER_TINT_MSB;
			break;

		case ARD2990_CHANNEL_U2_VSUPPLY:
			i2cAddr = i2cAddr_ltc2990_u2;
			i2cRegister = LTC2990_REGISTER_VCC_MSB;
			break;
			
		default:
			return 0;
	}
	
	Wire.beginTransmission(i2cAddr);
	Wire.write(i2cRegister);
	Wire.endTransmission(false);
	Wire.requestFrom(i2cAddr, (uint8_t)2, (uint8_t)true);
	
	while(blockingCountdown--)
	{
		// Error occurred, we don't have as many bytes as expected
		if (Wire.available() < 2)
		{
			if (0 == blockingCountdown)
				return 0;
			_delay_ms(5);
		}	
		else
			break;
	}
	
	retval = Wire.read();
	retval <<= 8;
	retval |= Wire.read();

	return retval;
}

long Ard2990::ltc2990ReadMicrovolts(byte channel)
{
	uint8_t chanConfig = 0;
	// First, test to make sure that channel is configured for temperature, return 0 if not
	switch(channel)
	{
		case ARD2990_CHANNEL_A1:
		case ARD2990_CHANNEL_A2:
			chanConfig = channelConfig[0];
			break;
		case ARD2990_CHANNEL_B1:
		case ARD2990_CHANNEL_B2:
			chanConfig = channelConfig[1];
			break;

		case ARD2990_CHANNEL_C1:
		case ARD2990_CHANNEL_C2:
			chanConfig = channelConfig[2];
			break;

		case ARD2990_CHANNEL_D1:
		case ARD2990_CHANNEL_D2:
			chanConfig = channelConfig[3];
			break;

		default:
			return ARD_LTC2990_VOLTAGE_ERR;
	}

	// FIXME: Need to trigger a conversion

	uint16_t rawRead = ltc2990ReadRaw(channel) & 0x7FFF;

	switch(chanConfig)
	{
		case ARD2990_LTC2990_SINGLE_ENDED:
			if (rawRead & 0x4000)
				rawRead = ~rawRead + 1;
			return (((((long)rawRead * 100) * 30518L) + 0) / 100);
			
		case ARD2990_LTC2990_DIFFERENTIAL:
			if (rawRead & 0x4000)
				rawRead = ~rawRead + 1;
			return (((((long)rawRead * 100) * 1942L) + 0) / 100);

		case 0:
			// 0 means it's an internal voltage, so we have to add to it
			rawRead &= 0x3FFF;
			return 2500000L + (((((long)rawRead * 100) * 30518L) + 0) / 100);

		default:
			return ARD_LTC2990_VOLTAGE_ERR;
	}
	
	return(0L);
}

float Ard2990::ltc2990ReadTemperature(byte channel, byte temperatureUnits)
{
	// First, test to make sure that channel is configured for temperature, return 0 if not
	switch(channel)
	{
		case ARD2990_CHANNEL_A1:
		case ARD2990_CHANNEL_A2:
			if (ARD2990_LTC2990_TEMPERATURE != channelConfig[0])
				return 0.0;
			break;
		case ARD2990_CHANNEL_B1:
		case ARD2990_CHANNEL_B2:
			if (ARD2990_LTC2990_TEMPERATURE != channelConfig[1])
				return 0.0;
			break;

		case ARD2990_CHANNEL_C1:
		case ARD2990_CHANNEL_C2:
			if (ARD2990_LTC2990_TEMPERATURE != channelConfig[2])
				return 0.0;
			break;

		case ARD2990_CHANNEL_D1:
		case ARD2990_CHANNEL_D2:
			if (ARD2990_LTC2990_TEMPERATURE != channelConfig[3])
				return 0.0;
			break;

		case ARD2990_CHANNEL_U1_TEMP:
		case ARD2990_CHANNEL_U2_TEMP:
			break;
		
		default:
			return 0.0;
	}
	
	// Trigger a conversion
	// FIXME: Should trigger a conversion be its own function, which the user must then follow with a read...() call?
	Wire.beginTransmission(0x77);  // LTC2990 Global Address
	Wire.write(LTC2990_REGISTER_TRIGGER);
	Wire.write(0x00);
	Wire.endTransmission(true);

	_delay_ms(200);  // Wait until max conversion time plus some margin (FIXME: read busy byte?)
	
	float tempK = (float)(ltc2990ReadRaw(channel) & 0x1FFF) * 0.0625;

	switch(temperatureUnits)
	{
		case ARD2990_TEMP_K:
			return(tempK);
		case ARD2990_TEMP_C:
			return(tempK - 273.15);
		case ARD2990_TEMP_F:
			return(((tempK - 273.15) * 9.0)  / 5.0 + 32.0);
	}
	return(0);
}

byte Ard2990::begin(byte j11State, byte chanAConfig, byte chanBConfig, byte chanCConfig, byte chanDConfig)
{
	byte retval = begin(j11State);
	if (ARD2990_SUCCESS != retval)
		return retval;
	

	return ltc2990ConfigSet(chanAConfig, chanBConfig, chanCConfig, chanDConfig);
}

byte Ard2990::begin(byte j11State)
{
	byte retval = 0;
	byte i;
	
	init_status = ARD2990_SUCCESS;
	strcpy(eui48, "Unknown");

	if (ARD2990_J11_SHORTED == j11State)
	{
		i2cAddr_ltc2990_u1 = 0x4C;
		i2cAddr_ltc2990_u2 = 0x4D;
		i2cAddr_eeprom = 0x50;	
	} else {
		i2cAddr_ltc2990_u1 = 0x4E;
		i2cAddr_ltc2990_u2 = 0x4F;
		i2cAddr_eeprom = 0x52;	
	}

	Wire.beginTransmission(i2cAddr_eeprom);
	Wire.write(ARD2990_EEPROM_ADDR_EUI48);
	retval = Wire.endTransmission(false);
	// Anything but zero means we couldn't initialize the ARD-LTC2990 EEPROM
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
		return(ARD2990_EEPROM_ERR);

	// Our writable address range only goes to 0xFF
	if (address > 0x7F)
		return(ARD2990_EEPROM_ERR);
		
	Wire.beginTransmission(i2cAddr_eeprom);
	Wire.write(address);
	Wire.write(value);
	retval = Wire.endTransmission(true);
	// Anything but zero means we couldn't write to the LTC2499
	if (0 != retval)
	{
		return(ARD2990_EEPROM_ERR);
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
		return(ARD2990_EEPROM_ERR);
	}
	return(ARD2990_SUCCESS);
}


