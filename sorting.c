#include<stdio.h>
#include<string.h>
#define MaxLines 90
#define MaxLength 30
#define Num_Student 15

int main(){
    int i,line=0;
    char arrTotal[MaxLines][MaxLength];
    char name[MaxLines][MaxLength];
    FILE *fin;
    fin=fopen("total.text","r");
    if(fin==NULL){
        printf("Error Opening File\n");
    }
    while (!feof(fin)&&!ferror(fin))
    {
        if (fgets(arrTotal[line],MaxLines,fin) != NULL)
        {
            line++;
        }
    }
    
    fclose(fin);

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

    
    return 0;
}
