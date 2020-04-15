#include<iostream>
#include<vector>

#define REP(i,n) for(int i =0; i< n; i++)

using namespace std;

int ar[1001];

int gcd(int a , int b){
    if(a==0) return b;
    if(b==0) return a;

    else return gcd(b, a%b);
}

int main(){

    int t, n; 
    cin>>t;

    while(t--){
        int n;
        cin>>n;

        REP(i,n) cin>>ar[i];

        int res=0, count=0, g=0;

        for(int i =0; i< n; i++){
            res = gcd(res, ar[i]);
        }

        if(res==1) cout<<0<<endl;
        else cout<<-1<<endl;    
    }
        
        
    
    return 0;
}