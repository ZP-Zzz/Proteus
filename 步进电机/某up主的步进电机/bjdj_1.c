#include<reg51.h>
#define uchar unsigned char
#define uint unsigned int
#define OUT P2

sbit pos = P1^0;						//��������תλP1^0
sbit neg = P1^1;						//��ת     
	
//void delay(uint);

uint TIME;

uchar code turn[] = {0x02,0x06,0x04,0x0c,0x08,0x09,0x01,0x03};			//�������������

void main()
{
	uchar a;
  	OUT = 0x03;
	TMOD = 0x01;	      //��ʱ��T0Ϊ��ʽ1
	TH0 = 0x3c;		      //���ö�ʱ����ֵ15536��D��
	TL0 = 0xb0;		  
	EA = 1;			        //�����ж�															  
	ET0 = 1;		        //����ʱ��TO�ж�
	TR0 = 1;		        //������ʱ��T0

/*
	��ʱ��ʱ��=��65536-15536��*12/12=5000us=5ms    
	���ת�ټ���n=60000/(10*8)=750 r/min
*/
	
	while(1)
	{
		if (pos&&neg) TIME=0;			
		if (!pos)               //�����ת��������
		{
			if (TIME==2)
			{
							
				a = a<8?a+1:0;
				OUT = turn[a];
				TIME = 0;
			}
		}
				
		if (!neg)								//��ת��������
		{
			if (TIME==2)
			{
							
				a = a>0?a-1:7;
				OUT = turn[a];
				TIME = 0;
			}
				
		}
			
/*		a = a<8?a+1:0;
		  OUT = turn[a];
	    delay(20);
*/			
   }		   			
}

/*
void delay(uint j)
{
	uchar i;
	for(;j>0;j--)
	{
		i=250;
		while(--i);
		i=249;
		while(--i);
	}  
}
*/

void timer()interrupt 1	 //T0�жϳ���
{
   TH0=0x3c;				 //���¸�ֵ--ѭ��һ��ʱ��Ϊ5ms
   TL0=0xb0;
   TIME++;					 //ѭ��������һ
}

