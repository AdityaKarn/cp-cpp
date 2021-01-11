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
const int MAX = (int)1e2 + 5;

int arr[MAX];
int prefixSum[MAX];

void solveTestCases()
{
    int n;
    cin >> n;
    lli sum = 0;
    bool allzeros = true;
    prefixSum[0] = 0;
    REP(i, n)
    {
        cin >> arr[i];
        prefixSum[i] = prefixSum[i - 1] + arr[i];

        if (arr[i] != 0)
        {
            allzeros = false;
        }
    }

    if (prefixSum[n] != 0)
    {
        cout << "YES\n";
        cout << 1 << '\n';
        cout << 1 << " " << n << "\n";
        return;
    }

    if (allzeros)
    {
        cout << "NO\n";
    }
    int i = n - 1;
    while (i >= 0)
    {
        if (prefixSum[i] != 0)
        {
            cout << "YES\n";
            cout << "2\n";
            cout << 1 << " " << i << "\n";
            cout << i + 1 << " " << n << "\n";
            break;
        }
        i--;
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