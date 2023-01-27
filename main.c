#include<stdio.h>
char answer(char ans0[],int num);




int main(){
    int qnum=125;
    char ans[]="ACDCBCCACBCBDBCCBCCDCBBBACCDACBCAAACBBBCDBBDBBBCBBACBCBBACCDBCDACAACCBBCDDBCCBAABBDDBCBABBDBCCCAABCBBBACBCCCCCAAABABAABCCCABD";
    answer(ans,qnum);
}



//answer sheet for 125 question
char answer(char ans0[],int num){
    int i;
    for(i=0;i<num;i++){
        printf("%d is %c\n",i+1,ans0[i]);
    }
}