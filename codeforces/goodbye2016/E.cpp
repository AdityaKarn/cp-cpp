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
const int MAX = (int)1e4 + 5;
void solveTestCases()
{
    int n, q;
    string s;
    cin >> n >> q;
    cin >> s;

    vector<int> two(n + 1, 0), zero(n + 1, 0), one(n + 1, 0), six(n + 1, 0), seven(n + 1, 0);
    for (int i = n - 1; i >= 0; i--)
    {
        if (s[i] == '2')
        {
            two[i] = two[i + 1] + 1;
        }
        else
        {
            two[i] = two[i + 1];
        }
        if (s[i] == '0')
        {
            zero[i] = zero[i + 1] + 1;
        }
        else
        {
            zero[i] = zero[i + 1];
        }
        if (s[i] == '1')
        {
            one[i] = one[i + 1] + 1;
        }
        else
        {
            one[i] = one[i + 1];
        }
        if (s[i] == '7')
        {
            seven[i] = seven[i + 1] + 1;
        }
        else
        {
            seven[i] = seven[i + 1];
        }
        if (s[i] == '6')
        {
            six[i] = six[i + 1] + 1;
        }
        else
        {
            six[i] = six[i + 1];
        }
    }

    while (q--)
    {
        int l, r;
        cin >> l >> r;
        l--, r--;
        int twos = two[l] - two[r], zeros = zero[l] - zero[r], ones = one[l] - one[r], sevens = seven[l] - seven[r], sixes = six[l] - six[r];

        if (s[r] == '2')
        {
            twos++;
        }
        if (s[r] == '0')
        {
            zeros++;
        }
        if (s[r] == '1')
        {
            ones++;
        }
        if (s[r] == '7')
        {
            sevens++;
        }
        if (s[r] == '6')
        {
            sixes++;
        }

        trace5(twos, zeros, ones, sevens, sixes);

        if (twos * zeros * ones * sevens == 0)
        {
            cout << "-1\n";
            continue;
        }

        lli res = twos * ones * zeros * sixes;
        cout << res << "\n";
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