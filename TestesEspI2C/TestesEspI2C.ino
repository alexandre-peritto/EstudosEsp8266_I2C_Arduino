#include "ComunicacaoI2c.h"
#include <Wire.h>

void setup() {
	Serial.begin(115200);
	Wire.begin(D2, D1);
	Wire.setClockStretchLimit(1500);
}

void loop() {
	RequisitarDadosModulo(0x08);
}

void RequisitarDadosModulo(int enderecoModulo) {
	using namespace comunicacao;
	DadosI2c dadosI2c;
	Wire.requestFrom(enderecoModulo, 2);
	if (Wire.available() == 2) {
		 Wire.readBytes((byte*)&dadosI2c, 2);
	}
	Serial.println(dadosI2c.dadoByte1);
	Serial.println(dadosI2c.dadoByte2);
	
	delay(500);
}