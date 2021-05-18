#include <stdio.h>
#define true 1
#define false 2 
typedef struct snode {
	int data;
	struct snode* link;
}SNode;

typedef struct
{
	SNode* topstk;
}TStack;

TStack* createHead()
{
	TStack* t = (TStack*)malloc(sizeof(TStack));
	if (t != NULL) t->topstk = NULL;
	return t;
}

int isEmpty(TStack* ptstack)
{
	if (ptstack->topstk == NULL) return true;
	else return false;
}

void push(TStack* ptstack, int data)
{
	SNode* newNode = (SNode*)malloc(sizeof(SNode));
	if (newNode == NULL) return;
	newNode->data = data;
	newNode->link = ptstack->topstk; //���� ��尡 �Ʒ� ��带 ����Ű�� 
	ptstack->topstk = newNode;

}

int pop(TStack* ptstack)
{
	int data;
	SNode* temp;
	if (isEmpty(ptstack))
	{
		printf("STACK is EMPTY!\n");
		return;
	}
	else
	{
		data = ptstack->topstk->data;
		temp = ptstack->topstk;
		ptstack->topstk = ptstack->topstk->link;
		free(temp);
		return data;
	}
}
void printStack(TStack* ptstack)
{
	SNode* curr = ptstack->topstk;
	while (curr != NULL)
	{
		printf("%d        ", curr->data);
		curr = curr->link;
	}
	printf("\n");
}
int main()
{
	TStack* h = createHead();
	push(h, 10);
	push(h, 20);

	printStack(h);
	return 0;
}