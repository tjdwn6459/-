#include <stdio.h>
\

void main()
{
	int i = 10, j = 20;
	int* ptr;

	printf("i �� �� = %d, j�� �� = %d\n", i, j);
	printf("i�� �޸� �ּ�(&i) = %u\n ", &i);
	printf("j�� �޸� �ּ� (&j) = %u \ n", &j);

	ptr = &i;
	printf("ptr�� �޸� �ּ�(&ptr) = %u\n", &ptr);
	printf("ptr�� ��(ptr) = %u", ptr);
	printf("ptr�� ������ (*ptr) = %d", *ptr);

	ptr = &j;
	printf("ptr�� �޸� �ּ�(&ptr) = %u\n", &ptr);
	printf("ptr�� ��(ptr) = %u", ptr);
	printf("ptr�� ������ (*ptr) = %d", *ptr);

	i = *ptr;
	printf("i�� �� : %d", i);	




}