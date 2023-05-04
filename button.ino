/*
  Button

  Turns on and off a light emitting diode(LED) connected to digital pin 13,
  when pressing a pushbutton attached to pin 2.

  The circuit:
  - LED attached from pin 13 to ground through 220 ohm resistor
  - pushbutton attached to pin 2 from +5V
  - 10K resistor attached to pin 2 from ground

  - Note: on most Arduinos there is already an LED on the board
    attached to pin 13.

  created 2005
  by DojoDave <http://www.0j0.org>
  modified 30 Aug 2011
  by Tom Igoe

  This example code is in the public domain.

  https://www.arduino.cc/en/Tutorial/BuiltInExamples/Button
*/

// constants won't change. They're used here to set pin numbers:

// variables will change:
    // variable for reading the pushbutton status
#define ROW1 13

#define ROW2 12

#define ROW3 11

#define ROW4 10

#define ROW5 9

#define ROW6 8

#define ROW7 7

#define ROW8 6

#define COL1 5

#define COL2 4

#define COL3 3

#define COL4 A4

#define COL5 A3

#define COL6 A2

#define COL7 A1

#define COL8 A0

const int row[]= {
  ROW1,  ROW2,  ROW3,  ROW4,  ROW5,  ROW6,  ROW7,  ROW8
};
const int col[]= {
  COL1,  COL2,  COL3,  COL4,  COL5,  COL6,  COL7,  COL8
};
byte scan[8][8] = {

{1,0,0,0,0,0,0,0},

{0,1,0,0,0,0,0,0},

{0,0,1,0,0,0,0,0},

{0,0,0,1,0,0,0,0},

{0,0,0,0,1,0,0,0},

{0,0,0,0,0,1,0,0},

{0,0,0,0,0,0,1,0},

{0,0,0,0,0,0,0,1}

};

byte circle[8][8] = {

{1,1,0,0,0,0,1,1},

{1,0,1,1,1,1,0,1},

{0,1,1,1,1,1,1,0},

{0,1,1,1,1,1,1,0},

{0,1,1,1,1,1,1,0},

{0,1,1,1,1,1,1,0},

{1,0,1,1,1,1,0,1},

{1,1,0,0,0,0,1,1}
};

byte heart[8][8] = {
{1,1,1,1,1,1,1,1},
{1,0,0,1,1,0,0,1},
{0,0,0,0,0,0,0,0},
{0,0,0,0,0,0,0,0},
{1,0,0,0,0,0,0,1},
{1,0,0,0,0,0,0,1},
{1,1,0,0,0,0,1,1},
{1,1,1,0,0,1,1,1}
};


byte a[8][8] =          
{
{1,1,1,0,0,1,1,1},
{1,1,0,0,0,0,1,1},
{1,0,0,0,0,0,0,1},
{0,0,0,0,0,0,0,0},
{1,1,1,0,0,1,1,1},
{1,1,1,0,0,1,1,1},
{1,1,1,0,0,1,1,1},
{1,1,1,0,0,1,1,1}
};

/*for (int i=0; i<8; i++){
  for(int j=0; j<8; j++){
    if(scan[i][j] == 0){
      scan[i][j] == 1;
    }
    else{
      scan[i][j] == 0;
    }
  }
}


for(i=0; i<8; i++){
  for(int j=0; j<8; j++){
    if(circle[i][j] == 0){
      circle[i][j] == 1;
    }
    else{
      circle[i][j] == 0;
    }
  }
}
*/
#define BUTTON 2
byte previousState=1, presentState=1, patternNumber=0;

void setup() {

  for (byte i = 0; i <= sizeof(row); i++) {

  pinMode(row[i], OUTPUT);

  }

  for (byte i = 0; i <= sizeof(col); i++) {

  pinMode(col[i], OUTPUT);

  }

  pinMode(2, INPUT_PULLUP);
  
  Serial.begin(9600);
}
int buttonState = 0;
void loop() {
  presentState = digitalRead(BUTTON);
  if(presentState == LOW){
    
  }
  Serial.print(BUTTON);
  //Serial.print(presentState);
  if(presentState ==0 && previousState==1){
    patternNumber++;
    if(patternNumber >2){
      patternNumber = 0;
    }
  }
  if(patternNumber ==0){
    showPattern(circle);
  }
  else if(patternNumber == 1) {
    showPattern(heart);
  }
  else{
    showPattern(a);
  }
}

void showPattern(byte matrix[8][8]){

  for(byte i = 0; i < 8; i++){

    for(byte j = 0; j < 8; j++){

      digitalWrite(row[j], 1 - scan[i][j]);

      digitalWrite(col[j], 1 - matrix[i][j]);

    }

    for(byte j = 0; j < 8; j++){

      digitalWrite(row[j], HIGH);

      digitalWrite(col[j], LOW);

    }

  }

}