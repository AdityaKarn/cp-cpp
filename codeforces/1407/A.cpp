#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
#include <queue>
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
void solveTestCases()
{
    int n;
    cin >> n;

    int countZeros = 0;

    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        if (!a[i])
        {
            countZeros++;
        }
    }

    int countOnes = n - countZeros;

    if (countZeros >= n / 2)
    {
        cout << countZeros << '\n';

        for (int i = 0; i < countZeros; i++)
        {
            cout << "0 ";
        }
        cout << "\n";
    }
    else
    {
        if (countOnes % 2)
        {
            countOnes--;
        }

        cout << countOnes << "\n";

        for (int i = 0; i < countOnes; i++)
        {
            cout << 1 << " ";
        }
        cout << "\n";
    }
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