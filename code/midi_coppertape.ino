#include <CapacitiveSensor.h>

CapacitiveSensor Sensor = CapacitiveSensor(7,5);  //7 is charge pin.  5 is sense pin.
byte noteON = 144;//note on command

long currentState = 0;//storage for current state
long lastState = 0;//storage for last state

// def function for playing note - input the note value, abstracts so not copy/pasting 12 times
// run sh script to automatically run serial midi python program
// have the port # be a parameter

// notes: 60-71
// if button is pressed once: 

void setup(){
  Serial.begin(115200);//initialize Serial connection
}

void loop(){
  long sensorValue = Sensor.capacitiveSensor(1000);
  sensorValue = map(sensorValue, 0,1000000, 0, 127);
  //map sensor value and go into trackable 
  // put a plateau on a value/upper threshold

  currentState = sensorValue;
  // switch to do "sensor sensitivity"button
  int high = 50;
  int low = 0;
  if (currentState > high  && lastState == low){
    MIDImessage(noteON, 60, 127);//turn note 60 on with 127 velocity
    delay(200);//crude form of button debouncing
  } else if(currentState <= high  && lastState == low){
    MIDImessage(noteON, 60, 0);//turn note 60 off
    delay(10);//crude form of button debouncing
  }
  lastState = currentState;

//  Serial.println(sensorValue); // Debugging
//  Serial.println(currentState);
// check to see if there is a way to write data in a different channel
// different channel/or note on command correspod to diff tape, 
//  would be another parameter , data3 being the channel
// do diff if statements for each one
// multiple note ons?
// check at local hardware store
// look at erik's documentation
// osc protocol --> more updated. midi japan 80s

}
//send MIDI message
void MIDImessage(byte command, byte data1, byte data2, bool on) {
  Serial.write(command);
  Serial.write(data1);
  Serial.write(data2);
}

// default values are note 60 (C3?) and full volume
void sendNote(int noteVal=60, bool VelOpt) {
  long sensorValue = Sensor.capacitiveSensor(1000);      
  // map sensor value and go into trackable 
  // put a plateau on a value/upper threshold
  sensorValue = map(sensorValue, 0,1000000, 0, 127);
  //initialize velocity value
  int veloVal = 0;
  if (VelOpt){
    // need to do sensor stuff -- mapping?
    // high low here?
  }
  else{
    //    if VelOpt is not triggered, just do default full volume
    veloVal = 127; 
  }

  currentState = sensorValue;
  // switch to do "sensor sensitivity"button
  int high = 50;
  int low = 0;
  if (currentState > high  && lastState == low){
    MIDImessage(noteON, noteVal, veloVal);//turn input note on with 127 velocity
    delay(200); // sensor debouncing
  } else if(currentState <= high  && lastState == low){
    MIDImessage(noteON, noteVal, 0);// turn note off
    delay(10); // sensor debouncing
  }
  lastState = currentState;
}

//(in logic -> make output device the midi keyboard instead of the computer)
