#include <HCSR04.h>

int Trigger_Pin=11;
int Echo_Pin=10;

int Buzzer_Pin=8;

double sure;
double mesafe;

void setup()
{
  pinMode(Trigger_Pin,OUTPUT);
  pinMode(Echo_Pin,INPUT);

  pinMode(Buzzer_Pin,OUTPUT);

  Serial.begin(9600);
}

void alarm()
{
  //Buzzer aktif etmek için
  tone(Buzzer_Pin,440);//Ses yüksekliği
  delay(25);
  noTone(Buzzer_Pin);
  delay(600);
}

void alarm2()
{
  //Buzzer aktif etmek için
  tone(Buzzer_Pin,440);
  delay(25);
  noTone(Buzzer_Pin);
  delay(300);
}

void alarm3()
{
  //Buzzer aktif etmek için
  tone(Buzzer_Pin,440);
  delay(25);
  noTone(Buzzer_Pin);
}

void loop()
{
  //Ses dalgası üretimi
  digitalWrite(Trigger_Pin,HIGH);
  delayMicroseconds(1000);
  digitalWrite(Trigger_Pin,LOW);

  sure=pulseIn(Echo_Pin,HIGH);

  mesafe=(sure*0.034)/2;

  if(mesafe<10)
  {
    alarm3();
  }
  
  else if(mesafe<25)
  {
    alarm2();
  }
  
  else if(mesafe<50);
  {
    alarm();
  }

  Serial.print("Mesafe= ");
  Serial.println(mesafe);

}
