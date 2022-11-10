#include <stdio.h>
int main(){
	
	FILE *file=fopen("try.txt","r");
	FILE *file2=fopen("try1.txt","w");
	if(file!=NULL){
		printf("The file has been opened successfully!\n");
	}else{
		printf("The file hasn't been opened successfully! An error is occured\n");
	}
	if(file2!=NULL){
		printf("The file to be written has been opened successfully!\n");
	}else{
		printf("The file to be written hasn't been opened successfully! An error is occured\n");
	}
	int ch;
	printf("\n\n-----------------------------------------------\n\n");
	printf("try.txt :");
	printf("\n\n-----------------------------------------------\n\n");
	do{
	    ch=fgetc(file);
	    fputc(ch,file2);
	}while(ch!=EOF);
	printf("\n\n-----------------------------------------------\n\n");
	printf("try1.txt :");
	printf("\n\n-----------------------------------------------\n\n");
	do{
	    ch=fgetc(file);
	    fputc(ch,file2);
	}while(ch!=EOF);
	printf("\n\n-----------------------------------------------\n\n");
	int IsClosed=fclose(file);
	int IsClosed1=fclose(file2);
	if(IsClosed==0){
		printf("The file has been closed successfully!\n");
	}else{
		printf("The file hasn't been closed successfully! An error is occured\n");
	}
	if(IsClosed1==0){
		printf("The file to be written has been closed successfully!\n");
	}else{
		printf("The file to be written hasn't been closed successfully! An error is occured\n");
	}
	return 0;
}
