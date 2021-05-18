#include <stdio.h>


int BSearch(int* pary, int sz, int tg)
{
	int first = 0;
	int last = sz - 1;
	int mid;
	while (first <= last)
	{
		mid = (first + last) / 2; //구역을 2개로 나눠서 탐색
		if (fg == pary[mid]) return mid;
		else {
			if (tg > pary[mid]) first = mid + 1;
			else last = mid - 1;
		}
	}
	return -1;
}



int main()
{
	int ary[] = { 3, 4, 5, 6, 7, 3, 4 };
	int size = sizeof(ary) / sizeof(ary[0]);
	int index;

	index = BSearch(ary, size, 9);
	if (index == -1) printf("탐색 실패 !!\n");
	else printf("방번호 : %d\n", index);


	return 0;
}