#include<iostream>
#include<vector>
#include<algorithm>

#define REP(i,n) for (int i = 1; i <= n; i++)

#define mod 1000000007
#define pb push_back
#define ii pair<int,int>
#define vi vector<int>
#define vii vector<ii>
#define lli long long int
#define INF 1000000000


using namespace std;

int arr[100001], st[400004];

void build(int si, int ss, int se){
    if(ss==se) {st[si]= arr[ss];
    return;}

    int mid = (ss+se)/2;

    build(2*si, ss, mid);
    build(2*si +1, mid+1, se);

    st[si] = min(st[2*si], st[(2*si)+1]);
}

int query(int si, int ss, int se, int qs, int qe){
    if(ss>qe || se<qs) return INF;

    if(ss >= qs && se <= qe) return st[si];

    int mid = (se+ss)/2;

    int l = query(2*si, ss, mid, qs, qe);
    int r = query(2*si+1, mid+1, se, qs, qe);

    return min(l,r);
}

int main(){

    int n,q, l, r;

    cin>>n;

    REP(i,n) cin>>arr[i];
    build(1,1,n);
    cin>>q;

    REP(i,q){
        cin>>l>>r;
        cout<<query(1,1,n, l+1, r+1)<<endl;
    }


    return 0;
}