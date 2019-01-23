#include "mbed.h"
#include "MMA8451Q.h"

#define MMA8451_I2C_ADDRESS (0x1d<<1)

Serial xbee(PTE0, PTE1);

float parametro_X = 0;

int main(void) {
    MMA8451Q acc(PTE25, PTE24, MMA8451_I2C_ADDRESS);

    while (true) {
        parametro_X = acc.getAccX();
        xbee.printf("X = %f\r", parametro_X);
        wait(2);
    }
}
