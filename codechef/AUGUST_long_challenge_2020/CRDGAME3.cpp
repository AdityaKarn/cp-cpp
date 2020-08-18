#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
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

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t, pc, pr;

    cin>>t;

    while (t--) {
        cin>>pc>>pr;

        //steps needed by chef
        int cq = pc/9;
        int cr = pc%9;
        cr = !(!cr);
        int cs = cq+cr;

        //steps by rick 
        int rq = pr/9;
        int rr = pr%9;
        rr = !(!rr);
        int rs = rq+rr;

        if (cs<rs) {
            cout<<0<<" "<<cs<<"\n";
        }
        else {
            cout<<1<<" "<<rs<<"\n";
        }
    }
    return 0;
}