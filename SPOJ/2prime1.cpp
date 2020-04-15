#include<iostream>
#include<cstring>
#include<stdio.h>
#include<math.h>
using namespace std;

bool isprime(long int a){
    if(a%2==0){
        return false;
    }
    int upperlimit = sqrt(a)+1;
    for(int i=3;i<= upperlimit;i+=2){
        if(a%i==0){
            return false;
        }
    }
    
    return true;
}
int main(){
    int testCases;
    scanf("%d",&testCases);
    long int smallNo, largeNo;

    for(int k=0;k<testCases;k++){
        
        scanf("%ld %ld",&smallNo,&largeNo);
        printf("\n");
        
        for(int j = smallNo; j<= largeNo; j++){
            if(isprime(j)){
                printf("%ld\n",j);
            }
        }
}

    return 0;
}