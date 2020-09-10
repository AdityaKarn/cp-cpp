#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
#include <map>
#define REP(i, n) for (int i = 1; i <= n; i++)

#define MOD 1000000007
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
    int n;
    cin >> n;
    vector<lli> B(n);
    map<lli, lli> freq;

    lli maxI = INT_MIN, minI = INT_MAX;

    for (int i = 0; i < n; i++)
    {
        cin >> B[i];
        maxI = max(B[i], maxI);
        minI = min(B[i], minI);
        freq[B[i]]++;
    }

    cout << maxI - minI << " ";
    if (maxI == minI)
    {
        cout << (freq[minI] * (freq[minI] - 1)) / 2;
    }
    else
        cout << freq[maxI] * freq[minI];
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