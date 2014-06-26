/*************************************************************************
Title:    ARD-LTC2990 Library Example Arduino Sketch
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

#include <Wire.h>
#include <Ard2990.h>

Ard2990 ard2990board;

void setup() {
  // initialize serial communications at 9600 bps:
  Serial.begin(9600);
  Wire.begin();
  ard2990board.begin(ARD2990_J11_SHORTED, ARD2990_LTC2990_TEMPERATURE, ARD2990_LTC2990_TEMPERATURE, ARD2990_LTC2990_TEMPERATURE, ARD2990_LTC2990_TEMPERATURE);

}

byte i=0;

void printTemperatureWithErrors(float temperature)
{
	if (ARD2990_TEMP_NOT_CONFIGURED == temperature)
		Serial.print("** Not Configured **");
	else if (ARD2990_TEMP_SENSOR_SHORTED == temperature)
		Serial.print("** Sensor Shorted **");
	else if (ARD2990_TEMP_SENSOR_OPEN == temperature)
		Serial.print("** Sensor Open **");
	else
	{
		Serial.print(temperature);
		Serial.print(" F");
	}
}

void loop() {
  // print the results to the serial monitor:

  byte retval = 0;
  float temperature = 0.0;
 
  if (!ard2990board.isInitialized())
  {
     Serial.print("ARD-LTC2990 could not be found!\nCheck that either J11 is shorted or you change the address in the example!\n\n\n");
     ard2990board.begin(ARD2990_J11_SHORTED, ARD2990_LTC2990_TEMPERATURE, ARD2990_LTC2990_TEMPERATURE, ARD2990_LTC2990_TEMPERATURE, ARD2990_LTC2990_TEMPERATURE);
     delay(1000);
     return;
  }
 
 
  Serial.print("eeprom mac = [");
  Serial.print(ard2990board.eui48Get());
  Serial.print("]\n");
  
  Serial.print("write eeprom[0] ");
  Serial.print(i);
  retval = ard2990board.eepromWrite(0, i, true);
  Serial.print(" retval=");
  Serial.print(retval);
  Serial.print("\n");
  i++;

  Serial.print("read eeprom[0] ");
  Serial.print(ard2990board.eepromRead(0, true));
  Serial.print("\n");

  Serial.print("Temp U1 Internal = [");
  temperature = ard2990board.ltc2990ReadTemperature(ARD2990_CHANNEL_U1_TEMP, ARD2990_TEMP_F);
  printTemperatureWithErrors(temperature);
  Serial.print("]\n");

  Serial.print("Temp U2 Internal = [");
  temperature = ard2990board.ltc2990ReadTemperature(ARD2990_CHANNEL_U2_TEMP, ARD2990_TEMP_F);
  printTemperatureWithErrors(temperature);
  Serial.print("]\n");
  
  Serial.print("Temp Channel A   = [");
  temperature = ard2990board.ltc2990ReadTemperature(ARD2990_CHANNEL_A, ARD2990_TEMP_F);
  printTemperatureWithErrors(temperature);
  Serial.print("]\n");

  Serial.print("Temp Channel B   = [");
  temperature = ard2990board.ltc2990ReadTemperature(ARD2990_CHANNEL_B, ARD2990_TEMP_F);
  printTemperatureWithErrors(temperature);
  Serial.print("]\n");

  Serial.print("Temp Channel C   = [");
  temperature = ard2990board.ltc2990ReadTemperature(ARD2990_CHANNEL_C, ARD2990_TEMP_F);
  printTemperatureWithErrors(temperature);
  Serial.print("]\n");

  Serial.print("Temp Channel D   = [");
  temperature = ard2990board.ltc2990ReadTemperature(ARD2990_CHANNEL_D, ARD2990_TEMP_F);
  printTemperatureWithErrors(temperature);
  Serial.print("]\n");
  
  long voltage = ard2990board.ltc2990ReadMicrovolts(ARD2990_CHANNEL_U1_VSUPPLY);
  Serial.print("U1 Supply Voltage = [");
  Serial.print((float)voltage / 1000000.0);
  Serial.print(" V]\n");

  voltage = ard2990board.ltc2990ReadMicrovolts(ARD2990_CHANNEL_U2_VSUPPLY);
  Serial.print("U2 Supply Voltage = [");
  Serial.print((float)voltage / 1000000.0);
  Serial.print(" V]\n");  
  
  Serial.print("\n\n");
  delay(1000);
}
