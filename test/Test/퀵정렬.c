/*퀵 정렬 : 대표적인 분할 정복 알고리즘
정렬이 되어 있지않은 구조에서 사용하면 빠르다 
1. 원소들 중에서 pivot을 고른다
2.이 pivot를 기준으로 앞에는 작은 값, 뒤에는 큰값들을 위치시킨다.(분할)
3.분한된 작은 리스트를 재귀적으로 동작을 시킨다.(정복)
4. 정렬된 작은 리스트들을 결합한다(결합)*/

#include <stdio.h>

//왼쪽오른쪽을 구분해야한다(int, int)


void quickSort(int*, int, int);

int main()
{
	int ary[] = { 3, 5, 2, 4, 7, 6, 1 };
	int size = sizeof(ary) / sizeof(ary[0]);
	quickSort(ary, size, size);
	
	return 0;
}

void quickSort(int*pary, int left, int right)
{
	//재귀 조건을 만들어준다
	if (left >= right) return;
	int pivot = left; //0번째 있는 원소를 기준점
	int lleft = pivot + 1;//오른쪽으로 가면서 찾는다 
	int lright = right; //오른쪽에서 왼쪽으로 찾는거 
	int temp;

	while (lleft <= lright)//lleft와 lright가 교체가 안될때 까지
	{
		while (pary[lleft] <= pary[pivot]) lleft++;//왼쪽에서 오른쪽으로 이동
		while (pary[lright] >= pary[pivot] && lright > left) lright--;//오른쪽에서 왼쪽으로 이동( lright > left 배열크기를 벗어나지 않게 만들어준다) 

		if (lleft > lright) //왼쪽과 오른쪽이 교체 되었다
		{
			temp = pary[lright];
			pary[lright] = pary[pivot];
			pary[pivot] = temp;
		}
		else//만약에 교체를 안했을때
		{
			temp = pary[lright];
			pary[lright] = pary[lleft];//여기서 두값을 바꿔준다
			pary[lleft] = temp;
		}

	}
	for (int k = 0; k < right + 1; k++)
	{
		printf("%d   ", pary[k]);
		printf("\n");
	}
	quickSort(pary, left, lright - 1);
	quickSort(pary, lright + 1, right);
}