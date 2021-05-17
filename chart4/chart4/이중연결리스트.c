#include <stdio.h>

typedef struct dlistnode {
	int data;
	struct dlistnode* prev;//�ճ�带 ����Ű�� ����Ʈ
	struct dlistnode* next; //�޳�带 ����Ű�� ����Ʈ

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
		printf("�޸� �Ҵ� ���� !!");
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


	if (phead->head == NULL) //�Ǿ� ����
	{
		phead->head = newNode;
	}
	else
	{
		//if (newNode->next == NULL)//�ǵ� ����
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

// ù��° h, newNode 
// ������ h, newNode 
// while(tmp->next =NULL) {tmp = tmp->next;}

//��� �Լ�
void printNode(HeadNode* h)
{
	DListNode* temp = h->head;
	int i = 0;
	
	while (temp != NULL)
	{
		printf("%d��° ������ ��� : %d \n", i, temp->data);
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
			printf("��ġ�ϴ� ��尡 ���� \n");
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

	DListNode* node1 = createNode(10);//InsertNode�� �Է� ���� �����Ͷ� DListNode* createNode(int data)�� �°� ���Է�
	InsertNode(h, NULL, node1);
	InsertNode(h, node1, createNode(20)); 
	printNode(h);


	return 0;
}