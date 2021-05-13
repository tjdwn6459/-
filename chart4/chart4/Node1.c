#include <stdio.h>

typedef struct node {
	int data;    //data멤버
	
	struct node* link; //다음 노드의 주소를 저장할 멤버
}Node;


int main()
{

	int i = 0;
	Node * head = (Node*)malloc(sizeof(Node)); //머리노드 생성
	Node* node1 = (Node*)malloc(sizeof(Node)); //첫번째 노드 생성
	if (node1 == NULL)return;


	node1->data = 10;//구조체에 값을 넣는다
	node1->link = NULL; //생성을 했으면 값을 초기화
	head->link = node1;  //헤더노드가 첫번째 노드의 주소값을 넣는다(헤더가 첫번째 값을 가리킨다)

	Node* node2 =(Node*)malloc(sizeof(Node)); //두번째 노드 생성
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


	
	Node* curr = head->link;//첫번째 노드의 주소에 저장
	while (curr != NULL)
	{
		printf("%d번째 노드 데이터 : %d\n",i, curr->data);
		curr = curr->link;//포인터 다음의 노드주소 저장
		i++;
	}

	free(node1);
	free(head);
	free(node2);




	return 0;
}