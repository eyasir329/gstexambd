#include <stdio.h>
#include <string.h>
#define Max_lines 129
#define Max_len 30

int main()
{
    int i = 0, k, line = 0, len = 0;
    int num_stud = 10;
    char ch[Max_lines][Max_len];
    char ans[Max_lines][Max_len];

    FILE *fans, *fpt, *fout;

    // input answersheet from ans.text
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
    printf("\t\t\t\tTotal 100 Marks\n");
    printf("\n");
    printf("\t\t----------------------------------------------------\n");
    for (k = 4; k < Max_lines; k++)
    {
        printf("\t\t\tQuestion %d:- Answer is : %s\t\t\t\n", k - 3, ans[k]);
    }
    printf("\t\t----------------------------------------------------\n");

    // input student marks from stud*.txt
    // for multiple input change * to integer number from 1-15
    fpt = fopen("stud4.txt", "r");

    if (fpt == NULL)
    {
        printf("\t\t\tStudent data file is not found\n\t\t----------------------------------------------------\n");
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
    // marks checking
    // phy(4-28)
    // che(29-53)
    // math(54-78)
    // bio(79-103)
    // eng(104-128)
    int phy = 0, che = 0, math = 0, bio = 0, eng = 0;
    int dcut = 0, count = 0;
    for (i = 4; i < line; i++)
    {
        // if answer double or more then its not count
        if (strlen(ch[i]) > 2)
        {
            dcut++;
        }
        else
        {
            // physics number count
            if (i >= 4 && i < 29)
            {
                if (strcmp(ans[i], ch[i]) == 0)
                {
                    count++;
                    phy++;
                }
            }
            // chemistry number count
            if (i >= 29 && i < 54)
            {
                if (strcmp(ans[i], ch[i]) == 0)
                {
                    count++;
                    che++;
                }
            }
            // math number count
            if (strlen(ch[2]) == 12)
            {
                if (i >= 54 && i < 79)
                {
                    if (strcmp(ans[i], ch[i]) == 0)
                    {
                        count++;
                        math++;
                    }
                }
            }
            // biology number count
            if ((strlen(ch[2]) == 8) || (strlen(ch[3]) == 8))
            {
                if (i >= 79 && i < 104)
                {
                    if (strcmp(ans[i], ch[i]) == 0)
                    {
                        count++;
                        bio++;
                    }
                }
            }
            // english number count
            if ((strlen(ch[2]) == 17) || (strlen(ch[3]) == 17))
            {
                if (i >= 104 && i < 129)
                {
                    if (strcmp(ans[i], ch[i]) == 0)
                    {
                        count++;
                        eng++;
                    }
                }
            }
        }
    }
    // details and total marks printing
    printf("\t\t\t\tTotal Marks Counting\n");
    printf("\t\t----------------------------------------------------\n");
    // name print
    printf("\t\tName : %s", ch[0]);
    // roll print
    printf("\t\tRoll : %s", ch[1]);
    // marks for phy,chemistry
    printf("\t\tOptained Marks From Selected Subject :\n\t\t1.Physics - %d\n\t\t2.Chemistry - %d\n", phy, che);
    printf("\n");
    printf("\t\tOptained Marks From Optional Subjects Are:\n");
    printf("\t\t--------------------\n");
    // optional subjects marks print
    //  math
    if (strlen(ch[2]) == 12)
    {
        printf("\t\tHigher Math - %d\n", math);
    }
    // bio
    if ((strlen(ch[2]) == 8) || (strlen(ch[3]) == 8))
    {
        printf("\t\tBiology - %d\n", bio);
    }
    // eng
    if ((strlen(ch[2]) == 17) || (strlen(ch[3]) == 17))
    {
        printf("\t\tEnglish Language - %d\n", eng);
    }
    // total number print
    printf("\t\t----------------------------------------------------\n");
    printf("\t\t\t\tTotal Number : %d\n", count);
    printf("\t\t----------------------------------------------------\n");
    printf("\t\t----------------------------------------------------\n");

    // saving total marks and other info to a file
    fout = fopen("total.text", "a");
    fprintf(fout, "Student Name : \n%s", ch[0]);
    fprintf(fout, "Roll Number : \n%s", ch[1]);
    fprintf(fout, "Obtained Marks : \n%d\n", count);

    fclose(fout);
    return 0;
    // end
}
