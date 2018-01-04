#ifndef _COMUNICACAOI2C_h
#define _COMUNICACAOI2C_h

#if defined(ARDUINO) && ARDUINO >= 100
	#include "Arduino.h"
#else
	#include "WProgram.h"
#endif

namespace comunicacao
{
	struct DadosVolume
	{
		double pesoBruto;
	};
}
#endif