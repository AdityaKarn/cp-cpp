#include<iostream>

using namespace std;

int main(){
    int n, a, b, count=0;
    long int m;
    cin>>n>>m;

    long int seg[m];

    for(int i = 0; i<n; i++){
        cin>>a>>b;

        for(int j=a; j<=b;j++){
            seg[j]=1;
        }

    }

    for(int i = 1; i<=m; i++){
        if(seg[i]!=1){
            seg[i]=0;
            count++;
        }
    }

    cout<<count<<"\n";

    for(int i = 1; i<=m; i++){
        if(seg[i]==0){
            cout<<i<<" ";
        }
    }
    return 0;
}