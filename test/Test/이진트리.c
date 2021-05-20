/*����Ʈ�� ��ȸ*/
#include<stdio.h>

/*Ʈ�� ����ü �Ҵ�*/
typedef struct btnode
{
	char data;
	struct btnode* left;		//����Ʈ�� �����̹Ƿ�
	struct btnode* right;		// left, right �ʿ�
}BTNode;

/*��� ����*/
BTNode* makeBTNode(data)
{
	BTNode* newNode = (BTNode*)malloc(sizeof(BTNode));
	newNode->data = data;
	newNode->left = NULL;
	newNode->right = NULL;
	return newNode;
}

/*���� Ʈ�� ����*/
void makeLeftTree(BTNode* root, BTNode* sub)
{
	if (root->left != NULL) free(root->left);
	root->left = sub;
	//������ subƮ���� ������ �����ϰ� ���ο� subƮ�� ���� 
}

/*������ Ʈ�� ����*/
void makeRightTree(BTNode* root, BTNode* sub)
{
	if (root->right != NULL) free(root->right);
	root->right = sub;
	//������ subƮ���� ������ �����ϰ� ���ο� subƮ�� ����
}

/*��ȸ�ϴ� ���� 3������ ���� - dataó���ϴ� ��ġ*/
//�̵��� ������ ���� ���� �̵� 
//1. ���� ��ȸ = ���� ��� N(data�� ����)�� ó�� �� ���ʿ��ִ� subƮ���� �̵� ��, ������ sub�̵�
//2. ���� ��ȸ = ���� subƮ���� �̵� �� dataó�� �� ������ sub Ʈ�� �̵�
//3. ���� ��ȸ = ���� subƮ���� �̵� �� ������ subƮ�� �̵� �� dataó��
//rootó���� ������ dataó���� ���� ��ȸ�ϴ� ���°� �޶�����

/*��ȸ �ڵ� �ۼ�*/

//���� ��ȸ : ������ -> ���� ����-> ������ ����
void preorder(BTNode* root)
{
	if (root == NULL) return;

	//������ ó��
	printf("%c  ", root->data);
	//���� ���� 
	preorder(root->left);
	//������ ����
	preorder(root->right);
}

//���� ��ȸ : ���� ���� -> ������ -> ������ ����
void inorder(BTNode* root)
{
	if (root == NULL) return;

	//���� ����
	inorder(root->left);
	//������ ó��
	printf("%c  ", root->data);
	//������ ����
	inorder(root->right);
}

//���� ��ȸ : ���� ���� -> ������ ���� -> ������
void postorder(BTNode* root)
{
	if (root == NULL) return;

	//���� ����
	postorder(root->left);
	//������ ����
	postorder(root->right);
	//������ ó��
	printf("%c  ", root->data);
}
int main()
{
	//a~h ����, b1~8 = root
	BTNode* b1 = makeBTNode('a');
	BTNode* b2 = makeBTNode('b');
	BTNode* b3 = makeBTNode('c');
	BTNode* b4 = makeBTNode('d');
	BTNode* b5 = makeBTNode('e');
	BTNode* b6 = makeBTNode('f');
	BTNode* b7 = makeBTNode('g');
	BTNode* b8 = makeBTNode('h');

	//������ subƮ�� ���� - ��ȸ �˾ƺ���
	makeLeftTree(b1, b2);
	makeRightTree(b1, b3);
	makeLeftTree(b2, b4);
	makeRightTree(b2, b5);
	makeLeftTree(b3, b6);
	makeRightTree(b3, b7);
	makeLeftTree(b4, b8);

	//���� ���� �� ���� ���� Ȯ��
	preorder(b1);
	printf("\n");
	inorder(b1);
	printf("\n");
	postorder(b1);
	printf("\n");

	//���� �尣�� 
	/*
	* ������ ����ϰ� �̵�, ����ϰ� �̵�
	* ����, ������ �̵� �� ���, �̵� �� ���
		����� data �߽����� �ؼ� ����, ������ ó����!
		���� ó�� �Ѵٰ� �ؼ� �������θ� ��� ó���ϴ� �͵� �ƴϰ�,
		������ ó�� �Ѵٰ� �ؼ� ���������θ� ��� ó���ϴ� �͵� �ƴ�!
		������ �߽����� ����, ������ �� ���� ������
		���� ó�� �� ������ ó�� �̷��� ��ȸ��!
	*/


	return 0;
}