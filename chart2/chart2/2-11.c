#include <stdio.h>

void main()
{
	char* ptrArray[2];
	char** ptrptr;
	int i;


	//*ptrArray -> ��ȿ� �ش��ϴ� ���ڿ�
	//**ptrptr -> ���ڿ��ȿ� �ش��ϴ� ����
	ptrArray[0] = "Korea"; //�迭�ȿ� ù��° �濡 �ش��ϴ� ���ڿ�
	ptrArray[1] = "Seoul"; // �ι�° �濡 �ش��ϴ� ���ڿ�

	ptrptr = ptrArray; //ptrArray�� �������� ������ ptrptr�� ���� 
	printf("\nptrArray[0]�� �ּ� (&ptrArray[0]) = %u", &ptrArray[0]); // �迭�� ù��° �濡 �ش��ϴ� �ּڰ�
	printf("\n ptrArray[0]�� �� (ptrArray[0]) = %u", ptrArray[0]);//korea�� ��
	printf("\n ptrArray[0]�� ���� �� (*ptrArray[0]) = %c", *ptrArray[0]);// korea�� ���� ã�� ù��° �濡 �ִ� ���� ���
	printf("\n ptrArray[0]��  ���� ���ڿ� (*ptrArray[0]) = %s\n", *ptrArray);//���ȿ� ����Ǿ� �ִ� ���ڿ� ��ü ���

	printf("\n ptrArray[1]�� �ּ� (&ptrArray[1]) = %u", &ptrArray[1]); //�迭�� �ι�° �濡 �ش��ϴ� �ּڰ�
	printf("\n ptrArray[1]�� �� (ptrArray[1]) = %u", ptrArray[1]);//seoul�� ��
	printf("\n ptrArray[1]�� ���� �� (*ptrArray[1]) = %c", *ptrArray[1]);//seoul�� ���� ã�� ���ڿ��� ù��° �濡 �ش��ϴ� �� ���
	printf("\n ptrArray[1]��  ���� ���ڿ� (*ptrArray[1]) = %s\n", *ptrArray);//���ڿ��� ��ü ���

	printf("\n ptrptr�� �ּ� (&ptrptr) = %u", &ptrptr);//
	printf("\n ptrptr�� �� (ptrptr) = %u", ptrptr);
	printf("\n ptrptr�� 1�� ������ (*ptrptr) = %u", *ptrptr);
	printf("\n ptrptr�� 2�� ������ (**ptrptr) = %c", **ptrptr);
	printf("\n ptrptr�� 2�� ���� ���ڿ� (**ptrptr) = %s", *ptrptr);
	 
	printf("\n\n *ptrArray[0] : ");
	for (i = 0; i < 5; i++)
		printf("%c", *(ptrArray[0] + i));
	printf("\n **ptrptr : ");
	for (i = 0; i < 5; i++)
		printf("%c", *(*ptrptr + i));

	printf("\n\n *ptrArray[1] : ");
	for (i = 0; i < 5; i++)
		printf("%c", *(ptrArray[1] + i));
	printf("\n **(ptrptr + 1) : ");
	for (i = 0; i < 5; i++)
		printf("%c", *(*(ptrptr + 1) + i));




}