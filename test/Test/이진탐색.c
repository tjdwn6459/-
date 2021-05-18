#include <stdio.h>


int BSearch(int* pary, int sz, int tg)
{
	int first = 0;
	int last = sz - 1;
	int mid;
	while (first <= last)
	{
		mid = (first + last) / 2; //������ 2���� ������ Ž��
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
	if (index == -1) printf("Ž�� ���� !!\n");
	else printf("���ȣ : %d\n", index);


	return 0;
}