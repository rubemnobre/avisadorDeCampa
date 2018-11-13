#include <RTClib.h>
#include<Wire.h>
RTC_DS1307 rtc; //objeto do rtc

void setup()
{
	// put your setup code here, to run once:
	Serial.begin(9600);
	pinMode(13,OUTPUT);
	
	digitalWrite(13,HIGH);
	Wire.begin();
	rtc.begin();
}

void loop()
{
	digitalWrite(13,LOW);
	DateTime now = rtc.now();
	digitalWrite(13,HIGH);
	Serial.print(now.year(), DEC);
	Serial.print('/');
	Serial.print(now.month(), DEC);
	Serial.print('/');
	Serial.print(now.day(), DEC);
	Serial.print(' ');
	Serial.print(now.hour(), DEC);
	Serial.print(':');
	Serial.print(now.minute(), DEC);
	Serial.print(':');
	Serial.print(now.second(), DEC);
	Serial.println();
	digitalWrite(13,HIGH);
	delay(1000);
}
void serialEvent(){
	int ano  = Serial.readStringUntil('~').toInt();
	int mes  = Serial.readStringUntil('~').toInt();
	int dia  = Serial.readStringUntil('~').toInt();
	int hor  = Serial.readStringUntil('~').toInt();
	int min  = Serial.readStringUntil('~').toInt();
	int sec  = Serial.readStringUntil('~').toInt();
	DateTime tempo = DateTime(ano,mes,dia,hor,min,sec);
	rtc.adjust(tempo);
}
