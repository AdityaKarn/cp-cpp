#include <bits/stdc++.h>
#define REP(i, n) for (int i = 1; i <= n; i++)

#define trace1(x) cerr << #x << ": " << x << "\n"
#define trace2(x, y) cerr << #x << ": " << x << " | " << #y << ": " << y << "\n"
#define trace3(x, y, z) cerr << #x << ":" << x << " | " << #y << ": " << y << " | " << #z << ": " << z << "\n"
#define trace4(a, b, c, d) cerr << #a << ": " << a << " | " << #b << ": " << b << " | " << #c << ": " << c << " | " << #d << ": " << d << "\n"
#define trace5(a, b, c, d, e) cerr << #a << ": " << a << " | " << #b << ": " << b << " | " << #c << ": " << c << " | " << #d << ": " << d << " | " << #e << ": " << e << "\n"
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
int a[MAX];

void solveTestCases()
{
    int n, k;
    cin >> n >> k;

    int neg = 0;

    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];

        if (a[i] >= 0)
        {
            a[i] = 0;
        }
        else
        {
            a[i] = -1;
            neg++;
        }
    }

    if (neg > k)
    {
        cout << "-1\n";
        return;
    }

    vector<ii> v;
    int check = 0, cntsum = 0;
    int ans = 0;
    for (int i = 1; i <= n; i++)
    {
        if (a[i] != a[i - 1])
        {
            // cout << a[i] << " ";
            ans++;
        }
        if (a[i] >= 0)
        {
            cntsum++;
        }
        else
        {
            k--;
            if (cntsum > 0 && check >= 1)
            {
                v.pb({cntsum, check});
            }
            check++;
            cntsum = 0;
        }
    }
    if (cntsum > 0 && check >= 1)
    {
        v.pb({cntsum, check});
    }

    sort(v.begin(), v.end());

    int storelast = -1;

    for (auto it : v)
    {
        if (it.second == check)
        {
            storelast = it.first;
            continue;
        }
        if (it.first <= k)
        {
            k -= it.first;
            ans -= 2;
        }
    }

    if (storelast != -1 && storelast <= k)
    {
        ans--;
    }

    cout << ans << "\n";
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