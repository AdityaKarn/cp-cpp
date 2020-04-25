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
vi adj[100001];
bool visited[100001];

int level[100001];
int LCA[10001][10001];
int maxN;


void dfs(int node, int par, int d){
    visited[node]=1;
    LCA[node][0] = par;
    level[node] = d;
    for(int child: adj[node]){
        if(child != par){
            dfs(child, node, d+1);
        }
    }

}


void init(){
    dfs(1,-1,1);
    
    for(int j = 1; j<maxN; j++){
        for(int i =1; i<=n; i++){
            if(LCA[i][j-1]!=-1){
                int par = LCA[i][j-1];
                LCA[i][j]= LCA[par][j-1];
            }
        }
    }


}

int findLCA(int a, int b){
    int diff = level[a] - level[b];

    while(diff>0){
        int i = log2(diff);
        b = LCA[b][i];
        diff -= (1<<i);
    } 

    if(a==b) return a;

    // while(LCA[a][0]!= LCA[b][0]){
    //     a = LCA[a][0]; b= LCA[b][0];
    // }

    for(int i = maxN; i>0; i--){
        if(LCA[a][0]=-1 && (LCA[a][i] != LCA[b][i])){
            a = LCA[a][i]; b = LCA[b][i];
        }
    }

    return LCA[a][0];
}

int main(){

    int e,a,b;
    cin>>n>>e;
    int maxN = log2(n);

    REP(i,n) visited[i] =0;

    for(int i =0; i<=n ; i++){
        for(int j =0; j<= maxN; j++) {
            LCA[i][j] = -1;
        }       
    }

    REP(i,e){
        cin>>a>>b;
        adj[a].pb(b), adj[b].pb(a);
    }
    

   
    init();

    cin>>a>>b;

    if(level[a]>level[b]) cout<<findLCA(a,b);
    else cout<<findLCA(b,a);



    return 0;
}