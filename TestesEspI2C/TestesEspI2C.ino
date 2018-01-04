#include <Wire.h>

void setup() {
	Serial.begin(115200);
	Wire.begin(D2, D1);
}

void loop() {
	RequisitarDadosModulo(0x08);
}

void RequisitarDadosModulo(int enderecoModulo) {
	Wire.requestFrom(enderecoModulo, 6);
	String conteudo = "";
	while (Wire.available()) {
		const char c = Wire.read();
		conteudo += c;
	}
	Serial.println(conteudo);
	delay(500);
}