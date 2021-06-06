#include <REGX52.H>
#include "delay.h"

#define GPIO_MOTOR P2


unsigned char code Clockwise[8]={0x01,0x03,0x02,0x06,0x04,0x0c,0x08,0x09}; //˳ʱ��A-AB-B-BC-C-CD-D-DA
unsigned char code Anticlockwise[8]={0x09,0x08,0x0c,0x04,0x06,0x02,0x03,0x01};  //��ʱ��ת��˳��

//��ʱ��ת��8��
void  Motor()  
{ 
	unsigned char i;
	for(i=0;i<8;i++)
	{ 
		GPIO_MOTOR&=0xf0;  //����λ����
		GPIO_MOTOR|=Anticlockwise[i];  //��λ����λ����Ӧλ
		Delay(2);	//�ı�������Ե���ת��	
		//���Ҫʹ�������ֹͣת������ʹ��GPIO_MOTOR&=0xf0; 
	}	                  
}



//��ʱ��ת��180��
void  Anticlockwise180() 
{ 
	unsigned char i,j;
	for(j=0;j<79;j++)  //79����������������йأ���Ҫ�ڷ���ʵ���в��ϵ����Ӷ�ȷ��
	{
		for(i=0;i<8;i++)
		{ 
			GPIO_MOTOR&=0xf0;  //����λ����
			GPIO_MOTOR|=Anticlockwise[i];  //��λ����λ����Ӧλ
			Delay(3);	//����ת��	
		}	   		
  }  
	GPIO_MOTOR&=0xf0;  //����λ����,ֹͣת��
}


//˳ʱ��ת��180��
void Clockwise180()  
{
	unsigned char i,j;
	for(j=0;j<79;j++)  //79����������������йأ���Ҫ�ڷ���ʵ���в��ϵ����Ӷ�ȷ��
	{
		for(i=0;i<8;i++)
		{ 
			GPIO_MOTOR&=0xf0;  //����λ����
			GPIO_MOTOR|=Clockwise[i];  //��λ����λ����Ӧλ
			Delay(3);	//����ת��	
		}	   		
  }  
	GPIO_MOTOR&=0xf0;  //����λ����,ֹͣת��
}



/*���˲���ǲ��������ǾͿ��Լ����Ҫʹ�������ת��180�㣬����Ҫ��������
ÿ��ת����5.625/64���㣬�ڰ��Ĺ�����ʽ�£�һ��ѭ��������ת����(5.625��/8)�㣬
Ҫʹ���ת��180�����Ҫ����180/((5.625��/8))=256�ֵ�8��ѭ����256ǡ�����޷���8λ�����������ɵ���������0-255��256����
��Ҳ����������Ƶ�����֮����*/
//��ʱ��ת��180��(������28BYJ48)
void  Anticlockwise_28BYJ48_180() 
{ 
	unsigned char i,j;
	for(j=0;j<255;j++)  //�ĳ�255
	{
		for(i=0;i<8;i++)
		{ 
			GPIO_MOTOR&=0xf0;  //����λ����
			GPIO_MOTOR|=Anticlockwise[i];  //��λ����λ����Ӧλ
			Delay(3);	//����ת��	
		}	   		
    }  
	GPIO_MOTOR&=0xf0;  //����λ����,ֹͣת��
}


