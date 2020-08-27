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

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n, m, a, b;

    cin >> n >> m >> a >> b;

    int price = 0;
    if (m * a >= b)
    {
        int noOfTicket = n / m;
        price += b * noOfTicket;

        n -= noOfTicket * m;

        price += min(n * a, b);
    }
    else
    {
        price += n * a;
    }

    cout << price;

    return 0;
}