#include<stdio.h>
#define MAX(a, b) ((a>b)? a:b)
#define MAX_DEGREE 50

typedef struct
{
	int degree;
	float coef[MAX_DEGREE]; //#define 50 �̾ȿ� �� ��
} polynomial;

polynomial addPoly(polynomial, polynomial);
void printPoly(polynomial); //return���� ����Լ��� �Է����� 

void main()
{
	polynomial A = { 3,{4, 3, 5, 0} }; //A�� 3������ ��������� �ʱ�ȭ
	polynomial B = { 4, {3, 1, 0, 2,1} };//B�� 4������ ��������� �ʱ�ȭ 

	polynomial C;
	C = addPoly(A, B); //A,B�� �Լ��� ���ؼ� ���Ϲ޾� C�� ����

	printf("\nA(x) ="); printPoly(A);
	printf("\nB(x) ="); printPoly(B);
	printf("\nC(x) ="); printPoly(C);
}

polynomial addPoly(polynomial A, polynomial B)
{
	polynomial C; //������ ����ü ���� C
	int A_index = 0, B_index = 0, C_index = 0;
	int A_degree = A.degree, B_degree = B.degree; //������ ��
	C.degree = MAX(A.degree, B.degree); //A,B�� ���Ͽ� ū���� C�� ����

	while (A_index <= A.degree && B_index <= B.degree) // �ΰ��� �����ҽ� ��
	{
		if (A_degree > B_degree) { //A���ִ� ���� ũ�� ����
			C.coef[C_index++] = A.coef[A_index++];
			A_degree--;
		}
		else if (A_degree == B_degree) {//�ΰ��� ���� ������ ����
			C.coef[C_index++] = A.coef[A_index++] + B.coef[B_index++];
			A_degree--;
			B_degree--;
		}
		else
		{
			C.coef[C_index++] = B.coef[B_index++];
			B_degree--;
		}
	}

	return C;
}

	void printPoly(polynomial P)
	{
		int i, degree;
		degree = P.degree;

		for (i = 0; i <= P.degree; i++)
		{
			printf("%3.0fx^%d", P.coef[i], degree--);
			if (i < P.degree)printf("+");
		}

		printf("\n");
	}

