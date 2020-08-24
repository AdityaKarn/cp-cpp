#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
#include <queue>
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

void nearlySortedAlgo(int arr[], int n, int k)
{
    priority_queue<int, vector<int>, greater<int>> hp(arr, arr + k + 1);

    int index = 0;

    for (int i = k + 1; i < n; i++)
    {
        arr[index++] = hp.top();
        hp.pop();
        hp.push(arr[i]);
    }

    while (!hp.empty())
    {
        arr[index++] = hp.top();
        hp.pop();
    }

    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << "\n";
}

int main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;

    int arr[101];

    while (t--)
    {
        int n, k;

        cin >> n >> k;

        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
        }

        nearlySortedAlgo(arr, n, k);
    }

    return 0;
}