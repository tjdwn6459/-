#include <stdio.h>

typedef struct node {
	int data; //데이터 저장 멤버
	struct node* link; //다음노드 주소 저장하는 포인터
}Node;


void addNode(Node* target, int data)//기존 노드위에 노드를 추가 생성
{
	Node* newNode = malloc(sizeof(Node)); //동적 할당
	newNode->data = data; //데이터 저장
	newNode->link = NULL; 
	newNode->link = target->link; // target ->link에 newnode를 끼워넣다 (target의 값에 연결을 끼워넣음으로써 다시 해준다)
	target->link = newNode; //기존노드꺼에서 다음 새노드를 지정 
}

int main()
{
	int i = 0;

	Node* head = (Node*)malloc(sizeof(Node));//머리노드 생성 
	head->link = NULL;

	/*함수호출*/
	addNode(head, 10); //머리노드 뒤에 새노드 생성
	addNode(head, 12);
	addNode(head, 30);

	Node* curr = head->link; //curr임시 변수로 포인터를 만들어 head에서 link를 가리키는 값을 넣다 

	while (curr != NULL)
	{
		printf("%d번째 노드데이터 :%d\n",i, curr->data);
		curr = curr->link; //포인터 다음의 노드 주소 저장
		i++;
	}
	
	while (curr != NULL)
	{

		//거꾸로 순으로 만들어지니 그 순서대로 동적해제를 해준다.
		int* temp; //주소값을 저장할 임시 temp 선언
		temp = curr->link; //주솟값을 저장
		free(curr);// 동적해제
		curr = temp; 

	}
	free(head);

	
	
	return 0;
}