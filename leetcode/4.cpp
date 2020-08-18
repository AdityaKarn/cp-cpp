
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
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

double findMedianSortedArrays(vector<int> &nums1, vector<int> &nums2)
{

    if (nums1.size() > nums2.size())
    {
        return findMedianSortedArrays(nums2, nums1);
    }

    int start = 0, end = nums1.size();
    int pa, pb;

    while (start <= end)
    {

        pa = start + (end - start) / 2;
        pb = (nums1.size() + nums2.size() + 1) / 2 - pa;

        double mxlx = (pa == 0 ? INT_MIN : nums1[pa - 1]);
        double mnlx = (pa == nums1.size() ? INT_MAX : nums1[pa]);

        double mxry = (pb == 0 ? INT_MIN : nums2[pb - 1]);
        double mnry = (pb == nums2.size() ? INT_MAX : nums2[pb]);

        if (mxlx <= mnry && mxry <= mnlx)
        {
            if ((nums1.size() + nums2.size()) % 2 == 0)
            {
                return (max(mxlx, mxry) + min(mnlx, mnry)) / 2;
            }
            else
            {
                return max(mxlx, mxry);
            }
        }

        else if (mxlx > mnry)
        {
            end = pa - 1;
        }
        else
        {
            start = pa + 1;
        }
    }

    return -1;
}

int main()
{

    vector<int> a = {1, 2};
    vector<int> b = {3};

    cout << findMedianSortedArrays(a, b);
}