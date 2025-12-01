ProxiGuard - Bare-Metal ATmega328P Ultrasonic Proximity Alert System with Multi-Stage Feedback

Description:
	ProxiGuard is a high-precision distance detection system built on the ATmega328P 
	microcontroller without the use of high-level Arduino libraries. It utilizes an 
	HC-SR04 ultrasonic sensor to detect objects within specific proximity zones and 
	provides differentiated audio-visual feedback to the user.
Key Features:
	I.  Precision Timing: Utilizes the ATmega328P's 16-bit Timer1 Input Capture Unit 
            (ICP1) to measure sensor echo pulses with 0.5 microsecond resolution, A highly 
            accurate distance calculations compared to standard software polling methods.
	II. Zone-Based Logic: Implements a distinct "Threat Level" algorithm based on 
            distance:
		o Critical Zone (0–5 cm): Full visual alert (3 LEDs) and urgent audio 
                  warning (3x Long Beeps).
		o Warning Zone (6–9 cm): High visual alert (2 LEDs) and mixed audio 
                  warning (1 Short + 1 Long Beep).
		o Caution Zone (10–15 cm): Moderate visual alert (1 LED) and subtle 
                  audio warning (1 Short Beep).
	III. Direct Hardware Control: All GPIO manipulation is performed via bitwise operations 
             on the PORTD registers for maximum execution speed.
	IV.  Modular Architecture: The codebase is separated into drivers (sensor.c, gpio.c) and
             application logic (main.c), making the code maintainable and scalable.
Hardware Stack:
	MCU: Microchip ATmega328P.
 	Sensor: HC-SR04 Ultrasonic Module.
	Output: 3x Status LEDs, 1x Piezoelectric Buzzer.

