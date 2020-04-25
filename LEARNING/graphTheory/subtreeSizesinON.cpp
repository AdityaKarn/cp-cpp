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
#include<iostream>
#include<vector>

using namespace std;

vector<int> adj[1000];

int subTree[1000];
bool visited[1000];


int dfs(int src){
    visited[src]=1;
    int count_subtree=1;

    for(int child: adj[src]){
        if(visited[child]==0){
            count_subtree += dfs(child);
        }
    }

    subTree[src] = count_subtree;
    return count_subtree;

}



int main(){
    cout<<"enter vertices and edges";
    int n,a,b,e;  cin>>n>>e;
    cout<<"enter pairs of digits";


    for(int i=0; i<n; i++){
        visited[i]=0;
    }

    for(int i=0; i < n-1; i++){
        cin>>a>>b;

        adj[a].push_back(b), adj[b].push_back(a);
    }

    dfs(1);


    REP(i,n) cout<<subTree[i]<<" ";

    return 0;
}
