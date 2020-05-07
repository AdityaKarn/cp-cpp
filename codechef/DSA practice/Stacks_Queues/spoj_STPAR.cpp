#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
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

int main()
{
    int current;
    while (true)
    {
        int n, cur, last, element;
        cin >> n;

        if (n == 0)
        {
            break;
        }

        queue<int> V;
        stack<int> free;

        for (int i = 0; i < n; i++)
        {
            cin >> cur;
            V.push(cur);
        }

        current = 1;

        while (!V.empty() || !free.empty())
        {
            if (!V.empty() && V.front() == current)
            {
                V.pop();
                current++;
            }
            else if (!free.empty() && free.top() == current)
            {
                free.pop();
                current++;
            }
            else if (!V.empty())
            {
                int s = V.front();
                V.pop();
                free.push(s);
            }
            else
            {
                break;
            }
        }

        if (current == n + 1)
        {
            cout << "yes\n";
        }
        else
        {
            cout << "no\n";
        }
    }
    return 0;
}
