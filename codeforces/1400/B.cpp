#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
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

    int t;
    cin >> t;

    while (t--)
    {

        lli p, f, cnts, cntw, s, w;
        cin >> p >> f >> cnts >> cntw >> s >> w;

        if (s > w)
        {
            swap(s, w);
            swap(cnts, cntw);
        }

        int toIterate = min(cnts, p / s);

        int res = 0;
        for (int i = 0; i <= toIterate; i++)
        {
            int myAxes = min(cntw, (p - (i * s)) / w);
            int fSwords = min(cnts - i, f / s);
            int fAxes = min(cntw - myAxes, (f - (fSwords * s)) / w);

            res = max(i + myAxes + fSwords + fAxes, res);
        }

        cout << res << "\n";
    }

    return 0;
}