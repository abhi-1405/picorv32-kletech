#include <stdio.h>

int main() { 
   volatile int *led;
   volatile int i;

   led = 0x03000000;

   *led = 0x1;
   for (i=0; i < 10; i++);
   *led = 0x0;
   for (i=0; i < 10; i++);
   *led = 0x3;
   for (i=0; i < 10; i++);
   *led = 0x0;
   for (i=0; i < 10; i++);
   *led = 0x7;
   for (i=0; i < 10; i++);
   *led = 0x0;
   for (i=0; i < 10; i++);
   *led = 0xf;
   for (i=0; i < 10; i++);
   *led = 0x0;

   return 0;
}
