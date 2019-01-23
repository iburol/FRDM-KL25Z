#include "mbed.h"
#include "TSISensor.h"

Serial pc(USBTX, USBRX);

float valor_instantaneo = 0;
float valor_anterior = 0;

int main(void) 
{
    TSISensor tsi;
    
    while (true) 
    {
        valor_instantaneo = tsi.readPercentage();
        if (valor_instantaneo != valor_anterior)
        {
            pc.printf("%f\r", valor_instantaneo);
        }
        valor_anterior = valor_instantaneo;
        wait(0.2);
    }
}
