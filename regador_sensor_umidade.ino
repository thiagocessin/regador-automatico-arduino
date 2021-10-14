// Código de Funcionamento para Sistema de Monitoramento e Irrigação com Arduino
//Carrega a biblioteca do servo motor
#include <Servo.h> 
 
// Define o pino para o servo (Porta PWM)
#define SERVO 6 
Servo servo;

int ValAnalogIn; // Introduz o valor analógico ao código
 
void setup() {
 // inicio da comunicação serial
  Serial.begin(9600);
  servo.attach(SERVO);
  servo.write(90);
}
 
void loop() {
// Leitura do sensor no pino A0 e armazenamento em SensorValue
  int sensorValue = analogRead(A0);
  int porcento = map(sensorValue, 1023, 0, 0, 100); // Relaciona o valor analógico à porcentagem
  
   if(porcento < 40) {
       Serial.println("{\"info\":\"terra seca, regando planta\"}");
       Serial.print(porcento);
       Serial.println("%");
       //delay(300);
       servo.write(10);
       delay(5000);
    }else{
      Serial.println("{\"info\":\"umidade normal\"}");
      Serial.print(porcento);
      Serial.println("%");
      
      servo.write(90);
   }
  delay(3000);

}
