#include<stdio.h>
#define MAX(a, b) ((a>b)? a:b)
#define MAX_DEGREE 50

typedef struct
{
	int degree;
	float coef[MAX_DEGREE]; //#define 50 이안에 들어갈 수
} polynomial;

polynomial addPoly(polynomial, polynomial);
void printPoly(polynomial); //return받은 출력함수를 입력으로 

void main()
{
	polynomial A = { 3,{4, 3, 5, 0} }; //A는 3차항의 계수값들을 초기화
	polynomial B = { 4, {3, 1, 0, 2,1} };//B는 4차항의 계수값들을 초기화 

	polynomial C;
	C = addPoly(A, B); //A,B의 함수를 더해서 리턴받아 C에 저장

	printf("\nA(x) ="); printPoly(A);
	printf("\nB(x) ="); printPoly(B);
	printf("\nC(x) ="); printPoly(C);
}

polynomial addPoly(polynomial A, polynomial B)
{
	polynomial C; //저장할 구조체 변수 C
	int A_index = 0, B_index = 0, C_index = 0;
	int A_degree = A.degree, B_degree = B.degree; //차항의 수
	C.degree = MAX(A.degree, B.degree); //A,B를 비교하여 큰값을 C에 저장

	while (A_index <= A.degree && B_index <= B.degree) // 두개다 만족할시 참
	{
		if (A_degree > B_degree) { //A에있는 항이 크면 실행
			C.coef[C_index++] = A.coef[A_index++];
			A_degree--;
		}
		else if (A_degree == B_degree) {//두개의 항이 같으면 실행
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

