#include "MicroBit.h"

MicroBit uBit;

int main()
{
    
    // Declare vars
    int i;
    float sleep_time;
    
    // Initialise the micro:bit runtime.
    uBit.init();
    
    // Send thermometer readings to serial and display
    sleep_time = 0.1;  // # seconds to sleep
    i = 0;
    while (i==0) {
        ManagedString temp_reading(uBit.thermometer.getTemperature());
        ManagedString pitch_reading(uBit.accelerometer.getPitch());
        ManagedString roll_reading(uBit.accelerometer.getRoll());
                
        ManagedString reading = temp_reading + ',' + pitch_reading + ',' + roll_reading + '\n';
        uBit.serial.send(reading);
        
        uBit.sleep(sleep_time * 1000);
        }
    
    // If main exits, there may still be other fibers running or registered event handlers etc.
    // Simply release this fiber, which will mean we enter the scheduler. Worse case, we then
    // sit in the idle task forever, in a power efficient sleep.
    release_fiber();
}


