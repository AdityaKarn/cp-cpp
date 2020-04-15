#include<iostream>
#include<vector>
#include<queue>

using namespace std;

vector<int> adj[100001];
vector<int> primes;
int dis[100001];
int vis[100001];

bool isValid(int a, int b){
    int count=0;
    while(a){
        if(a%10 != b%10){
            count++;
        }
        a/=10; b/=10;
    }

    if(count == 1) return true;
    else return false;
}

bool isPrime(int x){
    for(int i =2;i*i<x; i++){
        if(x%i==0) return false;
    }
    return true;
}

void makeGraph(){
    for(int i=1000; i<=9999;i++){
        if(isPrime(i)) primes.push_back(i);
    }

    for(int i=0; i< primes.size(); i++){
        for(int j = i+1; j< primes.size(); j++){
            int a = primes[i]; int b =  primes[j];

            if(isValid(a,b)){
                adj[a].push_back(b); adj[b].push_back(a);
            }
        }
    }
}

void bfs(int src){
    queue<int> q;
    dis[src]=0; vis[src]=1;
    q.push(src);

    while(!q.empty()){
        int curr = q.front();
        q.pop();

        for(int child: adj[curr]){
            if(vis[child]==0){
                vis[child]=1;
                dis[child]= dis[curr]+1;
                q.push(child);
            }
        }
    }
}


int main(){
    int t; cin>>t;

    makeGraph();

    while(t--){
        int a, b; cin>>a>>b;

        for(int i=1000; i<=9999; i++){
            dis[i]=-1;
            vis[i]=0;
        }

        bfs(a);

        if(dis[b]==-1) cout<<"Impossible"<<endl;
        else cout<<dis[b]<<endl;

    }
    

    return 0;
}