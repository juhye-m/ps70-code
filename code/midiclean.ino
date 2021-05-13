#include <CapacitiveSensor.h>

CapacitiveSensor Sensor = CapacitiveSensor(7,5);  //7 is charge pin.  5 is sense pin.
byte noteON = 144;//note on command

long currentState = 0;//stroage for current state
long lastState = 0;//storage for last state


void setup(){
  Serial.begin(115200);//initialize Serial connection
}

void loop(){
  long sensorValue = Sensor.capacitiveSensor(1000);
  sensorValue = map(sensorValue, 0,300000, 0, 127);
  //map sensor value and go into trackable 
  // put a plateau on a value/upper threshold

  currentState = sensorValue;
  int high = 30;
  int low = 0;
  if (currentState > high  && lastState == low){
    MIDImessage(noteON, 60, 127);//turn note 60 on with 127 velocity
    delay(200);//crude form of button debouncing
  } else if(currentState <= high  && lastState == low){
    MIDImessage(noteON, 62, 0);//turn note 60 off
    delay(10);//crude form of button debouncing
  }
  lastState = currentState;

  Serial.println(sensorValue); // Debugging
  Serial.println(currentState);

}
//send MIDI message
void MIDImessage(byte command, byte data1, byte data2) {
//  Serial.write(command);
//  Serial.write(data1);
//  Serial.write(data2);
}
