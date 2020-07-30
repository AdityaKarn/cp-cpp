#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
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

int returnSum(lli a)
{
    int res = 0;

    lli temp = a;

    while (temp)
    {
        res += temp % 10;
        temp /= 10;
    }
    return res;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int t, n;
    lli curMor, curChef;

    cin >> t;

    while (t--)
    {
        int morty = 0, chef = 0;
        cin >> n;

        for (int i = 0; i < n; i++)
        {
            cin >> curChef >> curMor;

            if (returnSum(curChef) > returnSum(curMor))
            {
                chef++;
            }
            else if (returnSum(curChef) < returnSum(curMor))
            {
                morty++;
            }
            else if (returnSum(curChef) == returnSum(curMor))
            {
                chef++;
                morty++;
            }
        }

        if (morty < chef)
        {
            cout << 0 << " " << chef << "\n";
        }
        else if (morty > chef)
        {
            cout << 1 << " " << morty << "\n";
        }
        else if (morty == chef)
        {
            cout << 2 << " " << chef << "\n";
        }
    }
}