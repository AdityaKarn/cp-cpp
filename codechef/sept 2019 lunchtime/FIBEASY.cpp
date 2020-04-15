#include <iostream>
#include <math.h>

using namespace std;

int fib[60];

void loga(){
    long long n;
    cin>> n;

    int i=1;
    while(i<=n){
        i*=2;
    }
    i/=2;
    cout<<fib[(i-1)%60]<<"\n";
}
int main(){
    
    int T;
    cin>>T;
    fib[0]=0;
    fib[1]=1;
    for(int i =0; i<60; i++){
        fib[i+2]=(fib[i+1]+fib[i])%10 ;
    }

    while(T--){
        loga();
    }

    return 0;
}