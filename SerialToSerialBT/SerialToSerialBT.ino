//This example code is in the Public Domain (or CC0 licensed, at your option.)
//By Evandro Copercini - 2018
//
//This example creates a bridge between Serial and Classical Bluetooth (SPP)
//and also demonstrate that SerialBT have the same functionalities of a normal Serial

#include "BluetoothSerial.h"

#if !defined(CONFIG_BT_ENABLED) || !defined(CONFIG_BLUEDROID_ENABLED)
#error Bluetooth is not enabled! Please run `make menuconfig` to and enable it
#endif

BluetoothSerial SerialBT;

void setup() {
  Serial.begin(115200);
  SerialBT.begin("ESP32Dev001"); //Bluetooth device name
  Serial.println("The device started, now you can pair it with bluetooth!");
}

void MotorLeft() {
  Serial.println("Motor::Left");
    
}


void MotorRight() {
  Serial.println("Motor::Right");
}

void MotorUp()  {
  Serial.println("Motor::Up");
}

void MotorDown() {
  Serial.println("Motor::Down");
}

void loop() {
  if (Serial.available()) {
    SerialBT.write(Serial.read());
  }
  if (SerialBT.available()) {
    char cmd = SerialBT.read();
    Serial.write(cmd);
    switch(cmd) 
    {
    case '3' : MotorLeft();break;
    case '4' : MotorRight();break;
    case '1' : MotorUp();break;
    case '2' : MotorDown();break;
    default : break;
    }
  }
  delay(20);
}
