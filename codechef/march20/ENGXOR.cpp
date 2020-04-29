#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

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

int getSetPieces(int n)
{
    int res = 0, curr;
    while (n)
    {
        curr = n % 2;
        if (curr)
            res++;

        n /= 2;
    }
    return res;
}

int main()
{
    int t, n, q, p, setP, setA, a, aEven = 0, aOdd = 0;
    cin >> t;

    while (t--)
    {
        cin >> n >> q;

        for (int i = 0; i < n; i++)
        {
            cin >> a;
            setA = getSetPieces(a);

            if (setA % 2 == 0)
                aEven++;
            else
                aOdd++;
        }

        for (int i = 0; i < q; i++)
        {
            cin >> p;
            setP = getSetPieces(p);

            if ((abs(setP - setA)) % 2 == 0)
            {
                cout << aEven << " " << aOdd;
            }
            else
            {
                cout << aOdd << " " << aEven;
            }
        }
    }

    return 0;
}