#include "RANGEFINDER.h"

//*******************************************************
//FILTRO EM 16 BITS SIGNED PARA APLICAÇÃO EM SONAR
//*******************************************************

/*
   OBSERVAÇÃO:QUANTO MAIOR O NÚMERO AVERAGES MELHOR SERÁ O FILTRO,MAS EM CONSEQUENCIA A LEITURA FICA MUITO LENTA,PARA ALGORITIMOS
   QUE EXIGEM UMA LEITURA RAPIDA DE UM DETERMINADO SENSOR,O NÚMERO DE AVERAGES DEVE SER REDUZIDO.
*/

RF RANGEFINDER;

void RF::Init() {
  //INICIALIZA O HISTORICO DO FILTRO
  for (uint8_t i = 0; i < NUM_AVERAGES_SONAR; i++)_history16Bits[i] = Value_Filtered16Bits;
}

//FILTRA O SENSOR E RETORNA O VALOR FILTRADO
int16_t RF::SensorFiltered16Bits(int16_t Value_NotFiltered, int16_t MinValue, int16_t MaxValue) {
  int16_t temp_dist;
  int16_t total = 0;
  //QUAL A LEITURA MAXIMA E MINIMA DO SENSOR APLICADO?
  Value_NotFiltered = constrain(Value_NotFiltered, MinValue, MaxValue);
  //APLICA O RATE MAX E MIN NA LEITURA DO SENSOR
  if (Value_NotFiltered > Value_Filtered16Bits)temp_dist = min(Value_Filtered16Bits + 20, Value_NotFiltered);
  else                                         temp_dist = max(Value_Filtered16Bits - 20, Value_NotFiltered);
  //ADICIONA O FILTRO
  _history16Bits[_history_ptr16Bits] = temp_dist;
  //INCREMENTA O FILTRO
  _history_ptr16Bits++;
  //INICIALIZA O FILTRO
  if (_history_ptr16Bits == NUM_AVERAGES_SONAR) _history_ptr16Bits = 0;
  //FINALIZA O FILTRO
  for (uint8_t i = 0; i < NUM_AVERAGES_SONAR; i++) total += _history16Bits[i];
  //FINALIZA A FILTRAGEM DIVIDINDO O VALOR DA SAIDA FILTRADA PELO NÚMERO DE AVERAGES
  Value_Filtered16Bits = total / NUM_AVERAGES_SONAR;
  //RETORNA A DISTANCIA DO SENSOR FILTRADA
  return Value_Filtered16Bits;
}
