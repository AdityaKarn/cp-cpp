
#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
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

    string s;
    cin >> s;

    int a = 0, d = 0;
    for (char ch : s)
    {
        if (ch == 'A')
        {
            a++;
        }
        else
        {
            d++;
        }
    }
    if (a == d)
    {
        cout << "Friendship\n";
    }
    else if (a > d)
    {
        cout << "Anton\n";
    }
    else
    {
        cout << "Danik\n";
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