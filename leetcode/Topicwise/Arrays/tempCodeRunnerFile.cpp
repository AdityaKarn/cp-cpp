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

long long int findSubArr(int arr[], int n)
{

    for (int i = 0; i < n; i++)
    {
        arr[i] = (arr[i] == 0) ? -1 : arr[i];
    }

    unordered_map<int, vector<int>> map;

    vector<pair<int, int>> res;
    int sum = 0;

    for (int i = 0; i < n; i++)
    {
        sum += arr[i];

        if (sum == 0)
        {
            res.push_back({0, i});
        }

        if (map.find(sum) != map.end())
        {
            vector<int> vc = map[sum];

            for (auto it = vc.begin(); it != vc.end(); it++)
            {
                res.push_back({*it + 1, i});
            }
        }

        map[sum].push_back(i);
    }

    return res.size();
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int arr[] = {1, 0, 0, 1, 0, 1, 1};
    int n = sizeof(arr) / sizeof(arr[0]);

    cout << findSubArr(arr, n);
    return 0;
}