#include <REGX52.H>
#include "ADC0808.H"

sbit RS=P3^3;
sbit RW=P3^4;
sbit E=P3^5;

unsigned char str[]={"0123456789"};
unsigned char i;

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
	P1=Command;
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
	P1=Data;
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


//д���ݣ���ʾ
void Display()
{
	unsigned char Temp0,Temp1,Temp2;
	unsigned int Temp;
	Temp=ADC();
	Temp=Temp*100/51;
	Temp0=Temp/100;
	Temp1=Temp%100/10;
	Temp2=Temp%10;
	WriteCommand(0x80);		   //��һ��
	WriteData(str[Temp0]);
	WriteData('.');
	WriteData(str[Temp1]);
	WriteData(str[Temp2]);

}





















