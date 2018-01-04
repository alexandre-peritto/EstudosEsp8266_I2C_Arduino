#include "ComunicacaoI2c.h"
#include <Wire.h>

void setup() {
	Serial.begin(115200);
	Wire.begin(0x08);
	Wire.onRequest(Evento_RequisicaoDaCentral);
}

void loop() {
	delay(100);
}

void Evento_RequisicaoDaCentral() {
	using namespace comunicacao;
	double pesoBruto = 1.618;
	char dados[10];
	dtostrf(pesoBruto, 6, 3, dados);
	Wire.write(dados, 10);
	Serial.println(dados);
}