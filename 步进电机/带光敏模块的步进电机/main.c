#include "regx52.h"
#include "delay.h"
#include "motor.h"

//������
void main(void) 
{ 

  	while(1)
 	{
		if(P1_0==0)			  //�������ȳ������� 0
		{
			Anticlockwise_28BYJ48_180();    	
		}
				
		else if(P1_0==1)	 //�������ȴﲻ�������	1
		{
			clockwise_28BYJ48_180();
			
		}
	
					
  	}
}
