#include<iostream>

#define REP(i,n) 
using namespace std;




int main(){



        int n; cin>>n;
        int arr[n];

        for(int i=0; i<n; i++) cin>>arr[i];

        int tot = 1<<n; 

 
        for(int mask =0; mask<tot; mask++){
            for(int i =0; i<n; i++){
                int f= 1<<i;
                if((mask&f)!= 0){
                    cout<<arr[i]<<" ";
                }
            }
            cout<<endl;
        }

    return 0;
}