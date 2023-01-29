#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define MaxLines 90
#define MaxLength 30
#define Num_Student 15

struct student{
    char roll[MaxLines][MaxLength];
    char name[MaxLines][MaxLength];
    char marks[MaxLines][MaxLength];
};

int main(){
    int i,line=0
    ;
    char arrTotal[MaxLines][MaxLength];
    FILE *fin;
    fin=fopen("total.text","r");
    if(fin==NULL){
        printf("Error Opening File\n");
    }
    while (!feof(fin)&&!ferror(fin))
    {
        if (fgets(arrTotal[line],MaxLines,fin))
        {
            line++;
        }
    }
    
    fclose(fin);

    //structure
    int na=1;
    int ro=3;
    int to=5;
    struct student input[Num_Student];
    for(i=0;i<Num_Student;i++){

        strcpy(input[i].name,arrTotal[na]);
        na=na+6;

        strcpy(input[i].roll,arrTotal[ro]);
        ro=ro+6;

        strcpy(input[i].marks,arrTotal[to]);
        to=to+6;
    }

    //display struct
    printf("-----------------------------------------------------------\n");
    printf("-----------------------------------------------------------\n");
    printf("Display List Without Sorting\n");
    printf("-----------------------------------------------------------\n");
    for(i=0;i<Num_Student;i++){
        printf("Name : %sRoll : %sMarks : %s\n",input[i].name,input[i].roll,input[i].marks);
    }
    printf("-----------------------------------------------------------\n");


    //sorting structure


    











/*
    //name
    printf("Printing Name From File\n");
    int n=1;
    while (n<MaxLines)
    {
        printf("%s",arrTotal[n]);
        n=n+6;
    }
    


    //roll
    printf("Printing Roll From File\n");
    int r=3;
    while (r<MaxLines)
    {
        printf("%s",arrTotal[r]);
        r=r+6;
    }
    
    //total
    printf("Printing Total Number From File\n");
    int t=5;
    while (t<MaxLines)
    {
        printf("%s",arrTotal[t]);
        t=t+6;
    }

    */
    return 0;
}
