#include "mbed.h"

DigitalOut ledOrange(LED3);
DigitalOut ledGreen(LED4);
DigitalOut ledRed(LED5);
DigitalOut ledBlue(LED6);

Serial console(SERIAL_TX, SERIAL_RX, 115200);

Timer millis;

// main() runs in its own thread in the OS
// (note the calls to wait below for delays)
int main() {
   uint32_t oldTime;
   uint32_t newTime;
   console.printf("Hello, world.\r\n");
   millis.start();
   oldTime = millis.read();
   newTime = oldTime;

   while (true) {
      newTime = millis.read();
      if (newTime != oldTime) {
         oldTime = newTime;
         if (console.writeable()) {
            ledOrange = !ledOrange;
         }
         ledGreen = !ledGreen;
         ledRed = !ledRed;
         ledBlue = !ledBlue;

         console.printf("Tick %lu\r\n", millis.read());
         console.putc('R');
      }
   }
}

