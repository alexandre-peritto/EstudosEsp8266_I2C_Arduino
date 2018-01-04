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
	int bytesBuffer = 10;
	char pesoBruto[10] = "";
	Wire.requestFrom(enderecoModulo, bytesBuffer);
	int i = 0;
	while (Wire.available()) {
		pesoBruto[i] = Wire.read();
		i = i + 1;
	}
	auto peso = strtod(pesoBruto, NULL);
	Serial.println(peso, 2);

	delay(500);
}