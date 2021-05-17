#include <stdio.h>

typedef struct dlistnode {
	int data;
	struct dlistnode* prev;//앞노드를 가리키는 포인트
	struct dlistnode* next; //뒷노드를 가리키는 포인트

}DListNode;

typedef struct
{
	DListNode* head;
}HeadNode;

HeadNode* createHead()
{
	HeadNode* h = (HeadNode*)malloc(sizeof(HeadNode));
	if (h != NULL)
	{
		h->head = NULL;
		return h;
	}
}

DListNode* createNode(int data)
{
	DListNode* newNode = (DListNode*)malloc(sizeof(DListNode));
	if (newNode == NULL)
	{
		printf("메모리 할당 실패 !!");
		exit(1);
	}
	else
	{
		newNode->data = data;
		newNode->next = NULL;
		newNode->prev = NULL;
		return newNode;
	}
}

void InsertNode(HeadNode* phead, DListNode* preNode, DListNode* newNode)
{


	if (phead->head == NULL) //맨앞 삽입
	{
		phead->head = newNode;
	}
	else
	{
		//if (newNode->next == NULL)//맨뒤 삽입
		//{
		//	newNode->next = NULL;
		//	newNode->prev = preNode->next;

		//}
		newNode->prev = preNode->next;
		preNode->next = newNode;
		newNode->prev = preNode;
		newNode->next->prev = newNode;

	}
}

// 첫번째 h, newNode 
// 마지막 h, newNode 
// while(tmp->next =NULL) {tmp = tmp->next;}

//출력 함수
void printNode(HeadNode* h)
{
	DListNode* temp = h->head;
	int i = 0;
	
	while (temp != NULL)
	{
		printf("%d번째 데이터 출력 : %d \n", i, temp->data);
		temp = temp->next;
		i++;
	}


}

void allDeleteNode(HeadNode* phead)
{
	DListNode* curr = NULL;
	while (phead ->head !=NULL)
	{
		curr = phead->head;
		phead->head = phead->head->next;
		free(curr);
		curr = NULL;
	}
	
	

}

DListNode* findNode(HeadNode* phead, int data)
{
	DListNode* temp;
	temp = phead->head;
	while (temp != NULL)
	{
		if (temp->data == data)
		{
			printf("일치하는 노드가 존재 \n");
			return temp;
		}
		else
		{
			temp = temp->next;
		}
	}
}

int main()
{
	HeadNode* h = createHead();

	DListNode* node1 = createNode(10);//InsertNode의 입력 값이 포인터라 DListNode* createNode(int data)에 맞게 값입력
	InsertNode(h, NULL, node1);
	InsertNode(h, node1, createNode(20)); 
	printNode(h);


	return 0;
}