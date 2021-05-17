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
	Node* newNode = (Node*)malloc(sizeof(Node));
	Node* temp;

	//새로운 노드를 생성
	if (newNode != NULL)//생성할때의 값이 null
	{
		newNode->data = data;
		newNode->next = NULL;//마지막 노드의 값은 null이어야 한다
	}

	if (h->head == NULL)
	{
		h->head = newNode; //헤드노드의 head의 값에 newNode를 넣어주면 주솟값을 찾아서 연결
		return;
	}
	// if 리스트가 있으면...

	temp = h->head;
	while (temp->next != NULL)
	{
		temp = temp->next;
	}
	temp->next = newNode;

}



//노드 프린트 함수
void printNode(HeadNode*h)
{
	Node* temp = h->head;
	int i =0;
	


	while (temp != NULL)
	{
		printf(" %d번째 노드 데이터 : %d\n", i, temp->data);
		temp = temp->next;
		i++;
	}


}



//노드 전체 삭제 함수
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

//특정 노드 검색하기
Node* searchNode(HeadNode* h, int data)
{
	Node* s = h->head; //검색할 노드 포인터 s
	while ( s->next != NULL)
	{
		if (s->data == data)//데이터가 일치할 경우
		{
			printf("검색된 노드는 %d \n", s->data);
			return s; //s값 반환
		}
		else
		{
			s = s->next; //일치하는 값이 없기에 다른주솟값을 탐색
		}
	}

	printf("일치하는 값이 없습니다. \n");
	return s; //NULL; s가 찾는 값이 없다면 NULL이라서 이값을 반환
}


//겁색한 특정 노드 삭제 함수
void removeNode(HeadNode* h, Node* d)
{
	Node* curr = h->head;
	while (curr != NULL) //마지막 값까지 반복
	{
		if (d == curr)//첫번째 노드 확인
		{
			curr = d->next;//curr에 다음노즈 주소(d->next)를 넣어줌
			free(d); //d노드 삭제 
			printf("선택한 노드를 삭제했습니다. \n");
			break;//while문 탈출
		}

		else if (d == curr->next)
		{
			curr->next = d->next;

			free(d);
			printf("선택힌 노드를 삭제하시겠습니까?\n");
			break;
		}
		else
		{
			curr = curr->next;
		}
	}

	return NULL;



}

//중간노드 삽입 함수

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
			printf("위치를 찾을수 없습니다. \n");
		}
		else
		{
		
			newNode->next = pn->next;//앞에있는 next의 값을 새노드의 next의 값으로 집어 넣다 
			pn->next = newNode; 
		}
			
	}
	
}


//메인함수
int main()
{
	HeadNode* h = createHead();//함수를 기반으로 새로운 빈리스트 생성
	rearInsertNode(h, 10);
	rearInsertNode(h, 6);
	rearInsertNode(h, 90);
	printNode(h);
	Node *s = searchNode(h, 11);
	removeNode(h, s);
	return 0;
}