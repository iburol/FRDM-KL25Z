#include "mbed.h"
#include "TSISensor.h"

Serial pc(USBTX, USBRX);

float valor = 0;

int main(void) 
{
    TSISensor tsi;
    
    while (true) 
    {
        valor = tsi.readPercentage();
        pc.printf("%f\r", valor);
        wait(0.5);
    }
}
