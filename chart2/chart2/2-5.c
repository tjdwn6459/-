#include <stdio.h>

int main()
{
	int i, length = 0;
	char str[20];


	printf("���ڿ��� �Է��ϼ��� : ");
	gets(str);

	for (i = 0; i < str[i]; i++)
	{
		printf(" %c", str[i]);
		length += 1;

	}

	printf(" �Էµ� ���ڿ��� ���� = %d\n", length);

	getchar();

}