#include "MyBlink.h"


MyBlink::MyBlink(uint8_t pin) :	//init without parameters
__pin(pin),
__onTime(200000),
__offTime(800000)
{
	pinMode(pin,OUTPUT);
}

MyBlink::MyBlink(uint8_t pin, uint8_t pwm) : // init as pwm
__pin(pin)
{
	pinMode(pin,OUTPUT);
	set(pwm);
}

MyBlink::MyBlink(uint8_t pin, uint16_t onTime, uint16_t offTime) : // init as blink (in millis)
__pin(pin)
{
	pinMode(pin,OUTPUT);
	set(onTime,offTime);
}

void MyBlink::set(uint8_t pwm)
{
	__onTime  =        pwm  << __PRESCALER;
    __offTime = (255 - pwm) << __PRESCALER;
}
void MyBlink::set(uint16_t onTime, uint16_t offTime)
{
    digitalWrite(__pin,LOW);
    __lastEvent = micros();
    __state = false;
	__onTime  =  onTime*1000L;	//time is set in millis but handled in micros
	__offTime = offTime*1000L;

}

void MyBlink::run()
{
	if (__state)
  {
    if ( (micros()-__lastEvent) < __onTime ) return;
    if (__offTime) // don't turn off LED if permanent on
    {
      digitalWrite(__pin,LOW);
      __state = false;
    }
    __lastEvent += __onTime;
  }
  else
  {
    if ( (micros()-__lastEvent) < __offTime ) return;
    if (__onTime) // don't turn on LED if permanent off
    {
      digitalWrite(__pin,HIGH);
      __state = true;
    }
    __lastEvent += __offTime;
  }  
}




