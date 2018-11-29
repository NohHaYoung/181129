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
	return 1; //���� ����
	
	return 0; // ���ǹ��� ���� 
}

int fget_word(FILE* fp, char* word){
	
	char c;
	int cnt;
	
	//1. ���ǹ��� ���� �ǳʶٱ�(���ǹ��� ���ڰ� ���� ������ �Էµ� ���� ���� �ݺ�)
	while((c=fgetc(fp)) != EOF){
		if(is_whitespace(c) == 0){
			break;
		}
	}
	//2. ���� ������ �� ���� 0 ��ȯ
	if(c == EOF){
		return 0;
	}
	
	//3. ���ǹ��� ���� ����
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
	
	/*�м� ��� ���� ����*/
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
	
		
	/*���� �� �ڵ��� �ܾ� �ϳ��ϳ� �м�*/
	while(fget_word(fp, word) != 0)
	{
		//word processing
		count_word(word);
	}
	
	print_word();
	
	//fclose
	fclose(fp);

	
	/*�м� ��� ���*/
	
	return 0;
}
