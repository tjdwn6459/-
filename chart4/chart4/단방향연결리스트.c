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



//��� ����Ʈ �Լ�
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



//��� ��ü ���� �Լ�
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

//Ư�� ��� �˻��ϱ�
Node* searchNode(HeadNode* h, int data)
{
	Node* s = h->head; //�˻��� ��� ������ s
	while ( s->next != NULL)
	{
		if (s->data == data)//�����Ͱ� ��ġ�� ���
		{
			printf("�˻��� ���� %d \n", s->data);
			return s; //s�� ��ȯ
		}
		else
		{
			s = s->next; //��ġ�ϴ� ���� ���⿡ �ٸ��ּڰ��� Ž��
		}
	}

	printf("��ġ�ϴ� ���� �����ϴ�. \n");
	return s; //NULL; s�� ã�� ���� ���ٸ� NULL�̶� �̰��� ��ȯ
}


//�̻��� Ư�� ��� ���� �Լ�
void removeNode(HeadNode* h, Node* d)
{
	Node* curr = h->head;
	while (curr != NULL) //������ ������ �ݺ�
	{
		if (d == curr)//ù��° ��� Ȯ��
		{
			curr = d->next;//curr�� �������� �ּ�(d->next)�� �־���
			free(d); //d��� ���� 
			printf("������ ��带 �����߽��ϴ�. \n");
			break;//while�� Ż��
		}

		else if (d == curr->next)
		{
			curr->next = d->next;

			free(d);
			printf("������ ��带 �����Ͻðڽ��ϱ�?\n");
			break;
		}
		else
		{
			curr = curr->next;
		}
	}

	return NULL;



}

//�߰���� ���� �Լ�

void midInsertNode(HeadNode* h, Node* pn, int data)
{
	Node* newNode = (Node*)malloc(sizeof(Node));
	if (newNode != NULL)
	{
		newNode->data = data;
		newNode->next = NULL;
		if (h->head = NULL)
		{
			h->head = newNode;
		}
		else if (pn == NULL)
		{
			printf("��ġ�� ã���� �����ϴ�. \n");
		}
		else
		{
		
			newNode->next = pn->next;//�տ��ִ� next�� ���� ������� next�� ������ ���� �ִ� 
			pn->next = newNode; 
		}
			
	}
	
}


//�����Լ�
int main()
{
	HeadNode* h = createHead();//�Լ��� ������� ���ο� �󸮽�Ʈ ����
	rearInsertNode(h, 10);
	rearInsertNode(h, 6);
	rearInsertNode(h, 90);
	printNode(h);
	Node *s = searchNode(h, 11);
	removeNode(h, s);
	return 0;
}