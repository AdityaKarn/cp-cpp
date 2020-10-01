#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
#include <unordered_map>
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
    string s;
    cin >> s;

    int n = s.size();

    unordered_map<string, int> sub;
    lli res = 0;
    for (int i = 0; i < n; i++)
    {
        string cur;
        for (int j = i; j < i + n; j++)
        {
            cur += s[j % n];
        }

        // cout << cur << "\n";

        if (sub.find(cur) == sub.end())
        {
            res++;
            sub[cur]++;
        }
    }

    cout << res << "\n";
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