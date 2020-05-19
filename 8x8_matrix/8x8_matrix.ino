#define DIN     12
#define CS      10
#define CLK     11

#define DELAY   500
#define DEVICES 1

#include <LedControl.h>


LedControl lc = LedControl(DIN, CLK, CS, DEVICES);
byte happy[8]= {B00111100,B01000010,B10100101,B10000001,B10100101,B10011001,B01000010,B00111100};
byte sad[8]= {B00111100,B01000010,B10100101,B10000001,B10011001,B10100101,B01000010,B00111100};
byte neutral[8]={B00111100, B01000010,B10100101,B10000001,B10111101,B10000001,B01000010,B00111100};

void setup() {
  /*
   The MAX72XX is in power-saving mode on startup,
   we have to do a wakeup call
   */
  lc.shutdown(0,false);
  /* Set the brightness to a medium values */
  lc.setIntensity(0,8);
  /* and clear the display */
  lc.clearDisplay(0);

  Serial.begin(9600);
  Serial.println("Program 8x8 matrix started");
}

void loop() {
  // Display happy face
  for (int i = 0; i < 8; i++) {
    lc.setRow(0,i,happy[i]);
  }
  delay(DELAY);
  
  // Display neutral face
  for (int i = 0; i < 8; i++) {
    lc.setRow(0,i,neutral[i]);
  }
  
  delay(DELAY);
  // Display sad face
  for (int i = 0; i < 8; i++) {
    lc.setRow(0,i,sad[i]);
  }
  delay(DELAY);
}
