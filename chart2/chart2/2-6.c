#include <stdio.h>

void main() //출력이 void (x)
{
	int ary[2][3][4];
	int i, j, k, value = 1;


	for (i = 0; i < 2; i++) {
		for (j = 0; j < 3; j++) {
			for (k = 0; k < 4; k++) {
				ary[i][j][k] = value;
				printf("\narray[%d][%d][%d] = %d", i, j, k, ary[i][j][k]);
				value++; //1씩 증가하는 값을 넣기 위해서 
			}
		}
	}

	getchar();//return(반환값) 이 없어도 댄다 

}


