#include<iostream>
#include<vector>

using namespace std;

vector<int> adj[1000];

int In[1000];
int Out[1000];
int timer =1;
bool visited[1000];

int flatTree[2000];


void dfs(int src){
    visited[src]=1;
    In[src] =timer++;

    for(int child: adj[src]){
        if(visited[child]==0){
            dfs(child);
        }
    }

    Out[src]= timer++;
}



int main(){
    cout<<"enter vertices and edges";
    int n,a,b,e;  cin>>n>>e;
    cout<<"enter pairs of digits";

    for(int i=0; i < n-1; i++){
        cin>>a>>b;

        adj[a].push_back(b), adj[b].push_back(a);
    }

    for(int i=0; i<n; i++){
        visited[i]=0;
    }

    dfs(1);

    for(int i=1; i<=n; i++){
        flatTree[In[i]]=i;
        flatTree[Out[i]]=i;
    }

    for(int i=1; i<= 2*n; i++){
        cout<<flatTree[i]<<" ";
    }
    
    return 0;
}