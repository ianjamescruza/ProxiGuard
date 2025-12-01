#ifndef UART_H
#define UART_H

#include <avr/io.h>

void UART_Init(void);
void UART_TxChar(char ch);
void UART_SendString(char *str);
void UART_SendInt(uint16_t num);

#endif