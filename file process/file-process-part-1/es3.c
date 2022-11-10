#include <stdio.h>
#include <stdlib.h>
void Rev(FILE *file, FILE *file1){
	int i;
	fseek(file,0,SEEK_END);
	int chnum=ftell(file);
	printf("Info.txt character number : %d\n",chnum);
	fseek(file,-1,SEEK_END);
	for(i=2;i<chnum+1;i++){
		int ch=fgetc(file);
		printf("%c ",ch);
		fputc(ch,file1);
		fseek(file,-(i),SEEK_END);
	}
	printf("The process has been completed!\n");
}
void Rev1(int num,FILE *file, FILE *file1){
	int i;
	
	fseek(file,0,SEEK_END);
	int limit=ftell(file);
	int chnum=num;
	if(limit>=chnum){
	printf("Desired character number to be revresed: %d\n",chnum);
	fseek(file,-1,SEEK_END);
	for(i=2;i<chnum+1;i++){
		int ch=fgetc(file);
		printf("%c ",ch);
		fputc(ch,file1);
		fseek(file,-(i),SEEK_END);
	}
	printf("\nThe process has been completed!\n");
}else{
	printf("An unexpected error occured!\n");
}
}
void Rev2(int num,FILE *file, FILE *file1){
	int i;
	
	fseek(file,0,SEEK_END);
	int limit=ftell(file);
	int chnum=num;
	if(limit>=chnum){
	rewind(file);
	char *arr;
	arr=(char *)malloc(sizeof(char)*num);
	printf("Desired character number to be revresed: %d\n",chnum);
	for(i=0;i<chnum;i++){
		arr[i]=fgetc(file);
		printf("%c ",arr[i]);
	}
	for(i=chnum-1;0<=i;i--){
		
		fputc(arr[i],file1);
	}
	printf("\nThe process has been completed!\n");
}else{
	printf("An unexpected error occured!\n");
}
}
int main(){
	FILE *file=fopen("Info.txt","r");
	FILE *file1=fopen("Info1.txt","w");
	if(file==EOF||file==EOF){
		fprintf(stderr,"An unexpected error occured!\n");
		exit(0);
	}
	//Rev(file,file1);
	int num;
	fseek(file,0,SEEK_END);
	int limit=ftell(file);
	printf("\n\n-------------------------------------------------------\n\n");
	printf("Limit : %d\n",limit);
	printf("\n\n-------------------------------------------------------\n\n");
	printf("Please enter the number to be reversed : ");
	scanf("%d",&num);
	fflush(stdin);
	//Rev1(num,file,file1);
	Rev2(num,file,file1);
	fclose(file);
	fclose(file1);
	return 0;
}