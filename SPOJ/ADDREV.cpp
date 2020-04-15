#include<iostream>

#define REP(i,n) for(int i =0; i<n; i++)

using namespace std;

int rev(int x){
    int revr=0;
    int temp= x;
    while(temp){
        revr = revr*10;
        revr = revr + temp%10;
        temp = temp/10;
    }
    return revr;
}


int main(){
    int t;
    cin>>t;

    while(t--){
        int a,b;

        cin>>a>>b;

        int sum = rev(a) + rev(b);

        cout<<rev(sum)<<endl;
    }
    return 0;
}