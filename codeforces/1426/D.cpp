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

void solveTestCases()
{
    int n;
    cin >> n;
    vector<int> arr(n + 1), pr(n + 1);
    pr[0] = 0;

    unordered_map<lli, lli> pr_freq;
    pr_freq[0]++;
    lli res = 0;
    lli cur = 0;
    for (int i = 1; i <= n; i++)
    {
        cin >> arr[i];
    }

    for (int i = 1; i <= n; i++)
    {
        cur += arr[i];

        if (pr_freq.find(cur) != pr_freq.end())
        {
            res++;
            pr_freq.clear();
            pr_freq[0]++;
            cur = arr[i];
        }

        pr_freq[cur]++;
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