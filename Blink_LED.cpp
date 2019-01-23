#include "mbed.h"

DigitalOut LedRojo(LED1);
DigitalOut LedVerde(LED2);
DigitalOut LedAzul(LED3);

int main() {
    while(1) {
        LedRojo = 0;
        LedVerde = 1;
        LedAzul = 1;
        wait(2);
        LedRojo = 1;
        LedVerde = 0;
        LedAzul = 1;
        wait(2);
        LedRojo = 1;
        LedVerde = 1;
        LedAzul = 0;
        wait(2);
        LedRojo = 0;
        LedVerde = 0;
        LedAzul = 0;
        wait(2);
    }
}
