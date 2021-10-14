/*
//Carrega a biblioteca do sensor ultrassônico
#include <Ultrasonic.h>


//Define os pinos para o trigger e echo
#define pino_trigger 4
#define pino_echo 5

//Inicializa o sensor nos pinos definidos acima
Ultrasonic ultrasonic(pino_trigger, pino_echo);

//Le as informacoes do sensor, em cm e pol
float cmMsec;

byte contator = 0;

void setup () {
pinMode(13, OUTPUT);
Serial.begin(57600);

}

void loop()
{
  //Le as informacoes do sensor, em cm e pol
  cmMsec = ultrasonic.convert(ultrasonic.timing(), Ultrasonic::CM);
  
  delay(2000);
  Serial.println(cmMsec);
}
*/
