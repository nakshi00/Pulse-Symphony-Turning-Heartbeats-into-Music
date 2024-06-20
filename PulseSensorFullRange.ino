
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
   Serial.println("Velocity " + String(Velocity));
   Serial.println("Tone " + String(Tone));

    
  

   if(Signal > Threshold){                          
          digitalWrite(LED,HIGH);
    
   } else {
     digitalWrite(LED,LOW);  
             
   }
     sendMidi(144,Tone,Velocity);
     delay(50);  

 


}


void sendMidi(byte Com, byte Key, byte Vel){
   Serial.write(Com);
   Serial.write(Key);
   Serial.write(Vel);
   delay(100);
  Serial.write(128);
   Serial.write(Key);
   Serial.write(0);


}

void stopMidi(byte Com, byte Key, byte Vel){
  
   Serial.write(Com);
   Serial.write(Key);
   Serial.write(Vel);

}
