#include <stdio.h>
#include <stdlib.h>

typedef char element;
typedef struct treeNode
{
	char key;
	struct treeNode* left;
	struct treeNode* right;
}treeNode;

//이진탐색 트리에서 키값이x인 노드의 위치를 탐색하는 연산
treeNode* searchBST(treeNode* root, char x)
{
	treeNode* p;
	p = root;
	while ( p != NULL)
	{
		if (x < p->key) p = p->left;
		else if (x == p->key) return p;
		else p = p->right;
	}
	printf("\n 찾는 키가 없습니다.");
	return p;
}

//포인터 p가 가리키는 노드와 비교하여 노드 x를 삽입하는 연산
treeNode* insertNode(treeNode* p, char x)
{
	treeNode* newNode;
	if (p == NULL)
	{
		newNode = (treeNode*)malloc(sizeof(treeNode));
		newNode->key = x;
		newNode->left = NULL;
		newNode->right = NULL;
		return newNode;
	}

	else if (x < p->key) p->left = insertNode(p->left, x);
	else if (x > p->key) p->right = insertNode(p->right, x);
	else printf("\n 이미 같은 키가 있습니다. ");

	return p;

}

//루트 노드부터 탐색하여 키값과 같은 노드를 찾아 삭제하는 연산
void deleteNode(treeNode* root, element key)
{
	treeNode* parent, * p, * succ, * succ_parent;
	treeNode* child;
	parent = NULL;
	p = root;
	while ((p != NULL) && ( p-> key != key)) // 삭제할 노드의 위치탐색
	
		parent = p;
		if (key < p->key) p = p->left;
		else p = p->right;
		if (p == NULL)
		{
			printf("\n 찾는 키가 이진 트린에 없습니다.");
			return;
		}

		if ((p->left == NULL) && (p->right == NULL))
		{
			if (parent != NULL) {
				if (parent->left == p)parent->left = NULL;
				else parent->right = NULL;
			}
			else root = NULL;
		}

		else if ((p->left == NULL) || (p->right == NULL))
		{
			if (p->left != NULL) child = p->left;
			else child = p->right;

			if (parent != NULL)
			{
				if (parent->left = p)parent->left = child;
				else parent->right = child;
			}
			else root = child;
		}

		else {
			succ_parent = p;
			succ = p->left;
			while (succ ->right != NULL)
			{
				succ_parent = succ;
				succ = succ->right;
			}
			if (succ_parent->left == succ) succ_parent->left = succ->left;
			else succ_parent->right = succ->left;
			p->key = succ->key;
			p = succ;

		}
		free(p);
	
}

void displayInorder(treeNode* root)
{
	if (root)
	{
		displayInorder(root->left);
		printf("%c  ", root->key);
		displayInorder(root->right);
	}
}

int main()
{
	treeNode* root = NULL;
	//searchBST(root, 'K');
	root = insertNode(root, 'K');
	insertNode(root, 'i');
	insertNode(root, 'c');
	insertNode(root, 'g');
	insertNode(root, 's');
	insertNode(root, 'h');
	insertNode(root, 'r');
	insertNode(root, 't');
	insertNode(root, 't');



	displayInorder(root);//중위순회를 통하려 중복된 값이 두번 안나온다


	return 0;
}