#include "mbed.h"              

Serial pc(USBTX, USBRX); 
Serial Xbee(PTE22, PTE23);
 
int main() 
{
    char c;
    int p=0;
    while (true)
    {
        Xbee.printf("%d", p++);
        if(Xbee.readable())
        {
            c = Xbee.getc();
            while(c!= '\r')
            {
                pc.printf("%c", c);
                c = Xbee.getc();
            }
        wait(2);
        }
    }
}
