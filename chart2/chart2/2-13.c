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
	strcpy(Sptr->name, "이순신");
	Sptr->year = 2015;
	Sptr->pay = 5900;

	printf("이름 : %s", Sptr->name);
	printf("입사 : %s", Sptr->year);
	printf("연봉 : %s", Sptr->pay);

	getchar();//개행으로 바로 안끝나게 하려고
}