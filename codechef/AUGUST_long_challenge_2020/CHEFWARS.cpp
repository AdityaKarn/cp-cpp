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

    int t, p, h;
    cin>>t;

    while (t--) {
        bool possible=false;
        cin>> h>>p;

        while (p>0) {

            h = h - p;
            p = p/2;

            if (h<0) {
                possible =true;
                break;
            }
        }

        if (possible|| h<=0) cout<<1<<"\n";
        else cout<<0<<"\n";
    }
    return 0;
}