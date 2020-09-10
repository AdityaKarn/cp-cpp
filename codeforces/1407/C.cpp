// a mod b > b mod a <=> b > a

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

int ask(int x, int y)
{
    cout << "? " << x + 1 << " " << y + 1 << "\n";

    int res;
    cin >> res;

    return res;
}

int main()
{

    int n;
    cin >> n;

    vector<int> a(n, -1);

    int maxIndex = 0;

    for (int i = 1; i < n; i++)
    {
        int p = ask(maxIndex, i);
        int q = ask(i, maxIndex);

        if (p > q)
        {
            a[maxIndex] = p;
            maxIndex = i;
        }
        else
        {
            a[i] = q;
        }
    }

    a[maxIndex] = n;

    cout << "! ";

    for (int i = 0; i < n; i++)
    {
        cout << a[i] << " ";
    }
    cout << "\n";
    return 0;
}