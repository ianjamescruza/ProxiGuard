#ifndef SENSOR_H
#define SENSOR_H

#include <avr/io.h>

#define TRIG_PIN    PD7
#define ECHO_PIN    PB0

void Sensor_Init(void);
uint16_t Sensor_GetDistance(void);

#endif