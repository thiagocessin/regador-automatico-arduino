// Código de Funcionamento para Sistema de Monitoramento e Irrigação com Arduino
//Carrega a biblioteca do servo motor
#include <Servo.h> 
 
// Define o pino para o servo (Porta PWM)
#define SERVO 6 
Servo servo;

int ValAnalogIn; // Introduz o valor analógico ao código
 
void setup() {
 // inicio da comunicação serial
  Serial.begin(57600);
  servo.attach(SERVO);
  servo.write(90);
}
 
void loop() {
// Leitura do sensor no pino A0 e armazenamento em SensorValue
  int sensorValue = analogRead(A0);
  int porcento = map(sensorValue, 1023, 0, 0, 100); // Relaciona o valor analógico à porcentagem
   if(porcento < 40) {
       Serial.print("{\"deviceUUID\":\"b146b053-643a-4640-8a37-b34b888b0dc5\",\"info\":\"terra seca, regando planta\", \"porcentagem\":");
       Serial.print(porcento);
       Serial.println("}");
       servo.write(10);
       //se a terra estiver seca, permanece 5 segundos na rega e verifica novamente
       delay(5000);       
    }else{
       Serial.print("{\"deviceUUID\":\"b146b053-643a-4640-8a37-b34b888b0dc5\",\"info\":\"umidade normal\", \"porcentagem\":");
       Serial.print(porcento);
       Serial.println("}");
       servo.write(90);
       //se a terra estiver com a umidade OK, aguarda 10 segundos para verificar novamente
       delay(10000);
     }
  
}
