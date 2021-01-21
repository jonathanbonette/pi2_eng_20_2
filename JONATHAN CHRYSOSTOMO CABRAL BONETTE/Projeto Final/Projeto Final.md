<table align="center"><tr><td align="center" width="9999"><br>
<img src="../Imagens/logo.png" align="center" width="150" alt="Logo IFSC">

# SMART IDEAS

<b>Instituto Federal de Educação, Ciência e Tecnologia de Santa Catarina<br>
Campus Florianópolis<br>
Departamento Acadêmico de Eletrônica<br>
Projeto Integrador II</b>

*Jonathan Chrysostomo Cabral Bonette*
</td></tr></table>

As smart homes, também conhecidas como casas conectadas, viraram tendência nos últimos anos. Esse conceito de moradia envolve o uso da tecnologia para garantir mais conforto, segurança e praticidade aos moradores. Essa categoria de produtos inclui smart displays, fechaduras, câmeras de segurança e até mesmo lâmpadas. Os dispositivos são conectados à Internet e podem ser controlados à distância pelo celular, uma grande facilidade para os usuários. No caso das luminárias, por exemplo, essa característica ajuda até mesmo a economizar energia.

De acordo com informações do site Techaeris, quase 70% dos americanos imaginam que, em cerca de uma década, as smart home serão tão populares quanto smartphones. Além disso, mais de 80% dos compradores de imóveis dizem que casas inteligentes estão entre suas preferências para uma possível aquisição. Confira a seguir mais detalhes a respeito do conceito e conheça alguns dispositivos conectados que já estão disponíveis para comprar no Brasil.

<h2 align="center">Idealização do Projeto</h2>

A principal característica das casas conectadas é o uso massivo de tecnologia de ponta, mesmo em itens comuns como lâmpadas ou fechaduras. O emprego desses dispositivos tem como objetivo trazer maior comodidade, mesmo para tarefas simples como abrir a garagem ou apagar as luzes. A proposta desse projeto é mostrar como que simples ações podem ser automatizadas de formas bem diferentes das usuais.

Ao detectar o sol, sua janela se abre, o breafing diário liga e sua rotina começa, seu café começa a passar, você está pronto para seu dia, devidamente vestido para o dia, pois sua assistente virtual já falou se vai fazer chuva ou sol, se deve levar um guarda-chuva ou um óculos de sol, já sabe quais seus compromissos do dia e as principais notícias de seu interesse até o presente momento, tudo isso sem você fazer absolutamente nada (depois de ter que fazer tudo isso, é claro), e poder comandar e acomoanhar sua casa quando estiver fora dela, será que tem gente por ali? Quantos graus está hoje? Acender ou ligar uma músic ambiente — *ahh o futuro! Ou melhor, o presente!* — .

A idéia desse projeto foi retratar algumas dessas finalidades em um único lugar, o nosso celular. Usando um bot do Telegram, podemos comandar nossos eletrônicos, de qualquer lugar do mundo, via chat no Telegram, mandar comandos para acender a luz do quarto, ver a temperatura, a humidade, ligar uma televisão, uma câmera, etc.

********************************************************
<h2 align="center">Itens Utilizados (Hardware e Componentes)</h2>

**Sensor de Luminosidade LDR 5mm**<br>
Usado para detectar a luz do sol e acender o LED.<br>
<p align="center"><img src="../Imagens/ldr.jpg" align="center" width="300"><br></p>

**Módulo Relé 5V 1 Canal**<br>
Usado para ligar/desligar um determinado sensor/aparelho.
<p align="center"><img src="../Imagens/rele.jpg" align="center" width="200"><br></p>

**Módulo WiFi ESP8266 NodeMcu ESP-12**<br>
Necessário para se comunicar com o bot do Telegram e acionar dispositivos.
<p align="center"><img src="../Imagens/esp8266.jpg" align="center" width="300"><br></p>

**Sensor de Umidade e Temperatura DHT11**<br>
Necessário para medir temperatura e humidade do ar.
<p align="center"><img src="../Imagens/dht11.jpg" align="center" width="200"><br></p>

**LEDs 5mm**<br>
Usados para representarem luzes de ambientes ou lâmpadas.
<p align="center"><img src="../Imagens/led.png" align="center" width="200"><br></p>

**Celular**<br>
Usado para mandar os comandos ao sistema e se comunicar com a Alexa (para os que não possuem a assistente virtual da Amazon, Amazon Echo).
<p align="center"><img src="../Imagens/cbot.png" align="center" width="350"><br></p><br>

**Resistores**<br>
Usados para o funcionamento adequado do circuito.
<p align="center"><img src="../Imagens/resistor.png" align="center" width="300"><br></p>

