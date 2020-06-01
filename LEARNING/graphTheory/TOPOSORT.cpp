#include <iostream>
#include <vector>
#include <algorithm>
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

vector<int> ar[10001];
vector<int> res;
int in[10001];

bool Kahn(int n)
{
    priority_queue<int, vector<int>, greater<int>> pq;

    for (int i = 1; i <= n; i++)
    {
        if (in[i] == 0)
        {
            pq.push(i);
        }
    }

    while (!pq.empty())
    {
        int current = pq.top();
        res.push_back(current);
        pq.pop();

        for (int child : ar[current])
        {
            in[child]--;

            if (in[child] == 0)
            {
                pq.push(child);
            }
        }
    }

    return res.size() == n;
}

int main()
{
    int n, m, a, b;

    cin >> n >> m;

    for (int i = 0; i < m; i++)
    {
        cin >> a >> b;
        ar[a].push_back(b);
        in[b]++;
    }

    if (!Kahn(n))
    {
        cout << "Sandro fails.";
    }
    else
    {
        for (int node : res)
        {
            cout << node << " ";
        }
    }

    return 0;
}