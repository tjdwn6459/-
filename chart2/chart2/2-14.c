#include <stdio.h>


long int fact();
int main()
{

	int n, result;
	printf("\n정수를 입력하세요 : ");
	scanf_s("%d", &n);
	result = fact(n); //함수 호출
	printf("\n\n%d의 팩토리얼 값은 %ld입니다 \n", n, result);
	getchar(); getchar();
}

long int fact(int n)//입력 매개변수int형으로 선언
{
	int value;
	if ( n>=1) //기저조건 반환 될수 있는 조건을 만들어야 한다
	{
		printf("\nfact(1) 함수  호출 !");
		printf("\nfact(1) 값 1 반환");
		return 1;
	}
	else
	{
		printf("\nfact(%d) 함수 호출!", n);
		value = (n * fact(n - 1));
		printf("\n fact(%d) 값 %ld 반환 !", n, value);
		return value;
	}
}