#include <stdio.h>


long int fact();
int main()
{

	int n, result;
	printf("\n������ �Է��ϼ��� : ");
	scanf_s("%d", &n);
	result = fact(n); //�Լ� ȣ��
	printf("\n\n%d�� ���丮�� ���� %ld�Դϴ� \n", n, result);
	getchar(); getchar();
}

long int fact(int n)//�Է� �Ű�����int������ ����
{
	int value;
	if ( n>=1) //�������� ��ȯ �ɼ� �ִ� ������ ������ �Ѵ�
	{
		printf("\nfact(1) �Լ�  ȣ�� !");
		printf("\nfact(1) �� 1 ��ȯ");
		return 1;
	}
	else
	{
		printf("\nfact(%d) �Լ� ȣ��!", n);
		value = (n * fact(n - 1));
		printf("\n fact(%d) �� %ld ��ȯ !", n, value);
		return value;
	}
}