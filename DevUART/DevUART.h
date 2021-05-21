#include <avr/io.h>
#include <util/delay.h>
#include <string.h>
#include <stdlib.h>

/*
IF YOU WANT TO HAVE LINE CHANGE AFTER PRINTING SOMETHING ON THE SERIAL MONITOR....PLEASE ADD "\n" AT THE END OF YOUR STRING.
*/

class Serial
{
public:
  void begin(unsigned int ubrr)
  {
    UBRR0L = ubrr; //USE 103 for 9600 BAUD RATE, YOU CAN FIND MORE VALUES IN THE DATASHEET, PREFER 9600 BAUD RATE.
    UCSR0B = (1 << RXEN0) | (1 << TXEN0);
    UCSR0C = (1 << USBS0) | (1 << UCSZ00) | (1 << UCSZ01);
  }

  void print(char str[])
  {
    for (int i = 0; i < (strlen(str)); i++)
    {
      UDR0 = str[i];
      _delay_ms(2);
    }
  }

  void print(int num)
  {
    char numstr[10];
    itoa(num, numstr, 10);
    print(numstr);
  }

  char read()
  {
    while (!(UCSR0A & (1 << RXC0)))
      ;
    return UDR0;
  }
};