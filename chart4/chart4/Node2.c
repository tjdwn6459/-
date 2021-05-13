#include <stdio.h>

typedef struct node {
	int data; //������ ���� ���
	struct node* link; //������� �ּ� �����ϴ� ������
}Node;


void addNode(Node* target, int data)//���� ������� ��带 �߰� ����
{
	Node* newNode = malloc(sizeof(Node)); //���� �Ҵ�
	newNode->data = data; //������ ����
	newNode->link = NULL;
	newNode->link = target->link; // target ->link�� newnode�� �����ִ� (target�� ���� ������ �����������ν� �ٽ� ���ش�)
	target->link = newNode; //������岨���� ���� ����带 ���� 
}

int main()
{
	int i = 0;

	Node* head = (Node*)malloc(sizeof(Node));//�Ӹ���� ���� 
	head->link = NULL;

	/*�Լ�ȣ��*/
	addNode(head, 10); //�Ӹ���� �ڿ� ����� ����
	addNode(head, 12);
	addNode(head, 30);

	Node* curr = head->link; //curr��� ������ ���� ����

	while (curr != NULL)
	{
		printf("%d��° ��嵥���� :%d\n",i, curr->data);
		curr = curr->link; //������ ������ ��� �ּ� ����
		i++;
	}
	
	while (curr != NULL)
	{
		int* temp; //�ּҰ��� ������ �ӽ� temp ����
		temp = curr->link; //�ּڰ��� ����
		free(curr);// ��������
		curr = temp; 

	}
	free(head);

	
	
	return 0;
}