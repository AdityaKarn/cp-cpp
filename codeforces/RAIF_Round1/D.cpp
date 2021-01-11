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
const int MAX = (int)1e5 + 5;

int Ys[MAX];

void solveTestCases()
{
    int n;
    cin >> n;

    vector<int> ones;

    queue<int> thr, tw;

    for (int i = 1; i <= n; i++)
    {
        cin >> Ys[i];

        if (Ys[i] == 1)
        {
            ones.pb(i);
        }
        if (Ys[i] == 2)
        {
            tw.push(i);
        }
        if (Ys[i] == 3)
        {
            thr.push(i);
        }
    }

    if (tw.size() + thr.size() > ones.size())
    {
        cout << "-1\n";
        return;
    }
    vector<ii> res;
    int x = 1;
    while (!thr.empty())
    {
        int y_three = thr.front();
        thr.pop();

        int y_ones = ones.back();
        if (y_ones > y_three)
        {
            ones.pop_back();

            res.pb({x, y_three});
            res.pb({x, y_ones});
            res.pb({x + 1, y_ones});

            x += 2;
        }
        else
        {
            cout << "-1\n";
            return;
        }
    }
    while (!tw.empty())
    {
        int y_two = tw.front();
        tw.pop();

        int y_ones = ones.back();
        if (y_ones > y_two)
        {

            ones.pop_back();

            res.pb({x, y_two});
            res.pb({x, y_ones});

            x++;
        }
        else
        {
            cout << "-1\n";
            return;
        }
    }

    while (!ones.empty())
    {
        int y_ones = ones.back();
        ones.pop_back();

        res.pb({x, y_ones});
        x++;
    }

    cout << res.size() << "\n";

    for (auto p : res)
    {
        cout << p.first << " " << p.second << "\n";
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