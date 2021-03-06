#include <DevUART.h>

Serial serial;

int main()
{
  serial.begin(103);
  
  for(int i=0; i<=100; i++)
  {
    serial.printNumber(i);
    serial.printString("\n");
  }
}