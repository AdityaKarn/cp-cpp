#include<iostream>
#include<algorithm>

#define REP(i,n) for(int i =0; i< n; i++)
#define N 1000000007
#define size 1000100

using namespace std;

int main(){

    int t; cin>>t;        int ans[size];

    while(t--){
        int m, n, sumM=0, sumN=0, am;

        cin>>m>>n;

        for(int i =0; i< n; i++){
            cin>>am;
            sumM = (sumM + am)%N;
        }

        sumM = (sumM*m)%N;

        for(int i =0; i< n; i++){
            cin>>am;
            sumN = (sumN + am)%N;
        }

        sumN = (sumN*m)%N;




        ans[1]= sumM; ans[2] = sumN;

        for(int i=3; i<=n; i++){
            ans[i]= (ans[i-1]+ans[i-2])%N;
        }
        cout<<ans[n]<<endl;
    }


    return 0;
}