
/**********************************************************************************
* ardui550 is free software: you can redistribute it and/or modify
* it under the terms of the GNU General Public License as published by
* the Free Software Foundation, either version 3 of the License, or
* (at your option) any later version.
*
* ardui550 is distributed in the hope that it will be useful,
* but WITHOUT ANY WARRANTY; without even the implied warranty of
* MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
* GNU General Public License for more details. Please see /gpl-3.0.txt
*
* website https://github.com/masc-at/ardui550
* written by martin schneebacher thorsten zerha 
***********************************************************************************/


#ifndef ardui550_h
#define ardui550_h

#if defined(ARDUINO) && ARDUINO >= 100
#include "Arduino.h"
#else
#include "WProgram.h"
#endif

#define DEBUG 1


// status bits in status_sensors
#define MAG        1
#define ACC        2
#define BAROMETER  4
#define GPS        8
#define ANEMOMETER 16
#define LIGHT      32

// user units
#define U_TEMPERATURE 1   // 0: °C  - 1: °F
#define U_PRESSURE    2   // 0: absolute - 1: relative


struct ardui550
{
  int16_t pos_lat;
  int16_t pos_long;
  int16_t pos_alt;

  float temperature;
  float pressure_abs;
  float pressure_rel;

  int16_t pitch;
  int16_t roll;
  int16_t yaw;

  uint16_t SPD;  // boat speed
  uint16_t SOG;  // speed over ground
  uint16_t COG;  // course over ground
  uint16_t VMG;  // velocity made good

  uint16_t AWA;  // apparent wind angle
  uint16_t AWS;  // apparent wind speed
  uint16_t TWA;  // true wind angle
  uint16_t TWS;  // true wind speed
  
  byte status_sensors; 
  byte user_units; 
  int8_t timezone;

};



#endif

