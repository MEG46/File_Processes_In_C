#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
void WordCount(FILE *file,FILE *file1){
	char c;
	int i=2;
	int count=0;
	fseek(file,0,SEEK_END);
	int num=ftell(file);
	printf("\n\n------------------------------------------------------\n\n");
	printf("Character Number : %d",num);
	printf("\n\n------------------------------------------------------\n\n");
	fseek(file,-1,SEEK_END);
	rewind(file);
	int ch;
	while(1){
		if(ch==EOF){
			break;
		}
		ch=fgetc(file);
		fputc(ch,file1);
		if(ch==' '){
		   i=i+1;
		   fscanf(file,"%c",&ch);
		   ch=toupper(ch);
		   fprintf(file1,"%c",ch);
			count++;
		}
		
	}
	printf("\n\n------------------------------------------------------\n\n");
	printf("Character Number : %d",count);
	printf("\n\n------------------------------------------------------\n\n");
}
int main(){
	FILE *file=fopen("dnm1.txt","r");
	FILE *file1=fopen("dnm2.txt","w");
	if(file==NULL){
		fprintf(stderr,"An unexpected error!\n");
		exit(0);
	}
	WordCount(file,file1);
	fclose(file);
	fclose(file1);
	return 0;
}