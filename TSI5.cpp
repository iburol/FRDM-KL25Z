#include "mbed.h"
#include "TSISensor.h"

DigitalOut LedRojo(LED1);
DigitalOut LedVerde(LED2);
DigitalOut LedAzul(LED3);

int main(void) 
{
    TSISensor tsi;
    
    while (true)
    {
        if (tsi.readPercentage() >= 0.0 && tsi.readPercentage() < 0.25)
        {
            LedAzul = 1;
            LedRojo = 0;
            LedVerde = 1;
        }
        else if (tsi.readPercentage() >= 0.25 && tsi.readPercentage() < 0.50)
        {
            LedAzul = 1;
            LedRojo = 1;
            LedVerde = 0;
        }
        else if (tsi.readPercentage() >= 0.50 && tsi.readPercentage() < 0.75)
        {
            LedAzul = 0;
            LedRojo = 1;
            LedVerde = 1;
        }
         else if (tsi.readPercentage() >= 0.75 && tsi.readPercentage() < 1.00)
        {
            LedAzul = 0;
            LedRojo = 0;
            LedVerde = 0;
        }
        wait(0.1);
    }
}
