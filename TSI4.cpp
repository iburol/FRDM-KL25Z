#include "mbed.h"
#include "TSISensor.h"

DigitalOut LedRojo(LED1);
DigitalOut LedVerde(LED2);
DigitalOut LedAzul(LED3);

int main(void) 
{
    TSISensor tsi;
    LedVerde = 1;
    
    while (true) 
    {
        if (tsi.readPercentage() > 0)
        {
            LedAzul = 0;
            LedRojo = 1;
        }
        else
        {
            LedAzul = 1;
            LedRojo = 0;
        }
        wait(0.1);
    }
}
