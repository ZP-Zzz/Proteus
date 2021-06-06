#include <REGX52.H>			  

#include "timer0.h"

sbit SG_PWM=P2^0;							//�źſ�������						 �졪��VCC �ء���GND �ơ����ź���
unsigned char count=0;					     //�ƴ�  ����ֵΪ0
unsigned char PWM_count=0;                  //0--0�ȣ�2--45�ȣ�4--90�ȣ�6--135�ȣ�8--180��

void main()
{
  Timer0_Init();
  while(1)
  {
//	  	if(P1_0==0)PWM_count=0;	  //���ת��0��
//	  	if(P1_1==0)PWM_count=1;else PWM_count=0;	  //���ת��22.5��		ִֻ������һ��ɱ�����ţ�Ҳ��ִ�ж�� 
//    	if(P1_2==0)PWM_count=2;	  //���ת��45��
//	 	if(P1_3==0)PWM_count=3;	  //���ת��67.5��			
//	 	if(P1_4==0)PWM_count=4;	  //���ת��90��
//	  	if(P1_5==0)PWM_count=5;	  //���ת��112.5��
//	 	if(P1_6==0)PWM_count=6;	  //���ת��135��
//    	if(P1_7==0)PWM_count=7;	  //���ת��157.5��
//   	if(P2_1==0)PWM_count=8;	  //���ת��180��
		PWM_count=2;
   }
}

void Timer0() interrupt 1      //�ر�ע��˴���0--�ⲿ�ж�0��1--��ʱ���ж�0��2--�ⲿ�ж�1��3--��ʱ���ж�1��4--���п��ж�1
{
//	TR0=0;
	TL0 = 0x0C;		//���ö�ʱ��ʼֵ
	TH0 = 0xFE;		//���ö�ʱ��ʼֵ
  

	  if(count<=PWM_count)
	  {									
	   		SG_PWM=1;
	  }
	  else
	  {
	    	SG_PWM=0;
	  }
	  count++;						  //�ƴΣ�ÿ0.5�����1
	  if(count>=40)
	  {
	    	count=0;
	  }
//	  TR0=1;
}
