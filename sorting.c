#include<stdio.h>
#include<string.h>
#define MAX_LINES 1000
#define lineNEED 90
#define MAX_LENG 30
#define STUDENT 30

int main(){
    int i,line=1;
    char numArr[MAX_LINES][MAX_LENG];
    char name[500];
    int roll[100],total[100];
    FILE *fin, *fot;
    // input total number sheet -without modifying/unsorted
    fin = fopen("total.text", "r");
    if (fin == NULL)
    {
        printf("\t\t----------------------------------------------------\n\t\t\tTotal Number File Not Found\n\t\t----------------------------------------------------\n");
        return 1;
    }
    while (!feof(fin))
    {
        fscanf(fin,"%s",&name[line-0]);
        line=line+6;
    }
    fclose(fin);


/*
    //printing total number and other info from file
    printf("\t\t----------------------------------------------------\n");
    printf("\t\t\tWe found data from file :\n");
    printf("\t\t----------------------------------------------------\n");
    for(i=0;i<line;i++){
        printf("%s",numArr[i]);
    }
    printf("----------------------------------------------------------------------------\n");
    printf("----------------------------------------------------------------------------\n");

    //all name print
    printf("--------name--------\n");
    i=1;
    while(i<line){
        printf("%s",numArr[i]);
        i=i+6;
    }
    //roll
    printf("--------roll--------\n");
    i=3;
    while(i<line){
        printf("%s",numArr[i]);
        i=i+6;
    }
    //total
    printf("--------total--------\n");
    i=5;
    while(i<line){
        printf("%s",numArr[i]);
        i=i+6;
    }
int k=(int)numArr[3];
printf("%d",k);
    //input name from numARR to name
    


*/









    return 0;
}