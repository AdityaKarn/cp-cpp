#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
#include <map>
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

    int cur;
    int n, m;
    map<int, int> boys, girls;

    cin >> n;

    for (int i = 0; i < n; i++)
    {
        cin >> cur;
        boys[cur]++;
    }

    cin >> m;

    for (int i = 0; i < m; i++)
    {
        cin >> cur;
        girls[cur]++;
    }

    int res = 0;

    for (auto x : boys)
    {
        int current_level = x.first;
        int noOfBoys = x.second;

        if (girls.find(current_level - 1) != girls.end())
        {
            // cout << "currently searching" << current_level << "and girls level at " << current_level - 1 << "\n";
            int noOfgirlsOneLess = girls[current_level - 1];

            int noOfPairs = min(noOfBoys, noOfgirlsOneLess);
            // cout << current_level << " " << noOfBoys << " " << noOfgirlsOneLess << " " << noOfPairs << "\n";

            boys[current_level] -= noOfPairs;
            girls[current_level - 1] -= noOfPairs;
            noOfBoys -= noOfPairs;
            res += noOfPairs;
        }

        if (noOfBoys > 0 && girls.find(current_level) != girls.end())
        {
            // cout << "currently searching" << current_level << "and girls level at " << current_level << "\n";

            int noOfgirls = girls[current_level];

            int noOfPairs = min(noOfBoys, noOfgirls);
            // cout << current_level << " " << noOfBoys << " " << noOfgirls << " " << noOfPairs << "\n";

            boys[current_level] -= noOfPairs;
            girls[current_level] -= noOfPairs;

            noOfBoys -= noOfPairs;
            res += noOfPairs;
        }
        if (noOfBoys > 0 && girls.find(current_level + 1) != girls.end())
        {
            // cout << "currently searching" << current_level << "and girls level at " << current_level + 1 << "\n";

            int noOfgirls = girls[current_level + 1];

            int noOfPairs = min(noOfBoys, noOfgirls);
            // cout << current_level << " " << noOfBoys << " " << noOfgirls << " " << noOfPairs << "\n";

            boys[current_level] -= noOfPairs;
            girls[current_level + 1] -= noOfPairs;
            noOfBoys -= noOfPairs;
            res += noOfPairs;
        }
    }

    cout << res;
    return 0;
}