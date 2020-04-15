#include<iostream>
#include<stdio.h>

using namespace std;

long long int maxy(long long int a, long long int b){
    if(a>b) return a;
    else return b;
}

int main(){
    int t;
    long long int arr[10001], dp[10001];    
    long long int n;
    cin>>t;
    
    for(int i =0; i<t; i++){

      cin>>n;

      for(int j = 0; j< n; j++){
          cin>>arr[j];
        }

        dp[0]=arr[0];
        dp[1] = maxy(dp[0], arr[1]);


        for(int j= 2; j< n; j++){
            dp[j] = maxy(dp[j-1], arr[j]+dp[j-2]);
        }

        printf("Case %d: %lld\n", i+1, dp[n-1]);
    }
    return 0;
    
}