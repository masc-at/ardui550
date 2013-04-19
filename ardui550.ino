
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


// Include Scheduler since we want to manage multiple tasks.
#include <Scheduler.h>

void setup() {
  Serial.begin(9600);

  // mainloop: system
 
  // loop 1: sensors readout 
  Scheduler.startLoop(sensors_loop);

  // loop 2: communication, bluetooth 
//  Scheduler.startLoop(commmunication_loop);

  // loop 3: ui 
//  Scheduler.startLoop(ui_loop);



}





