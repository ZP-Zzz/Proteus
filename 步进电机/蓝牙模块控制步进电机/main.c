#include "regx52.h"
#include "delay.h"
#include "motor.h"
#include "UART.h"

unsigned char Flag;

//������
void main(void) 
{ 
	UART_Init();
 	while(1)
 	{
  		
  	}
}



void UART_Routine() interrupt 4
{
	 if(RI==1)    //RIΪ�����жϱ�־λ����������ϻ��Զ���1��
	 {	
	 	Flag=SBUF;
		if(Flag==0x01)
		{
			Anticlockwise_28BYJ48_180();
		}
		if(Flag==0x02)
		{
			Clockwise_28BYJ48_180();
		}						
		RI=0;     //��Ӧ�жϺ�����ֶ���0
	 }
}

