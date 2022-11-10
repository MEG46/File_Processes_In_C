#include <stdio.h>
#include <stdlib.h>
typedef struct{
	char name[50];
    char surname[50];
    int qz1;
    int qz2;
    int mdtrm;
    int fnl;
    char note[2];
}Infos;
void Calc(FILE *file, FILE *file1){
	float result1=0;
	int count=0;
	while(!feof(file)){
		Infos stu;
		fscanf(file,"%s %s %d %d %d %d ",&stu.name,&stu.surname,&stu.qz1,&stu.qz2,&stu.mdtrm,&stu.fnl);
		float result=0.1*stu.qz1 + 0.1*stu.qz2 + 0.4*stu.mdtrm + 0.4*stu.fnl; 
		result1=result1+result;
		count++;
	}
	rewind(file);
	while(!feof(file)){
		Infos stu;
		fscanf(file,"%s %s %d %d %d %d ",&stu.name,&stu.surname,&stu.qz1,&stu.qz2,&stu.mdtrm,&stu.fnl);
		float result=0.1*stu.qz1 + 0.1*stu.qz2 + 0.4*stu.mdtrm + 0.4*stu.fnl; 
	if(result<=100 && result>90){
	   stu.note[0]='A';
	   stu.note[1]='A';
	}else if(result<=90 && result>85){
	   stu.note[0]='B';
	   stu.note[1]='A';
	}else if(result<=85 && result>75){
	   stu.note[0]='B';
	   stu.note[1]='B';
	}	else if(result<=75 && result>67){
	   stu.note[0]='C';
	   stu.note[1]='B';
	}	else if(result<=67 && result>60){
	   stu.note[0]='C';
	   stu.note[1]='C';
	}else if(result<=60 && result>55){
	   stu.note[0]='D';
	   stu.note[1]='C';
	}	else if(result<=55 && result>50){
	   stu.note[0]='D';
	   stu.note[1]='D';
	}	else if(result<=50 && result>45){
	   stu.note[0]='F';
	   stu.note[1]='D';
	}		else if(result<=45 && result>=0){
	   stu.note[0]='F';
	   stu.note[1]='F';
	}else{
	   printf("Invalid Process!\n");
	}			
	fprintf(file1,"Name: %s\nSurname: %s\n1st Quiz: %d\n2nd Quiz: %d\nMidterm: %d\nFinal: %d\nStduent Average : %.2f\nGeneral Average :%.2f\nMark : %s\n\n--------------------------------------------\n\n",stu.name,stu.surname,stu.qz1,stu.qz2,stu.mdtrm,stu.fnl,result,result1/count,stu.note);
	
	}
}

int main(){
	FILE *file=fopen("infostd.txt","r");
	FILE *file1=fopen("infostd1.txt","w");	
	if(file==NULL||file1==NULL){
		fprintf(stderr,"An unexpected error occured!\n");
		exit(0);
	}
	Calc(file,file1);
	fclose(file);
	fclose(file1);
	return 0;
}