#include <stdio.h>
#include <string.h>

struct employee {
	char name[10];
	int year;
	int pay;

};

void main()
{
	int i;
	struct employee Lee[4] = {
		{"����ȣ", 2014,4200},
		{"���ѿ�", 2015,2982},
		{"�̻��", 4444,3433},
		{"�̻��", 3333,4444}
	};

	for (i = 0; i < 4; i++)
	{
		printf("�̸� : %s", Lee[i].name);
		printf("�Ի� : %d", Lee[i].year);
		printf("���� : %d", Lee[i].pay);
	}


}