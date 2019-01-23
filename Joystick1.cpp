#include "mbed.h"

Serial pc(USBTX, USBRX); // tx, rx
AnalogIn posX(PTB0);
AnalogIn posY(PTB1);

int main() 
{
    while (1)
    {
        float valorXreal = posX.read();
        float valorYreal = posY.read();
        unsigned long valorXint = posX.read_u16();
        unsigned long valorYint = posY.read_u16();
        pc.printf("valor real: %f %f; valor entero %d, %d:\r", valorXreal, valorYreal, valorXint, valorYint);
        wait(0.5);
    }
}
