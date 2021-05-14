#include <stdio.h>

typedef struct node {

	int data;//������ ���� ������
	struct node* next;//��������ü�� ����Ű�� �����͸� next
}Node;

typedef struct {
	Node* head;//���Ÿ���� ����ü �������;� ��带 ����ų �� �ִ�
}HeadNode; //HeadNode�� �ִ�head

//����� �����ϴ� �Լ�
HeadNode* createHead(void) //head�� �������� �����ؾ��ؼ� ����� �������Ѵ�(�ٸ� �Լ����� ���)
{

	HeadNode* h = (HeadNode*)malloc(sizeof(HeadNode)); //�����Ҵ��� ���� ���� ����� �� ���� ���Ͻ����ش�
	if (h != NULL) h->head = NULL; //h�� ������ head�� ���� null�� �ؾ��Ѵ�


	return h;
}

//���� �Լ�
void preinsertNode(HeadNode* h, int data)
{
	Node* newNode = (Node*)malloc(sizeof(Node)); //����带 ����Ű�� �����Ϳ�  �޸� �Ҵ�
	if (newNode != NULL)
	{
		newNode->data = data;//����忡 �����͸� ���� ����
		newNode->next = h->head;//������� ���� 
		h->head = newNode;//ó���� ����带 �ִ´� 

	}
}


/*���� ���� �Լ�*/
//head������ �ָ� ������ ��������� �ڿ� ���ο� ��� ����

void rearInsertNode(HeadNode* h, int data)
{
	Node* newNode = (Node*)malloc(sizeof(Node));
	Node* temp;

	//���ο� ��带 ����
	if (newNode != NULL)//�����Ҷ��� ���� null
	{
		newNode->data = data;
		newNode->next = NULL;//������ ����� ���� null�̾�� �Ѵ�
	}

	if (h->head == NULL)
	{
		h->head = newNode; //������� head�� ���� newNode�� �־��ָ� �ּڰ��� ã�Ƽ� ����
		return;
	}
	// if ����Ʈ�� ������...

	temp = h->head;
	while (temp->next != NULL)
	{
		temp = temp->next;
	}
	temp->next = newNode;

}

void printNode(HeadNode*h)
{
	Node* temp = h->head;
	int i =0;
	


	while (temp != NULL)
	{
		printf(" %d��° ��� ������ : %d\n", i, temp->data);
		temp = temp->next;
		i++;
	}


}

void deleteNode(HeadNode*h)
{
	
	Node* curr;

	curr = h->head;

	while (curr !=NULL)
	{
		int* temp;
		temp = curr->next;
		free(curr);
		curr = temp;
	}
	
}


int main()
{
	HeadNode* h = createHead();//�Լ��� ������� ���ο� �󸮽�Ʈ ����
	rearInsertNode(h, 10);
	rearInsertNode(h, 6);
	rearInsertNode(h, 90);
	printNode(h);
	deleteNode(h);
	printNode(h);
	
	return 0;
}