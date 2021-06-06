#include <REGX52.H>

sbit RS=P3^0;
sbit RW=P3^1;
sbit E=P3^2;

unsigned int Sec=0,Min=52,Hour=22;
unsigned int NUM;


void delay(int ms)		//@12.000MHz
{
	while(ms)
	{
	 	unsigned char i, j;
		i = 2;
		j = 239;
		do
			{
				while (--j);
			} 
			while (--i);
		ms--;
	}	
}




//дָ���
void WriteCommand(unsigned char Command)
{
	RS=0;
	RW=0;
	E=0;
	P2=Command;
	delay(5);	  //��ʱһ�£���Ȼ��ʾ������
	E=1;
	E=0;
}

//д���ݺ���
void WriteData(unsigned char Data)
{
	RS=1;
	RW=0;
	E=0;
	P2=Data;
	delay(5);   //��ʱһ�£���Ȼ��ʾ������
	E=1;
	E=0;
}

//��ʼ��
void LCD_Init()
{
	WriteCommand(0x38);
	WriteCommand(0x0c);
	WriteCommand(0x06);
	WriteCommand(0x01);
}

//��ʼ����ʱ��
void Timer0Init(void)		//1����@12.000MHz
{
	TMOD &= 0xF0;	//���ö�ʱ��ģʽ
	TMOD |= 0x01;	//���ö�ʱ��ģʽ
	TL0 = 0x18;		//���ö�ʱ��ʼֵ
	TH0 = 0xFC;		//���ö�ʱ��ʼֵ
	TR0 = 1;		//��ʱ��0��ʼ��ʱ
	EA=1;
	ET0=1;
}




//д���ݣ���ʾ
void Display()
{
	WriteCommand(0x80);		   //��һ��
	WriteData(Hour/10+'0');
	WriteData(Hour%10+'0');		 //���ּ��ϡ�0�����ܱ��ʮ����������
    WriteData(':');
	WriteData(Min/10+'0');
	WriteData(Min%10+'0');
    WriteData(':');
	WriteData(Sec/10+'0');
	WriteData(Sec%10+'0');
}



void Timer0() interrupt 1
{

	TL0 = 0x18;		//���ö�ʱ��ʼֵ
	TH0 = 0xFC;		//���ö�ʱ��ʼֵ
	NUM++;

	if(NUM>=1000)
	{		   
		NUM=0;
		Sec++;
	}

	if(Sec>=60)
	{
		Sec=0;
		Min++;
	}
	if(Min>=60)
	{
		Min=0;
		Hour++;
	}
	if(Hour>=24)
	{
		Hour=0;
	}
				
		
	
}

















