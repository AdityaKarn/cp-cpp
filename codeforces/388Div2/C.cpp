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
const int MAX = (int)1e4 + 5;
void solveTestCases()
{
    int n;
    string s;

    cin >> n;
    cin >> s;

    vector<int> color(n);

    // D = 1, R = 2, Not voting = -1
    queue<int> d, r;

    for (int i = 0; i < n; i++)
    {
        char ch = s[i];

        if (s[i] == 'D')
        {
            d.push(i);
        }
        else
        {
            r.push(i);
        }
    }

    while (!d.empty() && !r.empty())
    {
        int a = d.front();
        int b = r.front();
        d.pop();
        r.pop();

        if (a < b)
        {
            d.push(a + n);
        }
        else
        {
            r.push(a + n);
        }
    }

    if (d.empty())
    {
        cout << "R\n";
    }
    else
    {
        cout << "D\n";
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