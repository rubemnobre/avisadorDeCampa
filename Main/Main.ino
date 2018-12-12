#include <RTClib.h>
#include<Wire.h>

RTC_DS1307 rtc; //objeto do rtc

//Materias
const int bio =  0;
const int ef  =  1;
const int el2 =  2;
const int ed  =  3;
const int e2  =  4;
const int fil =  5;
const int fis =  6;
const int geo =  7;
const int his =  8;
const int mat =  9;
const int qui = 10;
const int soc = 11;
const int por = 12;
const int art = 13;
const int ing = 14;
const int ons = 15;
const int tc1 = 16;
const int tc2 = 17;
const int tc3 = 18;
const int tc4 = 19;
const int tc5 = 20;
const int tut = 21;
const int alm = 22;
const int ite = 23;
const int pre = 24;

const long int minms = 60000; //DuraÃ§Ã£o de um minuto em ms (para teste)
const int ntempos = 11; //Contando com intervalo, almoÃ§o e tutoria
const int ndias = 5; // Po
const int nchars = 4;
const int initmin = 435;
int dispdelay = 3000;

int sembe[ndias][ntempos] = {
  pre, art, his, ite,  bio, mat, tut, alm, ing, fil, por,
  pre,  e2,  e2, ite,  mat,  ef, tut, alm, qui, por, fis,
  pre,  e2, mat, ite,  el2, his, tut, alm, fis, el2, ons,
  pre, soc, geo, ite,  ing,  ef, tut, alm, por,  ed,  ed,
  pre,  ed,  ed, ite,  bio, fis, tut, alm, qui, mat, por
};

int semana[ndias][ntempos];

const int pinlat = 6;
const int pinclk = 5;
const int pinser = 7;
const int pinoud = 4;

void setup()
{
	//promw();
	promr();
	Serial.begin(9600);
	Wire.begin();
	rtc.begin();
	set();
	syncfromrtc();
	pinMode(13, OUTPUT);
	pinMode(pinlat, OUTPUT);
	pinMode(pinclk, OUTPUT);
	pinMode(pinser, OUTPUT);
	pinMode(pinoud, OUTPUT);
	digitalWrite(13, LOW);
	digitalWrite(pinoud, LOW);
}

void loop()
{
	disp();  //Atualizar o display
	update();//Atualizar a temporizacao
}

