#include<stdio.h>

void main(){
    int num, rem, rev;
    rev = 0;
    scanf("%d",&num);
    while(num!=0){
        rem = num%10;
        num = num/10;
        rev = (rev*10) + rem;
    }
    printf("%d",rev);
}