#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
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
    int t, n, s, p, v, res = 0;
    cin >> t;

    while (t--)
    {
        res = 0;
        cin >> n;

        while (n--)
        {
            cin >> s >> p >> v;

            int people = p / (s + 1);
            int currRes = people * v;
            res = max(res, currRes);
        }

        cout << res << endl;
    }
    return 0;
}