#include <stdio.h>



//�迭�ϳ��ϳ� �Ѿ�鼭 �װ� ��
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
	int ary[] = { 3, 4, 7, 2, 4, 5, 1 };//�迭����
	int size = sizeof(ary) / sizeof(ary[0]);//�迭 ������ (��ü�� ��ĭ������ ������)
	int index = LSearch(ary, size, 2);//
	index = LSearch(ary, size, 2);
	if (index == -1) printf("ã�� ���� !!\n");
	else
	{
		printf("%d\n", index);
		return 0;
	}

	return 0;
}