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
	auto pacote = "hello!";
	Wire.write(pacote);
	Serial.println(pacote);
}