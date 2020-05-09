#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>

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

lli histogram[100001];

lli getMaxArea(lli his[], int n)
{
    stack<int> s;
    int i = 0, tp;
    lli currArea = 0, maxArea = 0;

    while (i < n)
    {
        if (s.empty() || his[i] >= his[s.top()])
        {
            s.push(i++);
        }
        else
        {
            tp = s.top();
            s.pop();

            currArea = his[tp] * (s.empty() ? i : i - s.top() - 1);

            maxArea = max(maxArea, currArea);
        }
    }

    while (!s.empty())
    {
        tp = s.top();
        s.pop();

        currArea = his[tp] * (s.empty() ? i : i - s.top() - 1);

        maxArea = max(maxArea, currArea);
    }

    return maxArea;
}

int main()
{
    while (true)
    {
        int n;
        cin >> n;
        if (n == 0)
        {
            break;
        }

        for (int i = 0; i < n; i++)
        {
            cin >> histogram[i];
        }

        cout << getMaxArea(histogram, n) << endl;
    }
    return 0;
}