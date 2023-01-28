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
    printf("Physics[1-25],Chemistry[26-50],Higher Math[51-75],Biology[76-100],English[101-125]\n");
    printf("\t\tSelect Phusics, Chemistry And Two More Subjects\n");
    printf("\t\t\t\tTotal 100 Marks Exam\n");
    printf("\n");
    printf("\t\t----------------------------------------------------\n");
    for (k = 4; k < Max_lines; k++)
    {
        printf("\t\t\tQuestion %d:- Answer is : %s\t\t\t\n", k - 3, ans[k]);
    }
    printf("\t\t----------------------------------------------------\n");

    // input student marks
    // functionality for multiple student
    fpt = fopen("stud9.txt", "r");

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
    // double marks checking
    printf("\t\tSelected Subject :\n");
    printf("\t\t%s", ch[2]);
    printf("\t\t%s", ch[3]);
    int dcut = 0, count = 0;
    for (i = 4; i < line; i++)
    {
        if (strlen(ch[i]) > 2)
        {
            dcut++;
        }
        // phy,chemistry
        if (i >= 4 && i < 54)
        {
            if (strcmp(ans[i], ch[i]) == 0)
            {
                count++;
            }
        }
        // math
        if (strlen(ch[2]) == 12)
        {
            if (i >= 54 && i < 79)
            {
                if (strcmp(ans[i], ch[i]) == 0)
                {
                    count++;
                }
            }
        }
        // bio
        if ((strlen(ch[2]) == 8) || (strlen(ch[3]) == 8))
        {
            if (i >= 79 && i < 104)
            {
                if (strcmp(ans[i], ch[i]) == 0)
                {
                    count++;
                }
            }
        }
        // eng
        if ((strlen(ch[2]) == 9) || (strlen(ch[3]) == 9))
        {
            if (i >= 104 && i < 129)
            {
                if (strcmp(ans[i], ch[i]) == 0)
                {
                    count++;
                }
            }
        }
    }
    // comparing marks and answer
    printf("\t\t\tTotal Number : %d\n", count);
    printf("\t\t----------------------------------------------------\n");
    printf("\t\t----------------------------------------------------\n");

    // saving total marks and other info to a file
    fout = fopen("total.text", "a");
    fprintf(fout, "Student Name : \n%s", ch[0]);
    fprintf(fout, "Roll Number : \n%s", ch[1]);
    fprintf(fout, "Optional Subjects\n");
    fprintf(fout, "%s", ch[2]);
    fprintf(fout, "%s", ch[3]);
    fprintf(fout, "Obtained Marks : \n%d\n", count);

    fclose(fout);
    return 0;
}