#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <set>
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

vector<vector<int>> threeSum(vector<int> &nums)
{
    sort(nums.begin(), nums.end());
    set<vector<int>> check;
    int size = nums.size() - 1;
    vector<vector<int>> ans;

    if (nums.size() < 3)
    {
        return ans;
    }
    int j, k;

    for (int i = 0; i < size - 1; i++)
    {
        j = i + 1;
        k = size;

        while (j < k)
        {
            int sum = nums[i] + nums[j] + nums[k];

            if (sum == 0)
            {
                vector<int> v = {nums[i], nums[j], nums[k]};
                if (check.find(v) == check.end())
                {
                    ans.push_back(v);
                    check.insert(v);
                }

                j++;
                k--;
            }
            else if (sum > 0)
            {
                k--;
            }
            else
            {
                j++;
            }
        }
    }

    return ans;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    vector<int> v = {-1, 0, 1, 2, -1, -4};
    vector<vector<int>> res = threeSum(v);
    for (int i = 0; i < res.size(); i++)
    {
        for (auto x : res[i])
        {
            cout << x << " ";
        }
        cout << "\n";
    }

    return 0;
}