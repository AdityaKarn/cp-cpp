#include<iostream>
#include<vector>
#include<queue>

using namespace std;

vector<int> adj[1000001];
int vis[1000001];
int dis[1000001];
int level[1000001];

void bfs(int src){

    queue<int> q; q.push(src);
    vis[src]=1; dis[src]=0;

    while(!q.empty()){
        int curr = q.front();
        q.pop();

        for(int child: adj[curr]){
            if(vis[child]==0){
                q.push(child);
                vis[child]=1;
                dis[child] = dis[curr]+1;
                level[dis[child]]++; 
            }
        }
    }
}

int main(){
    int n,e,a,b; cin>>n>>e;

    for(int i =0; i< e; i++){
        cin>>a>>b;
        adj[a].push_back(b); adj[b].push_back(a);
    }

    int m; cin>>m;
    int src,d;
    for(int i =0; i<m; i++){
        cin>>src>>d;
        for(int i=0; i<=n; i++){
            level[i]=0;
            vis[i]=0;
        }
        
        bfs(src);

        cout<<level[d]<<endl;
    }


    return 0;
}