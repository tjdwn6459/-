#include <stdio.h>


#define STACK_SZ    3// STACK_SZ  문자를 발견하면 3으로 치환
#define true 1
#define false 2

//1) 포화상태인지 비어있는지 상태를 확인 2) 공간을 사용

int isEmpty(); //공백체크
int isFull();  // 포화체크

void push(int); //삽입하는 함수(스텍에 입력)
int pop();//스택에서 출력

void printStack();

int peek();//맨위의 스택확인

int stack[STACK_SZ];//스택의 배열생성
int top = -1;//현재 스택에 몇개의 데이터가 있는지 확인가능(현재의 위치를 확인, 항상 스택의 맨위를 가리킴)
int main()
{

	push(10);

	printStack();

	return 0;
}

//공백인지 확인
int isEmpty()
{
	if (top <= -1)//안에 들어있는 원소가 없으면
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
	if (top >= STACK_SZ - 1) return true; //가득찼으면 true
	else return false;
}
void push(int data)
{
	if (isFull()) //데이터를 넣는데 가득차있을 경우
	{
		printf("STACK overflow!!\n");
		return;
	}
	else
	{
		stack[++top] = data; //안찼을경우 데이터를  집어 넣는다(top = -1)
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