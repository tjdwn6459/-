#include <stdio.h>

int main()
{
	int i, length = 0;
	char str[20];


	printf("문자열을 입력하세요 : ");
	gets(str);

	for (i = 0; i < str[i]; i++)
	{
		printf(" %c", str[i]);
		length += 1;

	}

	printf(" 입력된 문자열의 길이 = %d\n", length);

	getchar();

}