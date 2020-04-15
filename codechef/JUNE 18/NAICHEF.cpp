#include<iostream>
#include<iomanip>

using namespace std;

int main(){

    int t; cin>>t;

    while (t--)
    {
        int n, a, b, curr, diff=0;
        double nA=0, nB=0;

        cin>>n>>a>>b;

        for(int i =1; i<=n; i++){
            cin>>curr;
            if(curr==a) nA++;
            if(curr==b) nB++;
        }

        double res=0; 

        res= (double)(nA*nB)/(n*n);

        cout<<res<<endl;

    }

    return 0;
}