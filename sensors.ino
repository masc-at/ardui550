
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

  hull352.status_sensors = 0;
  hull352.pos_alt = 379; // graz/austria, should be read from GPS or configuration

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
    hull352.status_sensors |= MAG;
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
    hull352.status_sensors |= ACC;
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
    hull352.status_sensors |= BAROMETER;
  }

//    hull352.status_sensors |= GPS;
//    hull352.status_sensors |= LIGHT;
}

void sensors_loop(){

  Serial.println("sensors: magnetic hmc5883l");
  Serial.println("sensors: acceleration adxl345");


  // read calibrated temperature value in degrees Celsius
  // wait appropriate time for conversion (4.5ms delay)
  // and read calibrated temperature value in degrees Celsius
  barometer.setControl(BMP085_MODE_TEMPERATURE);
  delayMicroseconds(barometer.getMeasureDelayMicroseconds());
  hull352.temperature = barometer.getTemperatureC();


  // request pressure (3x oversampling mode, high detail, 23.5ms delay)
  // read calibrated pressure value in Pascals (Pa)
  barometer.setControl(BMP085_MODE_PRESSURE_3);
  delayMicroseconds(barometer.getMeasureDelayMicroseconds());
  hull352.pressure_abs = barometer.getPressure();
  // international barometric formula
  hull352.pressure_rel = hull352.pressure_abs / pow((1-(0.0065 * hull352.pos_alt/288.15)), 5.255);


#ifdef DEBUG

  Serial.print("sensors: barometer bmp085 ");
  if ( !(hull352.user_units & U_PRESSURE) )
  {
    Serial.print(hull352.pressure_abs);
    Serial.print(" Pa abs  ");
  }
  else
  {
    Serial.print(hull352.pressure_rel);
    Serial.print(" Pa rel  ");
  }


  if ( !(hull352.user_units & U_TEMPERATURE) )
  {
    Serial.print(hull352.temperature);
    Serial.println(" C ");
  }
  else
  {
    float temperature_f = hull352.temperature * 1.8 + 32;
    Serial.print(temperature_f);
    Serial.println(" F ");
  }


  Serial.print("status: ");
  if (hull352.status_sensors == 0)
    Serial.println("ok.");
  else
    Serial.println(hull352.status_sensors);

#endif

  delay(1000);

}



