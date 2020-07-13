#include "Arduino.h"
#include "595Lib.h"

ShiftReg::ShiftReg(int latch, int clck, int data){

  //estableciendo los pines a sus funciones correspondientes
  latchPin = latch;
  clockPin = clck;
  dataPin = data;

  //declarando como salida los pines establecidos
  pinMode(latchPin, OUTPUT);
  pinMode(clockPin, OUTPUT);
  pinMode(dataPin, OUTPUT);
}

ShiftReg::FanCar(int t){

    for(int i = 0; i < n; i++){
      bitWrite(state, i, 0);
      digitalWrite(latchPin, LOW);
      shiftOut(dataPin, clockPin, MSBFIRST, state);
      digitalWrite(latchPin, HIGH);
      delay(t);
      state = B11111111;
    }

    for(int j = 0; j < n; j++){
      bitWrite(state, j, 0);
      digitalWrite(latchPin, LOW);
      shiftOut(dataPin, clockPin, LSBFIRST, state);
      digitalWrite(latchPin, HIGH);
      delay(t);
      state = B11111111;
    }
    
}

ShiftReg::Chaser(int t, int count){
  unsigned int temp = count;

  while(count > 0){

    for(int i = 0; i < n; i++){
      bitWrite(state, i, 0);
      digitalWrite(latchPin, LOW);
      shiftOut(dataPin, clockPin, MSBFIRST, state);
      digitalWrite(latchPin, HIGH);
      delay(t);
    }

    for(int j = 0; j < n; j++){
      bitWrite(state, j, 1);
      digitalWrite(latchPin, LOW);
      shiftOut(dataPin, clockPin, LSBFIRST, state);
      digitalWrite(latchPin, HIGH);
      delay(t);
    }

    count--;
  }

  count = temp;

  while(count > 0){

    for(int i = 0; i < n; i++){
      bitWrite(state, i, 0);
      digitalWrite(latchPin, LOW);
      shiftOut(dataPin, clockPin, LSBFIRST, state);
      digitalWrite(latchPin, HIGH);
      delay(t);
    }

    for(int j = 0; j < n; j++){
      bitWrite(state, j, 1);
      digitalWrite(latchPin, LOW);
      shiftOut(dataPin, clockPin, MSBFIRST, state);
      digitalWrite(latchPin, HIGH);
      delay(t);
    }

    count--;
  }
}

ShiftReg::KRider(int t){
  unsigned int tempPinCount = n - 1, tempState = B11111111;

  while(tempPinCount != 0){

    for(int i = 0; i < tempPinCount; i++){
      bitWrite(state, i, 0);
      digitalWrite(latchPin, LOW);
      shiftOut(dataPin, clockPin, MSBFIRST, state);
      digitalWrite(latchPin, HIGH);
      delay(t);
      state = tempState;
    }

    bitWrite(tempState, tempPinCount, 0);
    digitalWrite(latchPin, LOW);
    shiftOut(dataPin, clockPin, MSBFIRST, tempState);
    digitalWrite(latchPin, HIGH); 
    tempPinCount--;
  }

  for(int j = 0; j < n; j++){
    bitWrite(tempState, j, 1);
    digitalWrite(latchPin, LOW);
    shiftOut(dataPin, clockPin, LSBFIRST, tempState);
    digitalWrite(latchPin, HIGH);
    delay(t);
  }
}

ShiftReg::BLINK(int t){
  for(int i = 0; i < n; i++){
    bitWrite(state, i, 0);
    digitalWrite(latchPin, LOW);
    shiftOut(dataPin, clockPin, MSBFIRST, state);
    digitalWrite(latchPin, HIGH);
  }

  delay(t);

  for(int j = 0; j < n; j++){
    bitWrite(state, j, 1);
    digitalWrite(latchPin, LOW);
    shiftOut(dataPin, clockPin, LSBFIRST, state);
    digitalWrite(latchPin, HIGH);
  }

  delay(t);
}

/*ShiftReg::Collision(int t){
  int count = n / 2;
  int temp = state;

  for(int i = 0; i < count; i++){
    bitWrite(state, i, 0);
    
    digitalWrite(latchPin, LOW);
    shiftOut(dataPin, clockPin, MSBFIRST, state);
    digitalWrite(latchPin, HIGH);

    digitalWrite(latchPin, LOW);
    shiftOut(dataPin, clockPin, LSBFIRST, state);
    digitalWrite(latchPin, HIGH);

    delay(t);

    state = temp;
  }

  for(int j = count - 1; j >= 0; j--){
    bitWrite(state, j, 1);

    digitalWrite(latchPin, LOW);
    shiftOut(dataPin, clockPin, MSBFIRST, state);
    digitalWrite(latchPin, HIGH);

    digitalWrite(latchPin, LOW);
    shiftOut(dataPin, clockPin, LSBFIRST, state);
    digitalWrite(latchPin, HIGH);

    delay(t);

    state = temp;
  }
}*/
