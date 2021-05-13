#include <CapacitiveSensor.h>

//int buttonPin1 = 2;

CapacitiveSensor Sensor = CapacitiveSensor(13,0);  //7 is charge pin.  5 is sense pin.
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

byte noteON = 144;//note on command

long currentState = 0;//stroage for current state
long lastState = 0;//storage for last state
long currentState2 = 0;
long lastState2 = 0;
long currentState3 = 0;
long lastState3 = 0;
long currentState4 = 0;
long lastState4 = 0;
long currentState5 = 0;
long lastState5 = 0;
long currentState6 = 0;
long lastState6 = 0;
long currentState7 = 0;
long lastState7 = 0;
long currentState8 = 0;
long lastState8 = 0;
long currentState9 = 0;
long lastState9 = 0;
long currentState10 = 0;
long lastState10 = 0;
long currentState11 = 0;
long lastState11 = 0;
long currentState12 = 0;
long lastState12 = 0;
long currentState13 = 0;
long lastState13 = 0;

void setup(){
//  pinMode(buttonPin1, INPUT);
  Serial.begin(115200);//initialize Serial connection
}

void loop(){
  long sensorValue = Sensor.capacitiveSensor(1000);
  sensorValue = map(sensorValue, 0,5000, 0, 127);
  long sensorValue2 = Sensor2.capacitiveSensor(1000);
  sensorValue2 = map(sensorValue2, 0,5000, 0, 127);
  long sensorValue3 = Sensor3.capacitiveSensor(1000);
  sensorValue3 = map(sensorValue3, 0,5000, 0, 127);
  long sensorValue4 = Sensor4.capacitiveSensor(1000);
  sensorValue4 = map(sensorValue4, 0,5000, 0, 127);
  long sensorValue5 = Sensor5.capacitiveSensor(1000);
  sensorValue5 = map(sensorValue5, 0,5000, 0, 127);
  long sensorValue6 = Sensor6.capacitiveSensor(1000);
  sensorValue6 = map(sensorValue6, 0,5000, 0, 127);
  long sensorValue7 = Sensor7.capacitiveSensor(1000);
  sensorValue7 = map(sensorValue7, 0,5000, 0, 127);
  long sensorValue8 = Sensor8.capacitiveSensor(1000);
  sensorValue8 = map(sensorValue8, 0,5000, 0, 127);
    long sensorValue9 = Sensor9.capacitiveSensor(1000);
  sensorValue9 = map(sensorValue9, 0,5000, 0, 127);
  long sensorValue10 = Sensor10.capacitiveSensor(1000);
  sensorValue10 = map(sensorValue10, 0,5000, 0, 127);
    long sensorValue11 = Sensor11.capacitiveSensor(1000);
  sensorValue11 = map(sensorValue11, 0, 10000, 0, 127);
    long sensorValue12 = Sensor12.capacitiveSensor(1000);
  sensorValue12 = map(sensorValue12, 0,10000, 0, 127);
  long sensorValue13 = Sensor13.capacitiveSensor(1000);
  sensorValue13 = map(sensorValue13, 0,10000, 0, 127);

  //map sensor value and go into trackable 
  // put a plateau on a value/upper threshold

  currentState = sensorValue;
  currentState2 = sensorValue2;
  currentState3 = sensorValue3;
  currentState4 = sensorValue4;
    currentState5 = sensorValue5;
  currentState6 = sensorValue6;
  currentState7 = sensorValue7;
    currentState8 = sensorValue8;
  currentState9 = sensorValue9;
  currentState10 = sensorValue10;
      currentState11 = sensorValue11;
  currentState12 = sensorValue12;
  currentState13 = sensorValue13;
  int high = 8;
  int low = 5;

  if (currentState > high  && lastState < low){
    MIDImessage(noteON, 60, 127, 0, 0,0,0);//turn note 60 on with 127 velocity
    delay(10);//crude form of button debouncing
  } else if(currentState <= high  && lastState < low){
    MIDImessage(noteON, 60, 0, 0, 0,0,0);//turn note 60 off
    delay(10);//crude form of button debouncing
  }
  lastState = currentState;
  if (currentState2 > high  && lastState2 < low){
    MIDImessage(noteON, 0, 0, 61, 127,0,0);//turn note 60 on with 127 velocity
    delay(10);//crude form of button debouncing
  } else if(currentState2 <= high  && lastState2 < low){
    MIDImessage(noteON, 0, 0, 61, 0,0,0);//turn note 60 off
    delay(10);//crude form of button debouncing
  }
  lastState2 = currentState2;
    if (currentState3> high  && lastState3 < low){
    MIDImessage(noteON, 0, 0, 62, 127,0,0);//turn note 60 on with 127 velocity
    delay(10);//crude form of button debouncing
  } else if(currentState3 <= high  && lastState3 < low){
    MIDImessage(noteON, 0, 0, 62, 0,0,0);//turn note 60 off
    delay(10);//crude form of button debouncing
  }
  lastState3 = currentState3;
    if (currentState4 > high  && lastState4 < low){
    MIDImessage(noteON, 0, 0, 63, 127,0,0);//turn note 60 on with 127 velocity
    delay(10);//crude form of button debouncing
  } else if(currentState4 <= high  && lastState4 < low){
    MIDImessage(noteON, 0, 0, 63, 0,0,0);//turn note 60 off
    delay(10);//crude form of button debouncing
  }
  lastState4 = currentState4;
  
      if (currentState5 > high  && lastState5 < low){
    MIDImessage(noteON, 0, 0, 64, 127,0,0);//turn note 60 on with 127 velocity
    delay(10);//crude form of button debouncing
  } else if(currentState5 <= high  && lastState5 < low){
    MIDImessage(noteON, 0, 0, 64, 0,0,0);//turn note 60 off
    delay(10);//crude form of button debouncing
  }
    lastState5 = currentState5;
    
  if (currentState6 > high  && lastState6 < low){
    MIDImessage(noteON, 0, 0, 65, 127,0,0);//turn note 60 on with 127 velocity
    delay(10);//crude form of button debouncing
  } else if(currentState6 <= high  && lastState6 < low){
    MIDImessage(noteON, 0, 0, 65, 0,0,0);//turn note 60 off
    delay(10);//crude form of button debouncing
  }
  lastState6 = currentState6;

    if (currentState7 > high  && lastState7 < low){
    MIDImessage(noteON, 0, 0, 0,0, 66, 127);//turn note 60 on with 127 velocity
    delay(10);//crude form of button debouncing
  } else if(currentState7 <= high  && lastState7 < low){
    MIDImessage(noteON, 0, 0, 0,0,66, 0);//turn note 60 off
    delay(10);//crude form of button debouncing
  }
  lastState7 = currentState7;
 
    if (currentState8> high  && lastState8 < low){
    MIDImessage(noteON, 0, 0, 0,0,67, 127);//turn note 60 on with 127 velocity
    delay(10);//crude form of button debouncing
  } else if(currentState8 <= high  && lastState8 < low){
    MIDImessage(noteON, 0, 0,0,0, 67, 0);//turn note 60 off
    delay(10);//crude form of button debouncing
  }
  lastState8 = currentState8;
    if (currentState9 > high  && lastState9 < low){
    MIDImessage(noteON, 0, 0, 0,0,68, 127);//turn note 60 on with 127 velocity
    delay(10);//crude form of button debouncing
  } else if(currentState9 <= high  && lastState9 < low){
    MIDImessage(noteON, 0, 0, 0,0,68, 0);//turn note 60 off
    delay(10);//crude form of button debouncing
  }
  lastState9 = currentState9;

    if (currentState10 > high  && lastState10 < low){
    MIDImessage(noteON, 0, 0, 0,0, 69, 127);//turn note 60 on with 127 velocity
    delay(10);//crude form of button debouncing
  } else if(currentState10 <= high  && lastState10 < low){
    MIDImessage(noteON, 0, 0,0,0, 69, 0);//turn note 60 off
    delay(10);//crude form of button debouncing
  }
  lastState10 = currentState10;

      if (currentState11 > high  && lastState11 < low){
    MIDImessage(noteON, 0, 0, 0,0, 70, 127);//turn note 60 on with 127 velocity
    delay(10);//crude form of button debouncing
  } else if(currentState11 <= high  && lastState11 < low){
    MIDImessage(noteON, 0, 0,0,0, 70, 0);//turn note 60 off
    delay(10);//crude form of button debouncing
  }
  lastState11 = currentState11;

      if (currentState12 > high  && lastState12 < low){
    MIDImessage(noteON, 0, 0, 0,0, 71, 127);//turn note 60 on with 127 velocity
    delay(10);//crude form of button debouncing
  } else if(currentState12 <= high  && lastState12 < low){
    MIDImessage(noteON, 0, 0,0,0, 71, 0);//turn note 60 off
    delay(10);//crude form of button debouncing
  }
  lastState12 = currentState12;

      if (currentState13 > high  && lastState13 < low){
    MIDImessage(noteON, 0, 0, 0,0, 72, 127);//turn note 60 on with 127 velocity
    delay(10);//crude form of button debouncing
  } else if(currentState13 <= high  && lastState13 < low){
    MIDImessage(noteON, 0, 0,0,0, 72, 0);//turn note 60 off
    delay(10);//crude form of button debouncing
  }
  lastState13 = currentState13;

  // could use for loop

//  Serial.println(sensorValue); // Debugging
//  Serial.print(" , ");
//    Serial.println(sensorValue11); // Debugging
//  Serial.println(sensorValue2); // Debugging
////  Serial.println(currentState);

}
//send MIDI message
//void MIDImessage(byte command, byte data1, byte data2, byte data3, byte data4, byte data5, byte data6) {
void MIDImessage(byte command, byte data1, byte data2, byte data3, byte data4, byte data5, byte data6) {
  Serial.write(command);
  Serial.write(data1);
  Serial.write(data2);
  Serial.write(command);
  Serial.write(data3);
  Serial.write(data4);
  Serial.write(command);
  Serial.write(data5);
  Serial.write(data6);
}
