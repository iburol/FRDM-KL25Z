#include "mbed.h"              
#include "MMA8451Q.h"

#define MMA8451_I2C_ADDRESS (0x1d<<1)

Serial pc(USBTX, USBRX); 
Serial Xbee(PTE0, PTE1);
DigitalOut LedRojo(LED1);
MMA8451Q acc(PTE25, PTE24, MMA8451_I2C_ADDRESS);

float parametro_X = 0;
float parametro_Y = 0;
float parametro_Z = 0;
int num = 0;
int i = 0;
char c;
char cad[3] = {0, 0, 0};
int p=0;
 
int main() 
{ 
    while (true)
    {
        Xbee.printf("%d", p++);
        if(Xbee.readable())
        {
            c = Xbee.getc();
            while(c!= '\r')
            {
                pc.printf("%c\r", c);
                c = Xbee.getc();
                cad[i++] = c;
            }
        }
        i = 0;
        if((cad[0] >= '0' and cad[0] <= '9'))
        {
            num = cad[0] - '0';
        }
        if(cad[1] >= '0' and cad[1] <= '9')
        {
            num = cad[1] - '0';
        }
        if(cad[2] >= '0' and cad[2] <= '9')
        {
            num = cad[2] - '0';
        }
        if(cad[0] == 'L' or cad[1] == 'L' or cad[2] == 'L')
        {
            LedRojo = 0;
            wait(num*0.1);
            LedRojo = 1;
            wait(num*0.1);
            LedRojo = 0;
            wait(num*0.1);
            LedRojo = 1;
            wait(num*0.1);
        }
        if(cad[0] == 'A' or cad[1] == 'A' or cad[2] == 'A')
        {
            parametro_X = acc.getAccX();
            parametro_Y = acc.getAccY();
            parametro_Z = acc.getAccZ();
            pc.printf("Posiciones (X,Y,Z) = (%f,%f,%f)\r", parametro_X, parametro_Y, parametro_Z);
        }
        wait(2);
    }
}
