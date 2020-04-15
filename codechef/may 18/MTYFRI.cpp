#include<iostream>
#include<algorithm>

#define REP(i,n) for(int i =0; i< n; i++)

using namespace std;


int main(){

    int t; cin>>t;

    while (t--)
    {
        int n, k, l=0, r=0, motu=0, tomu=0, diff,flag =0;
        cin>>n>>k;

        int arr[n], odd[n], even[n];
        

        REP(i,n) {
            cin>>arr[i];
            if(i%2==0) {
                motu = motu+arr[i];
                even[r] = arr[i];
                r++;
            }
            else {
                tomu = tomu + arr[i];
                odd[l]= arr[i];
                l++;
            }
        }

        diff = motu - tomu;

        if(diff<0){
            cout<<"YES"<<endl;
            continue;
        }


        sort(odd, odd+ l);
        sort(even, even + r, greater<int>());

        int p;

        k<l? p =k: p = l;

        
        REP(i,p){

                tomu = tomu + even[i] - odd[i];
                motu = motu - even[i] + odd[i];

                if(tomu>motu){
                    flag =1;
                    break;
                }
        }
        
        if(flag) cout<<"YES"<<endl;
        else cout<<"NO"<<endl;



    }

    return 0;
}