**Transistor**<br>
Usado para o funcionamento adequado do circuito.
<p align="center"><img src="../Imagens/transistor.jpg" align="center" width="200"><br></p>

**Jumpers**<br>
Usados para o funcionamento adequado do circuito.
<p align="center"><img src="../Imagens/jumper.jpg" align="center" width="300"><br></p>

********************************************************
<h2 align="center">C: Conceito</h2>

O projeto se baseará em 2 partes ativas (que necessitam comandos de usuário) e 1 parte passiva (onde não é necessário atenção do usuário):

1. A integração celular <=> casa (Ativa)
2. A integração celular <=> assistênte virtual (Ativa)
3. A instalação de uma luz com o módulo LDR (Passiva)

Apesar das daus primeiras partes não conversarem entre sí no primeiro momento, seria possivel se tivessemos um equipamento especifico para isso, como por exemplo o dispositivo Amazon Echo.

Podemos no primeiro momento ter uma casa conectada e comandada via um Bot do Telegram, onde podemos enviar comandos e ter resultados daquilo, como por exemplo, ligar uma lâmpada, um ventilador, uma televisão, ter controles remotos como informações de temperatura e umidade (Várias outros módulos podem ser implementados através de ligações simples pelos relês ou mesmo na próprio módulo ESP, que permite mais de 9 conexões de controles simultâneas).

No segundo momento podemos ter acesso a uma assistênte virtual, com comandos definidos por nós, como, quantos graus vai fazer hoje, quanto foi os jogos da rodada do meu campeonato preferido, meus compromissos do dia pelo meu calêndario, programas preferidos, conversas pessoas, etc.

Em um terceiro momento com a aquisição de um dispositivo Echo, podemos fazer o Bot do Telegram e/ou sensores se comunicar diretamente pela assistênte virtual no celular ou no próprio dispositivo (Não utilizado nesse projeto porém é bom ressaltar a possibilidade).

Para a **parte 1**. foi desenvolvido ligações e esquemáticos e um bot no Telegram a fim de fazer conversarem entre sí. Para a **parte 2**. foi desenvolvida uma rotina e uma integração com uma assistênte virtual e programada para tais funções definidas. E por fim para a **parte passiva** foi instalado um módulo LDR e uma luz para que quando não tiver mais luminosidade do ambiente (escurecer o dia, fechar uma janela) ele identificará e acionará a luz (que pode ser uma luz de um quarto, um sistema de alarme, entre outras possibilidades).<br>

<p align="center"><img src="../Imagens/JONATHANBONETTE-MAPAMENTAL.png" align="center" width="900"><br></p><br>

********************************************************
<h2 align="center">D: Design</h2>

A imagem do fritzing demonstra a construção na protoboard feita para este projeto, na qual mostra como foram feitas as ligações de cada módulo e quais as pinagens definidas que foram selecionados para o funcionamento do projeto.

<h3>Parte Eletrônica do Projeto</h3>
<p align="center"><img src="../Imagens/telegrambot_esp_bb.png" align="center" width="900"><br></p><br>

<h3>Fluxograma</h3>
<p align="center"><img src="../Imagens/f_telegram_bb.png" align="center" width="600"><br></p><br>

<h3>Imagem</h3>
<p align="center"><img src="../Imagens/foto2.png" align="center" width="900"><br></p><br>

********************************************************
<h2 align="center">I: Implementação</h2>

O projeto foi implementado através do código abaixo, que foi construído consultando diversos modos de funcionamento de cada módulo e adaptando-os ao objetivo deste projeto:

<h3>Declaração e variaveis</h3>

``` c++

#include <ESP8266WiFi.h>
#include <WiFiClientSecure.h>
#include <UniversalTelegramBot.h>
#include "DHT.h"

// Inicializa a conexão Wifi com o roteador
//Informações de login da rede
#define WIFI_SSID "minharedeaqui"
#define WIFI_PASSWORD "minhasenhaaqui"
//Token do bot
#define BOTtoken "000000000:XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX"  // Seu token do telegram

#define LED_PIN D3
#define RELAY_PIN D6
#define DHT_PIN D5
#define DHTTYPE DHT11
//Definição dos pinos do LDR e LED
const int ledPin = 15; //D8
const int ldrPin = 5; //D1

#define BOT_SCAN_MESSAGE_INTERVAL 1000 //Intervalo para obter novas mensagens (1000 ms)
long lastTimeScan;  // Ultima vez que buscou mensagem
bool ledStatus = false; // Estado do LED
bool relayStatus = false; // Estado do Relê

```

<h3>Comandos e definições</h3>

