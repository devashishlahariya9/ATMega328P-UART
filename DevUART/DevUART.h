#include <avr/io.h>
#include <util/delay.h>
#include <string.h>
#include <stdlib.h>

void UARTinit(unsigned int ubrr)
{
  UBRR0L = ubrr;
  UCSR0B = (1 << RXEN0) | (1 << TXEN0);
  UCSR0C = (1 << USBS0) | (1 << UCSZ00) | (1 << UCSZ01);
}

void serialPrintString(char str[])
{
  for(int i=0; i<(strlen(str)); i++)
  {
    UDR0 = str[i];
    _delay_ms(2);
  }
}