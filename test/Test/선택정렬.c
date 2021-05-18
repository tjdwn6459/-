//
//선택정렬: 0번 방을 최소값이라고 가정하고 나머지 원소들과 비교하여 교체 한다


#include <stdio.h>


void selectSort(int*, int);


int main()
{
	int ary[] = { 4, 2, 7, 5, 9, 1, 8, 3, 6 };//배열선언
	int size = sizeof(ary) / sizeof(ary[0]);//크기 
	selectSort(ary, size);


	return 0;
}

void selectSort(int* pary, int sz)
{
	int i, min, j, temp, k;
	for (i = 0; i < sz - 1; i++)
	{
		min = i;//min값 초기화(기준 위치 원소의 인덱스 i를 변수 min에 설정
		for (j = i + 1; j < sz; j++)//i번 부터 마지막 원소까지 비교하여 
		{
			if (pary[min] > pary[j]) min = j;//가장 작은 원소의 인덱스를 변수 min에 저장
		}
	
		//최솟값이후부터 가장 최솟값을 찾는거다 swap을 이용해 값을 바꾼다
		//가장작은 값 pary[min]의 값과 기준원소 pary[i]를 temp를 이용해 교환한다
		temp = pary[min];
		pary[min] = pary[i];
		pary[i] = temp; 


		printf("\n%d 단계 :  ", i + 1);//한단계의 삽입정렬이 끝난 현재상태를 출력
		for (k = 0; k < sz; k++)
		{
			printf("%d  ", pary[k]);//다음 삽입정렬을 위해 기준위치 인덱스i를 하나 증가킨다  
		}
	}

}


