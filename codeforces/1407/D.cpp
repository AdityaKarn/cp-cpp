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

#define IOS                  \
    ios::sync_with_stdio(0); \
    cin.tie(0);              \
    cout.tie(0);

using namespace std;
const int MAX = 3e5 + 1;

int h[MAX], dp[MAX], lle[MAX], lge[MAX], rle[MAX], rge[MAX];
vector<int> jumps[MAX];

int main()
{
    IOS;
    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        cin >> h[i];
        dp[i] = INF;
    }
    dp[0] = 0;
    vector<pair<int, int>> st;

    for (int i = 0; i < n; i++)
    {
        while (!st.empty() && st.back().first < h[i])
        {
            st.pop_back();
        }
        if (st.empty())
        {
            lge[i] = -1;
        }
        else
        {
            lge[i] = st.back().second;
        }
        st.push_back({h[i], i});
    }
    st.clear();

    // for (int i = 0; i < n; i++)
    // {
    //     cout << lge[i] << " ";
    // }

    for (int i = 0; i < n; i++)
    {
        while (!st.empty() && st.back().first > h[i])
        {
            st.pop_back();
        }

        if (st.empty())
        {
            lle[i] = -1;
        }
        else
        {
            lle[i] = st.back().second;
        }
        st.push_back({h[i], i});
    }
    st.clear();

    // for (int i = 0; i < n; i++)
    // {
    //     cout << lle[i] << " ";
    // }

    for (int i = n - 1; i >= 0; i--)
    {
        while (!st.empty() && st.back().first < h[i])
        {
            st.pop_back();
        }
        if (st.empty())
        {
            rge[i] = -1;
        }
        else
        {
            rge[i] = st.back().second;
        }
        st.push_back({h[i], i});
    }
    st.clear();
    // for (int i = 0; i < n; i++)
    // {
    //     cout << rge[i] << " ";
    // }
    for (int i = n - 1; i >= 0; i--)
    {
        while (!st.empty() && st.back().first > h[i])
        {
            st.pop_back();
        }
        if (st.empty())
        {
            rle[i] = -1;
        }
        else
        {
            rle[i] = st.back().second;
        }
        st.push_back({h[i], i});
    }
    st.clear();
    // for (int i = 0; i < n; i++)
    // {
    //     cout << rle[i] << " ";
    // }

    for (int i = 0; i < n; i++)
    {
        if (rle[i] != -1)
            jumps[i].push_back(rle[i]);
        if (rge[i] != -1)
            jumps[i].push_back(rge[i]);

        if (lle[i] != -1)
            jumps[lle[i]].push_back(i);
        if (lge[i] != -1)
            jumps[lge[i]].push_back(i);
    }

    for (int i = 0; i < n; i++)
    {
        // cout << i << ":> ";
        for (auto x : jumps[i])
        {
            dp[x] = min(dp[x], dp[i] + 1);
            // cout << x << " ";
        }
        // cout << "\n";
    }
    cout << dp[n - 1] << "\n";

    return 0;
}