#include "mbed.h"
#include "TextLCD.h"

DigitalOut myled(LED1);

#ifdef TARGET_KL25Z
    TextLCD lcd(PTA13, PTD5, PTA4, PTA5, PTC8, PTC9);
    AnalogIn button(PTB0);
    PwmOut backlight(PTD0);
#endif

int main()
{
#ifdef TARGET_KL25Z
    backlight = 1;
    lcd.cls();
    wait(0.5);
#endif
    while (1)
    {

#ifdef TARGET_KL25Z
        unsigned long valueint = button.read_u16();
        float valuereal = button.read();
        lcd.cls();
        lcd.locate(0,0);
        lcd.printf("BUTTON : %d", valueint);        
        lcd.locate(0,1);
        lcd.printf("BUTTON : %f", valuereal);
#endif
        wait(0.2);
    }
}
