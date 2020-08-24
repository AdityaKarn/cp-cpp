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

int numTeams(vector<int> &rating)
{
    int n = rating.size();
    int res = 0;
    for (int i = 0; i < n - 2; i++)
    {
        for (int j = i + 1; j < n - 1; j++)
        {
            for (int k = j + 1; k < n; k++)
            {
                if (rating[i] > rating[j] && rating[j] > rating[k])
                {
                    res++;
                }
                if (rating[i] < rating[j] && rating[j] < rating[k])
                {
                    res++;
                }
            }
        }
    }
    return res;
}

int main()
{
    vector<int> rating = {2, 5, 3, 4, 1};
    cout << numTeams(rating);
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    return 0;
}