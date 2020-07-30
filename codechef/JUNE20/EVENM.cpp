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

void printOdd(int n)
{
    int k = 1;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            cout << k++ << " ";
        }
        cout << "\n";
    }
}

void printEven(int n)
{

    int k = 0;
    for (int i = 1; i <= n; i++)
    {
        if (i % 2)
        {
            for (int j = 1; j <= n; j++)
            {
                cout << ++k << " ";
            }
            cout << "\n";
        }
        else
        {
            int p = k + n;

            for (int j = 1; j <= n; j++)
            {
                cout << p-- << " ";
            }
            cout << "\n";
            k += n;
        }
    }
}

int main()
{
    int t, n;
    cin >> t;

    while (t--)
    {
        cin >> n;

        if (n % 2)
        {
            printOdd(n);
        }
        else
        {
            printEven(n);
        }
    }
    return 0;
}