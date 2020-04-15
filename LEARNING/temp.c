#include <stdio.h>

int fib(int a,int b,int n){
    if(n==0){
        return 0;
    }
    int c;
    c = a+b;
    printf("%d ",c);
    fib(b, c, n-1);
    return 0;
}
int main(){
    int n;
    scanf("%d",&n);
    int first =0, sec =1;
    printf("%d %d ",first, sec);
    fib(first, sec , n-2);
    
}