#include <stdio.h>
#include <string.h>

struct employee {
	char name[10];
	int year;
	int pay;

};

void main()
{
	struct employee Lee;
	struct employee* Sptr = &Lee;
	strcpy(Sptr->name, "�̼���");
	Sptr->year = 2015;
	Sptr->pay = 5900;

	printf("�̸� : %s", Sptr->name);
	printf("�Ի� : %s", Sptr->year);
	printf("���� : %s", Sptr->pay);

	getchar();//�������� �ٷ� �ȳ����� �Ϸ���
}