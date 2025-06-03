#include "project.h"
#include "stdio.h"
#include "stdlib.h"

#define SlaveAddress 0x68
#define height_tank 28


uint8 Tabla[7];
char cost[1];
uint8 min_dec,min_uni,hour_dec,hour_uni;
char dato;

static int temperature=99;
static int humidity=99;
char output_dht[15];
char percent_data[7];

char bomb_data;
int bomb_active = 0;

CY_ISR(bomb_inter)
{
    bomb_data = UART_GetChar();
    if (bomb_data =='A')
    {
        bomb_active = 1 ;
    }
    if (bomb_data =='B')
    {
        bomb_active = 0 ;
    }
}

void HC_SR04()
{

    float distance = 0.0, aux = 0.0;
    int time;
    Control_Write(1);
    CyDelayUs(10);
    Control_Write(0);   
    while(echo_Read() == 0){}
    while(echo_Read() == 1){};
    time = 65535 - Timer_ReadCounter();
    distance = time/58.0;
    aux = 100 - (distance*100)/height_tank;
    CyDelay(10);
    LCD_I2C_setCursor(7,0);    
    LCD_I2C_print("N.A=");
    sprintf(percent_data,"%.1f",aux);
    LCD_I2C_setCursor(11,0); 
    LCD_I2C_print(percent_data);
    LCD_I2C_setCursor(15,0); 
    LCD_I2C_write(0x25);
    
}

void RTC_data()
{
    uint8 result,i;
    do{

        result = I2C_MasterSendStart(SlaveAddress, I2C_WRITE_XFER_MODE);
    }

    while (result != I2C_MSTR_NO_ERROR);

    result = I2C_MasterWriteByte(0x00);
    result = I2C_MasterSendRestart(SlaveAddress, I2C_READ_XFER_MODE);
    for(i=0; i<6; i++){
        Tabla[i] = I2C_MasterReadByte(I2C_ACK_DATA);
    }
    Tabla[6] = I2C_MasterReadByte(I2C_NAK_DATA);
    I2C_MasterSendStop();
}

void RTC_show_data()
{
    LCD_I2C_setCursor(0,0); 
    hour_dec= (Tabla[2]>>4)&0x03;
    itoa(hour_dec,cost,10);
    LCD_I2C_write(cost[0]);
    hour_uni=Tabla[2]&0X0F;
    itoa(hour_uni,cost,10);
    LCD_I2C_write(cost[0]);
    LCD_I2C_write(':');
    min_dec=Tabla[1]>>4;
    itoa(min_dec,cost,10);
    LCD_I2C_write(cost[0]);
    min_uni=Tabla[1]&0x0F;
    itoa(min_uni,cost,10);
    LCD_I2C_write(cost[0]);
}

int DHTread() 
{     
   int i;
   uint8 bits[5]; 
   uint8 cnt = 7; 
   uint8 idx = 0; 
   int   calc=0; 
   int   timeout=0; 

   for (i=0; i< 5; i++) bits[i] = 0; 
   DHT_Write(0u); 
   CyDelay(19); 
   DHT_Write(1u); 
   while(DHT_Read()==1) 
   { 
       timeout++; 
   } 
   while(DHT_Read()==0) 
   {         
       timeout++; 
   } 
   calc=timeout; 
   timeout=0; 
   while(DHT_Read()==1); 
   for (i=0; i<40; i++) 
	{ 
       timeout=0; 
       while(DHT_Read()==0); 
       while(DHT_Read()==1) 
           timeout++; 
       //Data acquiring point 
       if ((timeout) > (calc/2)) 
           bits[idx] |= (1 << cnt); 
       if (cnt == 0)   // next byte? 
   	{ 
   		cnt = 7;    // restart at MSB 
   		idx++;      // next byte! 
   	} 
   	else cnt--; 
   } 
   humidity    = bits[0];  
   temperature = bits[2];  
   CyDelay(1); 
   return 0; 
}

char temp_RX[5];
char hum_RX[5];

int main(void)
{
    CyGlobalIntEnable;
    I2C_Start();
    LCD_I2C_start();
    UART_Start();
    Timer_Start();
    Clock_Start();
    isrRX_StartEx(bomb_inter);
    for(;;)
    {
        Bomb_Write(bomb_active);
        HC_SR04();
        RTC_data();
        RTC_show_data();   
        DHTread();
        sprintf(temp_RX,"%i",temperature);
        sprintf(hum_RX,"%i",humidity);
        sprintf(output_dht,"Tem=%i C Hum=%i",temperature, humidity);
        LCD_I2C_setCursor(0,1);    
        LCD_I2C_print(output_dht);
        LCD_I2C_setCursor(6,1); 
        LCD_I2C_write(0xDF);
        LCD_I2C_setCursor(15,1); 
        LCD_I2C_write(0x25);
        UART_PutString(temp_RX);
        UART_PutString(" C ");
        UART_PutString("|");
        UART_PutString(hum_RX);
        UART_PutString(" %H ");
        UART_PutString("|");
        UART_PutString(percent_data);
        UART_PutString(" % ");
        UART_PutString("|");
        
        
        CyDelay(3000);

    }
}