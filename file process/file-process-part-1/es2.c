#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
void ToUpper(FILE *file, FILE *file1){
		int ch,ch2;
		while(1){
			if(ch2==EOF){
			break;
		}
			ch2=fgetc(file);
			fputc(toupper(ch2),file1);
		
	}
}
int main(){
	FILE *file=fopen("Info.txt","r");
	FILE *file1=fopen("Info1.txt","w");
	if(file==NULL || file1==NULL){
		printf("The files haven't'been opened successfully!\n");
		exit(0);
	}else{
		printf("The file have been opened successfully!\n");
	}
	ToUpper(file,file1);
	fclose(file);
	fclose(file1);
	return 0;
}