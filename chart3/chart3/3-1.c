#include <stdio.h>

//������ ���� ���������� Ȯ���ϱ�
void main()
{
	int i, ary[4] = { 157, 209, 251, 312 };

	for (i = 0; i < 4; i++)
	{
		printf("address : %u sale[%d] = %d", &ary[i], i, ary[i]); //%u�������� ���ϴ� ����� 
	}


}