#include "mbed.h"              

Serial pc(USBTX, USBRX);

int main() 
{
    while (1)
    {
        pc.printf("Hello World!\n");
        wait (1);
    }
}
