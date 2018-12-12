int dianow;

const char chamada = 'e';
const char calltempo = 't';
const char entradavsc = 's';
const char cdelayc = 'd';
const char resetc = 'r';      //caracteres de comando serial
const char syncrtcc = 'c';
const char showrtcc = 'h';
const char syncfromc = 'j';

void checkevent();

void rectempo() //Esta funcao le do buffer serial a informacao de tempo para sincronizae o relogio
{
	long msread = 0, diaread = 0;
	msread = Serial.readStringUntil('~').toInt();
	String s = Serial.readStringUntil('~');
	diaread = s.toInt();
	Serial.println("G");
	settime(msread, diaread);
}

void entradavs() //Esta funcao recebe um tempo a ser atualizado na memoria
{
	int tmp = -1, dia = -1, mat = -1;
	String t, d, m;
	m = Serial.readStringUntil('~');
	mat = m.toInt();
	t = Serial.readStringUntil('~');
	tmp = t.toInt();
	d = Serial.readStringUntil('~');
	dia = d.toInt();
	Serial.println("G");
	if (mat != -1 && dia != -1 && tmp != -1) {
		sembe[dia][tmp] = mat;
		promw();
		promr();
	} else {
		if (dia == -1) {
			digitalWrite(13, HIGH);
		}
	}
}

void entrada() //Esta funcao faz um prompt no serial para atualizar toda a agenda
{
	for (int i = 0; i < ndias; i++) {
		for (int j = 0; j < ntempos; j++) {
			String m1 = "Digite o tempo ";
			String m2 = " do dia ";
			String mensagem = m1 + j + m2 + i;
			Serial.println(mensagem);
			int a;
			while (Serial.available() == 0) {
				a++;
				if (a == 100000) {
					break;
				}
			}
			String in = Serial.readString();
			sembe[i][j] = in.toInt();
			Serial.println(sembe[i][j]);
		}
	}
	dianow = -1;
	set();
	promw();
}

void changedelay() //Recebe do serial um novo delay do display (tempo por linha)
{
	dispdelay = Serial.readStringUntil('~').toInt();
}

void reset() //Reseta os dados da agenda a partir da matriz padrao
{
	if (Serial.readStringUntil('~') == "eset") {
		promw();
		promr();
	}
}

void syncrtc() //Recebe dados do serial para atualizar o RTC
{
	int ano  = Serial.readStringUntil('~').toInt();
	int mes  = Serial.readStringUntil('~').toInt();
	int dia  = Serial.readStringUntil('~').toInt();
	int hor  = Serial.readStringUntil('~').toInt();
	int min  = Serial.readStringUntil('~').toInt();
	int sec  = Serial.readStringUntil('~').toInt();
	DateTime tempo = DateTime(ano, mes, dia, hor, min, sec);
	rtc.adjust(tempo);
	Serial.println("updated");
	syncfromrtc();
}

void checkevent() //Le o primeiro caractere quando e recebida informacao serial para chamar as funcoes
{
	if (Serial.available()) {
		char a = Serial.read();
		if (a == chamada) {
			entrada();
		}
		if (a == calltempo) {
			rectempo();
		}
		if (a == entradavsc) {
			entradavs();
		}
		if (a == cdelayc) {
			changedelay();
		}
		if (a == resetc) {
			reset();
		}
		if (a == syncrtcc) {
			syncrtc();
		}
		if (a == showrtcc) {
			showrtc();
		}
                if (a == syncfromc){
                        syncfromrtc();
                }
	}
}

void showrtc(){
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
}

void serialEvent()
{
	checkevent();
}
