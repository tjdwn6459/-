/*이진트리 순회*/
#include<stdio.h>

/*트리 구조체 할당*/
typedef struct btnode
{
	char data;
	struct btnode* left;		//이진트리 구성이므로
	struct btnode* right;		// left, right 필요
}BTNode;

/*노드 생성*/
BTNode* makeBTNode(data)
{
	BTNode* newNode = (BTNode*)malloc(sizeof(BTNode));
	newNode->data = data;
	newNode->left = NULL;
	newNode->right = NULL;
	return newNode;
}

/*왼쪽 트리 생성*/
void makeLeftTree(BTNode* root, BTNode* sub)
{
	if (root->left != NULL) free(root->left);
	root->left = sub;
	//기존에 sub트리가 있으면 삭제하고 새로운 sub트리 생성 
}

/*오른쪽 트리 생성*/
void makeRightTree(BTNode* root, BTNode* sub)
{
	if (root->right != NULL) free(root->right);
	root->right = sub;
	//기존에 sub트리가 있으면 삭제하고 새로운 sub트리 생성
}

/*순회하는 형태 3가지가 존재 - data처리하는 위치*/
//이동은 무조건 왼쪽 먼저 이동 
//1. 전위 순회 = 현재 노드 N(data를 먼저)을 처리 후 왼쪽에있는 sub트리로 이동 후, 오른쪽 sub이동
//2. 중위 순회 = 왼쪽 sub트리로 이동 후 data처리 후 오른쪽 sub 트리 이동
//3. 후위 순회 = 왼쪽 sub트리로 이동 후 오른쪽 sub트리 이동 후 data처리
//root처리는 같으나 data처리에 따라 순회하는 형태가 달라진다

/*순회 코드 작성*/

//전위 순회 : 데이터 -> 왼쪽 서브-> 오른쪽 서브
void preorder(BTNode* root)
{
	if (root == NULL) return;

	//데이터 처리
	printf("%c  ", root->data);
	//왼쪽 서브 
	preorder(root->left);
	//오른쪽 서브
	preorder(root->right);
}

//중위 순회 : 왼쪽 서브 -> 데이터 -> 오른쪽 서브
void inorder(BTNode* root)
{
	if (root == NULL) return;

	//왼쪽 서브
	inorder(root->left);
	//데이터 처리
	printf("%c  ", root->data);
	//오른쪽 서브
	inorder(root->right);
}

//후위 순회 : 왼쪽 서브 -> 오른쪽 서브 -> 데이터
void postorder(BTNode* root)
{
	if (root == NULL) return;

	//왼쪽 서브
	postorder(root->left);
	//오른쪽 서브
	postorder(root->right);
	//데이터 처리
	printf("%c  ", root->data);
}
int main()
{
	//a~h 생성, b1~8 = root
	BTNode* b1 = makeBTNode('a');
	BTNode* b2 = makeBTNode('b');
	BTNode* b3 = makeBTNode('c');
	BTNode* b4 = makeBTNode('d');
	BTNode* b5 = makeBTNode('e');
	BTNode* b6 = makeBTNode('f');
	BTNode* b7 = makeBTNode('g');
	BTNode* b8 = makeBTNode('h');

	//생성한 sub트리 연결 - 순회 알아보기
	makeLeftTree(b1, b2);
	makeRightTree(b1, b3);
	makeLeftTree(b2, b4);
	makeRightTree(b2, b5);
	makeLeftTree(b3, b6);
	makeRightTree(b3, b7);
	makeLeftTree(b4, b8);

	//연결 끝난 후 연결 형태 확인
	preorder(b1);
	printf("\n");
	inorder(b1);
	printf("\n");
	postorder(b1);
	printf("\n");

	//설명 드간다 
	/*
	* 전위는 출력하고 이동, 출력하고 이동
	* 중위, 후위는 이동 후 출력, 이동 후 출력
		출력할 data 중심으로 해서 왼쪽, 오른쪽 처리함!
		왼쪽 처리 한다고 해서 왼쪽으로만 계속 처리하는 것도 아니고,
		오른쪽 처리 한다고 해서 오른쪽으로만 계속 처리하는 것도 아님!
		데이터 중심으로 왼쪽, 오른쪽 다 값이 있으면
		왼쪽 처리 후 오른쪽 처리 이렇게 순회함!
	*/


	return 0;
}