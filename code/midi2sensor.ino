#include <CapacitiveSensor.h>

CapacitiveSensor Sensor = CapacitiveSensor(7,5);  //7 is charge pin.  5 is sense pin.
CapacitiveSensor Sensor2 = CapacitiveSensor(7,2);  //7 is charge pin.  5 is sense pin.
byte noteON = 144;//note on command

long currentState = 0;//stroage for current state
long lastState = 0;//storage for last state
long currentState2 = 0;//stroage for current state
long lastState2 = 0;//storage for last state


void setup(){
  Serial.begin(115200);//initialize Serial connection
}

void loop(){
  long sensorValue = Sensor.capacitiveSensor(1000);
  sensorValue = map(sensorValue, 0,300000, 0, 127);
  long sensorValue2 = Sensor2.capacitiveSensor(1000);
  sensorValue2 = map(sensorValue2, 0,300000, 0, 127);
  //map sensor value and go into trackable 
  // put a plateau on a value/upper threshold

  currentState = sensorValue;
  currentState2 = sensorValue2;
  int high = 20;
  int low = 0;
//   int high = 5;
//  int low = 0;
  if (currentState > high  && lastState == low){
//      if (currentState > high  && lastState < high){
    MIDImessage(noteON, 60, 127, 0, 0);//turn note 60 on with 127 velocity
    delay(100);//crude form of button debouncing
  } else if(currentState <= high  && lastState == low){
    MIDImessage(noteON, 60, 0, 0, 0);//turn note 60 off
    delay(10);//crude form of button debouncing
  }
  lastState = currentState;
  if (currentState2 > high  && lastState2 == low){
    MIDImessage(noteON, 0, 0, 62, 127);//turn note 60 on with 127 velocity
    delay(100);//crude form of button debouncing
  } else if(currentState2 <= high  && lastState2 == low){
    MIDImessage(noteON, 0, 0, 62, 0);//turn note 60 off
    delay(10);//crude form of button debouncing
  }
  lastState2 = currentState2;

////  Serial.print(sensorValue); // Debugging
//    Serial.println(sensorValue); // Debugging
////  Serial.println(sensorValue2); // Debugging
////  Serial.println(currentState);

}
//send MIDI message
void MIDImessage(byte command, byte data1, byte data2, byte data3, byte data4) {
  Serial.write(command);
  Serial.write(data1);
  Serial.write(data2);
  Serial.write(command);
  Serial.write(data3);
  Serial.write(data4);
}
