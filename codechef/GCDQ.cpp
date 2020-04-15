#include <iostream>

using namespace std;

int GCD(int a , int b){
    if(a==0) return b;

    return GCD(b%a, a);
}



int main(){
    int t,l, r;

    cin>>t;
    while(t--){
        int n,q;
        cin>>n>>q;
        int ar[n];

        for(int i=0;i<n;i++){
            cin>>ar[i];
        }

        while(q--){
            cin>>l>>r;l--;r--;

            int result=0;

            for(int i =0; i<n;i++){
                if(i>=l && i<=r) continue;

                result = GCD(result, ar[i]);
            }
            cout<<result;
        }
    }



    return 0;
}