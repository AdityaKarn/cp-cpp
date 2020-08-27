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

vector<pair<pair<int, int>, int>> segmentT(int arr[], int l, int r)
{
    vector<pair<pair<int, int>, int>> res;

    int minI = INT_MAX;
    int start = l;
    for (int i = l; i < r; i++)
    {
        if (arr[i] == 0)
        {
            pair<int, int> startEnd = {start, i - 1};

            if ((i - 1) - start > 1)
                res.push_back(make_pair(startEnd, minI));
            start = i + 1;
            minI = INT_MAX;
        }
        else
        {
            minI = min(minI, arr[i]);
        }
    }

    if (start != r - 1)
    {
        res.push_back(make_pair(make_pair(r - 1, start), minI));
    }

    return res;
}

int a[5000];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        cin >> a[n];
    }

    vector<pair<pair<int, int>, int>> seg = segmentT(a, 0, n);

    for (auto x : seg)
    {
        cout << x.first.first << " " << x.first.second << "\n";
        cout << x.second << "\n";
    }

    return 0;
}