#include<stdio.h>
char answer(char ans0[],int num);
int total(char arr1[],char arr2[],int num);




int main(){
    int qnum=125;
    char ans[]="ACDCBCCACBCBDBCCBCCDCBBBACCDACBCAAACBBBCDBBDBBBCBBACBCBBACCDBCDACAACCBBCDDBCCBAABBDDBCBABBDBCCCAABCBBBACBCCCCCAAABABAABCCCABD";
    answer(ans,qnum);

    char marks[]={"BCACBCCACBCBDBCCBCCDCBBBACCDACBCAAACBBBCDBBDBBBCBBACBCBBACCDBCDACAACCBBCDDBCCBAABBDDBCBABBDBCCCAABCBBBACBCCCCCAAABABAABCCCABD"};

    total(ans,marks,qnum);
}



//answer sheet for 125 question
char answer(char ans0[],int num){
    int i;
    for(i=0;i<num;i++){
        printf("%d is %c\n",i+1,ans0[i]);
    }
}

//compare marks to answer and count total
int total(char arr1[],char arr2[],int num){
    int i,count=0,cut=0;
    float total0=0;
    for(i=0;i<num;i++){
        if(arr1[i]==arr2[i]){
            count++;
        }else{
            cut++;
        }
    }
    total0=(float)count-((0.25)*(float)cut);
    printf("total is %.2f\n",total0);
}