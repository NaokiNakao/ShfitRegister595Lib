#include "Arduino.h"

class ShiftReg {

  public:

  ShiftReg(int latch, int clck, int data);   //declarando pines de salida
  FanCar(int t);   //secuencia 'carro fantastico'
  Chaser(int t, int count);   //secuencia 'Led Chaser'
  KRider(int t);   //secuencia 'Knight Rider'
  BLINK(int t);
  //Collision(int t);

  private:

     int latchPin, clockPin, dataPin;   //pines que se usaran para shift en todo el codigo
     byte state = B11111111;   //estado en el que inicia cada secuencia
     int n = 8;   //numero de pines que tine cada Shift Register
  
};
