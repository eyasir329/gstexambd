#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define MaxLines 90
#define MaxLength 30
#define Num_Student 15

struct student{
    int rollNum;
    char studName[MaxLines][MaxLength];
    int MarksALL;
};

int main(){
    int i,j,line=0;
    char arrTotal[MaxLines][MaxLength];
    char roll[MaxLines][MaxLength];
    char marks[MaxLines][MaxLength];

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
    int ro=3,r1;
    int to=5,t1;
    struct student input[Num_Student];
    for(i=0;i<Num_Student;i++){

        strcpy(input[i].studName,arrTotal[na]);
        na=na+6;

        strcpy(roll[i],arrTotal[ro]);
        r1=atoi(roll[i]);
        input[i].rollNum=r1;
        ro=ro+6;

        strcpy(marks[i],arrTotal[to]);
        t1=atoi(marks[i]);
        input[i].MarksALL=t1;
        to=to+6;
    }

    //display struct
    printf("-----------------------------------------------------------\n");
    printf("-----------------------------------------------------------\n");
    printf("Display List Without Sorting\n");
    printf("-----------------------------------------------------------\n");
    printf("-----------------------------------------------------------\n");
    for(i=0;i<Num_Student;i++){
        printf("\nName : %sRoll : %d\nMarks : %d\n",input[i].studName,input[i].rollNum,input[i].MarksALL);
    }
    printf("-----------------------------------------------------------\n");


    //sorting structure
    struct student temp;
    for(i=0;i<Num_Student-1;i++){
        for(j=0;j<(Num_Student-1-i);j++){
            if(input[j].MarksALL<input[j+1].MarksALL){
                temp=input[j];
                input[j]=input[j+1];
                input[j+1]=temp;
            }
        }
    }

    //display after sorting
    //display struct
    printf("-----------------------------------------------------------\n");
    printf("\t\t\tMerit List\n");
    printf("-----------------------------------------------------------\n");
    printf("-----------------------------------------------------------\n");
    for(i=0;i<Num_Student;i++){
        printf("\nName : %sRoll : %d\nMarks : %d\n",input[i].studName,input[i].rollNum,input[i].MarksALL);
    }
    printf("-----------------------------------------------------------\n");
    printf("-----------------------------------------------------------\n");

    return 0;
}
