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
 
struct edge{
    int a;
    int b;
    int w;
};

edge arr[10001];
bool visited[10001];
int par[10001];

bool comp(edge a, edge b){
    if(a.w<b.w) return true;
    else return false;
}

void merge(int a, int b){
    par[a] = b;

}

int find(int a){
    if(par[a]==-1) return a;

    else return par[a] = find(par[a]);
}

int main(){
    int m,n,a,b,w; cin>>n>>m;

    REP(i,n) par[i] = -1;

    for(int i = 0; i< m; i++){
        cin>>arr[i].a>>arr[i].b >>arr[i].w;
    }

    sort(arr, arr+m, comp);
    int sum =0;

    for(int i =0; i< m; i++){
        a = find(arr[i].a);
        b = find(arr[i].b);

        if(a!=b){
            sum += arr[i].w;
            merge(a,b);
        }
    }
    cout<<sum;

}