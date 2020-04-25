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

vi adj[100001];
bool visited[100001];

int In[100001], Low[100001];
int timer = 1;

void dfs(int node, int par){
    visited[node]=1;
    In[node]= Low[node]= timer;
    timer++;

    for(int child: adj[node]){
        if(child==par) continue;
        
        else if(visited[child] == 1){
            Low[node] = min(Low[node], In[child]);
        }
        else{
            dfs(child, node);

            if(Low[child]> In[node]){
                cout<<node<<" - "<<child<<" is a bridge";
            }
            Low[node] = min(Low[node],Low[child]);
        }
    }

}

int main(){

    int n,e,a,b;
    cin>>n>>e;

    REP(i,n) visited[i] =0;

    REP(i,e){
        cin>>a>>b;
        adj[a].pb(b), adj[b].pb(a);
    }

    dfs(1,-1);


    return 0;
}