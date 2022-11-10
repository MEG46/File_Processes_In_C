#include <stdio.h>
int Compare(FILE *file, FILE *file1){
	int chnum,chnum1;
	fseek(file,0,SEEK_END);
	fseek(file1,0,SEEK_END);
	chnum=ftell(file);
	chnum1=ftell(file1);
	printf("Info.txt Character Number : %d\n",chnum);
	printf("Info1.txt Character Number : %d\n",chnum1);
	if(chnum>chnum1){
		printf("Info.txt Character Number is bigger than Info1.txt Character Number!\n");
		return 0;
	}else if(chnum<chnum1){
		printf("Info1.txt Character Number is bigger than Info.txt Character Number!\n");
		return 0;
	}else{
		rewind(file);
		rewind(file1);
		int ch,ch2;
		while(1){
			ch=fgetc(file);
			ch2=fgetc(file1);
			printf("Info.txt's character : %c\n",ch);
			printf("Info1.txt's character : %c\n",ch2);
		if(ch==EOF && ch2==EOF){
			break;
		}
		if(ch!=ch2){
			return 0;
		}
	}
}
	return 1;
}
int main(){
	FILE *file=fopen("Info.txt","r");
	FILE *file1=fopen("Info1.txt","r");
	if(file!=NULL && file1!=NULL){
		printf("The files have been opened successfully!\n");
		int result=Compare(file,file1);
		if(result==1){
			printf("The files are same!\n");
		}else if(result==0){
			printf("The files are not same!\n");
		}
	}else{
		printf("The file haven't been opened successfully!\n");
	}
	return 0;
}