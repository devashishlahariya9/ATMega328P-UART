#include <DevUART.h>

Serial serial;

int main()
{
    serial.begin(103);

    while(1)
    {
        char data = serial.readChar();
        
        if(data == '1')
        {
            serial.printString("1");
        }

        if(data == '0')
        {
            serial.printString("0");
        }
    }
}