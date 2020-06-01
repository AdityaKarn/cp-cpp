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

lli D[10001];
int n;

int diff(int i, int j, int k, int l, int sum1, int sum2)
{

    int sum1 = 0, sum2 = 0;

    for (int a = i; a <= j; a++)
    {
        sum1 += D[a];
    }

    for (int a = k; a <= l; a++)
    {
        sum2 += D[a];
    }

    
}

int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        cin >> n;

        for (int i = 0; i < n; i++)
        {
            cin >> D[i];
        }
    }
    return 0;
}