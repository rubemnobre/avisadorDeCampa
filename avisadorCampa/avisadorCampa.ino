#include<EEPROM.h>

const uint8_t PROGMEM fonte[96][7] = {
   0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,   // 0x20, Space
   0x04, 0x04, 0x04, 0x04, 0x04, 0x00, 0x04,   // 0x21, !
   0x09, 0x09, 0x12, 0x00, 0x00, 0x00, 0x00,   // 0x22, "
   0x0a, 0x0a, 0x1f, 0x0a, 0x1f, 0x0a, 0x0a,   // 0x23, #
   0x04, 0x0f, 0x14, 0x0e, 0x05, 0x1e, 0x04,   // 0x24, $
   0x19, 0x19, 0x02, 0x04, 0x08, 0x13, 0x13,   // 0x25, %
   0x04, 0x0a, 0x0a, 0x0a, 0x15, 0x12, 0x0d,   // 0x26, &
   0x04, 0x04, 0x08, 0x00, 0x00, 0x00, 0x00,   // 0x27, '
   0x02, 0x04, 0x08, 0x08, 0x08, 0x04, 0x02,   // 0x28, (
   0x08, 0x04, 0x02, 0x02, 0x02, 0x04, 0x08,   // 0x29, )
   0x04, 0x15, 0x0e, 0x1f, 0x0e, 0x15, 0x04,   // 0x2a, *
   0x00, 0x04, 0x04, 0x1f, 0x04, 0x04, 0x00,   // 0x2b, +
   0x00, 0x00, 0x00, 0x00, 0x04, 0x04, 0x08,   // 0x2c, ,
   0x00, 0x00, 0x00, 0x1f, 0x00, 0x00, 0x00,   // 0x2d, -
   0x00, 0x00, 0x00, 0x00, 0x00, 0x0c, 0x0c,   // 0x2e, .
   0x01, 0x01, 0x02, 0x04, 0x08, 0x10, 0x10,   // 0x2f, /
   0x0e, 0x11, 0x13, 0x15, 0x19, 0x11, 0x0e,   // 0x30, 0
   0x04, 0x0c, 0x04, 0x04, 0x04, 0x04, 0x0e,   // 0x31, 1
   0x0e, 0x11, 0x01, 0x02, 0x04, 0x08, 0x1f,   // 0x32, 2
   0x0e, 0x11, 0x01, 0x06, 0x01, 0x11, 0x0e,   // 0x33, 3
   0x02, 0x06, 0x0a, 0x12, 0x1f, 0x02, 0x02,   // 0x34, 4
   0x1f, 0x10, 0x1e, 0x01, 0x01, 0x11, 0x0e,   // 0x35, 5
   0x06, 0x08, 0x10, 0x1e, 0x11, 0x11, 0x0e,   // 0x36, 6
   0x1f, 0x01, 0x02, 0x04, 0x08, 0x08, 0x08,   // 0x37, 7
   0x0e, 0x11, 0x11, 0x0e, 0x11, 0x11, 0x0e,   // 0x38, 8
   0x0e, 0x11, 0x11, 0x0f, 0x01, 0x02, 0x0c,   // 0x39, 9
   0x00, 0x0c, 0x0c, 0x00, 0x0c, 0x0c, 0x00,   // 0x3a, :
   0x00, 0x0c, 0x0c, 0x00, 0x0c, 0x04, 0x08,   // 0x3b, ;
   0x02, 0x04, 0x08, 0x10, 0x08, 0x04, 0x02,   // 0x3c, <
   0x00, 0x00, 0x1f, 0x00, 0x1f, 0x00, 0x00,   // 0x3d, =
   0x08, 0x04, 0x02, 0x01, 0x02, 0x04, 0x08,   // 0x3e, >
   0x0e, 0x11, 0x01, 0x02, 0x04, 0x00, 0x04,   // 0x3f, ?
   0x0e, 0x11, 0x17, 0x15, 0x17, 0x10, 0x0f,   // 0x40, @
   0x04, 0x0a, 0x11, 0x11, 0x1f, 0x11, 0x11,   // 0x41, A
   0x1e, 0x11, 0x11, 0x1e, 0x11, 0x11, 0x1e,   // 0x42, B
   0x0e, 0x11, 0x10, 0x10, 0x10, 0x11, 0x0e,   // 0x43, C
   0x1e, 0x09, 0x09, 0x09, 0x09, 0x09, 0x1e,   // 0x44, D
   0x1f, 0x10, 0x10, 0x1c, 0x10, 0x10, 0x1f,   // 0x45, E
   0x1f, 0x10, 0x10, 0x1f, 0x10, 0x10, 0x10,   // 0x46, F
   0x0e, 0x11, 0x10, 0x10, 0x13, 0x11, 0x0f,   // 0x37, G
   0x11, 0x11, 0x11, 0x1f, 0x11, 0x11, 0x11,   // 0x48, H
   0x0e, 0x04, 0x04, 0x04, 0x04, 0x04, 0x0e,   // 0x49, I
   0x1f, 0x02, 0x02, 0x02, 0x02, 0x12, 0x0c,   // 0x4a, J
   0x11, 0x12, 0x14, 0x18, 0x14, 0x12, 0x11,   // 0x4b, K
   0x10, 0x10, 0x10, 0x10, 0x10, 0x10, 0x1f,   // 0x4c, L
   0x11, 0x1b, 0x15, 0x11, 0x11, 0x11, 0x11,   // 0x4d, M
   0x11, 0x11, 0x19, 0x15, 0x13, 0x11, 0x11,   // 0x4e, N
   0x0e, 0x11, 0x11, 0x11, 0x11, 0x11, 0x0e,   // 0x4f, O
   0x1e, 0x11, 0x11, 0x1e, 0x10, 0x10, 0x10,   // 0x50, P
   0x0e, 0x11, 0x11, 0x11, 0x15, 0x12, 0x0d,   // 0x51, Q
   0x1e, 0x11, 0x11, 0x1e, 0x14, 0x12, 0x11,   // 0x52, R
   0x0e, 0x11, 0x10, 0x0e, 0x01, 0x11, 0x0e,   // 0x53, S
   0x1f, 0x04, 0x04, 0x04, 0x04, 0x04, 0x04,   // 0x54, T
   0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x0e,   // 0x55, U
   0x11, 0x11, 0x11, 0x11, 0x11, 0x0a, 0x04,   // 0x56, V
   0x11, 0x11, 0x11, 0x15, 0x15, 0x1b, 0x11,   // 0x57, W
   0x11, 0x11, 0x0a, 0x04, 0x0a, 0x11, 0x11,   // 0x58, X
   0x11, 0x11, 0x0a, 0x04, 0x04, 0x04, 0x04,   // 0x59, Y
   0x1f, 0x01, 0x02, 0x04, 0x08, 0x10, 0x1f,   // 0x5a, Z
   0x0e, 0x08, 0x08, 0x08, 0x08, 0x08, 0x0e,   // 0x5b, [
   0x10, 0x10, 0x08, 0x04, 0x02, 0x01, 0x01,   // 0x5c, ctrl barra
   0x0e, 0x02, 0x02, 0x02, 0x02, 0x02, 0x0e,   // 0x5d, ]
   0x04, 0x0a, 0x11, 0x00, 0x00, 0x00, 0x00,   // 0x5e, ^
   0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x1f,   // 0x5f, _ 
   0x04, 0x04, 0x02, 0x00, 0x00, 0x00, 0x00,   // 0x60, `
   0x00, 0x0e, 0x01, 0x0d, 0x13, 0x13, 0x0d,   // 0x61, a
   0x10, 0x10, 0x10, 0x1c, 0x12, 0x12, 0x1c,   // 0x62, b
   0x00, 0x00, 0x00, 0x0e, 0x10, 0x10, 0x0e,   // 0x63, c
   0x01, 0x01, 0x01, 0x07, 0x09, 0x09, 0x07,   // 0x64, d
   0x00, 0x00, 0x0e, 0x11, 0x1f, 0x10, 0x0f,   // 0x65, e
   0x06, 0x09, 0x08, 0x1c, 0x08, 0x08, 0x08,   // 0x66, f
   0x0e, 0x11, 0x13, 0x0d, 0x01, 0x01, 0x0e,   // 0x67, g
   0x10, 0x10, 0x10, 0x16, 0x19, 0x11, 0x11,   // 0x68, h
   0x00, 0x04, 0x00, 0x0c, 0x04, 0x04, 0x0e,   // 0x69, i
   0x02, 0x00, 0x06, 0x02, 0x02, 0x12, 0x0c,   // 0x6a, j
   0x10, 0x10, 0x12, 0x14, 0x18, 0x14, 0x12,   // 0x6b, k
   0x0c, 0x04, 0x04, 0x04, 0x04, 0x04, 0x04,   // 0x6c, l
   0x00, 0x00, 0x0a, 0x15, 0x15, 0x11, 0x11,   // 0x6d, m
   0x00, 0x00, 0x16, 0x19, 0x11, 0x11, 0x11,   // 0x6e, n
   0x00, 0x00, 0x0e, 0x11, 0x11, 0x11, 0x0e,   // 0x6f, o
   0x00, 0x1c, 0x12, 0x12, 0x1c, 0x10, 0x10,   // 0x70, p
   0x00, 0x07, 0x09, 0x09, 0x07, 0x01, 0x01,   // 0x71, q
   0x00, 0x00, 0x16, 0x19, 0x10, 0x10, 0x10,   // 0x72, r
   0x00, 0x00, 0x0f, 0x10, 0x0e, 0x01, 0x1e,   // 0x73, s
   0x08, 0x08, 0x1c, 0x08, 0x08, 0x09, 0x06,   // 0x74, t
   0x00, 0x00, 0x11, 0x11, 0x11, 0x13, 0x0d,   // 0x75, u
   0x00, 0x00, 0x11, 0x11, 0x11, 0x0a, 0x04,   // 0x76, v
   0x00, 0x00, 0x11, 0x11, 0x15, 0x15, 0x0a,   // 0x77, w
   0x00, 0x00, 0x11, 0x0a, 0x04, 0x0a, 0x11,   // 0x78, x
   0x00, 0x11, 0x11, 0x0f, 0x01, 0x11, 0x0e,   // 0x79, y
   0x00, 0x00, 0x1f, 0x02, 0x04, 0x08, 0x1f,   // 0x7a, z
   0x06, 0x08, 0x08, 0x10, 0x08, 0x08, 0x06,   // 0x7b, {
   0x04, 0x04, 0x04, 0x00, 0x04, 0x04, 0x04,   // 0x7c, |
   0x0c, 0x02, 0x02, 0x01, 0x02, 0x02, 0x0c,   // 0x7d, }
   0x08, 0x15, 0x02, 0x00, 0x00, 0x00, 0x00,   // 0x7e, ~
   0x1f, 0x1f, 0x1f, 0x1f, 0x1f, 0x1f, 0x1f,   // 0x7f, DEL 
};


