#include <Ultrasonic.h>

const int echo = 6;
const int trigger = 7;

Ultrasonic ultrasonic(trigger, echo);

int distancia;
String resultado;

void setup() {
  pinMode(echo, INPUT);
  pinMode(trigger, OUTPUT);
  Serial.begin(9600);
}


void loop() {
  hcsr04();
  Serial.print("Distancia ");
  Serial.print(resultado);
  Serial.println("cm");
}

void hcsr04(){
  digitalWrite(trigger, LOW);
  delayMicroseconds(2);
  digitalWrite(trigger, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigger,LOW);

  distancia = (ultrasonic.Ranging(CM));
  resultado = String(distancia);
  delay(500);
}
