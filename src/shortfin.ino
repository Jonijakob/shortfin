#include "Camra_control.h"
#include <SPI.h>
#include <SD.h>


Camro cam;
void setup() {
  Serial.begin(115200);
  pinMode(53, OUTPUT);
  if (!SD.begin(53)) {
    Serial.println("initialization failed!");
    return;
  }
  cam.init_last_postion();
  }
void loop() { 
  if (Serial.available() > 0) {
  cam.commands();
  cam.gcod();
 
  }
}
  
 
  


  
