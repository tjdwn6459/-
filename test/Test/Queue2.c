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
	

//���鿬�� ť�� �����ϴ� ����


LQtype* createQueue()
{
	LQtype* LQ = (LQtype*)malloc(sizeof(LQtype));
	LQ->front = NULL;
	LQ->rear = NULL;

	return LQ;

}
//������°� �������� �˻� 
int isEmpty(LQtype* LQ)
{
	if (LQ->front == NULL)
	{
		printf("ť�� ������ϴ�. !!\n");
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


// ����ť�� rear ���Ҹ� �����ϴ� ���� 
void enQueue(LQtype* LQ, int data)
{
	QNode* newNode = (QNode*)malloc(sizeof(QNode));
	newNode->data = data;
	newNode->link = NULL;
	if (LQ->front == NULL)//���� ������°� ������ ���
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


//����ť���� ���Ҹ� �����ϰ� ��ȯ�ϴ� ����
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