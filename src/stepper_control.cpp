#include "Arduino.h"
#include "Camra_control.h"
#include <AccelStepper.h>




short postion[2];
#if ENABLED(MOTOR_Z)
    #define dirPin_Z 13
    #define stepPin_Z 12
    #define motorInterfaceType_Z 1
    AccelStepper stepper_Z = AccelStepper(motorInterfaceType_Z, stepPin_Z, dirPin_Z);
 void Camro::stpper_z(bool Set_Home_Z){
  stepper_Z.setEnablePin(9);
  stepper_Z.setPinsInverted(false,false,true);
  stepper_Z.setMaxSpeed(200);
  stepper_Z.setAcceleration(3000);
     if(Set_Home_Z==false){
     switch(command[1]){
      case '0':
              stepper_Z.enableOutputs();
             if(-Z_LIMETS<number<Z_LIMETS){
              Serial.print("setting the absolute postion Z to:");
              Serial.println(number);
              stepper_Z.moveTo(number*rev);
              stepper_Z.runToPosition();                         
              postion[0]=stepper_Z.currentPosition();
              sd_store(postion,true,false); 
              Serial.print("current postion Z: ");
              Serial.println(postion[0]/rev);                     
           }
       break;
      case '1':
              stepper_Z.enableOutputs();
             if(-Z_MAX_STEPS<number<Z_MAX_STEPS){
              Serial.println("setting the relative postion Z to:");
              Serial.println(number);
              stepper_Z.move(number*rev);
              stepper_Z.runToPosition();
              postion[0]=stepper_Z.currentPosition();       
              sd_store(postion,true,false);
              Serial.println("current postion Z:");
              Serial.println(postion[0]/rev);                     
              }
      break;
      
     }               
     }
         if(Set_Home_Z==true){  
         stepper_Z.setCurrentPosition(0);
         Serial.println("set home");
         }
   stepper_Z.disableOutputs();      
 }
 #endif
 #if ENABLED(MOTOR_X)
    #define dirPin_X 8
    #define stepPin_X 7
    #define motorInterfaceType_X 1
    AccelStepper stepper_X = AccelStepper(motorInterfaceType_X, stepPin_X, dirPin_X);
 void Camro::stpper_x(bool Set_Home_X){
  stepper_X.setEnablePin(6);
  stepper_X.setPinsInverted(false,false,true);
  stepper_X.setMaxSpeed(200);
  stepper_X.setAcceleration(3000);
     if(Set_Home_X==false){
     switch(command[1]){
      case '0':
              stepper_X.enableOutputs();
             if(-X_LIMETS<number<X_LIMETS){
              Serial.print("setting the absolute postion X to:");
              Serial.println(number);
              stepper_X.moveTo(number*rev);
              stepper_X.runToPosition();            
              postion[1]=stepper_X.currentPosition();             
              sd_store(postion,false,true);
              Serial.print("current postion X:");
              Serial.println(postion[1]/rev);                                   
            }
       break;
      case '1':
              stepper_X.enableOutputs();
             if(-X_MAX_STEPS<number<X_MAX_STEPS){
              Serial.print("setting the relative postion X to:");
              Serial.println(number);
              stepper_X.move(number*rev);
              stepper_X.runToPosition();          
              postion[1]=stepper_X.currentPosition();            
              sd_store(postion,false,true);
              Serial.print("current postion X:");
              Serial.println(postion[1]/rev);                         
              }
      break;
      
     }               
     }
         if(Set_Home_X==true){  
         stepper_X.setCurrentPosition(0);
         Serial.println("set home");
         }
   stepper_X.disableOutputs();      
 }
 #endif
 void Camro::initialization(char z_axsis[5],char x_axsis[5]){
             /*Serial.print("Zaxis: ");
             Serial.println(atoi(z_axsis)/rev);
             Serial.println("Xaxis:");         
             Serial.println(atoi(x_axsis)/rev);*/
  stepper_Z.setNewCurrentPosition(atoi(z_axsis));
  stepper_X.setNewCurrentPosition(atoi(x_axsis));
  }
