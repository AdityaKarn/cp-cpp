#include<iostream>
#include<vector>
#include<queue>

using namespace std;

vector<int> adj[100001];
int vis[100001];
int dis[100001];

void bfs(int v){
    vis[v]=1;
    dis[v]=0;

    queue<int> curr;
    curr.push(v);

    while(curr.size()!=0){
        int temp= curr.front();
        curr.pop();
        
        for(int child: adj[temp]){

            if(!vis[child]){
                vis[child]=1;
                curr.push(child);
                dis[child] = dis[temp]+1;

            }
        }
    }



}

int main(){
    int t; cin>>t;

    while (t--)
    {
        int m,n,a,b; cin>>n>>m; 

        for(int i=0;i<n;i++){
            vis[i]=0; dis[i] = 1000001;
        }

        for(int i=0; i<m;i++){
            cin>>a>>b;
            adj[a].push_back(b); adj[b].push_back(a);
        }

        
        bfs(1);

        cout<<dis[n]<<endl;
    }
    
    return 0;
}