#ifndef MyBlink_h
#define MyBlink_h

#include "Arduino.h"
#define __PRESCALER 4
class MyBlink
{
	public:
		MyBlink(uint8_t pin);
		MyBlink(uint8_t pin, uint8_t pwm);
		MyBlink(uint8_t pin, uint16_t onTime,uint16_t offTime);
		void set(uint8_t pwm);
		void set(uint16_t onTime,uint16_t offTime);
		void run();
		
	private:
		uint8_t __pin;
		uint32_t __lastEvent;
		uint32_t __onTime;
		uint32_t __offTime;
		boolean  __state;
};

#endif
