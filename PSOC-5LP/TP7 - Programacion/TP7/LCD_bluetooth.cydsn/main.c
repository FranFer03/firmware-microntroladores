#include "project.h"
char data;
int row = 0, column = 0;

CY_ISR(input_data)
{
    data = UART_GetChar();
    column += 1;
    if (column == 15)
    {
        row = 1;
        column = 0;
    }
    LCD_I2C_setCursor(column,row);
    LCD_I2C_write(data);
}
int main(void)
{
    CyGlobalIntEnable;
    I2C_Start();
    LCD_I2C_start();
    UART_Start();
    isrRX_StartEx(input_data);
    for(;;)
    {

    }
}
