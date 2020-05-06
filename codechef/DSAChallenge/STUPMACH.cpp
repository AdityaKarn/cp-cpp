#include <iostream>
#include <vector>
#include <algorithm>

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

lli S[1000002];

lli minV = INF, minIdx;

void findMin(lli a[], int r)
{
    minV = INF;
    for (int i = 1; i <= r; i++)
    {
        if (S[i] < minV)
        {
            minV = S[i];
            minIdx = i;
        }
    }
}

int main()
{
    int t, n, iterations = 0;
    lli res = 0;
    cin >> t;

    while (t--)
    {
        res = 0;
        cin >> n;

        for (int i = 1; i <= n; i++)
        {
            cin >> S[i];

            if (S[i] < minV)
            {
                minV = S[i];
                minIdx = i;
            }
        }

        //initial res
        res = n * minV;
        iterations = minV;

        while (true)
        {

            findMin(S, minIdx - 1);
            if (minV - iterations <= 0)
            {
                break;
            }

            res += minIdx * (minV - iterations);
            iterations += minV;

            if (minIdx == 1)
                break;
        }

        cout << res << endl;
    }
    return 0;
}
