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

    for(int i=1; i<=n;i++){
        cin>>arr[i];
    }

    bool dp[n+1][m+1];

    dp[0][0] = 1;

    for(int i=1; i<=m ; i++){
        dp[0][i]=0;
    }

    for(int i = 1; i<=n; i++){
        for(int j=0; j<=m; j++){
            if(j<arr[i]){
                dp[i][j] = dp[i-1][j];
            }

            else{
                int need = j-arr[i];
                if(dp[i-1][j]==1 || dp[i-1][need]==1){
                    dp[i][j]=1;
                }
                else{
                    dp[i][j] =0;
                }
            }
        }
    }

    for(int i = 0; i<=n; i++){
        for(int j=0; j<m; j++){
            cout<<dp[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}