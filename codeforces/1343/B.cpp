#include<iostream>
#include<vector>
#include<algorithm>

#define REP(i,n) for (int i = 1; i <= n; i++)

#define mod 1000000007
#define pb push_back
#define ff first
#define ss second
#define ii pair<int,int>
#define vi vector<int>
#define vii vector<ii>
#define lli long long int
#define INF 1000000000


using namespace std;

int ar[200005];

int main(){
    int t,n; cin>>t;
    

    while(t--){
        int start = 2; int end= 199998;
        cin>>n;
        if(n%4==2) cout<<"NO"<<endl;

        else{
            cout<<"YES"<<endl;
            for(int i = 1; i<=n/2;i = i+2){
                ar[i] = start;
                ar[i+1] = end;
                ar[i+(n/2)] = start +1;
                ar[i+(n/2)+1] = end - 1;

                start += 2;
                end -=2;
            }

            for(int i = 1; i<=n; i++){
                cout<<ar[i]<<" ";
            }
            cout<<endl;
        }
    }



    return 0;
}