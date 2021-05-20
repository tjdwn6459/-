#include <stdio.h>
#include <stdlib.h>

typedef char element;
typedef struct treeNode
{
	char key;
	struct treeNode* left;
	struct treeNode* right;
}treeNode;

//����Ž�� Ʈ������ Ű����x�� ����� ��ġ�� Ž���ϴ� ����
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
	printf("\n ã�� Ű�� �����ϴ�.");
	return p;
}

//������ p�� ����Ű�� ���� ���Ͽ� ��� x�� �����ϴ� ����
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
	else printf("\n �̹� ���� Ű�� �ֽ��ϴ�. ");

	return p;

}

//��Ʈ ������ Ž���Ͽ� Ű���� ���� ��带 ã�� �����ϴ� ����
void deleteNode(treeNode* root, element key)
{
	treeNode* parent, * p, * succ, * succ_parent;
	treeNode* child;
	parent = NULL;
	p = root;
	while ((p != NULL) && ( p-> key != key)) // ������ ����� ��ġŽ��
	
		parent = p;
		if (key < p->key) p = p->left;
		else p = p->right;
		if (p == NULL)
		{
			printf("\n ã�� Ű�� ���� Ʈ���� �����ϴ�.");
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



	displayInorder(root);//������ȸ�� ���Ϸ� �ߺ��� ���� �ι� �ȳ��´�


	return 0;
}