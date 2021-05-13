#include <stdio.h>

void main()
{
	char* ptrArray[2];
	char** ptrptr;
	int i;


	//*ptrArray -> 방안에 해당하는 문자열
	//**ptrptr -> 문자열안에 해당하는 문자
	ptrArray[0] = "Korea"; //배열안에 첫번째 방에 해당하는 문자열
	ptrArray[1] = "Seoul"; // 두번째 방에 해당하는 문자열

	ptrptr = ptrArray; //ptrArray를 포인터의 포인터 ptrptr로 지정 
	printf("\nptrArray[0]의 주소 (&ptrArray[0]) = %u", &ptrArray[0]); // 배열의 첫번째 방에 해당하는 주솟값
	printf("\n ptrArray[0]의 값 (ptrArray[0]) = %u", ptrArray[0]);//korea의 값
	printf("\n ptrArray[0]의 참조 값 (*ptrArray[0]) = %c", *ptrArray[0]);// korea의 값을 찾아 첫번째 방에 있는 값을 출력
	printf("\n ptrArray[0]의  참조 문자열 (*ptrArray[0]) = %s\n", *ptrArray);//값안에 저장되어 있는 문자열 전체 출력

	printf("\n ptrArray[1]의 주소 (&ptrArray[1]) = %u", &ptrArray[1]); //배열의 두번째 방에 해당하는 주솟값
	printf("\n ptrArray[1]의 값 (ptrArray[1]) = %u", ptrArray[1]);//seoul의 값
	printf("\n ptrArray[1]의 참조 값 (*ptrArray[1]) = %c", *ptrArray[1]);//seoul의 값을 찾아 문자열의 첫번째 방에 해당하는 값 출력
	printf("\n ptrArray[1]의  참조 문자열 (*ptrArray[1]) = %s\n", *ptrArray);//문자열을 전체 출력

	printf("\n ptrptr의 주소 (&ptrptr) = %u", &ptrptr);//
	printf("\n ptrptr의 값 (ptrptr) = %u", ptrptr);
	printf("\n ptrptr의 1차 참조값 (*ptrptr) = %u", *ptrptr);
	printf("\n ptrptr의 2차 참조값 (**ptrptr) = %c", **ptrptr);
	printf("\n ptrptr의 2차 참조 문자열 (**ptrptr) = %s", *ptrptr);
	 
	printf("\n\n *ptrArray[0] : ");
	for (i = 0; i < 5; i++)
		printf("%c", *(ptrArray[0] + i));
	printf("\n **ptrptr : ");
	for (i = 0; i < 5; i++)
		printf("%c", *(*ptrptr + i));

	printf("\n\n *ptrArray[1] : ");
	for (i = 0; i < 5; i++)
		printf("%c", *(ptrArray[1] + i));
	printf("\n **(ptrptr + 1) : ");
	for (i = 0; i < 5; i++)
		printf("%c", *(*(ptrptr + 1) + i));




}