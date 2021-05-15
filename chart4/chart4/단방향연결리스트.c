#include <stdio.h>

typedef struct node {

	int data;//정수형 저장 데이터
	struct node* next;//다음구조체를 가리키는 포인터를 next
}Node;

typedef struct {
	Node* head;//노드타입의 구조체 변수가와야 노드를 가리킬 수 있다
}HeadNode; //HeadNode에 있는head

//헤더를 생성하는 함수
HeadNode* createHead(void) //head를 기준으로 동작해야해서 출력을 만들어야한다(다른 함수에서 사용)
{

	HeadNode* h = (HeadNode*)malloc(sizeof(HeadNode)); //동적할당을 받을 공간 만들고 그 값을 리턴시켜준다
	if (h != NULL) h->head = NULL; //h의 변수에 head의 값을 null로 해야한다


	return h;
}

//전위 함수
void preinsertNode(HeadNode* h, int data)
{
	Node* newNode = (Node*)malloc(sizeof(Node)); //새노드를 가리키는 포인터에  메모리 할당
	if (newNode != NULL)
	{
		newNode->data = data;//새노드에 데이터를 집어 넣음
		newNode->next = h->head;//새노드의 순서 
		h->head = newNode;//처음에 새노드를 넣는다 

	}
}


/*후위 삽입 함수*/
//head랑제일 멀리 떨어진 마지막노드 뒤에 새로운 노드 삽입

void rearInsertNode(HeadNode* h, int data)
{
	Node* newNode = (Node*)malloc(sizeof(Node));//newnode에 동적할당 해줌
	Node* temp;

	//새로운 노드를 생성
	if (newNode != NULL)//생성할때의 값이 null
	{
		newNode->data = data;
		newNode->next = NULL;//마지막 노드의 값은 null이어야 한다(마지막노드 뒤에 삽입하는 노드가 마지막이 되어야 하니까)
	}

	//헤드노드와 새로운 노드의 연결
	if (h->head == NULL)
	{
		h->head = newNode; //헤드노드의 head의 값에 newNode를 넣어주면 주솟값을 찾아서 연결
		return;
	}
	// if 리스트가 있으면...

	temp = h->head; //임시저장소 TEMP에 
	while (temp->next != NULL)
	{
		temp = temp->next;
	}
	temp->next = newNode;

}

//노드안의 값을확인 
void printNode(HeadNode*h)
{
	Node* temp = h->head;
	int i =0;
	


	while (temp != NULL)
	{
		printf(" %d번째 노드 데이터 : %d\n", i, temp->data);//임시로 저장된 안의 데이터 값을 확인
		temp = temp->next;// 그다음을 가리키는 주솟값을 저장
		i++;//i값 증가 
	}


}

//전체 삭제 노드 
void deleteNode(HeadNode*h)
{
	
	Node* curr; //노드를 가리키는 curr포인터 선언

	curr = h->head; 

	while (curr !=NULL)
	
		int* temp; //임시 변수 temp선언
		temp = curr->next;//temp에 주소를 복사
		free(curr);//동적해제를 해준다
		curr = temp;//다음꺼 저장한다	
	}
	
}


int main()
{
	HeadNode* h = createHead();//함수를 기반으로 새로운 빈리스트 생성
	rearInsertNode(h, 10);
	rearInsertNode(h, 6);
	rearInsertNode(h, 90);
	printNode(h);
	deleteNode(h);
	printNode(h);
	
	return 0;
}