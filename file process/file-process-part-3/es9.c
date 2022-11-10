#include <stdio.h>
#include <stdlib.h>
int WordCount(FILE *file,char *str){
	int i=2;
	int count=0;
	char word[20];
	while(!feof(file)){
		fscanf(file,"%s",&word);
		count++;
		if(strcmp(word,str)==0){
	       return count;
		}
	}
	return -1;
}
int main(){
	FILE *file=fopen("dnm1.txt","r");
	char kelime[20];
	if(file==NULL){
		fprintf(stderr,"An unexpected error!\n");
		exit(0);
	}
	printf("Please enter a character : ");
    gets(kelime);
	int index=WordCount(file,kelime);
	if(index!=-1){
	  	printf("%s exists %d.word in the file!\n",kelime,index);
	}
	fclose(file);
	return 0;
}