
int tempo = 0, minuto = 0, segundo = 0;

void set() //Zera a temporizacao e incrementa o dia
{
	dianow++;
	dianow %= ndias;
	tempo = 0;
	minuto = 0;
}

long now;
long int agr = 0, agora = 0;

void checkevent();

void settime(long msread, long diaread) //Recebe a informacao de tempo e atualiza
{
	long twait = 0;
	agora = millis();
	agr = millis();
	digitalWrite(13, HIGH);
	segundo = (msread % minms) / 1000;
	if (diaread - 1 < 5) {
		if (msread / minms >= initmin && msread / minms <= initmin + totaldia(diaread - 1) / minms) {
			int mn = 0, tmp = 0, m = 0;
			do {
				mn++;
				m++;
				if (mn == duracao(semana[diaread - 1][tmp])) {
					mn = 0;
					tmp++;
				}
			} while (m != (msread / minms) - initmin);
			tempo = tmp;
			minuto = mn;
			dianow = diaread - 1;
		} else {
			if (msread / minms > initmin) {
				twait = (24 * 60 * minms) - msread;
				dianow = diaread;
			} else {
				twait = initmin * minms - msread;
				dianow = diaread - 1;
			}
			while (agora - agr <= twait) {
				agora = millis();
				checkevent();
			}
			agora = 0;
			agr = 0;
			tempo = 0;
			minuto = 0;
			segundo = 0;
		}
	} else {
		twait = (24 * 60 * minms) * (8 - diaread) + initmin * minms - msread;
		while (agora - agr <= twait) {
			agora = millis();
			checkevent();
		}
		agora = 0;
		agr = 0;
		tempo = 0;
		minuto = 0;
		segundo = 0;
	}
	digitalWrite(13, LOW);
}

void proxdia() //Realiza as atualizacoes e entra em modo de espera o proximo dia comecar
{
	agr = millis();
	dianow++;
	dianow %= ndias;
	minuto = 0;
	tempo = 0;
	segundo = 0;
	long int twait;
	if (dianow == 0) {
		twait = (24 * 60 * minms) * 3 - totaldia(dianow - 1);
	} else {
		twait = (24 * 60 * minms) - totaldia(dianow - 1);
	}
	digitalWrite(13, HIGH);
	while (agora - agr <= twait) {
                checkevent();  //Para receber eventos seriais mesmo em modo de espera
		agora = millis();
	}
	digitalWrite(13, LOW);
	agora = 0;
	agr = 0;
}

long int totaldia(int day) //Recebe um dia do calendario e retorna o numero de ms de aula no dia
{
	int t = 0;
	for (int i = 0; i < ntempos; i++) {
		t += duracao(semana[day][i]);
	}
	return t * minms;
}

int duracao(int tipo) //Recebe uma materia e retorna sua duracao
{
	if (tipo == ite) {
		return 20;
	}
	if (tipo == tut) {
		return 60;
	}
	if (tipo == pre) {
		return 15;
	}
	return 50;
}

long int tset = 0, ltset = 0, temp = 0;
long int ltmin = 0;
int setprev = 0;

long timeshow = 3000, ltshow = 0, st = 0;

void syncfromrtc(){ //Sincroniza o tempo do arduino com o rtc
	long msnow, dow;
	DateTime agr = rtc.now();
	dow = agr.dayOfTheWeek();
	Serial.println(agr.unixtime());
	msnow = (long)agr.unixtime() % (long)86400;
	Serial.println(msnow);
	msnow *= 1000;
	Serial.println(msnow);
	set();
	settime(msnow, dow);
}

void update() //Atualiza o tempo baseado no oscilador do arduino
{
  temp = millis();
  if (temp - ltmin >= 1000) {
    segundo++;
    if (segundo == minms / 1000) {
      minuto++;
      segundo = 0; 
      if (minuto == 5) { //Sincroniza com o rtc para eliminar o drift do oscilador do arduino
        set();
        syncfromrtc();
      }
      if (minuto == 45) {
        set();
        syncfromrtc();
      }
    }
    if (minuto == duracao(semana[dianow][tempo])) {
      minuto = 0;
      tempo++;
      if (tempo == ntempos) {
        proxdia();
      }
    }
    ltmin = temp;
  }
  if (temp - ltshow >= timeshow) {
    if (st == 0) {
      disptempo(dianow,tempo);
      st = 1;
    } else {
      if (st == 1) {
        paramatriz(String(duracao(semana[dianow][tempo]) - minuto) + " ");
        st = 0;
      }
    }
    ltshow = temp;
  }
}
