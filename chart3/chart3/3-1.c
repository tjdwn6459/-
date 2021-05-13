#include <stdio.h>

//원소의 논리적 물리적순서 확인하기
void main()
{
	int i, ary[4] = { 157, 209, 251, 312 };

	for (i = 0; i < 4; i++)
	{
		printf("address : %u sale[%d] = %d", &ary[i], i, ary[i]); //%u음수포함 안하는 양수값 
	}


}