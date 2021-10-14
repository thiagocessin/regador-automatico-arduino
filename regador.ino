/*
// LIVE 1 - dispenser alcool gel

//Carrega a biblioteca do servo motor
#include <Servo.h>

//Carrega a biblioteca do sensor ultrassônico
#include <Ultrasonic.h>

// Define o pino para o servo (Porta PWM)
#define SERVO 6 

//Define os pinos para o trigger e echo
#define pino_trigger 4
#define pino_echo 5

//Inicializa o sensor nos pinos definidos acima
Ultrasonic ultrasonic(pino_trigger, pino_echo);
Servo servo;

//Le as informacoes do sensor, em cm e pol
float cmMsec;

byte contator = 0;

void setup () {
pinMode(13, OUTPUT);
Serial.begin(57600);
servo.attach(SERVO);
servo.write(90);
}

void loop()
{
  //Le as informacoes do sensor, em cm e pol
  cmMsec = ultrasonic.convert(ultrasonic.timing(), Ultrasonic::CM);

  //alterar para sensor de umidade
  //enquanto a umidade for menor que x acionar o servo motor
 
   
  if(cmMsec < 10.0) {
     Serial.println("{\"info\":\"terra seca, regando planta\"}");
      Serial.println(cmMsec);
      //delay(300);
      servo.write(10);
      delay(5000);
    
  }else{
          
      Serial.println("{\"info\":\"umidade normal\"}");
      
      Serial.println(cmMsec);
      servo.write(90);
   }
  delay(3000);
}

void notifica(String info,float cmMsec){

  String json = "{"info":info}";
}

void notificaLiberacao() {
  Serial.println("{\"deviceUUID\":\"b146b053-643a-4640-8a37-b34b888b0dc5\",\"model\":\"DAGI-V1\",\"action\":\"TRIGGER\"}");
}
*/
