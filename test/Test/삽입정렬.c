//�������� : �ι�° �ڷ���� �� �ڷḦ ���Ͽ� �����Ѵ�
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
	for (i = 1; i < sz; i++) //�ι�° ���Ҹ� �������� �ؼ� �񱳸��ϱ⿡ i = 1
	{
		for (j = i; j > 0; j--)//�κ������� �ǵں��� ���ϱ� ����
		{
			if (pary[j] < pary[j - 1])//ù��° �ִ¹��� �ι�° �ִ� �溸�� Ŭ��� (swap), �ٷ��������ִ� ���� ��
			{
				//swap
				temp = pary[j];
				pary[j] = pary[j - 1];
				pary[j - 1] = temp;
			}
		}
		printf("\n %d�ܰ� : ", i);
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