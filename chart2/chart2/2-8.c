#include <stdio.h>
\

void main()
{
	int i = 10, j = 20;
	int* ptr;

	printf("i 의 값 = %d, j의 값 = %d\n", i, j);
	printf("i의 메모리 주소(&i) = %u\n ", &i);
	printf("j의 메모리 주소 (&j) = %u \ n", &j);

	ptr = &i;
	printf("ptr의 메모리 주소(&ptr) = %u\n", &ptr);
	printf("ptr의 값(ptr) = %u", ptr);
	printf("ptr의 참조값 (*ptr) = %d", *ptr);

	ptr = &j;
	printf("ptr의 메모리 주소(&ptr) = %u\n", &ptr);
	printf("ptr의 값(ptr) = %u", ptr);
	printf("ptr의 참조값 (*ptr) = %d", *ptr);

	i = *ptr;
	printf("i의 값 : %d", i);	




}