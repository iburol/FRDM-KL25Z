#include "mbed.h"              
 
Serial Xbee(PTE0, PTE1);
 
int main() 
{
    int p=0;
    while (true)
    {
        Xbee.printf("%d", p++);
        wait(2);
    }
}
