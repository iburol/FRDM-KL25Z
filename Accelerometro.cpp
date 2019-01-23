#include "mbed.h"
#include "MMA8451Q.h"

#define MMA8451_I2C_ADDRESS (0x1d<<1)

Serial pc(USBTX, USBRX);

float parametro_X = 0;
float parametro_Y = 0;
float parametro_Z = 0;

int main(void) {
    MMA8451Q acc(PTE25, PTE24, MMA8451_I2C_ADDRESS);

    while (true) {
        parametro_X = acc.getAccX();
        parametro_Y = acc.getAccY();
        parametro_Z = acc.getAccZ();
        pc.printf("Posiciones (X,Y,Z) = (%f,%f,%f)\r", parametro_X, parametro_Y, parametro_Z);
        wait(2);
    }
}
