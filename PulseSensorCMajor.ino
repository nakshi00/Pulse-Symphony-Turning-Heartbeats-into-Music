
int PulseSensorPurplePin = 0;        // A0
int LED = LED_BUILTIN;  


int Signal;                // holds the incoming raw data. Signal value can range from 0-1024
int Threshold = 550;   
int Velocity;
int Tone;    


void setup() {
  pinMode(LED,OUTPUT);         // pin that will blink to your heartbeat!
   Serial.begin(9600);     

}

void loop() {

  Signal = analogRead(PulseSensorPurplePin); 
  Velocity = (Signal - 300) * (127 - 80) / (900 - 300) + 100  ;  
  if (Velocity > 127){
    Velocity = 127;
  }  
   Tone =  (Signal - 400) * (127 - 60) / (1023 - 400) + 60;
   if(Tone < 0){
    Tone = 0;
   }
 

   Serial.println("Signal " + String(Signal));
  // Serial.println("Velocity " + String(Velocity));
  // Serial.println("Tone " + String(Tone));

 
  // delay(250);
    
  if(Signal < 450){
   sendMidi(144,60,Velocity); 
   delay(100);
   stopMidi(128,60,0);
   }
  else if(Signal<470){
    sendMidi(144,62,Velocity);
    delay(100);
       stopMidi(128,62,0);

  }
  else if(Signal<490){
    sendMidi(144,64,Velocity);
    delay(100);
       stopMidi(128,64,0);

  }
  else if(Signal<530){
    sendMidi(144,65,Velocity);
    delay(100);
       stopMidi(128,65,0);

  }
  else if(Signal<580){
    sendMidi(144,67,Velocity);
    delay(100);
       stopMidi(128,67,0);

  }
  else if(Signal<620){
    sendMidi(144,69,Velocity);
    delay(100);
       stopMidi(128,69,0);

  }
  else if(Signal<650){
    sendMidi(144,71,Velocity);
    delay(100);
       stopMidi(128,71,0);

  }
  else if(Signal<690){
    sendMidi(144,72,Velocity);
    delay(100);
       stopMidi(128,72,0);

  }
  else if(Signal<740){
    sendMidi(144,74,Velocity);
    delay(100);
       stopMidi(128,74,0);

  }
  else if(Signal<780){
    sendMidi(144,76,Velocity);
    delay(100);
       stopMidi(128,76,0);

  }
  else if(Signal<830){
    sendMidi(144,77,Velocity);
    delay(100);
       stopMidi(128,77,0);

  }
  else if(Signal<870){
    sendMidi(144,79,Velocity);
    delay(100);
       stopMidi(128,79,0);


  }
  else if(Signal<910){
    sendMidi(144,81,Velocity);
    delay(100);
       stopMidi(128,81,0);

  }
  else{
    sendMidi(144,83,Velocity);
    delay(100);
       stopMidi(128,83,0);

  }
  

   if(Signal > Threshold){                          
     digitalWrite(LED,HIGH);
   } else {
     digitalWrite(LED,LOW);                
   }


 


}


void sendMidi(byte Com, byte Key, byte Vel){
   Serial.write(Com);
   Serial.write(Key);
   Serial.write(Vel);


}

void stopMidi(byte Com, byte Key, byte Vel){
  
   Serial.write(Com);
   Serial.write(Key);
   Serial.write(Vel);

}
