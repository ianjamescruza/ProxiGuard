#include <avr/io.h>
#include <util/delay.h>
#include "gpio.h"
#include "sensor.h"
#include "uart.h" 

int main(void) {
    // Initialize peripherals
    GPIO_Init();
    Sensor_Init();
    UART_Init();   

    uint16_t dist = 0;

    // Startup sequence
    LED_Control(1, 1, 1);
    UART_SendString("System Initializing...\r\n"); 
    _delay_ms(200);
    All_Off();
    _delay_ms(200);

    while (1) {
        dist = Sensor_GetDistance();

        //PRINT TO SERIAL MONITOR 
        UART_SendString("Distance: ");
        UART_SendInt(dist);
        UART_SendString(" cm\r\n");

        // 0 – 34 cm
        if (dist > 0 && dist <= 34) {
            LED_Control(1, 1, 1); 
            Buzzer_LongBeep(3);
        }
        
        // 35 – 74 cm
        else if (dist >= 35 && dist <= 74) {
            LED_Control(0, 1, 1); 
            Buzzer_ShortBeep(1);
            _delay_ms(100);       
            Buzzer_LongBeep(1);
        }
        // 75 – 100 cm 
        else if (dist >= 75 && dist <= 100) {
            LED_Control(0, 0, 1); 
            Buzzer_ShortBeep(1);
        }

        // Out of Range
        else {
            All_Off();
        }

        _delay_ms(200);
    }

    return 0;
}