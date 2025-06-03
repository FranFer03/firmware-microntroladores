#include "project.h"
int count = 0;

CY_ISR(incremento)
{
    count++;
    led_board_Write(1);
    switch (count)
    {
    case 1:
        PWM_WriteCompare(25);
        break;
    case 2:
        PWM_WriteCompare(90);
        break;
    case 3:
        PWM_WriteCompare(170);
        break;
    case 4:
        PWM_WriteCompare(255);
        break;
    case 5:
        PWM_WriteCompare(25);
        count = 1;
    }
    reset_output_Write(1); //reseteo del modulo pwm
    reset_output_Write(0);
    CyDelay(100); //delay para led_board
    led_board_Write(0);
}
   
int main(void)
{  
 
    CyGlobalIntEnable;
    sw_inter_StartEx(incremento);
    PWM_Start();
    reloj_Start();
    for(;;)
    {
    }
}
