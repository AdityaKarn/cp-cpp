#include <bits/stdc++.h>
#define REP(i, n) for (int i = 1; i <= n; i++)

#define mod 1000000007
#define pb push_back
#define ff first
#define ss second
#define ii pair<int, int>
#define vi vector<int>
#define vii vector<ii>
#define lli long long int
#define INF 1000000000
#define IOS                  \
    ios::sync_with_stdio(0); \
    cin.tie(0);              \
    cout.tie(0);

using namespace std;
const int MAX = (int)1e4 + 5;

vector<int> gr, siz;

void DSU(int n){

    gr.resize(n);
    siz.resize(n, 1);
    iota(gr.begin(), gr.end(), 0);

}

int Find(int a){
    if(gr[a] == a){
        return a;
    }

    return gr[a] = Find(gr[a]);
}

void Union(int a, int b){

    a = Find(a);
    b = Find(b);

    if(a == b){
        return;
    }

    if(siz[a] < siz[b]){
        swap(a, b);
    }
    siz[a] += siz[b];
    gr[b] = a;

}

void solveTestCases()
{
    int n, m;
    cin>>n>>m;

    DSU(n);

    for(int i = 0; i<m ; i++){
        int u, v;
        cin>>u>>v;
        u--, v--;
        Union(u, v);
    }

    vector<int> parents;
    int maxId, maxSize= 0;

    for(int i = 0; i<n; i++){
        // cout<<Find(i)<<" ";

        if(i == Find(i)){
            parents.pb(i);

            if(siz[i]>maxSize){
                maxSize = siz[i];
                maxId = i;
            }
        }
    }
    cout<<parents.size()-1<<"\n";
    for(auto x: parents){
        if(x != maxId){
            cout<<x+1<<" "<<maxId+1<<"\n";
        }
    }
}

int main()
{
    IOS;
    int t;
    t = 1;

    while (t--)
    {
        solveTestCases();
    }

    return 0;
}