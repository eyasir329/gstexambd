#include <stdio.h>
#include <string.h>
#define Max_lines 129
#define Max_len 30

// input ans and student mark
int main()
{
    int i = 0, k, line = 0, len = 0;
    int num_stud = 10;
    char ch[Max_lines][Max_len];
    char ans[Max_lines][Max_len];
    char TOTAL[50];

    FILE *fans, *fpt, *fout;

    // input answersheet
    fans = fopen("ans.text", "r");
    if (fans == NULL)
    {
        printf("AnswerSheet is not found\n");
        return 1;
    }
    while (!feof(fans) && !ferror(fans))
    {
        if (fgets(ans[i], Max_len, fans) != NULL)
        {
            i++;
        }
    }
    fclose(fans);
    // answer sheet print
    printf("\t\t----------------------------------------------------\n");
    printf("\t\t-----------------------SOLUTION---------------------\n");
    printf("\t\t----------------------------------------------------\n");
    for (k = 0; k < Max_lines; k++)
    {
        printf("\t\t\tQuestion %d:- Answer is : %s\t\t\t\n", k + 1, ans[k]);
    }
    printf("\t\t----------------------------------------------------\n");

    // input student marks
    // functionality for multiple student
    fpt = fopen("stud1.txt", "r");

    if (fpt == NULL)
    {
        printf("Student data file is not found\n");
        return 1;
    }
    while (!feof(fpt) && !ferror(fpt))
    {
        if (fgets(ch[line], Max_len, fpt) != NULL)
        {
            line++;
        }
    }
    fclose(fpt);
    // student marks and answer
    printf("\t\t--------Comparing Answer And Marking Questions-------\n");
    printf("\t\t----------------------------------------------------\n");

    for (k = 4; k < line; k++)
    {
        printf("\t\t\t%d Answer is %s\n\t\t\t\t...Marking > %s", k + 1, ans[k], ch[k]);
        printf("\n");
    }
    printf("\t\t----------------------------------------------------\n");
    printf("\t\t----------------------------------------------------\n");

    // double marks checking
    // printf("ans %s ch %s",ans[1],ch[1]);
    int cut = 0, dcut = 0, count = 0;
    for (i = 4; i < line; i++)
    {
        if (strlen(ch[i]) > 2)
        {
            dcut++;
        }
    }
    if (strlen(ch[128]) > 1)
    {
        dcut++;
    }
    printf("\t\t\tTwo or more answer : %d\n", dcut);
    // physics 0-24;
    // chemistry 25-49;
    // Higher Math 50-74;
    // Biology 75-99;
    // English 99-124;

    // comparing marks and answer
    for (i = 4; i < line; i++)
    {
        if (strcmp(ans[i], ch[i]) == 0)
        {
            count++;
        }
        else
        {
            cut++;
        }
    }
    printf("\t\t\tTotal Number : %d\n", count);
    printf("\t\t\tNot Claimed Number : %d\n", cut);
    printf("\t\t----------------------------------------------------\n");
    printf("\t\t----------------------------------------------------\n");
    printf("%s",ch[0]);
    // saving total marks and other info to a file
    fout = fopen("total.text", "a");
    fprintf(fout, "Total Marks is %d\n", count);

    fclose(fout);

    return 0;
}

