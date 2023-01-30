#include <stdio.h>
// for strcpy function
#include <string.h>
// for atoi function
#include <stdlib.h>
// line number for total.text
#define MaxLines 90
// string length
#define MaxLength 30
// student number
#define Num_Student 15

struct student
{
    int rollNum;
    char studName[MaxLines][MaxLength];
    int MarksALL;
};

int main()
{
    int i, j, line = 0;
    char arrTotal[MaxLines][MaxLength];
    char roll[MaxLines][MaxLength];
    char marks[MaxLines][MaxLength];
    // input from file
    FILE *fin, *fmerit;
    fin = fopen("total.text", "r");
    if (fin == NULL)
    {
        printf("Error Opening File\n");
    }
    while (!feof(fin) && !ferror(fin))
    {
        if (fgets(arrTotal[line], MaxLines, fin))
        {
            line++;
        }
    }

    fclose(fin);

    // structure input
    int na = 1;
    int ro = 3, r1;
    int to = 5, t1;
    struct student input[Num_Student];
    for (i = 0; i < Num_Student; i++)
    {

        strcpy(input[i].studName, arrTotal[na]);
        na = na + 6;

        strcpy(roll[i], arrTotal[ro]);
        r1 = atoi(roll[i]);
        input[i].rollNum = r1;
        ro = ro + 6;

        strcpy(marks[i], arrTotal[to]);
        t1 = atoi(marks[i]);
        input[i].MarksALL = t1;
        to = to + 6;
    }

    // display structure without sorting
    printf("-----------------------------------------------------------\n");
    printf("-----------------------------------------------------------\n");
    printf("Display List Without Sorting\n");
    printf("-----------------------------------------------------------\n");
    printf("-----------------------------------------------------------\n");
    for (i = 0; i < Num_Student; i++)
    {
        printf("\nName : %sRoll : %d\nMarks : %d\n", input[i].studName, input[i].rollNum, input[i].MarksALL);
    }
    printf("-----------------------------------------------------------\n");

    // sorting structure using bubble sort mechanism
    struct student temp;
    for (i = 0; i < Num_Student - 1; i++)
    {
        for (j = 0; j < (Num_Student - 1 - i); j++)
        {
            if (input[j].MarksALL < input[j + 1].MarksALL)
            {
                temp = input[j];
                input[j] = input[j + 1];
                input[j + 1] = temp;
            }
        }
    }

    // display before sorting
    // display meritlist
    printf("-----------------------------------------------------------\n");
    printf("\t\t\tMerit List\n");
    printf("-----------------------------------------------------------\n");
    printf("-----------------------------------------------------------\n");
    for (i = 0; i < Num_Student; i++)
    {
        printf("\nName : %sRoll : %d\nMarks : %d\nMerit : %d\n", input[i].studName, input[i].rollNum, input[i].MarksALL, i + 1);
    }
    printf("-----------------------------------------------------------\n");
    printf("-----------------------------------------------------------\n");

    // output file save in merit.txt
    fmerit = fopen("merit.txt", "w");
    fprintf(fmerit, "------------------------------\nMerit List\n------------------------------\n");
    for (int k = 0; k < Num_Student; k++)
    {
        fprintf(fmerit, "Name  : %s", input[k].studName);
        fprintf(fmerit, "Roll  : %d\n", input[k].rollNum);
        fprintf(fmerit, "Marks : %d\n", input[k].MarksALL);
        fprintf(fmerit, "Merit Position : %d\n\n", k + 1);
    }
    fclose(fmerit);

    return 0;
    // end the program
}
