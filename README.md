# I2C-TWI-interface
I2C(TWI) interface for AVR 8-bit MCU

Example to send 1 byte to the slave the sequence is needed:
1. startConditionTWI();  // ST
2. sendTWI();            // SAD+W
3. sendTWI();            // SUB
4. sendTWI();            // data
5. stopConditionTWI();   // STOP

Example of data acquisition:
1. startConditionTWI();  // ST
2. sendTWI();            // SAD+W
3. sendTWI();            // SUB
4. startConditionTWI();  // ST
5. sendTWI();            // SAD+R
6. dat = lastReadTWI();
7. stopConditionTWI();   // STOP
