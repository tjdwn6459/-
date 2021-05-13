#include <stdio.h>

void main()
{

	char string1[20] = "Dreams come true!", string[20], ptr1, *ptr2;

	ptr1 = string1;
	printf("string1ÀÇ ÁÖ¼Ò : %u\t ptr1 = %u\n", string1, ptr1);
	printf("string : %s\n ptr1 = %s", string1, ptr1);

	printf("%s", ptr1 + 7);
	
	ptr2 = &string1[7];
	printf("%s", ptr2);

	for (i = 16; i >= 0; i--)
	{
		
	}


}