#include <stdio.h>


#define STACK_SZ    3// STACK_SZ  ���ڸ� �߰��ϸ� 3���� ġȯ
#define true 1
#define false 2

//1) ��ȭ�������� ����ִ��� ���¸� Ȯ�� 2) ������ ���

int isEmpty(); //����üũ
int isFull();  // ��ȭüũ

void push(int); //�����ϴ� �Լ�(���ؿ� �Է�)
int pop();//���ÿ��� ���

void printStack();

int peek();//������ ����Ȯ��

int stack[STACK_SZ];//������ �迭����
int top = -1;//���� ���ÿ� ��� �����Ͱ� �ִ��� Ȯ�ΰ���(������ ��ġ�� Ȯ��, �׻� ������ ������ ����Ŵ)
int main()
{

	push(10);

	printStack();

	return 0;
}

//�������� Ȯ��
int isEmpty()
{
	if (top <= -1)//�ȿ� ����ִ� ���Ұ� ������
	{
		return true;
	}
	else
	{
		return false;
	}

}

int isFull()
{
	if (top >= STACK_SZ - 1) return true; //����á���� true
	else return false;
}
void push(int data)
{
	if (isFull()) //�����͸� �ִµ� ���������� ���
	{
		printf("STACK overflow!!\n");
		return;
	}
	else
	{
		stack[++top] = data; //��á����� �����͸�  ���� �ִ´�(top = -1)
	}
}

int pop()
{
	if (isEmpty())
	{
		printf(" STACK underflow!!\n");
		return;
	}
	else
	{
		return stack[top--];
	}
}


int peek()
{
	if (isEmpty())
	{
		printf("STACK underflow!!!\n");
		exit(1);
	}
	else return stack[top];
}

void printStack()
{
	int i;
	if (!isEmpty())
	{
		for (i = 0; i <= top; i++)
		{
			printf("%d    ", stack[i]);
		}
	}
}