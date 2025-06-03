#include "project.h"
char data;
int valor = 0;

CY_ISR(input_data)
{
    data = UART_GetChar();
    if (data =='A')
    {
        valor = 1 ;
    }
    if (data =='B')
    {
        valor = 0 ;
    }
}
int main(void)
{
    CyGlobalIntEnable;
    UART_Start();
    isrRX_StartEx(input_data);
    for(;;)
    {
        LED_Write(valor);
    }
}