//Matérias
const uint8_t bio = 0;
const uint8_t ef = 1;
const uint8_t el2 =  2;
const uint8_t ed = 3;
const uint8_t e2 = 4;
const uint8_t fil = 5;
const uint8_t fis = 6;
const uint8_t geo = 7;
const uint8_t his = 8;
const uint8_t mat = 9;
const uint8_t qui = 10;
const uint8_t soc = 11;
const uint8_t por = 12;
const uint8_t art = 13;
const uint8_t ing = 14;
const uint8_t ons = 15;
const uint8_t tut = 20;
const uint8_t alm = 21;
const uint8_t ite = 22;
const uint8_t pre = 23;

const unsigned long int minms = 60000; //Duração de um minuto em ms (para teste)
const char chamada = 'e'; //Comando serial que inicia a entrada de dados
const char calltempo = 't'; //Comando serial que inicia a entrada de dados
const int ntempos = 11; //Contando com intervalo, almoço e tutoria
const int ndias = 5; // Po
const int clkpin = 3;
const int datpin = 4;
const int selpin = 5;
const int setpin = 2; //Pino do botão set
const int tbounce = 20; //Tempo para debounce do botão
const int nchars = 4;
const int xdim = 5;
const int ydim = 7;

const String nome[24] = 
{"bio","ef ","el2","ed ","e2 ","fil","fis","geo","his","mat","qui","soc","por","art","ing","ons","   ","   ","   ","   ","tut","alm","int"};

