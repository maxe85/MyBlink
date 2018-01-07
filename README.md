# MyBlink
Arduino MyBlinkPWM

A tiny libray to run a blink without delay, it ca also create a PWM at any pin

initialize it like that:

    MyBlink blink(pin); // default: 200 ms on / 800 ms off

  or since the constructor is overloaded

    MyBlink blink(pin, pwm); // creates software PWM at the pin, pwm is byte

  or

    MyBlink blink(pin, onTime, offTime); // times are in milliseconds and int


use it like that:

  include the objects methode run() in the loop, like that:

    loop() {
      
      blink.run();
      
    }
    
adjust it like that:

    blink.set(pwm); // sets a pwm to the blink object
  
  or since the set() ist overloaded you can also use 
  
    blink.set(onTime, offTime);
    
  
