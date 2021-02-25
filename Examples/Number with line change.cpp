#include <DevUART.h>

int main()
{
  serialBegin(103);
  
  for(int i=0;i<=100;i++)
  {
    serialPrintString("\n");
    serialPrintNumber(i);
  }
}