// sketch para teste do sensor PIR

const int sensor_pir = 7; 

void setup(){
  pinMode(LED_BUILTIN, OUTPUT); // led da placa
  pinMode(sensor_pir, INPUT); 
}

void loop(){
  if(digitalRead(pinoPIR) == HIGH)  // high: detectou movimento
  {
    digitalWrite(LED_BUILTIN, HIGH);
  }
  else
  {
    digitalWrite(LED_BUILTIN, LOW);
  }
}
