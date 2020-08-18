//Two pointer method

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
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

int maxArea(vector<int> &height)
{
    int n = height.size(), maxArea = 0;
    int p1 = 0, p2 = n - 1;

    while (p1 < p2)
    {
        int currArea = min(height[p1], height[p2]) * (p2 - p1);

        maxArea = max(maxArea, currArea);

        if (height[p2] < height[p1])
        {
            p2--;
        }
        else
        {
            p1++;
        }
    }
    return maxArea;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    vector<int> height = {1, 8, 6, 2, 5, 4, 8, 3, 7};
    cout << maxArea(height);
    return 0;
}