#include <stdio.h>

typedef struct node {
	int data;    //data���
	
	struct node* link; //���� ����� �ּҸ� ������ ���
}Node;


int main()
{

	int i = 0;
	Node * head = (Node*)malloc(sizeof(Node)); //�Ӹ���� ����
	Node* node1 = (Node*)malloc(sizeof(Node)); //ù��° ��� ����
	if (node1 == NULL)return;


	node1->data = 10;//����ü�� ���� �ִ´�
	node1->link = NULL; //������ ������ ���� �ʱ�ȭ
	head->link = node1;  //�����尡 ù��° ����� �ּҰ��� �ִ´�(����� ù��° ���� ����Ų��)

	Node* node2 =(Node*)malloc(sizeof(Node)); //�ι�° ��� ����
	node1->link = node2;
	node2->data = 11;
	node2->link = NULL;

	Node* node3 = (Node*)malloc(sizeof(Node));
	node2->link = node3;
	node3->data = 165;
	node3->link = NULL;

	Node* node4 = (Node*)malloc(sizeof(Node));
	node3->link = node4;
	node3->link = 23;
	node4->link = NULL;

	Node* node5 = (Node*)malloc(sizeof(Node));


	
	Node* curr = head->link;//ù��° ����� �ּҿ� ����
	while (curr != NULL)
	{
		printf("%d��° ��� ������ : %d\n",i, curr->data);
		curr = curr->link;//������ ������ ����ּ� ����
		i++;
	}

	free(node1);
	free(head);
	free(node2);




	return 0;
}