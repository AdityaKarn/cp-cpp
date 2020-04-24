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


int main(){
    int t,n;
    cin>>t;
    
    while(t--){
        int n; cin>>n;
        lli sum = 3; lli powTwo = 2;
        
        
        while(true){
            if(n%sum== 0) break;
            
            else{
                powTwo *=2;
                sum += powTwo;
            }

        }

        cout<<n/sum<<endl;
    }


    return 0;
}