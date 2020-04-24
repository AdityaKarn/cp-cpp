#include<iostream>
#include<vector>
#include<algorithm>
#include<cmath>

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
int n;
pair<int,int> arr[3001];

lli dp[3001][3001];

int getAns(int pos, int pre){
    if(pos>n) return 0;
    if(dp[pos][pre] != -1) return dp[pos][pre];
    // pin 
    int x;
    x = arr[pos].second + getAns(pos+1, pos);

    // not pin
    int y;
    y = abs(arr[pos].first - arr[pre].first) + getAns(pos+1, pre);

    return dp[pos][pre]= min(x,y);
}

int main(){
    int sum;
    cin>>n;
    
    for(int i= 1; i<=n; i++){
        for(int j =1; j<=n; j++){
            dp[i][j] = -1;
        }
    }

    for(int i =1; i<= n; i++){
        cin>>arr[i].first>>arr[i].second;
    }

    sort(arr+1,arr+n+1);

    cout<<getAns(2,1) + arr[1].second;
    return 0;
}