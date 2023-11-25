/* deve-se baixar essa biblioteca manualmente
e utilizar o arduino IDE v 1.6.13 pois atualmente
 essa biblioteca não é aceita*/

#include <RTClib.h>

const int motorB1= 5;
const int motorB2 = 6;

RTC_DS1307 rtc;


//variaveis de hora 
int Hor;
int Min;
int Sec;
int Data;

void setup(){
  rtc.begin();

  pinMode(motorB1, OUTPUT);
  pinMode(motorB2, OUTPUT);

//função rtc para guardar a hora atual
rtc.adjust(DateTime(F(__DATE__), F(__TIME__)));

}

void loop(){
  Hor = rtc.now().hour();
  Min = rtc.now().minute();
  Sec = rtc.now().second();
  Data = rtc.now().day();
// Verifica se o horario é igual ao periodo escolhido
if ( Hor == 12 && Min == 41 && Sec == 00) {
  // dentro da movimentação do motor, o B1 é sentido horário, informado duas ativações completas(duas voltas)
  analogWrite(motorB1, 255);
  analogWrite(motorB2, 0);
  delay(3000);
  analogWrite(motorB1, 255);
  analogWrite(motorB2, 0);
  delay(2000);
  analogWrite(motorB1, 0);
  analogWrite(motorB2, 0);
  delay(3000);
  analogWrite(motorB1, 0);
  analogWrite(motorB2, 0);
}

// Verifica o horário e se o mesmo for igual à 18:00:00
if ( Hor == 20 && Min == 00 && Sec == 00) {
  analogWrite(motorB1, 255);
  analogWrite(motorB2, 0);
  delay(3000);
  analogWrite(motorB1, 255);
  analogWrite(motorB2, 0);
  delay(2000);
  analogWrite(motorB1, 0);
  analogWrite(motorB2, 0);
  delay(3000);
  analogWrite(motorB1, 0);
  analogWrite(motorB2, 0);
  delay(1000);
}
}
