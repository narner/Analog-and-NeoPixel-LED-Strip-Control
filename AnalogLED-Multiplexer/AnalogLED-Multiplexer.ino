  /*******************************************************************************

AnalogLED-Multiplexer.ino - analog LED strips controlled via multiplexer

Modified from example project and tutorial on Bildr: http://bildr.org/2011/02/cd74hc4067-arduino/

Tutorial README on GitHub: https://github.com/narner/Analog-LED-Multiplexing-Example/blob/master/README.md

Code modified by Nick Arner and Ray Brooks

*******************************************************************************/
  
#include <SoftwareSerial.h>

//Mux1 control pins
int s0 = 8;
int s1 = 9;
int s2 = 10;
int s3 = 11;

//Mux2 control pins
int s4 = 12;
int s5 = 13;
int s6 = 14;
int s7 = 15;

//Mux in "SIG" pin
int SIG_pin = 3;

//Voltage vlaue to write to the LEDs (full-on)
int testValue = 255;

void setup(){
  Serial.begin(9600);

  //Set all pins to the "OUTPUT" mode
  pinMode(s0, OUTPUT); 
  pinMode(s1, OUTPUT); 
  pinMode(s2, OUTPUT); 
  pinMode(s3, OUTPUT); 
  pinMode(s4, OUTPUT); 
  pinMode(s5, OUTPUT); 
  pinMode(s6, OUTPUT); 
  pinMode(s7, OUTPUT); 
  pinMode(SIG_pin, OUTPUT);

  digitalWrite(s0, LOW);
  digitalWrite(s1, LOW);
  digitalWrite(s2, LOW);
  digitalWrite(s3, LOW);
  digitalWrite(s4, LOW);
  digitalWrite(s5, LOW);
  digitalWrite(s6, LOW);
  digitalWrite(s7, LOW);
}


void loop(){

  /* Loop through each channel of the mux, and write an "on" value of 255 to turn on the 
  corresponding LED strand */
  for(int i = 0; i <= 19 ; i ++){
    Serial.println(i);
    testValue = 255;
    writeMux(i);    
    delay(500);     
  }
}


int writeMux(int channel){
  //array corresponding to our muxs' control pins
  int controlPin[] = {s0, s1, s2, s3, s4, s5, s6, s7};

  int muxChannel[20][8]={
    //Mux 1 
    {0,0,0,0,0,0,0,0}, //channel 0
    {1,0,0,0,0,0,0,0}, //channel 1
    {0,1,0,0,0,0,0,0}, //channel 2
    {1,1,0,0,0,0,0,0}, //channel 3
    {0,0,1,0,0,0,0,0}, //channel 4
    {1,0,1,0,0,0,0,0}, //channel 5
    {0,1,1,0,0,0,0,0}, //channel 6
    {1,1,1,0,0,0,0,0}, //channel 7
    {0,0,0,1,0,0,0,0}, //channel 8
    {1,0,0,1,0,0,0,0}, //channel 9

    //Max 2
    {1,1,1,1,0,0,0,0}, //channel 0
    {1,1,1,1,1,0,0,0}, //channel 1
    {1,1,1,1,0,1,0,0}, //channel 2
    {1,1,1,1,1,1,0,0}, //channel 3
    {1,1,1,1,0,0,1,0}, //channel 4
    {1,1,1,1,1,0,1,0}, //channel 5
    {1,1,1,1,0,1,1,0}, //channel 6
    {1,1,1,1,1,1,1,0}, //channel 7 
    {1,1,1,1,0,0,0,1}, //channel 8
    {1,1,1,1,1,0,0,1}, //channel 9
  }; 


  //loop through the 8 sig pins
  for(int i = 0; i < 8; i ++){
    digitalWrite(controlPin[i], muxChannel[channel][i]);
    Serial.println("CHANNEL IS ");
    Serial.println(muxChannel[channel][i]);

    Serial.println("Control pin IS ");
    Serial.println(controlPin[i]);
  }

  //write the value at the SIG pin
  analogWrite(SIG_pin, testValue);  
  Serial.println("Test value IS ");
  Serial.println(testValue);

  //return the value
  return 0;
}

