#include <REGX52.H>
#include "delaytime10us.h"
#include "motorrun.h"


void main()
{
	while(1)
	{
		MotorRun(4096,1,100);	//	nangle=4096ΪһȦ��	drct=0Ϊ��ʱ��ת����drct=1Ϊ˳ʱ��ת����  speedת��75`400��
		delay(50000);		//ֹͣ  ��ʱ500ms
	}
}

