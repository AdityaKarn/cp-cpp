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

bool hasBridge = false;
vi adj[100001];
bool visited[100001];
vector<pair<int,int>> edgeList;
int In[100001], Low[100001];
int timer = 1;

void dfs(int node, int par){
    visited[node]=1;
    In[node]= Low[node]= timer;
    timer++;

    for(int child: adj[node]){
        if(child==par) continue;
        
        else if(visited[child] == 1){
            //back-edge
            if(In[node]>In[child]){
                edgeList.pb({node,child});
            }
            
            Low[node] = min(Low[node], In[child]);
            
            //if descendant
            

        }
        else{
            //fwd-edge
            dfs(child, node);
			edgeList.pb({node,child});
            if(Low[child]> In[node]){
                hasBridge =1;
                return;
            }
            
            Low[node] = min(Low[node],Low[child]);
        }
    }

}

int main(){

    int n,e,a,b;
    cin>>n>>e;

    REP(i,e){
        cin>>a>>b;
        adj[a].pb(b), adj[b].pb(a);
    }
    timer = 0;  hasBridge = 0;

    dfs(1,-1);

    if(hasBridge) cout<<0;
    else{
        for(pair<int,int> e: edgeList){
            cout<<e.first<<" "<<e.second<<endl;
        }
    }

    return 0;
}