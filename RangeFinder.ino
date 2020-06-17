#include "RANGEFINDER.h"

/******************************INFO**********************************/
//AUTOR:JULIO CESAR MATIAS
//DESENVOLVIDO OFICIALMENTE PARA A CONTROLADORA DE VOO JCFLIGHT
//DATA:FEVEREIRO DE 2020
/********************************************************************/

void setup() {
  Serial.begin(115200);
  RANGEFINDER.Init();
}

int16_t InputToFilter;
int16_t OutputFiltered;
#define AnalogRead_Min 0     //LEITURA MINIMA DO SENSOR
#define AnalogRead_Max 1024  //LEITURA MAXIMA DO SENSOR
void loop() {
  InputToFilter  = analogRead(0); //AQUI ENTRA A LEITURA DO SENSOR ULTRASSONICO (ESTOU USANDO O PINO ANALOGICO APENAS PARA EXEMPLO)
  OutputFiltered = RANGEFINDER.SensorFiltered16Bits(InputToFilter, AnalogRead_Min, AnalogRead_Max);
  Serial.print(OutputFiltered);
  Serial.print(" ");
  Serial.println(InputToFilter);
}
