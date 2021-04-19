
#define BLYNK_PRINT Serial

#include <ESP8266_Lib.h>
#include <BlynkSimpleShieldEsp8266.h>

#include <DHT.h>

#define entradaDigital 52
#define entradaAnalogica 0

char auth[] = "RqNjEhT0XaNgcMy-A9hqIwe5VnSWQO6f"; //código do app do Blynk

//para a conexão com a internet
char ssid[] = "MARTINI";      
char pass[] = "FSBTmartini";

float t; //variavel umidade
float h; //variavel temperatura

#define EspSerial Serial1

#define ESP8266_BAUD 115200

ESP8266 wifi(&EspSerial);

//sensor de humidade e temperatura
#define DHTPIN 2     
#define DHTTYPE DHT11    

DHT dht(DHTPIN, DHTTYPE);
BlynkTimer timer;

//buzzer
int buzzer = 6;

//sensor de agua
const int pinoSensor = A15; //PINO ANALÓGICO UTILIZADO PELO SENSOR
int pinoLED = 7; //PINO DIGITAL UTILIZADO PELO LED            
int waterVal;

//gas
bool dSensor;
int aSensor;

//rele
int pbuttonPin = 5;// connect output to push button
int relayPin = 10;// Connected to relay (LED)

int val = 0; // push value from pin 2
int lightON = 0;//light status
int pushed = 0;//push status

//TEMP/UMI
  void sendSensor(){
    float h = dht.readHumidity();
    float t = dht.readTemperature(); 
    
    Serial.println(" ");
    Serial.print("Temperatura atual: ");
    Serial.print(t);
    Serial.println("ºC");
  
    Serial.print("Umidade relativa do ar atual: ");
    Serial.print(h);
    Serial.println("%");
    Serial.println("");
  
    if (isnan(h) || isnan(t)) {
      Serial.println("Failed to read from DHT sensor!");
      return;
      }

      //mandar os dados de temperatura e umidade para o blynk
      Blynk.virtualWrite(V5,dht.readHumidity());
      Blynk.virtualWrite(V6, dht.readTemperature());
    }
  
void setup()
{
  
// Debug console
Serial.begin(9600);

// ESP8266 baud rate
EspSerial.begin(ESP8266_BAUD);
delay(10);

Blynk.begin(auth, wifi, ssid, pass);
dht.begin();
timer.setInterval(1000L, sendSensor);

//buzzer
 pinMode(buzzer,OUTPUT);

//AGUA
 pinMode(pinoSensor, INPUT);
 pinMode(pinoLED, OUTPUT); //DEFINE O PINO COMO SAÍDA

//relay
  Serial.begin(9600);
  pinMode(entradaDigital, INPUT);
  pinMode(pbuttonPin, INPUT_PULLUP); 
  pinMode(relayPin, OUTPUT);
  digitalWrite(relayPin, HIGH);//MANTEM DESLIGADO NO INICIO

void loop()
{
  Blynk.run();
  timer.run(); 

  if(dSensor == 1){
   digitalWrite(buzzer,HIGH);
   digitalWrite(pinoLED,LOW);
  }else{
    digitalWrite(buzzer,LOW); 
    digitalWrite(pinoLED,HIGH); 
    }
  
  dSensor = digitalRead(entradaDigital);
  aSensor = analogRead(entradaAnalogica);
  
  Serial.print("Leitura entrada digital: ");
  Serial.println(dSensor);
  
  Serial.print("Leitura entrada analógica: ");
  Serial.println(aSensor);
  Serial.println();
  

  //RELE
  val = digitalRead(pbuttonPin);

  if(val == HIGH && lightON == LOW){

    pushed = 1-pushed;
    delay(100);
  }    

  lightON = val;

      if((pushed == LOW && dSensor == 1)){
        Serial.println("Light ON");
        digitalWrite(relayPin, HIGH); 
       
      }else{
        Serial.println("Light OFF");
        digitalWrite(relayPin, LOW);
      }

  //AGUA
  waterVal = analogRead(pinoSensor); //read the water sensor    
  Serial.println("SENSOR DE AGUA");
  Serial.println(waterVal);
       
  if (waterVal >= 500){
     digitalWrite(pinoLED, HIGH);//if the water sensor senses water turn the led on
     digitalWrite(buzzer,LOW);
  }

  else{
    digitalWrite(pinoLED, LOW);//if it doesn't sense anything turn the led off
    digitalWrite(buzzer,HIGH);
  }
  
  delay(100);
}
