//
//��������: 0�� ���� �ּҰ��̶�� �����ϰ� ������ ���ҵ�� ���Ͽ� ��ü �Ѵ�


#include <stdio.h>


void selectSort(int*, int);


int main()
{
	int ary[] = { 4, 2, 7, 5, 9, 1, 8, 3, 6 };//�迭����
	int size = sizeof(ary) / sizeof(ary[0]);//ũ�� 
	selectSort(ary, size);


	return 0;
}

void selectSort(int* pary, int sz)
{
	int i, min, j, temp, k;
	for (i = 0; i < sz - 1; i++)
	{
		min = i;//min�� �ʱ�ȭ(���� ��ġ ������ �ε��� i�� ���� min�� ����
		for (j = i + 1; j < sz; j++)//i�� ���� ������ ���ұ��� ���Ͽ� 
		{
			if (pary[min] > pary[j]) min = j;//���� ���� ������ �ε����� ���� min�� ����
		}
	
		//�ּڰ����ĺ��� ���� �ּڰ��� ã�°Ŵ� swap�� �̿��� ���� �ٲ۴�
		//�������� �� pary[min]�� ���� ���ؿ��� pary[i]�� temp�� �̿��� ��ȯ�Ѵ�
		temp = pary[min];
		pary[min] = pary[i];
		pary[i] = temp; 


		printf("\n%d �ܰ� :  ", i + 1);//�Ѵܰ��� ���������� ���� ������¸� ���
		for (k = 0; k < sz; k++)
		{
			printf("%d  ", pary[k]);//���� ���������� ���� ������ġ �ε���i�� �ϳ� ����Ų��  
		}
	}

}


