#include "mbed.h"

Serial pc(USBTX, USBRX);
DigitalIn Button(PTE1, PullUp);
DigitalOut LedRojo(LED1);
DigitalOut LedVerde(LED2);
DigitalOut LedAzul(LED3);

int main() 
{
    while (1)
    {
        if(Button == 0)
        {
            LedRojo = 0;
            LedVerde = 1;
            LedAzul = 1;
        }
        else
        {
            LedRojo = 1;
            LedVerde = 1;
            LedAzul = 1;
        }
    }
}