``` c++

WiFiClientSecure client;
UniversalTelegramBot bot(BOTtoken, client);
DHT dht(DHT_PIN, DHTTYPE);
//Tempo em que foi feita a última checagem
uint32_t lastCheckTime = 0;

//Quantidade de usuários que podem interagir com o bot (Deixa o bot seguro)
#define SENDER_ID_COUNT 2 //Ids dos usuários que podem interagir com o bot. 
//É possível verificar seu id pelo monitor serial ao enviar uma mensagem para o bot
String validSenderIds[SENDER_ID_COUNT] = {"id_aqui", "id_aqui"};

```

<h3>Implementação com o Telegram (Input e Output)</h3>

``` c++

// Trata as novas mensagens que chegaram
void handleNewMessages(int numNewMessages) {
  Serial.println("handleNewMessages");
  Serial.println(String(numNewMessages));

  for (int i=0; i<numNewMessages; i++) {
    String chat_id = String(bot.messages[i].chat_id);
    String text = bot.messages[i].text;

    // Pessoa que está enviando a mensagem
    String from_name = bot.messages[i].from_name;    
    if (from_name == "") from_name = "Convidado";

    // Tratamento para cada tipo de comando a seguir.

    if (text == "/led_ligado") {
      digitalWrite(LED_PIN, HIGH);   // liga o LED (HIGH é o nível da voltagem)
      ledStatus = true;
      bot.sendMessage(chat_id, "Led está ligado", "");
    }

    if (text == "/led_desligado") {
      ledStatus = false;
      digitalWrite(LED_PIN, LOW);    // desliga o LED (LOW é o nível da vontagem)
      bot.sendMessage(chat_id, "Led está desligado", "");
    }

    if (text == "/relay_ligado") {
      digitalWrite(RELAY_PIN, HIGH);
      relayStatus = true;
      bot.sendMessage(chat_id, "Relê está ligado", "");
    }

    if (text == "/relay_desligado") {
      relayStatus = false;
      digitalWrite(RELAY_PIN, LOW);
      bot.sendMessage(chat_id, "Relê está desligado", "");
    }

    if (text == "/status") {
      String message = "Led está ";
      if(ledStatus){
        message += "ligado";
      }else{
        message += "desligado";
      }
      message += ". \n";
      message += "Relê está ";
      if(relayStatus){
        message += "ligado";
      }else{
         message += "desligado";
      }
      message += ". \n";
      bot.sendMessage(chat_id, message, "Markdown");      
    }

    if( text == "/ambiente") {
      float humidity = dht.readHumidity();
      float temperature = dht.readTemperature();
      String message = "A temperatura é de " + String(temperature, 2) + " graus celsius.\n";
      message += "A umidade relativa do ar é de " + String(humidity, 2)+ "%.\n\n";      
      bot.sendMessage(chat_id, message, "Markdown");
    }

    // Cria teclado com as opções de comando
    if (text == "/opcoes") {
      String keyboardJson = "[[\"/led_ligado\", \"/led_desligado\"],[\"/relay_ligado\", \"/relay_desligado\"],[\"/ambiente\",\"/status\"],[\"/opcoes\"]]";
      bot.sendMessageWithReplyKeyboard(chat_id, "Escolha uma das opções", "", keyboardJson, true);
    }

    
    // Comando de inicio de conversa no telegram
    if (text == "/start") {
      String welcome = from_name + ", bem vindo ao Bot do Projeto Integrador II.\n";
      welcome += "Para interagir com a casa, use um dos comandos a seguir.\n\n";
      welcome += "/led_ligado : para ligar o Led \n";
      welcome += "/led_desligado : para desligar o Led \n";
      welcome += "/relay_ligado : para ligar o Relê \n";
      welcome += "/relay_desligado : para desligar o Relê \n";
      welcome += "/ambiente : saber a temperatura e umidade do ambiente \n";
      welcome += "/status : para saber o status dos sensores e atuadores \n";
      bot.sendMessage(chat_id, welcome, "Markdown");
    }
  }
}

```

<h3>Setup do Wifi</h3>

``` c++

void setupWifi(){  

  // Tentativa de conexão com o Wifi:
  Serial.print("Conectando o Wifi: ");
  Serial.println(WIFI_SSID);
  WiFi.begin(WIFI_SSID, WIFI_PASSWORD);

  while (WiFi.status() != WL_CONNECTED) {
    Serial.print(".");
    delay(500);
  }

  Serial.println("");
  Serial.println("WiFi conectado");
  Serial.print("Endereço de IP: ");
  Serial.println(WiFi.localIP());
}

```

<h3>Setup dos Pinos</h3>

``` c++

void setupPins(){
  pinMode(LED_PIN, OUTPUT); 
  pinMode(RELAY_PIN, OUTPUT); 
  delay(10);
  digitalWrite(LED_PIN, LOW); 
  digitalWrite(RELAY_PIN, LOW); 

  dht.begin();
}

```

<h3>Setup</h3>

