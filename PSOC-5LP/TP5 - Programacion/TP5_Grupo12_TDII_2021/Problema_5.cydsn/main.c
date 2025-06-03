#include "project.h"
int count = 0;
int speed = 0;

void move()
{
    speed = 25*count;
    PWM_WriteCompare(speed);
    reset_output_Write(1); //reseteo del modulo pwm
    reset_output_Write(0);  
}
CY_ISR(incremento)
{  
    if (count <= 10) count++;
    move();
}
CY_ISR(decremento)
{  
    if (count >= 1) count--;
    move();
}
   
int main(void)
{  
 
    CyGlobalIntEnable;
    sw_inter_1_StartEx(incremento);
    sw_inter_2_StartEx(decremento);
    PWM_Start();
    clock_Start();
    EN1_Write(1);
    EN2_Write(0);
    for(;;)
    { 
    }
}
