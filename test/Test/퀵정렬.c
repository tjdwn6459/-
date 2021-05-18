/*�� ���� : ��ǥ���� ���� ���� �˰���
������ �Ǿ� �������� �������� ����ϸ� ������ 
1. ���ҵ� �߿��� pivot�� ����
2.�� pivot�� �������� �տ��� ���� ��, �ڿ��� ū������ ��ġ��Ų��.(����)
3.���ѵ� ���� ����Ʈ�� ��������� ������ ��Ų��.(����)
4. ���ĵ� ���� ����Ʈ���� �����Ѵ�(����)*/

#include <stdio.h>

//���ʿ������� �����ؾ��Ѵ�(int, int)


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
	//��� ������ ������ش�
	if (left >= right) return;
	int pivot = left; //0��° �ִ� ���Ҹ� ������
	int lleft = pivot + 1;//���������� ���鼭 ã�´� 
	int lright = right; //�����ʿ��� �������� ã�°� 
	int temp;

	while (lleft <= lright)//lleft�� lright�� ��ü�� �ȵɶ� ����
	{
		while (pary[lleft] <= pary[pivot]) lleft++;//���ʿ��� ���������� �̵�
		while (pary[lright] >= pary[pivot] && lright > left) lright--;//�����ʿ��� �������� �̵�( lright > left �迭ũ�⸦ ����� �ʰ� ������ش�) 

		if (lleft > lright) //���ʰ� �������� ��ü �Ǿ���
		{
			temp = pary[lright];
			pary[lright] = pary[pivot];
			pary[pivot] = temp;
		}
		else//���࿡ ��ü�� ��������
		{
			temp = pary[lright];
			pary[lright] = pary[lleft];//���⼭ �ΰ��� �ٲ��ش�
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