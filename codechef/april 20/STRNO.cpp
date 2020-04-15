#include<iostream>

using namespace std;

int primeDivisor(long long int n){
    int res=0;

    if(n%2==0){
        while(n%2==0){
            res++;
            n = n/2;
        }
    }


    for(long long int i=3; i*i<n; i++){
        if(n%i==0){
            while(n%i==0) {
                res++;
                n = n/i;
            }
        }
    }
    if(n>1) res++;
    
    return res;
}


int main(){
    int t;  cin>>t;

    while(t--){
        int x,k;
        cin>>x>>k;

        int cur = primeDivisor(x);

        if(cur>=k) cout<<1<<endl;
        else cout<<0<<endl;


    }

    return 0;
}