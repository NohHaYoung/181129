#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	
	FILE *fp;
	char Name[100];
	
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
	
	//fclose
	fclose(fp);
	
	/*���� �� �ڵ��� �ܾ� �ϳ��ϳ� �м�*/
	
	/*�м� ��� ���*/
	
	return 0;
}
