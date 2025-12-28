#include <Arduino.h>
#include <Wire.h>
#include <Adafruit_PWMServoDriver.h>

Adafruit_PWMServoDriver pwm = Adafruit_PWMServoDriver();

enum Note{
  A,
  A_flat,
  B,
  B_flat,
  C,
  D,
  D_flat,
  E,
  E_flat,
  F,
  G,
  G_flat
};

#define CLOSED 150;
#define OPEN 250;

int thumb_0 = CLOSED;
int index_1 = CLOSED;
int middle_2 = CLOSED;
int ring_3 = CLOSED;
int index_4 = CLOSED;
int middle_5 = CLOSED;
int ring_6 = CLOSED;
int pinky_7 = CLOSED;

void set_note(Note n, int octave);

void setup() {
  Serial.begin(9600);
  pwm.begin();
  pwm.setPWMFreq(60);
}

void loop() {
  pwm.setPWM(0, 0, thumb_0);
  pwm.setPWM(1, 0, index_1);
  pwm.setPWM(2, 0, middle_2);
  pwm.setPWM(3, 0, ring_3);
  pwm.setPWM(4, 0, index_4);
  pwm.setPWM(5, 0, middle_5);
  pwm.setPWM(6, 0, ring_6);
  pwm.setPWM(7, 0, pinky_7);
}

void set_note(Note n, int octave){
  // Open for Db5, D5, Eb5
  if ((n == D_flat && octave == 5) || (n == D && octave == 5) || (n == E_flat && octave == 5)){
    thumb_0 = OPEN;
  } else{
    thumb_0 = CLOSED;
  }
  // Open for C5, D5, Eb5, Eb6
  if ((n == C && octave == 5) || (n == D && octave == 5) || (n == E_flat && (octave == 5 || octave == 6))){
    index_1 = OPEN;
  } else{
    index_1 = CLOSED;
  }
  // Open for Bb4, B4, C6, Db6, D6
  if (((n == B_flat || n == B) && octave == 4) || ((n == C || n == D_flat || n == D) && octave == 6)){
    middle_2 = OPEN;
  } else{
    middle_2 = CLOSED;
  }
}
