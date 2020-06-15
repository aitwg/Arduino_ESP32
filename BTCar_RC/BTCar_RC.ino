// ESP32 Bluetooth Remote Control Tank
// (@)gausskao
// 2020/05/19 v0.1 created. BlueTooth remote control crated.

#include "BluetoothSerial.h"

BluetoothSerial SerialBT;

#define IN1 32
#define IN2 33
#define IN3 25
#define IN4 26

int CAR_STATE=0;
#define CAR_FORWARD 1
#define CAR_BACK    2
#define CAR_LEFT    3
#define CAR_RIGHT   4
#define CAR_STOP    0

#define LED_RED   13
#define LED_BLUE  14

void setup() {
  
  Serial.begin(115200);
  SerialBT.begin("BTCar_01"); //Bluetooth device name
  Serial.println("The device started, now you can pair it with bluetooth!");
  
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);

  pinMode(LED_RED, OUTPUT);
  pinMode(LED_BLUE, OUTPUT);
}

void MotorUp()  {
  if (CAR_STATE==CAR_FORWARD)  return;
  CAR_STATE=CAR_FORWARD;
  Serial.println("Motor::Up");
  digitalWrite(IN1, HIGH);   
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, HIGH);   
  digitalWrite(IN4, LOW);
}

void MotorDown() {
  if (CAR_STATE==CAR_BACK)  return;
  CAR_STATE=CAR_BACK;
  Serial.println("Motor::Down");
  digitalWrite(IN1, LOW);   
  digitalWrite(IN2, HIGH);
  digitalWrite(IN3, LOW);   
  digitalWrite(IN4, HIGH);
}

void MotorLeft() {
  if (CAR_STATE==CAR_LEFT)  return;
  CAR_STATE=CAR_LEFT;
  Serial.println("Motor::Left");
  digitalWrite(IN1, LOW);   
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);

}

void MotorRight() {
  if (CAR_STATE==CAR_RIGHT)  return;
  CAR_STATE=CAR_RIGHT;
  Serial.println("Motor::Right");
  digitalWrite(IN1, LOW);   
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, HIGH);
}

void MotorStop() {
   if (CAR_STATE==CAR_STOP)  return;
  CAR_STATE=CAR_STOP;
  Serial.println("Motor::Stop");
  digitalWrite(IN1, LOW);   
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, LOW);   
  digitalWrite(IN4, LOW);
}

void RedLight(bool status)
{
  return status ? digitalWrite(LED_RED, HIGH) : digitalWrite(LED_RED, LOW);
}

void BlueLight(bool status)
{
  return status ? digitalWrite(LED_BLUE, HIGH) : digitalWrite(LED_BLUE, LOW);
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
      case 'L' : MotorLeft();break;
      case 'R' : MotorRight();break;  
      case 'B' : MotorUp();break;    // Reverse Backward
      case 'F' : MotorDown();break;  // Reverse Forward
      case 'X' : MotorStop();break;
      case 'x' : MotorStop();break;
      case 'W' : BlueLight(true);break;
      case 'w' : BlueLight(false);break;
      case 'U' : RedLight(true);break;
      case 'u' : RedLight(false);break;
      default : break;
      }
    }
  }
  delay(20);
}
