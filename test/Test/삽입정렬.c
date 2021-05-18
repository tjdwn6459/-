//삽입정렬 : 두번째 자료부터 앞 자료를 비교하여 정렬한다
#include <stdio.h>

void insertionSort(int*, int);
void print(int*, int);

int main()
{
	int ary[] = { 4, 2, 7, 5, 9, 1, 8, 3, 6 };
	int size = sizeof(ary) / sizeof(ary[0]);
	insertionSort(ary, size);
	//print(ary, size);
	return 0;
}
void insertionSort(int* pary, int sz)
{
	int i, j,k, temp;
	for (i = 1; i < sz; i++) //두번째 원소를 기준으로 해서 비교를하기에 i = 1
	{
		for (j = i; j > 0; j--)//부분정렬의 맨뒤부터 비교하기 시작
		{
			if (pary[j] < pary[j - 1])//첫번째 있는방이 두번째 있는 방보다 클경우 (swap), 바로직전의있는 값만 비교
			{
				//swap
				temp = pary[j];
				pary[j] = pary[j - 1];
				pary[j - 1] = temp;
			}
		}
		printf("\n %d단계 : ", i);
		for (k = 0; k < sz; k++)
		{
			printf("%d    ", pary[k]);
		}
	}
}

void print(int* pary, int sz)
{
	int i;
}