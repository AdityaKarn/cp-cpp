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

int level[100001];
int parent[100001];

void dfs(int node, int d){
    visited[node]=1;
    level[node] = d;

    for(int child: adj[node]){
        if(visited[child]==0){
            parent[child] = node;
            dfs(child,d+1);
        } 
    }

}

int findLCA(int a, int b){
    int diff = level[a] - level[b];

    while(diff>0){
        diff--;
        a = parent[a];
    } 

    if(a==b) return a;

    while(parent[a] != parent[b]){
        a = parent[a];
        b = parent[b];
    }

    return parent[a];
}

int main(){

    int n,e,a,b;
    cin>>n>>e;

    REP(i,n) visited[i] =0;

    REP(i,e){
        cin>>a>>b;
        adj[a].pb(b), adj[b].pb(a);
    }
    parent[1]=0;
    dfs(1,1);

    cin>>a>>b;

    if(level[a]>level[b]) cout<<findLCA(a,b);
    else cout<<findLCA(b,a);



    return 0;
}