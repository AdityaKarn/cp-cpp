#include<iostream>
#include<vector>
#include<math.h>

#define REP(i,n) for(int i =0; i< n; i++)

using namespace std;

int XOR(int a, int b){
    return (a|b) & (~a|~b);
}

int main(){

    int t; cin>>t;

    while (t--)
    {
        int n; cin>>n;
        int arr[n];

        REP(i,n) cin>>arr[i];
        
        int res = 0;

        REP(i,n) res = XOR(res, 2*arr[i]);

        cout<<res<<endl;
    }

    return 0;
}