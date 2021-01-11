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
const int MAX = (int)1e4 + 5;

string s;
int kr = 0, kb = 0, ky = 0, kg = 0;
int a[5];
void solveTestCases()
{
    cin >> s;

    for (int i = 0; i < s.size(); i++)
    {
        if (s[i] == 'G')
        {
            kg = i % 4;
        }
        else if (s[i] == 'B')
        {
            kb = i % 4;
        }
        else if (s[i] == 'Y')
        {
            ky = i % 4;
        }
        else if (s[i] == 'R')
        {
            kr = i % 4;
        }
        else
        {
            a[i % 4]++;
        }
    }

    // trace4(kg, kb, ky, kr);

    cout << a[kr] << " " << a[kb] << " " << a[ky] << " " << a[kg] << "\n";
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