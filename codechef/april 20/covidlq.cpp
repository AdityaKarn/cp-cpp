#include<iostream>

using namespace std;

int main(){
    int t; cin>>t; 
    int n;

    while(t--){
        cin>>n;
        int a[n];
        int prev=-7, curr=0;
        bool flag= true;

        for(int i =0; i<n; i++){
            
            
            cin>>a[i];
            if(a[i]==1){
                curr=i;


                if(curr-prev <6) {
                flag= false;
                break;
                }

                prev = curr;
            }
            
        }

        if(flag){ cout<<"YES"<<endl;}
        else if(!flag){ cout<<"NO"<<endl;}
    }

    return 0;
}