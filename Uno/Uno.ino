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
	DadosI2c dadosI2c;
	dadosI2c.dadoByte1 = 25;
	dadosI2c.dadoByte2 = 14;
	Wire.write((byte*)&dadosI2c, 2);
	Serial.println(dadosI2c.dadoByte1);
	Serial.println(dadosI2c.dadoByte2);
}