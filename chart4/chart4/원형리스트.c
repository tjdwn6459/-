#include <stdio.h>

typedef struct listnode {
	int data;
	struct listnode* link;
}ListNode;

typedef struct {
	ListNode* head; //��� ���� head
}HeadNode;

HeadNode* createHead(void) {
	HeadNode* h = (HeadNode*)malloc(sizeof(HeadNode));
		h->head = NULL;
		return h;
}

ListNode* createNode(HeadNode* phead, int data)
{
	ListNode* newNode = (ListNode*)malloc(sizeof(ListNode));
	if (newNode == NULL)
	{
		printf("�޸� �Ҵ� ���� !");
		return;
	}
	else {
		newNode->data = data;//�ּҿ� �ִ� ��������� �����͸� ã�� ���� �ֱ�
		newNode->link = NULL; //newnode�� link�� ��������� null�� ���� �־��
		return newNode;
	}

}

void insertFirstNode(HeadNode* phead, ListNode* newNode)
{

	ListNode* temp;
	if (phead->head == NULL) {//phead�ȿ� �ִ�head�� ���� ������ null��  ���� �ִ´� 
		phead->head = newNode; 
		newNode->link = newNode; //newnode�� �Ҵ�Ǿ��ִ� ���庯���� 
	}
	else
	{
		newNode->link = phead->head->link;
		phead->head->link = newNode;
	}
}

void insertLastNode(HeadNode* phead, ListNode* newNode)
{

	if (phead->head == NULL)
	{
		phead->head = newNode;
		newNode->link = newNode; //�ڱ��ڽ��� ����Ų��(newNode)
	}
	else
	{
		newNode->link = phead->head->link;
		phead->head->link = newNode;
		phead->head = newNode;
	}
	/*ListNode* temp;

	while (temp -> link != phead ->head)
	{
		temp->link = newNode;
		newNode->link = phead->head;
			 
	}*/
}

void printNode(HeadNode* h)
{
	ListNode* temp = h->head;
	int i = 0;

	while (temp != NULL)
	{
		printf("%d��° ��� ������ : %d\n", i, temp->data);
		temp = temp->link;
		i++;
	}


}
int main()
{



	return 0;
}