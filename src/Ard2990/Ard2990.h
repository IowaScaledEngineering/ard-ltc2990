/*************************************************************************
Title:    ARD-LTC2990 Driver Library
Authors:  Nathan D. Holmes <maverick@drgw.net>
File:     $Id: $
License:  GNU General Public License v3

LICENSE:
    Copyright (C) 2014 Nathan D. Holmes & Michael D. Petersen

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
#define ARD2990_INVALID_CONFIG 16

#define ARD2990_EEP_ADDR_00 0x50
#define ARD2990_EEP_ADDR_0Z 0x51
#define ARD2990_EEP_ADDR_Z0 0x52
#define ARD2990_EEP_ADDR_ZZ 0x53

#define ARD2990_PART_U1     0x00
#define ARD2990_PART_U2     0x01


#define ARD2990_LTC2990_SINGLE_ENDED         0x01
#define ARD2990_LTC2990_DIFFERENTIAL         0x02
#define ARD2990_LTC2990_TEMPERATURE          0x03

#define ARD2990_LTC2990_CELSUIS              0x00
#define ARD2990_LTC2990_KELVIN               0x80

#define ARD2990_LTC2990_CONTINUOUS           0x00
#define ARD2990_LTC2990_SINGLE               0x40

#define ARD2990_CHANNEL_A                    0x01
#define ARD2990_CHANNEL_A1                   0x01
#define ARD2990_CHANNEL_A2                   0x02
#define ARD2990_CHANNEL_B                    0x03
#define ARD2990_CHANNEL_B1                   0x03
#define ARD2990_CHANNEL_B2                   0x04
#define ARD2990_CHANNEL_C                    0x05
#define ARD2990_CHANNEL_C1                   0x05
#define ARD2990_CHANNEL_C2                   0x06
#define ARD2990_CHANNEL_D                    0x07
#define ARD2990_CHANNEL_D1                   0x07
#define ARD2990_CHANNEL_D2                   0x08
#define ARD2990_CHANNEL_U1_TEMP              0x09
#define ARD2990_CHANNEL_U1_VSUPPLY           0x0A
#define ARD2990_CHANNEL_U2_TEMP              0x0B
#define ARD2990_CHANNEL_U2_VSUPPLY           0x0C

#define ARD2990_J11_OPEN                     0x01
#define ARD2990_J11_SHORTED                  0x00

#define ARD2990_TEMP_K        0x00
#define ARD2990_TEMP_F        0x01
#define ARD2990_TEMP_C        0x02

#define LTC2990_REGISTER_STATUS              0x00
#define LTC2990_REGISTER_CONFIG              0x01
#define LTC2990_REGISTER_TRIGGER             0x02
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

#define ARD_LTC2990_VOLTAGE_ERR              0x80000000L


#define ARD2990_EEPROM_ADDR_EUI48  0xFA

#define ARD2990_TEMP_NOT_CONFIGURED   -900.0
#define ARD2990_TEMP_SENSOR_SHORTED   -901.0
#define ARD2990_TEMP_SENSOR_OPEN      -902.0

class Ard2990
{
	public:
		Ard2990();
		byte begin(byte j11State);
		byte begin(byte j11State, byte chanAConfig, byte chanBConfig, byte chanCConfig, byte chanDConfig);
		bool isInitialized();
		const char* eui48Get();
		byte eepromRead(int address, byte defaultOnError);
		byte eepromWrite(int address, byte value, byte blocking);
		byte ltc2990ConfigSet(byte chanAConfig, byte chanBConfig, byte chanCConfig, byte chanDConfig);
		uint16_t ltc2990ReadRaw(byte channel);
		float ltc2990ReadTemperature(byte channel, byte temperatureUnits);
		long ltc2990ReadMicrovolts(byte channel);
		
	private:
		uint8_t init_status;
		uint8_t i2cAddr_ltc2990_u1;
		uint8_t i2cAddr_ltc2990_u2;
		uint8_t i2cAddr_eeprom;
		uint8_t channelConfig[4];
		uint8_t globalConfig;
		char eui48[ARD2990_EUI48_STRLN+1];
		byte ltc2990SendControlByte(byte partNum);
};

#endif // ARD2990_H
