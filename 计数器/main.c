//������ֻ������P3_4��P3_5

#include <REGX52.H>


unsigned char shumaguan[]={0x3F,0x06,0x5B,0x4F,0x66,0x6D,0x7D,0x07,0x7F,0x6F};
unsigned int count;

void Init_counter()		//5000΢��@12.000MHz
{
	TMOD &= 0xF0;	//���ü�����ģʽ
	TMOD |= 0x06;	//���ü�����ģʽ   8λ�Զ����صļ�����
	TL0 = 256-3;	//���ü�����ʼֵ   �������ξͼ���
	TH0 = 256-3;	//���ü�����ʼֵ
	TF0 = 0;		//���TF0��־
	TR0 = 1;		//������0��ʼ��ʱ
	EA =  1;
	ET0 = 1;
}




void main()
{
	Init_counter();
	P2=0x3F;
	while(1)
	{
		P2=shumaguan[count];
		if(count>=10) count=0;
	}
}


void Counter0() interrupt 1
{
	count++;
}






