/*
	a siple example to demonstrate the MyBlink library  with serial interface
	
	call on Serial '#l 4' for PWM (whitespace and one digit)
	
	or 
	
	'#l200800'  for blink (six digits)

*/


#include "MyBlink.h"

#define _COMMAND_CHAR '#'
#define _THIS_DEVICE_ID 'l'

// initialize at pin 13
MyBlink led(13);

// Serial input buffer
char MySerialBuffer[] = {0,0,0,0};

// buffer to compute onTime and offTime
uint16_t temp[2];


void setup() {
  Serial.begin(9600);
  Serial.setTimeout(5);
}

void loop()
{

// this one always needs to be in the loop
led.run();
  
// check if there was al valid serial input
if (  Serial.available()  &&  Serial.readBytes(MySerialBuffer,4) == 4  &&  ( 
        MySerialBuffer[4]  ||  ( MySerialBuffer[0]==_COMMAND_CHAR  &&  MySerialBuffer[1]==_THIS_DEVICE_ID  )
     )  )
     {
        switch (MySerialBuffer[2])
        {
          case 0x20: // if first char is a whitespace set pwm (one digit)
            led.set(  pow(MySerialBuffer[3]&0x0f,2)*3  );
            break;
            
          default:
			// get the first two digits
            temp[0]  = MySerialBuffer[2]&0x0f;
            temp[0] *= 10;
            temp[0] += MySerialBuffer[3]&0x0f;
            temp[0] *= 10;
			// get the remaining four digits
            if (Serial.readBytes(MySerialBuffer,4) != 4) return;
            temp[0] += MySerialBuffer[0]&0x0f;
            temp[1]  = MySerialBuffer[1]&0x0f;
            temp[1] *= 10;
            temp[1] += MySerialBuffer[2]&0x0f;
            temp[1] *= 10;
            temp[1] += MySerialBuffer[3]&0x0f;
            led.set(temp[0],temp[1]);
            break;
            
        } // end switch command
        
     } // end if Serial
    
} // end loop

