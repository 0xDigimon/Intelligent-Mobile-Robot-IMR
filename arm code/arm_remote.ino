/*
   -- New project --
   
   This source code of graphical user interface 
   has been generated automatically by RemoteXY editor.
   To compile this code using RemoteXY library 3.1.8 or later version 
   download by link http://remotexy.com/en/library/
   To connect using RemoteXY mobile app by link http://remotexy.com/en/download/                   
     - for ANDROID 4.11.1 or later version;
     - for iOS 1.9.1 or later version;
    
   This source code is free software; you can redistribute it and/or
   modify it under the terms of the GNU Lesser General Public
   License as published by the Free Software Foundation; either
   version 2.1 of the License, or (at your option) any later version.    
*/

//////////////////////////////////////////////
//        RemoteXY include library          //
//////////////////////////////////////////////

// RemoteXY select connection mode and include library 
#define REMOTEXY_MODE__ESP32CORE_WIFI_POINT
#include <WiFi.h>

#include <RemoteXY.h>

// RemoteXY connection settings 
#define REMOTEXY_WIFI_SSID "RemoteXY"
#define REMOTEXY_WIFI_PASSWORD "12345678"
#define REMOTEXY_SERVER_PORT 6377


// RemoteXY configurate  
#pragma pack(push, 1)
uint8_t RemoteXY_CONF[] =   { 255,5,0,0,0,38,0,16,31,0,5,1,63,8,30,30,2,26,31,5,
  1,14,8,30,30,2,26,31,2,0,43,41,22,11,2,26,31,31,79,78,
  0,79,70,70,0 };/*45 bytes
  { 255,7,0,0,0,92,0,16,31,0,5,1,66,7,30,30,2,26,31,5,
  4,12,8,30,30,2,26,31,2,1,68,42,22,11,2,26,31,31,83,99,
  101,110,97,114,105,111,0,79,70,70,0,10,48,20,42,15,15,133,26,31,
  111,107,95,115,97,118,101,0,31,115,97,118,101,95,112,111,115,0,10,48,
  46,29,15,15,133,26,31,111,112,101,110,0,31,99,108,111,115,101,0 };*/
  
// this structure defines all the variables and events of your control interface 
struct {

    // input variables
  int8_t joystick_1_x; // from -100 to 100  
  int8_t joystick_1_y; // from -100 to 100  
  int8_t joystick_2_x; // from -100 to 100  
  int8_t joystick_2_y; // from -100 to 100  
  uint8_t switch_1; // =1 if switch ON and =0 if OFF 
 // uint8_t switch_2; // =1 if switch ON and =0 if OFF 
  uint8_t switch_3; // =1 if switch ON and =0 if OFF 
  uint8_t pushSwitch_1; // =1 if state is ON, else =0 
  uint8_t pushSwitch_2; // =1 if state is ON, else =0 
    // other variable
  uint8_t connect_flag;  // =1 if wire connected, else =0 

} RemoteXY;
#pragma pack(pop)

/////////////////////////////////////////////
//           END RemoteXY include          //
/////////////////////////////////////////////
#include <ESP32Servo.h>

  int SERVO_B_Center = 1500;
  int SERVO_SH_Center = 1500;
  int SERVO_E_Center = 1500;
  int SERVO_W_Center = 1500;
  
  Servo servoB;
  Servo servoSH1;
  Servo servoSH2;
  Servo servoE;
  Servo servoW;
  Servo servoG;
int count=0;
 bool save=false;
 int c=0;
 int arr[5];
void setup() 
{
  RemoteXY_Init (); 
  servoB.attach(4);
  servoSH1.attach(18);
  servoSH2.attach(19);
  servoE.attach(21);
  servoW.attach(22);
  servoG.attach(23);
  Serial.begin(115200);
  delay(10);
    for (int pos = 0; pos <=90; pos += 1) { // goes from 0 degrees to 180 degrees
    // in steps of 1 degree
 
   servoB.write(pos);
   servoSH1.write(pos);
   servoSH2.write(180-pos);
   servoE.write(pos);
   servoW.write(pos);
   servoG.write(pos+30);// tell servo to go to position in variable 'pos'
    delay(15);             // waits 15ms for the servo to reach the position
  }
   
  
  // TODO you setup code
  
}

void loop() 
{ 
  RemoteXY_Handler ();
  
  int B= map((RemoteXY.joystick_1_x*10 + SERVO_B_Center),500,2500,0,180);
   servoB.write(B);
     int SH= map((RemoteXY.joystick_1_y*10 + SERVO_SH_Center),500,2500,0,180);
   servoSH1.write(SH);
   servoSH2.write(180-SH);
  int E= map((RemoteXY.joystick_2_x*10 + SERVO_E_Center),500,2500,0,180);
   servoE.write(E);
     int W= map((RemoteXY.joystick_2_y*10 + SERVO_W_Center),500,2500,0,180);
   servoW.write(W);
     bool G=(RemoteXY.switch_1);
     Serial.println(G);

     if(G==true){
      servoG.write(5);}
      else{
        servoG.write(120);
        }
   
  /*save=(RemoteXY.pushSwitch_1);
   
   if(save==true){
     c=1;
   }
     if(save==false&&c==1){
       count=count+1;
      int index=count*4;
       c=0;
      }
      if(count==1){
   arr[4]={B,SH,W,E};
   }
  // TODO you loop code
  // use the RemoteXY structure for data transfer
  // do not call delay() 
Serial.print((RemoteXY.joystick_1_x*10 + SERVO_B_Center));
Serial.print("    ");
Serial.println(count);*/

}
