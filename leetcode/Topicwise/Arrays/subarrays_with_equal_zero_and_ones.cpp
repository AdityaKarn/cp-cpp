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
long long int countSubarrWithEqualZeroAndOne(int arr[], int N)
{
    unordered_map<int, int> um;
    int curr_sum = 0;

    for (int i = 0; i < N; i++)
    {
        curr_sum += (arr[i] == 0) ? -1 : arr[i];
        um[curr_sum]++;
    }

    long long int count = 0;

    for (auto itr = um.begin(); itr != um.end(); itr++)
    {

        // If there are more than one prefix subarrays
        // with a particular sum
        cout << itr->first << " " << itr->second << "\n";
        if (itr->second > 1)
            count += ((itr->second * (itr->second - 1)) / 2);

        cout << "count " << count << "\n";
    }

    if (um.find(0) != um.end())
    {
        count += um[0];
    }

    return count;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int arr[] = {1, 0, 0, 1, 0, 1, 1};
    int n = sizeof(arr) / sizeof(arr[0]);

    cout << countSubarrWithEqualZeroAndOne(arr, n);
    return 0;
}