#include "regx52.h"
#include "delay.h"
#include "motor.h"

//������
void main(void) 
{ 
  while(1)
  {
//	Motor();
	Anticlockwise_28BYJ48_180();
	Delay(100);
  }
}
