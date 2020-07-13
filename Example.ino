#include "595Lib.h"

int latch = 8, clck = 12, data = 11;
const int tDelay = 300;

ShiftReg myShift = ShiftReg(latch, clck, data);

void setup(){
  //nada por aqui
}

void loop(){
  //myShift.FanCar(tDelay);
  //myShift.Chaser(tDelay, 3);
  //myShift.KRider(tDelay);
  //myShift.BLINK(tDelay);
  //myShift.Collision(tDelay);
}
