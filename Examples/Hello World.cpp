#include <DevUART.h>

Serial serial;

int main()
{
  serial.begin(103);
  
  serial.printString("Hello World!");
}