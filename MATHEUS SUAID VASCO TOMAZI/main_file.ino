.#define BLYNK_PRINT Serial


#include <ESP8266_Lib.h>
#include <BlynkSimpleShieldEsp8266.h>

// You should get Auth Token in the Blynk App.
// Go to the Project Settings (nut icon).
char auth[] = "yKOK34yd6J2_LpZIhHuFC9hk1DvNzsQj";

// Your WiFi credentials.
// Set password to "" for open networks.
char ssid[] = "ANTWE";
char pass[] = "314159265";

// Hardware Serial on Mega, Leonardo, Micro...
#define EspSerial Serial1

// or Software Serial on Uno, Nano...
//#include <SoftwareSerial.h>
//SoftwareSerial EspSerial(0, 1); // RX, TX

// Your ESP8266 baud rate:
#define ESP8266_BAUD 115200

ESP8266 wifi(&EspSerial);

BlynkTimer timer;

// This function sends Arduino's up time every second to Virtual Pin (5).
// In the app, Widget's reading frequency should be set to PUSH. This means
// that you define how often to send data to Blynk App.
void myTimerEvent()
{
  // You can send any value at any time.
  // Please don't send more that 10 values per second.
  Blynk.virtualWrite(V5, millis() / 1000);
}
// PARTE DO PROJETO 

#include <Keypad.h>

char* password = '123';
int position = 100;
const byte ROWS = 4;
const byte COLS = 4;

char keys[ROWS][COLS]{ //mapa de teclas (Keymap)
  {'1','2','3','A'},
  {'4','5','6','B'},
  {'7','8','9','C'},
  {'*','0','#','D'},
};

byte rowPins[ROWS] = {13, 11,12,10};       // Declara os pinos de interpretação das linha
byte colPins[COLS] = {6, 5, 4, 3};      // Declara os pinos de interpretação das coluna
 
Keypad keypad = Keypad(makeKeymap(keys),rowPins, colPins, ROWS, COLS);


#define Relay1 53 //Rele da Fechadura
#define MQ2 49 // Modulo Sensor de Gás MQ2
#define pushb1 7  // Pushbutton interno
#define buz 8 //Buzzer

const int ledverde = 39;
const int ledvermelho = 35;


void setup()
{
  // Debug console
  Serial.begin(9600);

  // Set ESP8266 baud rate
  EspSerial.begin(ESP8266_BAUD);
  delay(10);

  Blynk.begin(auth, wifi, ssid, pass);
  // You can also specify server:
  //Blynk.begin(auth, wifi, ssid, pass, "blynk-cloud.com", 80);
  //Blynk.begin(auth, wifi, ssid, pass, IPAddress(192,168,1,100), 8080);

  // Setup a function to be called every second
  timer.setInterval(1000L, myTimerEvent);
   pinMode(Relay1,OUTPUT);
  digitalWrite(Relay1, LOW);
  pinMode(pushb1, INPUT_PULLUP);
  pinMode(MQ2, INPUT);
  pinMode(buz, OUTPUT);
  digitalWrite(buz,HIGH);
  pinMode (ledverde,OUTPUT);
  pinMode(ledvermelho,OUTPUT);
  char key;
}

void loop()
{
  Blynk.run();
  timer.run(); // Initiates BlynkTimer

  digitalWrite(ledvermelho,HIGH);
  digitalWrite(ledverde,LOW); // led vermelho aceso e led verde apagado amarelo apagado
   
  
  //Abertura por teclado matricial
  switch (keypad.getKey()){
    
    case  '1':
      digitalWrite(ledvermelho,LOW);
      delay(500);
      digitalWrite(ledvermelho,HIGH);
      if(position==0){
        position++;  
      }
      else{
        position=100;
      }
      break;
      
    case '2':
      digitalWrite(ledvermelho,LOW);
      delay(500);
      digitalWrite(ledvermelho,HIGH);
      if(position==1){
        position++; 
      }
      else{
        position=100;
      }
      break; 

      
    case '3':
      digitalWrite(ledvermelho,LOW);
      delay(500);
      digitalWrite(ledvermelho,HIGH);
      if(position==2){
        digitalWrite(ledverde,HIGH);
        alteraStatus(Relay1,true);
        delay(500);
        alteraStatus(Relay1,false);
        digitalWrite(ledverde,LOW);
        //digitalWrite(ledamarelo,LOW);
        position = 100;
      }
      else{
        position=100;
      }
      break;
      
    case '4':
    case '5':
    case '6':
    case '7':
    case '8':
    case '9':
    case '0':
    case 'A':
    case 'B':
    case 'C':
    case 'D':
      digitalWrite(ledvermelho,LOW);
      delay(500);
      digitalWrite(ledvermelho,HIGH);
      position = 100;
      break;

    
    case '#':
    case '*':
      digitalWrite(ledvermelho,LOW);
      delay(500);
      digitalWrite(ledvermelho,HIGH);
      position = 0;
      //digitalWrite(ledamarelo,HIGH);
      break;
  }
 
 
 
  //Abertura por pushbuttom
  if(digitalRead(pushb1)==LOW){
    alteraStatus(Relay1, true);
    digitalWrite(ledverde,HIGH);
   }else{
    alteraStatus(Relay1,false);
    digitalWrite(ledverde,LOW);
   }

   //Abertura por detecção de gás
   if(digitalRead(MQ2)==LOW){
      alteraStatus(Relay1, true);
      delay(500);
      alteraStatus(Relay1,false);
      while(digitalRead(MQ2)==LOW){
        digitalWrite(buz,LOW);//tocar buzzer com delay 500
        digitalWrite(ledvermelho,LOW);
        digitalWrite(ledverde,HIGH);
        delay(500);
        digitalWrite(buz,HIGH);
        digitalWrite(ledvermelho,HIGH);
        digitalWrite(ledverde,LOW);
        delay(200);    
      }
   }
  
}
/* Função Altera Status
   Desc.: Recebe uma porta e o estado atual dela e o altera
   Ret Val: Void
   Parametros: int porta - porta digital a ser alterada
               bool ativado - Status , se true altera digitalWrite para high, se false altera para low*/
void alteraStatus(int porta, bool ativado){
  if (ativado == true){
    digitalWrite(porta,HIGH);
  }
  else {
    digitalWrite(porta,LOW);
  }

};
