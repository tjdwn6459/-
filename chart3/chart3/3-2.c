#include <stdio.h>

void main()
{
	int i, n = 0, * ptr;
	int sale[2][4] = { {63, 84, 140, 130},
					  {157, 209, 251, 312} }; //2���� �迭�� �ʱ�ȭ

	ptr = &sale[0][0];

	/*int(*pptr)[4] = &sale;*/

	int** pptr; 
	pptr = &sale;

	for (i = 0; i < 8; i++)
	{
		printf("\naddress : %u sale %d = %d", ptr , i, *ptr);
		ptr++; //����Ʈ���� ���� 4����Ʈ�� ����(int���� ����Ʈ)
	}



	printf("\n%d", pptr[1][1]);
	getchar();



}