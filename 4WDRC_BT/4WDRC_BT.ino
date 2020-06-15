// ESP32 Bluetooth Remote Control Tank
// (@)gausskao
// 2020/05/19 v0.1 created. BlueTooth remote control crated.

#include "BluetoothSerial.h"

BluetoothSerial SerialBT;

#define IN1 32
#define IN2 33
#define IN3 25
#define IN4 26
#define IN5 27
#define IN6 14
#define IN7 19
#define IN8 18

int CAR_STATE=0;
#define CAR_FORWARD 1
#define CAR_BACK    2
#define CAR_STOP    0

void setup() {
  
  Serial.begin(115200);
  SerialBT.begin("ESP32_4WD"); //Bluetooth device name
  Serial.println("The device started, now you can pair it with bluetooth!");
  
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);
  //pinMode(IN5, OUTPUT);
  //pinMode(IN6, OUTPUT);
  //pinMode(IN7, OUTPUT);
  //pinMode(IN8, OUTPUT);
}

void MotorUp()  {
  if (CAR_STATE==CAR_FORWARD)  return;
  CAR_STATE=CAR_FORWARD;
  Serial.println("Motor::Up");
  digitalWrite(IN1, LOW);   
  digitalWrite(IN2, HIGH);
  digitalWrite(IN3, LOW);   
  digitalWrite(IN4, HIGH);
  //digitalWrite(IN5, LOW);   
  //digitalWrite(IN6, HIGH);
  //digitalWrite(IN7, LOW);   
  //digitalWrite(IN8, HIGH);
}

void MotorDown() {
  if (CAR_STATE==CAR_BACK)  return;
  CAR_STATE=CAR_BACK;
  Serial.println("Motor::Down");
  digitalWrite(IN1, HIGH);   
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, HIGH);   
  digitalWrite(IN4, LOW);
  //digitalWrite(IN5, HIGH);   
  //digitalWrite(IN6, LOW);
  //digitalWrite(IN7, HIGH);   
  //digitalWrite(IN8, LOW);
}

void MotorStop() {
   if (CAR_STATE==CAR_STOP)  return;
  CAR_STATE=CAR_STOP;
  Serial.println("Motor::Stop");
  digitalWrite(IN1, LOW);   
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, LOW);   
  digitalWrite(IN4, LOW);
  //digitalWrite(IN5, LOW);
  //digitalWrite(IN6, LOW);   
  //digitalWrite(IN7, LOW);   
  //digitalWrite(IN8, LOW);
}

char cmd = 'S';
char prevCmd = 'A';
int velocity = 0;  
unsigned long timer0 = 2000;  //Stores the time (in millis since execution started)
unsigned long timer1 = 0;  //Stores the time when the last command was received from the phone

void loop() {
  if (Serial.available()) {
    SerialBT.write(Serial.read());
  }
  if (SerialBT.available()) {
    timer1 = millis();  
    prevCmd = cmd;
    cmd = SerialBT.read();
    //Change pin mode only if new command is different from previous.  
    if(cmd!=prevCmd){
    
      Serial.write(cmd);
      switch(cmd) 
      {
      case 'F' : MotorUp();break;
      case 'B' : MotorDown();break;
      case 'X' : MotorStop();break;
      case 'x' : MotorStop();break;
      default : break;
      }
    }
  }
  delay(20);
}