uint8_t show[ydim][nchars*xdim];

void paramatriz(String text){
  char chars[nchars+1];
  text.toCharArray(chars,nchars);
  strupr(chars);
  for(uint8_t i = 0;i < nchars;i++){
    for(uint8_t k = 0;k < ydim;k++){
      for(uint8_t j = 0;j < xdim;j++){
        show[k][i*xdim + j] = bitRead(pgm_read_word(&fonte[(int)chars[i] - 0x20][k]),xdim-1-j);
      }
    }
  }
}
/*
typedef struct{
  uint8_t tempo[ntempos]; 
}dia;
dia semana[ndias];*/
uint8_t sembe[ndias][ntempos] = {
  23,13,8,22,0,9,20,21,14,5,12,
  23,4,4,22,9,1,20,21,10,12,6,
  23,4,9,22,2,8,20,21,6,2,15,
  23,11,7,22,14,0,20,21,12,3,3,
  23,3,3,22,0,6,20,21,10,9,12
};

uint8_t semana[ndias][ntempos];

uint8_t dianow = -1,tempo = 0,minuto = 0;

void set(){
  dianow++;
  dianow %= ndias;
  tempo = 0;
  minuto = 0;
}

unsigned long now;

void waitserial(){
  int a;
  while(Serial.available() == 0){
        a++;
        if (a == 100000){
          break;
        }
   }
}

