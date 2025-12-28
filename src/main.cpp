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
#define HALF 200;
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
  // thumb_0 open for Db5, D5, Eb5
  if (((n == D_flat || n == D || n == E_flat) && octave == 5)){
    thumb_0 = OPEN;
  // thumb_0 half-closed for notes above Eb5
  } else if (((n != C && n != D_flat && n != D && n != E_flat) && octave == 5) || octave == 6){
    thumb_0 = HALF;
  } else{
    thumb_0 = CLOSED;
  }
  // index_1 open for C5, D5, Eb5, Eb6
  if (((n == C || n == D) && octave == 5) || (n == E_flat && (octave == 5 || octave == 6))){
    index_1 = OPEN;
  } else{
    index_1 = CLOSED;
  }
  // middle_2 open for Bb4, B4, C6, Db6, D6
  if (((n == B_flat || n == B) && octave == 4) || ((n == C || n == D_flat || n == D) && octave == 6)){
    middle_2 = OPEN;
  } else{
    middle_2 = CLOSED;
  }
  // ring_3 open for Ab4, A4, B4, C5, Db5, D5, Ab5, A5, Bb5, B5, C6 
  if (((n == A_flat || n == A || n == B) && octave == 4) || ((n == C || n == D_flat || n == D || n == A_flat || n == A || n == B_flat || n == B) && octave == 5) || (n == C && octave == 6)){
    ring_3 = OPEN;
  } else{
    ring_3 = CLOSED;
  }
  // index_4 open for Gb4, G4, A4, B4, C5, Db5, D5, Gb5, G5, A5, Bb5, Eb6
    if (((n == G_flat || n == G || n == A || n == B) && octave == 4) || ((n == C || n == D_flat || n == D || n == G_flat || n == G || n == A || n == B_flat) && octave == 5) || (n == E_flat && octave == 6)){
    index_4 = OPEN;
  } else{
    index_4 = CLOSED;
  }
  // middle_5 open for F4, G4, A4, Bb4, B4, C5, Db5, D5, F5, G5, Ab5, A5, Db6, D6
      if (((n == F || n == G || n == A || n == B_flat || n == B) && octave == 4) || ((n == C || n == D_flat || n == D || n == F || n == G || n == A_flat || n == A) && octave == 5) || ((n == D_flat || n == D) && octave == 6)){
    middle_5 = OPEN;
  } else{
    middle_5 = CLOSED;
  }
  // ring_6 closed for C4, Db4, D4, F4, Gb4, Eb5, F5, Bb5, Db6, D6, Eb6
  if (((n == C || n == D_flat || n == D || n == B) && octave == 4) || ((n == C || n == D_flat || n == D || n == G_flat || n == G || n == A || n == B_flat) && octave == 5) || (n == E_flat && octave == 6)){
    ring_6 = CLOSED;
  // ring_6 half-closed for Eb4, Ab4
  } else if ((n == E_flat || n ==  A_flat) && octave == 4){
    ring_6 = HALF;
  } else{
    ring_6 = OPEN;
  }
  // pinky_7 closed for C4, F4, Db6, D6
  if (((n == C || n == F) && octave == 4) || ((n == D_flat || n == D) && octave == 6)){
    pinky_7 = CLOSED;
  // pinky_7 half-closed for Db4, Bb5
  } else if ((n == D_flat && octave == 4) || (n == B_flat && octave == 5)){
    pinky_7 = HALF;
  } else{
    pinky_7 = OPEN;
  }
}
