#include "Arduino.h"
#include "Camra_control.h"

    
    
    
void Camro::commands()
{
        code_c = false;
        count=Serial.readBytes(command, 10);
        if(count>8){
        number=atoi(&command[5]);
        }else number=atoi(&command[4]);
        code_c=true;
     
}
void Camro::gcod()
{ 
  #ifdef Serial_Debug
        Serial.println(count);
        Serial.println(number);
         Serial.println(command[0]);
         Serial.println(command[1]);
         Serial.println(command[2]);
       
  #endif      
 #ifdef Gcode_enable
      if(code_c==true){
      switch(command[0]){
        case 'G':
            switch(command[3]){
                 case 'Z':
                 #if ENABLED(MOTOR_Z)
                 stpper_z(false);
                 #endif 
                 break; 
                 case 'X':
                 #if ENABLED(MOTOR_X)
                 stpper_x(false);
                 #endif 
                 break; 
               }
          if(count>3){  
           switch(command[1],command[2],command[4]){
           #if ENABLED(MOTOR_Z)
           case ('9','2','Z'):
           stpper_z(true);
           #endif  
           break;
           #if ENABLED(MOTOR_X)
           case ('9','2','X'):
           stpper_x(true);
           #endif  
           break;
           }
         }
      }
    }
    #endif
   }