unsigned long int agr = 0,agora = 0;

void settime(){
  Serial.print(agora);
  waitserial();
  dianow = Serial.readString().toInt();
  waitserial();
  tempo = Serial.readString().toInt();
  waitserial();
  minuto = Serial.readString().toInt();
}

void proxdia(){
  //espera ue
  agr = millis();
  dianow++;
  dianow %= ndias;
  minuto = 0;
  tempo = 0;
  unsigned long int twait;
  if(dianow == 0){
    twait = (24*60*minms)*3-totaldia(dianow - 1);
  }else{
    twait = (24*60*minms)-totaldia(dianow - 1);
  }
  Serial.println(twait);
  while(agora-agr <= twait){
    agora = millis();
  }
  agr = 0;
  agora = 0;
}

unsigned long int totaldia(uint8_t day){
  int t = 0;
  for(int i = 0;i < ntempos;i++){
    t += duracao(semana[day][i]);
  }
  return t*minms;
}

int promw(){
  for(uint8_t i = 0;i < ndias;i++){
    for(uint8_t j = 0;j < ntempos;j++){
      EEPROM.write(i*ntempos + j,sembe[i][j]);
    }
  }
  return 0;
}

void entrada(){
  for(uint8_t i = 0;i < ndias;i++){
    for(uint8_t j = 0;j < ntempos;j++){
      String m1 = "Digite o tempo ";
      String m2 = " do dia ";
      String mensagem = m1 + j + m2 + i;
      Serial.println(mensagem);
      int a;
      while(Serial.available() == 0){
        a++;
        if (a == 100000){
          break;
        }
       }
      String in = Serial.readString();
      if(in == "-1"){
        break;
      }
      sembe[i][j] = in.toInt();
      Serial.println(sembe[i][j]);
    }
  }
  dianow = -1;
  set();
  promw();
}

