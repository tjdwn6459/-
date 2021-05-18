#include <stdio.h>



//배열하나하나 넘어가면서 그값 비교
int LSearch(int* pary, int sz, int tg)
{
	int i = 0;

	for (i = 0; i < sz; i++)
	{
		if (tg == pary[i]) return i;
	}
	return -1;
}

int main()
{
	int ary[] = { 3, 4, 7, 2, 4, 5, 1 };//배열선언
	int size = sizeof(ary) / sizeof(ary[0]);//배열 사이즈 (전체를 한칸당으로 나누기)
	int index = LSearch(ary, size, 2);//
	index = LSearch(ary, size, 2);
	if (index == -1) printf("찾기 실패 !!\n");
	else
	{
		printf("%d\n", index);
		return 0;
	}

	return 0;
}