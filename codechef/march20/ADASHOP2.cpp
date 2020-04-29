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

int main()
{
    int t, c, r;
    cin >> t;
    vector<pair<int, int>> moves;

    while (t--)
    {
        cin >> r >> c;

        moves.pb({(r + c) / 2, (r + c) / 2});
        moves.pb({1, 1});

        for (int i = 2; i <= 4; i++)
        {

            moves.pb({i, i});
            moves.pb({2 * i - 1, 1});
            moves.pb({1, 2 * i - 1});
            moves.pb({i, i});
        }

        for (int i = 5; i <= 7; i++)
        {

            moves.pb({i, i});
            moves.pb({2 * i - 8, 8});
            moves.pb({8, 2 * i - 8});
            moves.pb({i, i});
        }

        moves.pb({8, 8});

        cout << moves.size() << endl;

        for (int i = 0; i < moves.size(); i++)
        {
            cout << moves[i].first << " " << moves[i].second << endl;
        }
    }

    return 0;
}