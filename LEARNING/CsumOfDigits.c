#include<stdio.h>

void main(){

    int num, rem, sum;
    sum=0;
    scanf("%d",&num);
    while(num!=0){
        rem=num%10;
        num=num/10;
        sum=sum+rem;
    }  
    printf("%d",sum);

}