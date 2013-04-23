
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

#include "sensors.h"
#include "HMC5883L.h"
#include "ADXL345.h"
#include "BMP085.h"


// class default I2C address is 0x1E
// specific I2C addresses may be passed as a parameter here
// this device only supports one I2C address (0x1E)

HMC5883L mag;


// class default I2C address is 0x53
// specific I2C addresses may be passed as a parameter here
// ALT low = 0x53 (default for SparkFun 6DOF board)
// ALT high = 0x1D

ADXL345 accel;


// class default I2C address is 0x77
// specific I2C addresses may be passed as a parameter here
// (though the BMP085 supports only one address)

BMP085 barometer;




void sensors_init(){

  // init compass
  Serial.print("sensors: init magnetic sensor HMC5883L... ");
  mag.initialize();
  if (mag.testConnection())
  { 
    Serial.println(" connection successful.");
  }
  else
  {
    Serial.println(" connection failed.");
  }

  // init acceleration sensor / pan/tilt compensation
  Serial.print("sensors: init acceleration sensor ADXL345... ");
  accel.initialize();
  if (accel.testConnection())
  { 
    Serial.println(" connection successful.");
  }
  else
  {
    Serial.println(" connection failed.");
  }

  // init barometer
  Serial.print("sensors: init pressure sensor BMP345... ");
  barometer.initialize();
  if (barometer.testConnection())
  { 
    Serial.println(" connection successful.");
  }
  else
  {
    Serial.println(" connection failed.");
  }

}

void sensors_loop(){

  Serial.println("sensors: magnetic hmc5883l");
  Serial.println("sensors: acceleration adxl345");
  Serial.println("sensors: barometer bmp085");

}



