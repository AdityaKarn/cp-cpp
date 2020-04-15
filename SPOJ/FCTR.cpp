#include<iostream>

#define REP(i,n) for(int i =0; i<n; i++)

using namespace std;

int PowTen(int x){
    int temp = x;
    int res=0;
    while(temp){
        res = res + (temp/5);
        temp = temp/5;

    }
    return res;
}

int main(){

    int t; cin>>t;
    int a;
    while(t--){
        cin>>a;

        cout<<PowTen(a)<<endl;
    }

    return 0;
}