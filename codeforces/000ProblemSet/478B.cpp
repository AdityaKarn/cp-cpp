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

void solveTestCases()
{
    lli n, m;
    cin >> n >> m;

    //for minimal friends
    lli moreFriends = (n / m) + 1;
    lli lessFriends = (n / m);

    moreFriends = ((moreFriends) * (moreFriends - 1)) / 2;
    lessFriends = ((lessFriends) * (lessFriends - 1)) / 2;

    cout << (n % m) * moreFriends + (m - n % m) * lessFriends << " ";
    // for maximal friends
    lli equalFriends = n - m;
    equalFriends++;

    cout << ((equalFriends) * (equalFriends - 1)) / 2;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t;
    t = 1;

    while (t--)
    {
        solveTestCases();
    }

    return 0;
}