#include <ESP32Servo.h>
#include "BluetoothSerial.h"
#if !defined(CONFIG_BT_ENABLED) || !defined(CONFIG_BLUEDROID_ENABLED)
#error Bluetooth is not enabled! Please run `make menuconfig` to and enable it
#endif

#if !defined(CONFIG_BT_SPP_ENABLED)
#error Serial Bluetooth not available or not enabled. It is only available for the ESP32 chip.
#endif
BluetoothSerial Bluetooth; 

int bluedata,bluesignal=0;
Servo servo1;
Servo servo2;
Servo servo3;
Servo servo4;
Servo servo5;
Servo servo6;


// right
#define in11 32
#define in12 33
#define in13 25
#define in14 26
#define en11 17
#define en12 16

// left
#define in21 23
#define in22 27
#define in23 14
#define in24 13
#define en21 17
#define en22 16

int servo1PPos,servo2PPos,servo3PPos,servo4PPos,servo5PPos,servo6PPos;
int speedDelay = 20;
int wheelSpeed;
void setup() {
  pinMode(in11, OUTPUT);
  pinMode(in12, OUTPUT);
  pinMode(in13, OUTPUT);
  pinMode(in14, OUTPUT);
  pinMode(in21, OUTPUT);
  pinMode(in22, OUTPUT);
  pinMode(in23, OUTPUT);
  pinMode(in24, OUTPUT);
  pinMode(22, OUTPUT); //enable R,L A
  pinMode(12, OUTPUT); // enable R,L B
  digitalWrite(22,HIGH);
  digitalWrite(12,HIGH);
  Bluetooth.begin(38400); // Default baud rate of the Bluetooth module
  Bluetooth.setTimeout(5);
  delay(20);
  Serial.begin(38400);

  servo1.attach(15,500, 2500); // base
  servo1PPos = 75;
  servo1.write(servo1PPos);
  servo2.attach(2,500, 2500); // left
  servo2PPos = 75;
  servo2.write(servo2PPos);
  servo3.attach(22,500, 2500); // right
  servo3PPos = 75;
  servo3.write(servo3PPos);
  servo4.attach(4,500, 2500); // الكوع
  servo4PPos = 125;
  servo4.write(servo4PPos);
  servo5.attach(21,500, 2500); // المرفق
  servo5PPos = 120;
  servo5.write(servo5PPos);
  servo6.attach(19,500, 2500); // الايد
  servo6PPos = 25;
  servo6.write(servo6PPos);

}

