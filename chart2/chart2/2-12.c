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
		{"이진호", 2014,4200},
		{"이한영", 2015,2982},
		{"이상원", 4444,3433},
		{"이상범", 3333,4444}
	};

	for (i = 0; i < 4; i++)
	{
		printf("이름 : %s", Lee[i].name);
		printf("입사 : %d", Lee[i].year);
		printf("연봉 : %d", Lee[i].pay);
	}


}