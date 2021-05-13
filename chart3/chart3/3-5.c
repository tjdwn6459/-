#include <stdio.h>

typedef struct {
	int row;
	int col;
	int value;
}term;


void smTranspose(term a[], term b[]) {
	int m, n,v, i, j, p;
	m = a[0].row; //희소 행렬 a의 행수
	n = a[0].col;//a의 열수
	v = a[0].value;//희소 행렬a에서 0이 아닌 원소 수

	b[0].row = n;//전치 행렬 b의 행 수
	b[0].col = m;//열 수
	b[0].value = v; //전치행렬 b의 원소 수

	if (v > 0) {//0이 아닐때 연산 수행
		p = 1;
		for(i = 0; i <n; i++)//a의 열별로 전치 반복
			for(j = 1; j <=v; j++)//0이 아닌 원소 수에 대해서만 반복
				if (a[j].col == i) { //현재의 열에 속하는 원소 있을시 b[]에 삽입
					b[p].row = a[j].col;
					b[p].col = a[j].row;
					b[p].value = a[j].value;
					p++;
				}
	}
}