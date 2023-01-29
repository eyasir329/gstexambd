#include<stdio.h>
#define MAX_LINES 1000
#define lineNEED 90
#define MAX_LENG 30
#define STUDENT 30

int main(){
    int i,line=0;
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
    while (!feof(fin) && !ferror(fin))
    {
        if (fgets(numArr[line], MAX_LENG, fin) != NULL)
        {
            line++;
        }
    }
    fclose(fin);

    //printing total number and other info from file
    printf("\t\t----------------------------------------------------\n");
    printf("\t\t\tWe found data from file :\n");
    printf("\t\t----------------------------------------------------\n");
    for(i=0;i<line;i++){
        printf("%s",numArr[i]);
    }
    printf("----------------------------------------------------------------------------\n");
    printf("----------------------------------------------------------------------------\n");

    //input name from numARR to name
    for(i=0;i<STUDENT;i++){
        name[i]=numArr[i+1]
        break;
    }
    //checking
    for(i=0;i<STUDENT;i++){
        name[i]=numArr[i+1]
    }
    return 0;
}