#include "mbed.h"
#include "Servo.h"

Servo myservo(PTE21);

int main() 
{
    while (true)
    {    
        myservo.position(-45);
        wait(2);
        myservo.position(0);
        wait(2);
        myservo.position(45);
        wait(2);
    }  
}
