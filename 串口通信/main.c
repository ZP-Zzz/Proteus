#include <REGX52.H>
void UART_SendByte(unsigned char Byte);
unsigned char Temp;

void UART_Init()
{
	SCON = 0x50;	//8λ����,�ɱ䲨����
	TMOD &= 0x0F;	//���ö�ʱ��ģʽ
	TMOD |= 0x20;	//���ö�ʱ��ģʽ
	TL1 = 0xC7;		//���ö�ʱ��ʼֵ
	TH1 = 0xFE;		//���ö�ʱ��ʼֵ
	ET1 = 0;		//��ֹ��ʱ��1�ж�
	TR1 = 1;		//��ʱ��1��ʼ��ʱ
	ES=1;
	EA=1;
}

	


void main()
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
		UART_SendByte(SBUF);	//�ӻ��յ����ٷ���SBUF����ʾ
		P2_0=~P2_0;		
		RI=0;     //��Ӧ�жϺ�����ֶ���0
	 }
}



void UART_SendByte(unsigned char Byte)
{
	SBUF=Byte;
	while(TI==0);
	TI=0;
}



