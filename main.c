#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	
	FILE *fp;
	char Name[100];
	
	/*분석 대상 파일 열기*/
	//ptintf, scanf
	printf("Input a file name : ");
	scanf("%s", Name);
	
	//fopen
	fp = fopen(Name, "r");
	
	//error handling
	if(fp == NULL)
	{
		printf("ERROR! Check the file name : %s\n", Name);
		return -1;
	}
	
	//fclose
	fclose(fp);
	
	/*파일 내 코드의 단어 하나하나 분석*/
	
	/*분석 결과 출력*/
	
	return 0;
}
