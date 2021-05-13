#include <stdio.h>

void main()
{
	char *ary[4] = { {"Korea"}, {"Seoul"}, {"Mapo"}, {"152¹øÁö 2 / 3"} }; //¹æ
	int i;
	for (i = 0; i < 4; i++)
	
		printf("%s\n", ary[i]);
	
	ary[2] = "Jongno";
	printf("\n");
	for (i = 0; i < 4; i++)
		printf("%s\n", ary[i]);



}