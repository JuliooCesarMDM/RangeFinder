#ifndef RANGEFINDER_h
#define RANGEFINDER_h
#include "Arduino.h"
class RF
{
  public:
    RF() {};
    void Init();
    int16_t SensorFiltered16Bits(int16_t Value_NotFiltered, int16_t MinValue, int16_t MaxValue);
  private:
#define  NUM_AVERAGES_SONAR 4                    //NÚMERO DE ITERAÇÕES PARA O SONAR
    int16_t  Value_Filtered16Bits;               //VALOR FINAL FILTRADO DO SENSOR
    int16_t _history16Bits[NUM_AVERAGES_SONAR];  //VALORES GUARDADOS PARA FILTRAGEM
    int16_t _history_ptr16Bits;                  //VALORES GUARDADOS PARA TABELA DA FILTRAGEM
};
extern RF RANGEFINDER;
#endif
