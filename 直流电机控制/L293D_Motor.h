
#ifndef __L293D_Motor_H__
#define __L293D_Motor_H__

void Positive_Motor(); //�����ת

void Negative_Motor();//�����ת

void Delay_Motor();	//delay��PWMֱ���������

void Timer0Init(void);

void PWM_Motor(unsigned char i);

#endif