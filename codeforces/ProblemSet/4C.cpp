#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
#include <unordered_map>
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

    int n;
    string s;
    cin >> n;
    unordered_map<string, int> db;
    while (n--)
    {
        cin >> s;

        if (db.find(s) == db.end())
        {
            cout << "OK\n";
            db[s]++;
        }
        else
        {
            cout << s << db[s]++;
            cout << "\n";
        }
    }
    return 0;
}