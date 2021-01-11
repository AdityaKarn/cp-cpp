#include <bits/stdc++.h>
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
const int MAX = (int)1e4 + 5;
void solveTestCases()
{
    int n;
    string s;
    cin >> n;
    cin >> s;

    if (n % 4)
    {
        cout << "===\n";
        return;
    }

    int reqByEach = n / 4;

    int freq[5]; //A = 0, C = 1, G = 2, T = 3
    int maxfreq = 0;
    int queM = 0;

    for (int i = 0; i < 4; i++)
    {
        freq[i] = 0;
    }

    for (char ch : s)
    {
        if (ch == 'A')
        {
            freq[0]++;
            maxfreq = max(maxfreq, freq[0]);
        }
        else if (ch == 'C')
        {
            freq[1]++;
            maxfreq = max(maxfreq, freq[1]);
        }
        else if (ch == 'G')
        {
            freq[2]++;
            maxfreq = max(maxfreq, freq[2]);
        }
        else if (ch == 'T')
        {
            freq[3]++;
            maxfreq = max(maxfreq, freq[3]);
        }
        else
        {
            queM++;
        }
    }

    for (int i = 0; i < 4; i++)
    {
        if (freq[i] > reqByEach)
        {
            cout << "===\n";
            return;
        }
    }

    int reQ[5];

    for (int i = 0; i < 4; i++)
    {
        reQ[i] = reqByEach - freq[i];
    }

    for (char ch : s)
    {
        if (ch == '?')
        {
            if (reQ[0] != 0)
            {
                cout << "A";
                reQ[0]--;
            }
            else if (reQ[1] != 0)
            {
                cout << "C";
                reQ[1]--;
            }
            else if (reQ[2] != 0)
            {
                cout << "G";
                reQ[2]--;
            }
            else if (reQ[3] != 0)
            {
                cout << "T";
                reQ[3]--;
            }
        }
        else
        {
            cout << ch;
        }
    }
    cout << "\n";
}

int main()
{
    IOS;
    int t;
    t = 1;

    while (t--)
    {
        solveTestCases();
    }

    return 0;
}