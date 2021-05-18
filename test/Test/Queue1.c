#include <stdio.h>
#include <stdbool.h>
#define SIZE 6




int isEmpty();
int isFull();

void enQueue(int); //q에 삽입
int deQueue();//q에 제거

int rear = 0;//입구
int front = 0;//출구
int queue[SIZE];

int main()
{

	enQueue(10); //제일먼저 들어간게 제일먼저 빠져나오게 된다
	enQueue(20);
	enQueue(30);
	printf("%d\n", deQueue());
	printf("%d\n", deQueue());
	return 0;


}
int isEmpty()
{
	if (rear == front) return true;
	else
	{
		return false;
	}
}
int isFull()
{
	if (front == (rear + 1) % SIZE)
		return true;
	else return false;
}
void enQueue(int data)
{
	if (isFull()) printf("Queue overflow!!!\n");
	else
	{
		rear = rear % SIZE;
		queue[rear] = data;
		rear++;
	}
}

int deQueue() //Q에서 제거
{
	if (isEmpty())
	{
		printf("Queue underflow!!\n");
		return;
	}
	else
	{
		return queue[front++ % SIZE];
	}
}
