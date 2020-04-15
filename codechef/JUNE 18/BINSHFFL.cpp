#include<iostream>

using namespace std;

int setPieces(int a){
    int res=0;
    while (a)
    {
        if(a%2==1) {
            res++;
        }
        a /= 2;
    }
    return res;
}

int main(){
    int t; cin>>t;

    while(t--){
        long long int a, b;
        int ans;
        cin>>a>>b;
        
        if(a==b){
            ans=-1;
        }
        else if(b==0){
            ans=-1;
        }

        else if(b==1){
            if(a==0){
                ans=1;
            }
            else
            {
                ans=-1;
            }
        }
        else{
            int OA = setPieces(a);
            int OB = setPieces(b-1);

            if(OA>OB) ans = 2;
            else{
                ans=OB-OA+1;
            }
        }

        cout<<ans<<endl;
    }
    return 0;
}