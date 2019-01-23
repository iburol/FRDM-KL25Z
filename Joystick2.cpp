#include "mbed.h"

Serial pc(USBTX, USBRX);
DigitalIn Button(PTE1, PullUp);

int main() 
{
    while (1)
    {
        if(Button == 0)
        {
            pc.printf("Boton presionado\r");
            wait(0.25);
        }
        else
        {
            pc.printf("Boton no presionado\r");
            wait(0.25);
        }
    }
}
