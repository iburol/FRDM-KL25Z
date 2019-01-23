#include "mbed.h"
#include "Servo.h"

Servo myservo(PTE21);

int main() 
{
    while (true)
    {    
        for(float p=0; p<1.0; p += 0.1) 
        {
            myservo = p;
            wait(0.2);
        }
    }  
}
