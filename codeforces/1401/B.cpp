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
    int t;
    lli x1, y1, z1, x2, y2, z2;
    cin >> t;

    while (t--)
    {
        cin >> x1 >> y1 >> z1;
        cin >> x2 >> y2 >> z2;

        lli res = 0;
        // pairing a-2 with b-1
        lli temp = min(z1, y2);
        res += 2 * (temp);
        z1 -= temp;
        y2 -= temp;

        //pairing a-1 with b-0
        temp = min(y1, x2);
        y1 -= temp;
        x2 -= temp;

        //a-0 with b-2
        temp = min(x1, z2);
        x1 -= temp;
        z2 -= temp;

        //a-2 with b-2 and b-0
        temp = min(z1, x2);
        z1 -= temp;
        x2 -= temp;

        temp = min(z1, z2);
        z1 -= temp;
        z2 -= temp;

        //a1-b-1
        temp = min(y1, y2);
        y1 -= temp;
        y2 -= temp;

        //a-0 with b-1 and b-0
        temp = min(x1, x2);
        x1 -= temp;
        x2 -= temp;

        temp = min(x1, y2);
        x1 -= temp;
        y2 -= temp;

        // if remaining subtrainging a-1 and b-2
        temp = min(y1, z2);
        res -= 2 * (temp);

        cout << res << "\n";
    }

    return 0;
}