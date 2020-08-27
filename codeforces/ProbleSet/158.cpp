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

    int n;

    int freq[5];

    cin >> n;

    int cur;

    REP(i, 4)
    {
        freq[i] = 0;
    }

    REP(i, n)
    {
        cin >> cur;
        freq[cur]++;
    }

    int res = 0;

    res += freq[4];

    int threeAndOne = min(freq[3], freq[1]);
    res += threeAndOne;
    freq[3] -= threeAndOne;
    freq[1] -= threeAndOne;

    int twoAndTwo = freq[2] % 2;
    res += freq[2] / 2;
    freq[2] = twoAndTwo;

    int twoAndOne = min(freq[2], freq[1]);
    res += twoAndOne;
    freq[1] -= twoAndOne;
    freq[2] -= twoAndOne;
    //somwe 1s can still be added
    freq[1] -= min(twoAndOne, freq[1]);

    int oneAndOne = freq[1] % 4;
    res += freq[1] / 4;
    freq[1] = oneAndOne;

    if (freq[1])
    {
        res++;
    }
    res += freq[2];
    res += freq[3];

    cout
        << res << "\n";

    return 0;
}