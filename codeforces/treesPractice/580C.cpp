#include<iostream>
#include<vector>
using namespace std;

vector<int> adj[100001];
int cats[100001];
int countCats=0;
int m;
bool visited[100001];
void dfs(int node,  int seenCats){
    if(seenCats>m) return;
    visited[node]= true;

    bool ok = false;//tells if a path is ok

    for(int v=0; v < adj[node].size(); v++){
        if(!visited[adj[node][v]]){

            cats[adj[node][v]]?seenCats = seenCats+1: seenCats=0;

            seenCats = seenCats +1;
            dfs(adj[node][v], seenCats);
            ok=true;
            

        }

    }

    if(!ok) countCats++;

}

int main(){
    int n, a ,b;

    cin>>n>>m;
    for(int i=1; i<=n; i++){
        cin>>cats[i];
    }

    for(int i = 1; i< n; i++){
        cin>>a>>b;
        a;b;
        adj[a].push_back(b); adj[b].push_back(a);
    }

    //dfs call
    
    dfs(1,cats[1]);

    cout<<countCats;


    return 0;
}