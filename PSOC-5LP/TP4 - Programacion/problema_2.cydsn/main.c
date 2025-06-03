#include "project.h"

void parpadeo(int seg, int color)
{ 
    int i;
    for(i=0;i<seg;i++)
    {
       if(color == 1)
        {
            led_azul_Write(1);
            CyDelay(500);
            led_azul_Write(0);
            CyDelay(500);
        }  
        if(color == 2)
        {
            led_rojo_Write(1);
            CyDelay(500);
            led_rojo_Write(0);
            CyDelay(500);
        }  
    }

}
  
int main(void)
{
    CyGlobalIntEnable;
    int sw1 = 0, sw2 = 0;
    for(;;)
    {
        sw1 = sw_azul_Read();
        sw2 = sw_rojo_Read();
        
        if(sw1 == 0) parpadeo(5,1);
        else if (sw1==1) led_rojo_Write(0);
        
        if(sw2 == 0) parpadeo(3,2);
        else if (sw2==1) led_rojo_Write(0);
    }
}