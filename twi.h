#include <xc.h>
#include <avr/io.h>

#ifndef TWI_H_
#define TWI_H_

void initTWI();
void startConditionTWI();
void stopConditionTWI();
void sendTWI();
uint8_t readTWI();
uint8_t lastReadTWI();

#endif
