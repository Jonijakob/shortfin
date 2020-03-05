#include "Arduino.h"
#include "Camra_control.h"

#include <SPI.h>
#include <SD.h>

File location_save;

char location_read_z[5];
char location_read_x[5];

void Camro::sd_store(short location_store[2],bool write_z,bool write_x){
 /* Serial.println("send Z:")
  Serial.println(location_store[0]);
  Serial.println("send X:");
  Serial.println(location_store[1]);
  */
location_save=SD.open("location.dat", O_WRITE | O_CREAT | O_TRUNC);
             if(write_z==true && write_x==false){
              location_store[1]=atoi(location_read_x);
              } if(write_z==false && write_x==true){
                location_store[0]=atoi(location_read_z);
                }
             location_save.println(location_store[0]);
             location_save.print(location_store[1]);
             location_save.close();
           
}

void Camro::init_last_postion(){
  
  location_save=SD.open("location.dat");
             location_save.read(location_read_z,3);
             location_save.read(location_read_x,3);
             location_save.close();
             initialization(location_read_z,location_read_x);
             /*
             Serial.println("Zaxis:");
             Serial.println(location_read_z);
             Serial.print("Xaxis:");         
             Serial.println(location_read_x);
             */

  }
