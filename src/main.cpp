#include <Arduino.h>
#include <Wire.h>
#include <Adafruit_PWMServoDriver.h>

Adafruit_PWMServoDriver pwm = Adafruit_PWMServoDriver();

#define CLOSED 180;
#define OPEN 210;
#define CLOSED_R 240;
#define OPEN_R 220;

int thumb_0 = CLOSED;
int index_1 = CLOSED;
int middle_2 = CLOSED;
int ring_3 = CLOSED;
int pinky_4 = CLOSED;
int pointer_5 = CLOSED;
int middle_6 = CLOSED;
int ring_7 = CLOSED;
int pinky_8 = CLOSED;

void set_note(int n);
void open_all();
void close_all();
void move_motors();

#define song_size 57
int timer[song_size] = {112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112};
int notes[song_size] = {76, 79, 76, 72, 75, 79, 75, 71, 76, 79, 76, 72, 75, 79, 75, 71, 76, 79, 76, 72, 75, 79, 75, 71, 76, 79, 76, 72, 75, 79, 75, 71, 79, 74, 71, 67, 71, 74, 79, 83, 86, 83, 78, 74, 78, 83, 86, 90, 91, 86, 83, 79, 78, 79, 83, 86, 91};
int iter = 0;

void setup() {
  Serial.begin(9600);
  pwm.begin();
  pwm.setPWMFreq(50);
}

void loop() {
  set_note(notes[iter]);
  // open_all();
  move_motors();

  if (timer[iter] != 0){
    delay((int)(timer[iter]));
  } else{
    delay(1000);
  }
  iter++;
  if (iter > song_size - 1){
    iter = 0;
    delay(1000);
  }
}

void set_note(int n){
  // thumb_0 open for C5, Db5, C6, Db6, G6, Ab6, C7
  if (n == 72 || n == 73 || n == 84 || n == 85 || n == 91 || n == 92 || n == 96){
    thumb_0 = OPEN_R;
  } else{
    thumb_0 = CLOSED_R;
  }
  // index_1 open for Db5, D5, Db6, D6, Ab6, A6, Bb6
  if (n == 73 || n == 74 || n == 85 || n == 86 || n == 92 || n == 93 || n == 94){
    index_1 = OPEN;
  } else{
    index_1 = CLOSED;
  }
  // middle_2 open for Bb4, B4, C5, Db5, Bb5, B5, C6, Db6, F6, Gb6, Bb6, B6 
  if (n == 70 || n == 71 || n == 72 || n == 73 || n == 82 || n == 83 || n == 84 || n == 85 || n == 89 || n == 90 || n == 94 || n == 95){
    middle_2 = OPEN;
  } else{
    middle_2 = CLOSED;
  }
  // ring_3 open for A4, Bb4, B4, C5, Db5, A5, Bb5, B5, C6, Db6, E6, A6, Bb6
  if (n == 69 || n == 70 || n == 71 || n == 72 || n == 73 || n == 81 || n == 82 || n == 83 || n == 84 || n == 85 || n == 88 || n == 93 || n == 94){
    ring_3 = OPEN;
  } else{
    ring_3 = CLOSED;
  }
  // pinky_4 closed for Ab4, Ab5, Eb6, Ab6, C7
    if (n == 68 || n == 80 || n == 87 || n == 92 || n == 96){
    pinky_4 = CLOSED;
  } else{
    pinky_4 = OPEN;
  }
  // pointer_5 closed for D4, Eb4, E4, F4, Bb4, D5, Eb5, E5, F5, Bb5, Eb6, E6, F6, A6, Bb6, C7
      if (n == 62 || n == 63 || n == 64 || n == 65 || n == 70 || n == 74 || n == 75 || n == 76 || n == 77 || n == 82 || n == 87 || n == 88 || n == 89 || n == 93 || n == 94 || n == 96){
    pointer_5 = CLOSED;
  } else{
    pointer_5 = OPEN;
  }
  // middle_6 closed for D4, Eb4, E4, D5, Eb5, E5, Eb6, E6
  if (n == 62 || n == 63 || n == 64 || n == 74 || n == 75 || n == 76 || n == 87 || n == 88){
    middle_6 = CLOSED;
  } else{
    middle_6 = OPEN;
  }
  // ring_7 closed for D4, Eb4, Gb4, D5, Eb5, Gb5, Eb6, Gb6
  if (n == 62 || n == 63 || n == 66 || n == 74 || n == 75 || n == 78 || n == 87 || n == 90){
    ring_7 = CLOSED;
  }  else{
    ring_7 = OPEN;
  }
  // pinky_8 open for D4, D5, C7
  if (n == 62 || n == 74 || n == 96){
    pinky_8 = OPEN_R;
  } else{
    pinky_8 = CLOSED_R;
  }
}

void open_all(){
  thumb_0 = OPEN_R;
  index_1 = OPEN;
  middle_2 = OPEN;
  ring_3 = OPEN;
  pinky_4 = OPEN;
  pointer_5 = OPEN;
  middle_6 = OPEN;
  ring_7 = OPEN;
  pinky_8 = OPEN_R;
}

void close_all(){
  thumb_0 = CLOSED_R;
  index_1 = CLOSED;
  middle_2 = CLOSED;
  ring_3 = CLOSED;
  pinky_4 = CLOSED;
  pointer_5 = CLOSED;
  middle_6 = CLOSED;
  ring_7 = CLOSED;
  pinky_8 = CLOSED_R;
}

void move_motors(){
  pwm.setPWM(0, 0, thumb_0 - 15);
  pwm.setPWM(1, 0, index_1 + 20);
  pwm.setPWM(2, 0, middle_2 - 20);
  pwm.setPWM(4, 0, ring_3 - 40);
  pwm.setPWM(3, 0, pinky_4 - 40);
  pwm.setPWM(5, 0, pointer_5 - 70);
  pwm.setPWM(6, 0, middle_6 - 30);
  pwm.setPWM(7, 0, ring_7 + 50);
  pwm.setPWM(8, 0, pinky_8 + 10);
}
