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

using namespace std;

int a[1001];

// function to find gcd of two integer numbers
int gcd(int a, int b)
{
    if (!a)
        return b;
    return gcd(b % a, a);
}

void solveTestCases()
{
    int n;
    cin >> n;

    int a[n];

    int mi = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        if (a[mi] < a[i])
        {
            mi = i;
        }
    }

    vector<int> b(n);
    b[0] = a[mi];
    a[mi] = 0;

    int cg = b[0];

    for (int i = 1; i < n; i++)
    {
        int ci = 0, cans = 0;
        for (int j = 0; j < n; j++)
        {
            if (a[j] && gcd(a[j], cg) > cans)
            {
                cans = gcd(a[j], cg);
                ci = j;
            }
        }

        b[i] = a[ci];
        cg = cans;
        a[ci] = 0;
    }

    for (int i = 0; i < n; i++)
    {
        cout << b[i] << " ";
    }
    cout << "\n";
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;

    while (t--)
    {
        solveTestCases();
    }

    return 0;
}