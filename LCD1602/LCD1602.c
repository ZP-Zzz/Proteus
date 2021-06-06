#include <REGX52.H>

sbit RS=P3^0;
sbit RW=P3^1;
sbit E=P3^2;

unsigned char str[]={"Hello World"};
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


//д���ݣ���ʾ
void Display()
{
	WriteCommand(0x80);		   //��һ��
	WriteData('A');
	WriteCommand(0x80+0x40+2);	//�ڶ���
	WriteData('+');
	WriteCommand(0x80+2);
	for(i=0;str[i]!='\0';i++)
	{
		WriteData(str[i]);
	}
}





















