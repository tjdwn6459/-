#include <stdio.h>

void main() //����� void (x)
{
	int ary[2][3][4];
	int i, j, k, value = 1;


	for (i = 0; i < 2; i++) {
		for (j = 0; j < 3; j++) {
			for (k = 0; k < 4; k++) {
				ary[i][j][k] = value;
				printf("\narray[%d][%d][%d] = %d", i, j, k, ary[i][j][k]);
				value++; //1�� �����ϴ� ���� �ֱ� ���ؼ� 
			}
		}
	}

	getchar();//return(��ȯ��) �� ��� ��� 

}


