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

map<int, vector<string>> m;
int maxlvl = 1;
void dfs(stringstream &ss, string cur, int lvl)
{
    maxlvl = max(maxlvl, lvl);
    m[lvl].push_back(cur);

    string num;
    getline(ss, num, ',');

    int no = stoi(num);

    for (int i = 0; i < no; i++)
    {
        string nxt;
        getline(ss, nxt, ',');
        dfs(ss, nxt, lvl + 1);
    }
}

void solveTestCases()
{
    string s;
    cin >> s;
    stringstream ss(s);

    string cur;

    while (getline(ss, cur, ','))
    {
        dfs(ss, cur, 1);
    }

    cout << maxlvl << "\n";
    for (auto it : m)
    {
        for (auto x : it.second)
        {
            cout << x << " ";
        }
        cout << "\n";
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