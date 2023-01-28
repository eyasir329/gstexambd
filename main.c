#include<stdio.h>
#include<string.h>
#define Max_lines 130
#define Max_len 30

//input ans and student mark
int main(){
    int k,line=0,len=0,dcut=0,qnum=125;
    char ch[Max_lines][Max_len];
    char ans[qnum];

    FILE *fans,*fpt;

    //input answersheet
    fans=fopen("ans.text","r");
    if(fans==NULL){
        printf("AnswerSheet is not found\n");
    }else{
        for(k=0;k<qnum;k++){
            fscanf(fans,"%s",&ans[k]);
        }
    }
    fclose(fans);
    //answer sheet print
    printf("\t\t----------------------------------------------------\n");
    printf("\t\t-----------------------SOLUTION---------------------\n");
    printf("\t\t----------------------------------------------------\n");
    for(k=0;k<qnum;k++){
        printf("\t\t\tQuestion %d:- Answer is : %c\t\t\t\n",k+1,ans[k]);
    }
    printf("\t\t----------------------------------------------------\n");
    printf("\t\t----------------------------------------------------\n");

    //input student marks
    char stud1[4],stud2[4],stud3[4],stud4[4],stud5[4],stud6[4],stud7[4],stud8[4],stud9[4],stud9[4];
    fpt=fopen("stud2.txt","r");

    if(fpt==NULL){
        printf("Student data file is not found\n");
        return 1;
    }
    while(!feof(fpt)&&!ferror(fpt)){
        if(fgets(ch[line],Max_len,fpt)!=NULL){
            line++;
        }
    }
    fclose(fpt);

    //double mark counting
    for(k=0;k<line;k++){
        len= strlen(ch[k]);
        if(len>2){
            dcut++;
        }
    }
    printf("\ndouble ans %d\n",dcut);
    return 0;
}