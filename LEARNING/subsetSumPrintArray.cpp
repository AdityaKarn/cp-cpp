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
    int arr[100]; 
    int n,m;
    cin>>n>>m;

    for(int i=1; i<=n; i++){
        cin>>arr[i];
    }

    int dp[m+1]= {0};
    dp[0] = 1;

    for(int i =1; i<m; i++){
        dp[i] =0;
    }

    for(int i=1;i<=n; i++){
        int curr = arr[i];
        for(int j=m; j>= curr; j--){
            if(dp[j] || dp[j-curr]==0){
                continue;
            }
            else
            {
                dp[j] = curr;
            }
            

        }
    }

    if(dp[m]==0) cout<<-1;
    else{
        int curr = m;
        while(curr>0){
            cout<<dp[curr]<<" ";
            curr -= dp[curr];
        }
    }


    return 0;
}