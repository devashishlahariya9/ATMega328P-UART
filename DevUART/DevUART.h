#include <avr/io.h>
#include <util/delay.h>
#include <string.h>
#include <stdlib.h>

class Serial
{
  public:

  void begin(unsigned int ubrr)
  {
    UBRR0L = ubrr;
    UCSR0B = (1 << RXEN0) | (1 << TXEN0);
    UCSR0C = (1 << USBS0) | (1 << UCSZ00) | (1 << UCSZ01);    
  }

  void printString(char str[])
  {
    for(int i=0; i<(strlen(str)); i++)
    {
      UDR0 = str[i];
      _delay_ms(2);
    }
  }

  void printNumber(int num)
  {
    char numstr[10];
    itoa(num,numstr,10);
    printString(numstr);
  }

  char rxdata()
  {
    while(!(UCSR0A & (1 << RXC0)));
    
    return UDR0;
  }

  void read()
  {
    int i=0;
    char data[] = {""};
    data[i] = rxdata();
    i++;
  }
};