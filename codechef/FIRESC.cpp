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
#define N 100001

using namespace std;

vi adj[N];
int visited[N];
int members=1;
int dfs(int v){

    visited[v]=1;

    for(int child: adj[v]){
        if(visited[child]==0){
            members++;
            dfs(child);
        }
    }

    return members;
} 


int main(){
    int t,n,m,a,b; cin>>t;
    while (t--)
    {
        cin>>n>>m;

        REP(i,n) visited[i] = 0, adj[i].clear();

        REP(i, m){
            cin>>a>>b;
            adj[a].pb(b), adj[b].pb(a);
        }

        

        int cc_count =0, res =1, temp =1;

        REP(i,n){
            if(visited[i]==0){
                cc_count++;
                members=1;
                temp = dfs(i);
                res = res*temp;
            }
        }

        cout<<cc_count<<" "<<res<<endl;
        
    }
    

}