void loop() {
  if (Bluetooth.available() > 0)
  {
      bluedata = Bluetooth.read();
      Serial.println(bluedata);
      if (bluedata >= 30 && bluedata < 100) {
        wheelSpeed = map(bluedata,30,99,30,255);
        Serial.println(wheelSpeed);
      }
      if (bluedata == 0) {
        bluesignal = 0;
      }
      
      else if (bluedata == 2) {
        bluesignal = 2;
      }
      
      else if (bluedata == 4) {
        bluesignal = 4;
      }
      else if (bluedata == 5) {
        bluesignal = 5;
      }
      
      else if (bluedata == 7) {
        bluesignal = 7;
      }
      
      else if (bluedata == 9) {
        bluesignal = 9;
      }
      else if (bluedata == 10) {
        bluesignal = 10;
      }
      else if (bluedata == 27) {
        bluesignal = 27;
      }
      else if (bluedata == 26) {
        bluesignal = 26;
      }
      else if (bluedata == 24) {
        bluesignal = 24;
      }
      else if (bluedata == 25) {
        bluesignal = 25;
      }
      else if (bluedata == 22) {
        bluesignal = 22;
      }
      else if (bluedata == 23) {
        bluesignal = 23;
      }
      else if (bluedata == 20) {
        bluesignal = 20;
      }
      else if (bluedata == 21) {
        bluesignal = 21;
      }
      else if (bluedata == 16) {
        bluesignal = 16;
      }
      else if (bluedata == 17) {
        bluesignal = 17;
      }
      
    
    
      if (bluesignal == 2) {
        forward();
        Serial.println("FORWARD");
      }
      else if (bluesignal == 7) {
        back();
        Serial.println("BACK");
      }
      else if (bluesignal == 5) {
        right();
        Serial.println("RIGHT");
      }
      else if (bluesignal == 4) {
        left();
        Serial.println("LEFT");
      }
      else if (bluesignal == 10) {
        rotateleft();
        Serial.println("ROTATE RIGHT");
      }
      else if (bluesignal == 9) {
        rotateright();
        Serial.println("ROTATE LEFT");
      }
      if (bluesignal == 0) {
        stop();
        Serial.println("STOP");
      }
      //base
      while (bluesignal == 16) {
        if (Bluetooth.available() > 0) {
          bluesignal = Bluetooth.read();
        }
        servo1.write(servo1PPos);
        servo1PPos--;
        delay(speedDelay);
      }
      while (bluesignal == 17) {
        if (Bluetooth.available() > 0) {
          bluesignal = Bluetooth.read();
        }
        servo1.write(servo1PPos);
        servo1PPos++;
        delay(speedDelay);
      }
      // left right 
      while (bluesignal == 20) {
        if (Bluetooth.available() > 0) {
          bluesignal = Bluetooth.read();
        }
        servo2.write(servo2PPos);
        servo3.write(servo2PPos);
        servo2PPos--;
        delay(speedDelay);
      }
      while (bluesignal == 21) {
        if (Bluetooth.available() > 0) {
          bluesignal = Bluetooth.read();
        }
        servo2.write(servo2PPos);
        servo3.write(servo2PPos);

        servo2PPos++;
        delay(speedDelay);
      }
      //الكوع
      while (bluesignal == 22) {
        if (Bluetooth.available() > 0) {
          bluesignal = Bluetooth.read();
        }
        servo4.write(servo4PPos);
        servo4PPos--;
        delay(speedDelay);
      }
      while (bluesignal == 23) {
        if (Bluetooth.available() > 0) {
          bluesignal = Bluetooth.read();
        }
        servo4.write(servo4PPos);
        servo4PPos++;
        delay(speedDelay);
      }
      // المرفق 
      while (bluesignal == 24) {
        if (Bluetooth.available() > 0) {
          bluesignal = Bluetooth.read();
        }
        servo5.write(servo5PPos);
        servo5PPos--;
        delay(speedDelay);
      }
      while (bluesignal == 25) {
        if (Bluetooth.available() > 0) {
          bluesignal = Bluetooth.read();
        }
        servo5.write(servo5PPos);
        servo5PPos++;
        delay(speedDelay);
      }
      // الايد
      while (bluesignal == 26) {
        if (Bluetooth.available() > 0) {
          bluesignal = Bluetooth.read();
        }
        servo6.write(servo6PPos);
        servo6PPos--;
        delay(speedDelay);
      }
      while (bluesignal == 27) {
      if (Bluetooth.available() > 0) {
        bluesignal = Bluetooth.read();
      }
      servo6.write(servo6PPos);
      servo6PPos++;
      delay(speedDelay);
    }
      

  }
}
void forward(){
  // forward
    // right
  analogWrite(16,wheelSpeed);
  digitalWrite(in11, wheelSpeed);
  digitalWrite(in12, LOW);
  digitalWrite(in13, LOW);
  digitalWrite(in14, wheelSpeed);
// left
  analogWrite(17,wheelSpeed);
  digitalWrite(in21, wheelSpeed);
  digitalWrite(in22, LOW);
  digitalWrite(in23, LOW);
  digitalWrite(in24, wheelSpeed);
}
void stop(){
    // STOP
  // right
  digitalWrite(in11, LOW);
  digitalWrite(in12, LOW);
  digitalWrite(in13, LOW);
  digitalWrite(in14, LOW);
// left
  digitalWrite(in21, LOW);
  digitalWrite(in22, LOW);
  digitalWrite(in23, LOW);
  digitalWrite(in24, LOW);
}
void rotateright(){
  // rotate Right
  // right
  analogWrite(16,wheelSpeed);
  analogWrite(17,wheelSpeed);
  digitalWrite(in11, wheelSpeed);
  digitalWrite(in12, LOW);
  digitalWrite(in13, LOW);
  digitalWrite(in14, wheelSpeed);
  // left
  digitalWrite(in21, LOW);
  digitalWrite(in22, wheelSpeed);
  digitalWrite(in23, wheelSpeed);
  digitalWrite(in24, LOW);
}
void rotateleft(){
  // rotate Right
  // right
  analogWrite(16,wheelSpeed);
  analogWrite(17,wheelSpeed);
  digitalWrite(in11, LOW);
  digitalWrite(in12, wheelSpeed);
  digitalWrite(in13, wheelSpeed);
  digitalWrite(in14, LOW);
  // left
  digitalWrite(in21, wheelSpeed);
  digitalWrite(in22, LOW);
  digitalWrite(in23, LOW);
  digitalWrite(in24, wheelSpeed);
}
void back(){
  // back
  // right
  analogWrite(16,wheelSpeed);
  analogWrite(17,wheelSpeed);
  digitalWrite(in11, LOW);
  digitalWrite(in12, wheelSpeed);
  digitalWrite(in13, wheelSpeed);
  digitalWrite(in14, LOW);
// left
  digitalWrite(in21, LOW);
  digitalWrite(in22, wheelSpeed);
  digitalWrite(in23, wheelSpeed);
  digitalWrite(in24, LOW);
}
void left(){
    // left
  // right
  analogWrite(16,wheelSpeed);
  analogWrite(17,wheelSpeed);
  digitalWrite(in11, wheelSpeed);
  digitalWrite(in12, LOW);
  digitalWrite(in13, LOW);
  digitalWrite(in14, wheelSpeed);
// left
  digitalWrite(in21, LOW);
  digitalWrite(in22, LOW);
  digitalWrite(in23, LOW);
  digitalWrite(in24, LOW);
  
}
void right(){
  // Right
  // right
  analogWrite(16,wheelSpeed);
  analogWrite(17,wheelSpeed);
  digitalWrite(in11, LOW);
  digitalWrite(in12, LOW);
  digitalWrite(in13, LOW);
  digitalWrite(in14, LOW);
// left
  digitalWrite(in21, wheelSpeed);
  digitalWrite(in22, LOW);
  digitalWrite(in23, LOW);
  digitalWrite(in24, wheelSpeed);
}
