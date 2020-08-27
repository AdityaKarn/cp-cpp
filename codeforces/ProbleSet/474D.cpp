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
int k;

lli pre[100001];
lli dp[100001];

int getAnswer( int n){
    
    if(n==0) return 1;
    
    if(dp[n]!= -1) return dp[n];


    int ans =0;

    if(n>=k) ans += getAnswer(n-k), ans = ans%mod;

    ans += getAnswer(n-1), ans = ans%mod;
    
    return dp[n] = ans;
}

void init(){
    for(int i = 1; i<=100000; i++){
        dp[i] = -1;
    }

    for(int i = 1; i<=100000; i++){
        pre[i] = pre[i-1]+ getAnswer(i);
    }

}

int main(){
    
    int t, a , b;
    cin>>t>>k;
    pre[0] = 1;
    init();

    while(t--){
        cin>>a>>b;
        int sum = 0;
        
        sum = (pre[b] - pre[a-1]+ mod)%mod;
        
        cout<<sum<<endl;
    }

}