#include <stdio.h>

typedef struct listnode {
	int data;
	struct listnode* link;
}ListNode;

typedef struct {
	ListNode* head; //멤버 변수 head
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
		printf("메모리 할당 실패 !");
		return;
	}
	else {
		newNode->data = data;//주소에 있는 저장공간인 데이터를 찾아 집어 넣기
		newNode->link = NULL; //newnode의 link에 저장공간에 null을 집어 넣어라
		return newNode;
	}

}

void insertFirstNode(HeadNode* phead, ListNode* newNode)
{

	ListNode* temp;
	if (phead->head == NULL) {//phead안에 있는head의 저장 변수에 null을  집어 넣는다 
		phead->head = newNode; 
		newNode->link = newNode; //newnode가 할당되어있는 저장변수에 
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
		newNode->link = newNode; //자기자신을 가리킨다(newNode)
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
		printf("%d번째 노드 데이터 : %d\n", i, temp->data);
		temp = temp->link;
		i++;
	}


}
int main()
{



	return 0;
}