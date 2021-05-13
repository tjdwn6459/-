#include <stdio.h>

void main()
{
	int i, n = 0, * ptr;
	int sale[2][4] = { {63, 84, 140, 130},
					  {157, 209, 251, 312} }; //2차원 배열의 초기화

	ptr = &sale[0][0];

	/*int(*pptr)[4] = &sale;*/

	int** pptr; 
	pptr = &sale;

	for (i = 0; i < 8; i++)
	{
		printf("\naddress : %u sale %d = %d", ptr , i, *ptr);
		ptr++; //포인트변수 증가 4바이트씩 증가(int형의 포인트)
	}



	printf("\n%d", pptr[1][1]);
	getchar();



}