uint8_t duracao(uint8_t tipo){
  if(tipo == ite){
    return 20;
  }
  if(tipo == tut){
    return 60;
  }
  if(tipo == pre){
    return 15;
  }
  return 50;
}
int promr(){
  for(uint8_t i = 0;i < ndias;i++){
    for(uint8_t j = 0;j < ntempos;j++){
      semana[i][j] = (uint8_t)EEPROM.read(i*ntempos + j);
    }
  }
  return 0;
}

void shift(uint8_t a){
  if(a == 1){
    digitalWrite(clkpin,LOW);
    digitalWrite(datpin,HIGH);
    digitalWrite(clkpin,HIGH);
    digitalWrite(clkpin,LOW);
  }else{
    digitalWrite(clkpin,LOW);
    digitalWrite(datpin,LOW);
    digitalWrite(clkpin,HIGH);
    digitalWrite(clkpin,LOW);
  }
}
const int cat = 0;
void disp(){
  for(uint8_t i = 0;i < ydim;i++){
    digitalWrite(selpin,LOW);
    for(uint8_t j = 0;j < ydim;j++){
      if(j == i){
        shift(cat);
      }
    }
    for(uint8_t j = 0;j < xdim*(nchars-1);j++){
      shift(show[i][(xdim*(nchars-1)-1) - j] * (cat?0:1));
    }
    digitalWrite(selpin,HIGH);
    delay(12);
  }
}

void setup() {
  //promw();
  promr();
  Serial.begin(9600);
  pinMode(clkpin,OUTPUT);
  pinMode(datpin,OUTPUT);
  pinMode(selpin,OUTPUT);
  pinMode(setpin,INPUT_PULLUP);
  attachInterrupt(digitalPinToInterrupt(setpin),intset,FALLING);
  set();
}

unsigned long int tset = 0,ltset = 0,temp = 0;
unsigned long int ltmin = 0;
uint8_t setprev = 0;

void intset(){
  temp = millis();
  if(temp - ltset >= tbounce){
    set();
  }
  ltset = temp;
  agora = agr;
}

unsigned long int timeshow = 1000,ltshow = 0,st = 0;

void loop() {
  temp = millis();
  if(temp - ltmin >= minms){
    minuto++;
    if(minuto == duracao(semana[dianow][tempo])){
      minuto = 0;
      tempo++;
      if(tempo == ntempos){
        proxdia();
      }
    }
    ltmin = temp;
  }
  
  if(temp-ltshow >= timeshow){
    if(st == 0){
      String ntempo;
      if(tempo == ntempos-1){
        ntempo = "fim";
      }else{
        ntempo = nome[semana[dianow][tempo+1]];
      }
      Serial.println(dianow);
      Serial.println(tempo);
      Serial.println(semana[dianow][tempo+1]);
      Serial.println(sembe[dianow][tempo+1]);
      Serial.println(nome[semana[dianow][tempo+1]]);
      paramatriz(ntempo);
      for(uint8_t i = 0;i < 7;i++){
        for(uint8_t j = 0;j < 15;j++){
          Serial.print(show[i][j]?'.':' ');
           Serial.print(" ");
           if((j+1)%5 == 0){
             Serial.print("    ");
           }
        }
        Serial.println("");
      }
      st = 1;
    }
    else{
      if(st == 1){
        paramatriz(String(duracao(semana[dianow][tempo]) - minuto)+" ");
        //Serial.println(minuto);
        for(uint8_t i = 0;i < 7;i++){
        for(uint8_t j = 0;j < 15;j++){
          Serial.print(show[i][j]?'.':' ');
           Serial.print(" ");
           if((j+1)%5 == 0){
             Serial.print("    ");
           }
        }
        Serial.println("");
        }
        st = 0;
      }
    }
    ltshow = temp;
  }
}
void serialEvent(){
  if(Serial.available() > 0){
    char a;
    a = Serial.read();
    if(a == chamada){
      entrada();
    } 
    if(a == calltempo){
      settime();
    } 
  }
}