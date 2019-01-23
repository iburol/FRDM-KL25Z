#include "mbed.h"
#include "MMA8451Q.h"
#include<math.h>

#define MMA8451_I2C_ADDRESS (0x1d<<1)
#define pi 3.14159265358979323846

Serial pc(USBTX, USBRX); // tx, rx

float parametro_X = 0;
float parametro_Y = 0;
float parametro_Z = 0;
float angulo_XZ = 0;
float angulo_YZ = 0;

int main(void) {
    MMA8451Q acc(PTE25, PTE24, MMA8451_I2C_ADDRESS);

    while (true) {
        parametro_X = acc.getAccX();
        parametro_Y = acc.getAccY();
        parametro_Z = acc.getAccZ();
        angulo_XZ = abs((180*atan2(parametro_X, parametro_Z))/pi);
        angulo_YZ = abs((180*atan2(parametro_Y, parametro_Z))/pi);
        
        pc.printf("Inclinaciones (XZ,YZ) = (%f,%f)\r", angulo_XZ, angulo_YZ);
        wait(2);
    }
}
