#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
#include <cstring>
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

using namespace std;

void solveTestCases()
{
    char s[100005], *p;
    cin >> s;

    if ((p = strstr(s, "AB")) && strstr(p + 2, "BA"))
    {
        cout << "YES\n";
        return;
    }
    else if ((p = strstr(s, "BA")) && strstr(p + 2, "AB"))
    {
        cout << "YES\n";
        return;
    }
    else
    {
        cout << "NO\n";
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t;
    t = 1;

    while (t--)
    {
        solveTestCases();
    }

    return 0;
}