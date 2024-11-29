#include "twi.h"

void initTWI() {					// master
   PORTC ❘= (1 << PC4) ❘ (1 << PC5);			// pull-up twi pins
   TWBR = 0x01;					// formula prescaler
   TWSR ❘= (1 << TWPS0);				// prescaler 4
}

void startConditionTWI() {				// sending start conditions
   TWCR ❘= (1 << TWINT) ❘ (1 << TWSTA) ❘ (1 << TWEN);	// TWINT - interrupt enable, TWSTA - start condition, TWEN - data transfer
   while(!(TWCR & (1 << TWINT))); 			// waiting for confirmation
}

void stopConditionTWI() {
   TWCR ❘= (1 << TWINT) ❘ (1 << TWSTO) ❘ (1 << TWEN);	// TWINT - interrupt enable, TWSTA - stop condition, TWEN - data transfer
}

void sendTWI(uint8_t data) {
   TWDR = data;
   TWCR ❘= (1 << TWINT) ❘ (1 << TWEN);
   while(!(TWCR & (1 << TWINT))); 
}

uint8_t readTWI() {
   TWCR ❘= (1 << TWINT) ❘ (1 << TWEA) ❘ (1 << TWEN);	// TWEA - enable acknowledge bit
   while(!(TWCR & (1 << TWINT)));
   return TWDR;
}

uint8_t lastReadTWI() {
    TWCR ❘= (1 << TWINT) ❘ (1 << TWEN);
    while(!(TWCR & (1 << TWINT)));
    return TWDR; 
}
