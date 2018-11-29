#include <stdio.h>
#include <stdlib.h>
#include "keyword.h"
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int is_whitespace(char c)
{
	if (c ==' '||
		c == '\t' ||
		c == '\n' ||
		c == '\r' ||
		c == '(' ||
		c == ')')
	return 1; //공백 글자
	
	return 0; // 유의미한 글자 
}

int fget_word(FILE* fp, char* word){
	
	char c;
	int cnt;
	
	//1. 무의미한 글자 건너뛰기(유의미한 글자가 나올 때까지 입력된 글자 버림 반복)
	while((c=fgetc(fp)) != EOF){
		if(is_whitespace(c) == 0){
			break;
		}
	}
	//2. 파일 끝으로 간 경우는 0 반환
	if(c == EOF){
		return 0;
	}
	
	//3. 유의미한 글자 저장
	cnt = 0;
	word[cnt++] = c;
	word[cnt] = '\0';
	
	while((word[cnt] = fgetc(fp)) != EOF){
		if(is_whitespace(word[cnt]) == 1){
			word[cnt] = '\0';
			break;
		}
		cnt++;
	}

	return cnt;
}


int main(int argc, char *argv[]) {
	
	FILE *fp;
	char Name[100];
	char word[100];
	
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
	
		
	/*파일 내 코드의 단어 하나하나 분석*/
	while(fget_word(fp, word) != 0)
	{
		//word processing
		count_word(word);
	}
	
	print_word();
	
	//fclose
	fclose(fp);

	
	/*분석 결과 출력*/
	
	return 0;
}
