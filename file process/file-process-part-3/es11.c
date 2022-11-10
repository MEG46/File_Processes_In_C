#include <stdio.h>

int Compare(FILE *file,int num,int num1){
	int i,j;
	int count=1;
	int arr[num][num1];
	for(i=0;i<num;i++){
		for(j=0;j<num1;j++){
		    int c;
		    arr[i][j]=count;
		    fprintf(file,"%d\t",arr[i][j]);
		    count++;
	}
	fprintf(file,"\n");
	}
}
int main(){
	int num,num1;
	FILE *file=fopen("dnm3.txt","w");
	if(file==NULL){
		fprintf(stderr,"An unexpected error occured!\n");
	}
	printf("Please enter a number : ");
	scanf("%d",&num);
	fflush(stdin);
	printf("Please enter a number : ");
	scanf("%d",&num1);
	fflush(stdin);
	Compare(file,num,num1);
	fclose(file);
	return 0;
}