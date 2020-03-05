#ifndef Camra_control_h
#define Camra_control_h


#include "Arduino.h"
#include "macro.h"
//#define Serial_Debug

#define Gcode_enable
#define MOTOR_Z 1
#define Z_LIMETS 700
#define Z_MAX_STEPS 100
#define MOTOR_X 1
#define X_LIMETS 700
#define X_MAX_STEPS 100
class Camro
{
  public:
    void commands();
    void gcod();
    void sd_store(short location_store[2],bool write_z,bool write_x);
    void init_last_postion();
    void initialization(char z_axsis[5],char x_axsis[5]);
#if ENABLED(MOTOR_Z)
    void stpper_z(bool Set_Home_Z);
#endif
#if ENABLED(MOTOR_X)
    void stpper_x(bool Set_Home_X);
#endif
  private:
    char command[10] ;
    uint8_t count;
    short number;
    bool code_c ;
    uint8_t rev = 2;
    
};
#endif
