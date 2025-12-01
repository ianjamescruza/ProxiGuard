#include "uart.h"
#include <stdio.h>
#include <stdlib.h>

#define BAUDRATE 9600
#define BAUD_PRESCALER (((F_CPU / (BAUDRATE * 16UL))) - 1)

void UART_Init(void) {
    UBRR0H = (uint8_t)(BAUD_PRESCALER >> 8);
    UBRR0L = (uint8_t)(BAUD_PRESCALER);

    UCSR0B = (1 << TXEN0);

    UCSR0C = (1 << UCSZ01) | (1 << UCSZ00);
}

void UART_TxChar(char ch) {
    while (!(UCSR0A & (1 << UDRE0)));

    UDR0 = ch;
}

void UART_SendString(char *str) {
    while (*str) {
        UART_TxChar(*str++);
    }
}

void UART_SendInt(uint16_t num) {
    char buffer[10];
    itoa(num, buffer, 10);
    UART_SendString(buffer);
}