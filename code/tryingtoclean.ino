#include <CapacitiveSensor.h>

CapacitiveSensor Sensor = CapacitiveSensor(13,0);  //13 is charge pin.  0 is sense pin.
CapacitiveSensor Sensor2 = CapacitiveSensor(13,1);  
CapacitiveSensor Sensor3 = CapacitiveSensor(13,2);  
CapacitiveSensor Sensor4 = CapacitiveSensor(13,3);  
CapacitiveSensor Sensor5 = CapacitiveSensor(13,4);  
CapacitiveSensor Sensor6 = CapacitiveSensor(13,5);  
CapacitiveSensor Sensor7 = CapacitiveSensor(13,6); 
CapacitiveSensor Sensor8 = CapacitiveSensor(13,7);  
CapacitiveSensor Sensor9 = CapacitiveSensor(13,8);  
CapacitiveSensor Sensor10 = CapacitiveSensor(13,9); 
CapacitiveSensor Sensor11 = CapacitiveSensor(13,10);  
CapacitiveSensor Sensor12 = CapacitiveSensor(13,11); 
CapacitiveSensor Sensor13 = CapacitiveSensor(13,12);  

//note on MIDI command
byte noteON[13] = {144, 145, 146, 147, 148, 149, 150, 151, 152, 153, 154, 155, 156}; 
//byte noteON[13] = {144, 144, 144, 144, 144, 144, 144, 144, 144, 144, 144, 144, 144}; 
byte tones[13] = {60, 61, 62, 63, 64, 65, 66, 67, 68, 69, 70, 71, 72};

// stores current state
long currentStates[13] = {
  0,0,0,0,0,0,0,0,0,0,0,0,0
};

// stores previous state
long lastStates[13] ={
  0,0,0,0,0,0,0,0,0,0,0,0,0
};

void setup(){
  Serial.begin(115200);//initialize Serial connection
}

void loop(){
  
  // put the sensor values into an array
  long sensorValues[13] = {
    Sensor.capacitiveSensor(1000),
    Sensor2.capacitiveSensor(1000),
    Sensor3.capacitiveSensor(1000),
    Sensor4.capacitiveSensor(1000),
    Sensor5.capacitiveSensor(1000),
    Sensor6.capacitiveSensor(1000),
    Sensor7.capacitiveSensor(1000),
    Sensor8.capacitiveSensor(1000),
    Sensor9.capacitiveSensor(1000),
    Sensor10.capacitiveSensor(1000),
    Sensor11.capacitiveSensor(1000),
    Sensor12.capacitiveSensor(1000),
    Sensor13.capacitiveSensor(1000),
   };
  
  // map sensor value and go into a trackable rangee
  // put a plateau on a value/upper threshold
  // for sensors 1 to 10
  for (int i = 0; i < 10; i++) {
    sensorValues[i] = map(sensorValues[i], 0,10000, 0, 127);
  }
  // for sensors 11 to 13 (used different resistor)
  for (int i = 10; i < 13; i++) {
    sensorValues[i] = map(sensorValues[i], 0,10000, 0, 127);
  }

  // set current state of a sensor to be its sensor value
  for (int i = 0; i < 13; i++){
    currentStates[i] = sensorValues[i];
  }

  int high = 10;       // capacitive calibration
  int low = 1;

  // on or off midi message for each sensor
  for (int i = 0; i < 13; i++){
    if (currentStates[i] > high  && lastStates[i] < low){
      MIDImessage(noteON[i], tones[i], 127); // turn respective tone on with 127 velocity, in respective channel
      delay(200); // debouncing
    } else if(currentStates[i] <= high && lastStates[i] < low){
      MIDImessage(noteON[i], tones[i], 0); //turn note off
      delay(10); // debouncing
    }
   lastStates[i] = currentStates[i];
  }

//  Serial.println(sensorValue); // Debugging
//  Serial.print(" , ");
//  Serial.println(sensorValue11); // Debugging
//  Serial.println(sensorValue2); // Debugging
}


//send MIDI message
void MIDImessage(byte command, byte data1, byte data2) {
  Serial.write(command);
  Serial.write(data1);
  Serial.write(data2);
}
