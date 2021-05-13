byte noteON = 144;//note on command<br>byte note;//storage for currently playing note
int buttonPin1 = 2;

boolean currentState = LOW;//stroage for current button state
boolean lastState = LOW;//storage for last button state
void setup(){
  pinMode(buttonPin1, INPUT);

  //this time we will set the pin as INPUT
  Serial.begin(115200);//initialize Serial connection
}
void loop(){

  currentState = digitalRead(buttonPin1);
  if (currentState == HIGH && lastState == LOW){
    MIDImessage(noteON, 60, 127);//turn note 60 on with 127 velocity
    delay(200);//crude form of button debouncing
  } else if(currentState == LOW && lastState == HIGH){
    MIDImessage(noteON, 60, 0);//turn note 60 off
    delay(2);//crude form of button debouncing
  }
  lastState = currentState;
 
//  if (currentState == HIGH && lastState == LOW){//if button has just been pressed
//    MIDImessage(noteON, 63, 127);//turn note 60 on with 127 velocity
//    delay(200);//crude form of button debouncing
//  } else if(currentState == LOW && lastState == HIGH){
//    MIDImessage(noteON, 60, 0);//turn note 60 off
//    delay(2);//crude form of button debouncing
//  }
//  lastState = currentState; //test
}
//send MIDI message
void MIDImessage(byte command, byte data1, byte data2) {
  Serial.write(command);
  Serial.write(data1);
  Serial.write(data2);
}
