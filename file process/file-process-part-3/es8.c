#include <stdio.h>
#include <stdlib.h>
void WordCount(FILE *file){
	char c;
	int i=2;
	int count=0;
	printf("Please enter a character : ");
	scanf("%c",&c);
	fseek(file,0,SEEK_END);
	int num=ftell(file);
	printf("\n\n------------------------------------------------------\n\n");
	printf("Character Number : %d",num);
	printf("\n\n------------------------------------------------------\n\n");
	fseek(file,-1,SEEK_END);
	rewind(file);
	int ch;
	for(i=0;i<num;i++){
		ch=fgetc(file);
		if(ch==c){
		   printf("\n\n------------------------------------------------------\n\n");
	       printf("The number exists as %d.character!",i+1);
	       printf("\n\n------------------------------------------------------\n\n");
			count++;
		}
	}
	printf("\n\n------------------------------------------------------\n\n");
	printf("Character Number : %d",count);
	printf("\n\n------------------------------------------------------\n\n");
}
int main(){
	FILE *file=fopen("dnm1.txt","r");
	if(file==NULL){
		fprintf(stderr,"An unexpected error!\n");
		exit(0);
	}
	WordCount(file);
	fclose(file);
	return 0;
}