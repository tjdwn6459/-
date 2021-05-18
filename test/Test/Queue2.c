#include <stdio.h>
#include <malloc.h>
#define true 1
#define false 2
typedef char element;

typedef struct QNode {
	int data;
	int rear, front;
	int link;
}QNode;

typedef struct
{ QNode *front, *rear
}LQtype;
	

//공백연결 큐를 생성하는 연산


LQtype* createQueue()
{
	LQtype* LQ = (LQtype*)malloc(sizeof(LQtype));
	LQ->front = NULL;
	LQ->rear = NULL;

	return LQ;

}
//연결상태가 공백인지 검사 
int isEmpty(LQtype* LQ)
{
	if (LQ->front == NULL)
	{
		printf("큐가 비었습니다. !!\n");
		return true;
	}
	else return false;
}

int isFull(QNode* pq)
{
	if (pq->front == (pq->rear + 1) % SIZE) return true;
	else
	{
		return false;
	}
}


// 연결큐에 rear 원소를 삽입하는 연산 
void enQueue(LQtype* LQ, int data)
{
	QNode* newNode = (QNode*)malloc(sizeof(QNode));
	newNode->data = data;
	newNode->link = NULL;
	if (LQ->front == NULL)//현재 연결상태가 공백인 경우
	{
		LQ->front = newNode;
		LQ->rear = newNode;
	}
	else
	{
		LQ->rear->link = newNode;
		LQ->rear = newNode;
	}


}


//연결큐에서 원소를 삭제하고 반환하는 연산
int deQueue(LQtype* LQ)
{
	QNode* temp = LQ->front;
	int item;

	if (isEmpty(LQ)) return false;
	else
	{
		item = temp->data;
		LQ->front = LQ->front->link;
		if (LQ->front == NULL)
			LQ->rear = NULL;
		free(temp);
		return item;
	}
}



int main()
{



	return 0;
}