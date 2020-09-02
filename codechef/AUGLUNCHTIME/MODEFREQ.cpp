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
    int t;
    cin >> t;

    while (t--)
    {
        int n, a, min = INT_MAX, maxfreq = INT_MIN;
        cin >> n;
        map<int, int> freq, freqfreq;
        for (int i = 0; i < n; i++)
        {
            cin >> a;
            freq[a]++;
        }

        for (auto x : freq)
        {
            freqfreq[x.second]++;
        }

        for (auto y : freqfreq)
        {
            // cout << y.first << " " << y.second << " " << min << " " << maxfreq << "\n";
            if (y.second > maxfreq)
            {
                maxfreq = y.second;
                min = y.first;
            }
        }

        cout << min << "\n";
    }

    return 0;
}