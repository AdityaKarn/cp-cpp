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
const int MAX = (int)2e5 + 5;
vector<int> idx[MAX];
vector<ii> v;
int a[MAX], b[MAX];
void solveTestCases()
{
    int n;
    cin >> n;

    for (int i = 1; i <= n; i++)
    {
        cin >> a[i] >> b[i];
        idx[a[i]].pb(i);
    }

    for (int i = 1; i <= n; i++)
    {
        if (idx[i].size() > 0)
        {
            v.pb({idx[i].back(), i});
        }
    }

    sort(v.begin(), v.end());
    int q;
    cin >> q;

    while (q--)
    {
        int k;
        cin >> k;
        set<int> s;

        for (int i = 1; i <= k; i++)
        {
            int x;
            cin >> x;
            s.insert(x);
        }

        int cur = v.size() - 1;

        while (cur >= 0 && s.find(v[cur].second) != s.end())
        {
            cur--;
        }
        if (cur < 0)
        {
            cout << "0 0\n";
            continue;
        }
        int person = v[cur].second;
        cur--;
        while (cur >= 0 && s.find(v[cur].second) != s.end())
        {
            cur--;
        }

        int to_search = (cur >= 0) ? v[cur].first : 0;

        auto it = upper_bound(idx[person].begin(), idx[person].end(), to_search) - idx[person].begin();

        cout << person << " " << b[idx[person][it]] << "\n";
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