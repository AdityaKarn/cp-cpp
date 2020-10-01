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
#define IOS                  \
    ios::sync_with_stdio(0); \
    cin.tie(0);              \
    cout.tie(0);

using namespace std;
const int MAX = (int)1e4 + 5;

void solveTestCases()
{
    int n;
    cin >> n;
    vector<int> a(3), b(3);

    for (int i = 0; i < 3; i++)
    {
        cin >> a[i];
    }
    for (int i = 0; i < 3; i++)
    {
        cin >> b[i];
    }

    vector<ii> ord;

    ord.pb({0, 0});
    ord.pb({0, 2});
    ord.pb({1, 1});
    ord.pb({1, 0});
    ord.pb({2, 2});
    ord.pb({2, 1});

    sort(ord.begin(), ord.end());
    int minw = INT_MAX;
    do
    {
        vector<int> a1 = a, b1 = b;

        for (int i = 0; i < ord.size(); i++)
        {
            int cnt = min(a1[ord[i].first], b1[ord[i].second]);
            a1[ord[i].first] -= cnt;
            b1[ord[i].second] -= cnt;
        }

        int temp = min(a1[0], b1[1]) + min(a1[1], b1[2]) + min(a1[2], b1[0]);
        minw = min(minw, temp);

    } while (next_permutation(ord.begin(), ord.end()));

    int maxw = min(a[0], b[1]) + min(a[1], b[2]) + min(a[2], b[0]);

    cout << minw << " " << maxw << "\n";
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