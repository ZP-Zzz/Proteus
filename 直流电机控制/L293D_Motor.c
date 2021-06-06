#include <REGX52.H>
#include "delay.H" 

sbit IN1=P2^0;
sbit IN2=P2^1;
sbit EN1=P2^2;


unsigned char Compare,Counter;

//�����ת
void Positive_Motor()
{
	IN1=1;
	IN2=0;
	EN1=1;	
}


//�����ת
void Negative_Motor()
{
	IN1=0;
	IN2=1;
	EN1=1;	
}



//delay��PWMֱ���������
void Delay_Motor()
{
	IN1=0;
	IN2=1;
	delay(25);
	IN2=0;
	delay(75);
	EN1=1;	
}



void Timer0Init(void)	//1����@12.000MHz
{
	TMOD &= 0xF0;	//���ö�ʱ��ģʽ
	TMOD |= 0x01;	//���ö�ʱ��ģʽ
	TL0 = 0x18;		//���ö�ʱ��ʼֵ
	TH0 = 0xFC;		//���ö�ʱ��ʼֵ
	TF0 = 0;		//���TF0��־
	TR0 = 1;		//��ʱ��0��ʼ��ʱ
	EA=1;
	ET0=1;
	IN1=0;
}



//��ʱ����PWMֱ���������
void PWM_Motor(unsigned char i)
{
	 Compare=i;
}


void PWM_Timer0() interrupt 1
{
	TL0 = 0x18;		//���ö�ʱ��ʼֵ
	TH0 = 0xFC;		//���ö�ʱ��ʼֵ
	Counter++;
	if(Counter>=100)
		Counter=0;
	if(Counter<Compare)
	{
		IN1=0;
	}
	 else
	{
	 	IN1=1;
	}
}






