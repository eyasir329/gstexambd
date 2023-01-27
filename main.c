#include<stdio.h>



char answer(int num);
int main(){
    printf("hello\n");
    int qnum=125;
    answer(qnum);
}



//answer sheet for 125 question
char answer(int num){
    char ans[]="ACDCBCCACBCBDBCCBCCDCBBBACCDACBCAAACBBBCDBBDBBBCBBACBCBBACCDBCDACAACCBBCDDBCCBAABBDDBCBABBDBCCCAABCBBBACBCCCCCAAABABAABCCCABD";
    int i;
    for(i=0;i<num;i++){
        printf("%d is %c\n",i+1,ans[i]);
    }
}