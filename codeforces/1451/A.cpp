#include <bits/stdc++.h>

#define REP(i, n) for (int i = 0; i < n; i++)
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

template <typename T>
T gcd(T a, T b)
{
    if (a == 0)
        return b;
    return gcd(b % a, a);
}
template <typename T>
T pow(T a, T b, lli m)
{
    T ans = 1;
    while (b > 0)
    {
        if (b % 2 == 1)
            ans = (ans * a) % m;
        b /= 2;
        a = (a * a) % m;
    }
    return ans % m;
}

const int MAX = (int)1e4 + 5;
void solveTestCases()
{
    int n;
    cin >> n;

    if (n == 1)
    {
        cout << "0\n";
        return;
    }
    if (n == 2)
    {
        cout << "1\n";
        return;
    }
    if (n == 3)
    {
        cout << "2\n";
        return;
    }

    if (n % 2 == 0)
    {
        cout << "2\n";
    }
    else
    {
        cout << "3\n";
    }
}

int main()
{
    IOS;
    int t;
    cin >> t;

    while (t--)
    {
        solveTestCases();
    }

    return 0;
}