``` c++

void setup() {
  pinMode(ledPin, OUTPUT);
  pinMode(ldrPin, INPUT);
  client.setInsecure();
  Serial.begin(115200); // Velocidade do monitor

  setupWifi();
  setupPins();

  lastTimeScan = millis();
}

```

<h3>Loop</h3>

``` c++

void loop() {
// Verificação do LDR (sensor passivo)
int ldrStatus = digitalRead(ldrPin);

  if (ldrStatus == 1) {

  digitalWrite(ledPin, HIGH);
  //Serial.println("Sem presença de luz no LDR, LED está ligado"); // Mensagem enviada ao monitor (controle de funcionamento)
  Serial.print(ldrStatus);

  }

  else {

  digitalWrite(ledPin, LOW);
  //Serial.println("LED está desligado"); // Mensagem enviada ao monitor (controle de funcionamento)
  Serial.println(ldrStatus);

  }
  // Bot do Telegram
  if (millis() > lastTimeScan + BOT_SCAN_MESSAGE_INTERVAL)  {
    Serial.print("Checando comandos - ");
    int numNewMessages = bot.getUpdates(bot.last_message_received + 1);  
    Serial.println(numNewMessages);
    while(numNewMessages) {
      Serial.println("Leitura de comando efetuada");
      handleNewMessages(numNewMessages);
      numNewMessages = bot.getUpdates(bot.last_message_received + 1);
    }

    lastTimeScan = millis();
  }
  yield();
  delay(10);
}

```



Código telegram?<br>
Explicação das etapas<br>
Aplicativo?

********************************************************
<h2 align="center">O: Operação</h2>

Vídeo explicativo<br>
Fotos explicativas<br>
Fotos do aplicativo?<br>
Bot?

********************************************************
<h2 align="center">Resultados, Percepções Pessoais e Considerações Finais</h2>

Os resultados foram excelentes devido ao tempo e experiência na área pela minha pessoa, fiquei surpreso pela quantidade de possibilidades que podiamos ter e isso de certa forma até me deixou um pouco confuso, pois cada coisa que procurava na internet ficava mais entusiasmado de incluir mais um sensor, fazer uma coisa sempre a mais, dificultando as vezes o andamento do projeto.

Deixar o tema livre para o desenvolvimento do trabalho, me fez procurar bem mais a respeito dos sensores e aplicações, correr atrás e pensar em diversas soluções para o que havia proposto e no final do projeto, muito mais entusiamo pela área.

Normalmente para controlar nossos dispositivos, ficamos limitados a rede WiFi local ou se quisermos acessar externamente, temos que fazer uma tediosa configuração com um serviço de DNS dinâmico (como o DuckDNS), liberar porta no modem, colocar ip estático e outras configurações que não cabem aqui descrever, para poder acessar de fora de casa.

As dificuldades encontradas por mim foi o uso pela primeira vez do arduino e dos sensores, descobrir como funciona a IDE do arduino, os sensores, suas pinagens, como usar e fazer conversarem entre sí e apesar da faculdade prover todos os equipamentos, alguns equipamentos usados nesse projeto tiveram que ser comprados a parte como o ESP8266 e o módulo Bluetooh (não utilizado nesse peojeto mas essencial para ver como que funiona a conectividade dos sensores com um celular) e elevaram um pouco o processo de aprendizagem assim como a dificuldade encontrada por querer também aplica em um Bot do Telegram que é um recurso totalmente novo para mim.

********************************************************
<h2 align="center">Melhorias</h2>

No primeiro momento existem várias melhorias que poderiam ser implementadas, luzes, sensores e/ou equipamentos que poderiam ser ligados diretamente no relê, e outros sensores diretamente na protoboard. Mas não para por ai, podemos até mesmo criar alertas, como por exemplo, quando detectar algo na nossa casa, podemos receber diretamente no chat o que está ocorrendo, isso de qualquer lugar do mundo. E a longo prazo poderiamos pensar grande, com tempo e conhecimento adequados, podemos explorar por exemplo a instalação de um sistema parecido para automatizar todos os setores de uma residência, portão, verificação de entrada, câmeras, sensores diversos, luzes, automatização de cômodos, entre outras funções.<br><br>

<p align="center"><img src="../Imagens/melhorias_iot.png" align="center" width="900"><br></p><br>

********************************************************
<h2 align="center">Referências Bibliográficas</h2>

- https://github.com/Gianbacchio/ESP8266-TelegramBot<br>
- https://create.arduino.cc/projecthub/Shubhamkumar97/home-automation-using-arduino-and-bluetooth-control-404e9c?ref=search&ref_id=ldr%20window&offset=6<br>
- https://www.hackster.io/FilippoOnesti/esp8266-clock-using-max7219-led-matrix-display-b036c7
