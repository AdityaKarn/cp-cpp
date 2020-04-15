#include <iostream>
#include<vector>
using namespace std;

vector<int> ar[10001];
int vis[10001];

int maxD, maxNode;

void dfs(int node, int d){
	vis[node]=1;

    if(d>maxD){
        maxD=d;
        maxNode= node;
    }

    for(int child: ar[node])
        if(vis[child]!=1)
            dfs(child, d+1);

}

int main() {
	// your code goes here

	int n, a, b;
	cin>>n;
	
	for(int i = 0; i< n-1; i++){
		cin>>a>>b;
		ar[a].push_back(b);
		ar[b].push_back(a);
        
	}
	maxD=-1;
	dfs(1,0);

    for(int i= 0; i<n; i++){
        vis[i]=0;
    }

    maxD=-1;
    dfs(maxNode,0);

    cout<<maxD;
	
	return 0;
}