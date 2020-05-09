#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
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
    int i = 1;
    string s;
    stack<char> op;
    while (true)
    {
        int open = 0, count = 0;
        cin >> s;
        cout << i++ << ". ";
        if (s[0] == '-')
        {
            break;
        }

        for (char ch : s)
        {
            if (ch == '{')
            {
                count++;
            }
            else if (ch == '}')
            {
                if (count == 0)
                {
                    count++;
                    open++;
                }
                else
                {
                    count--;
                }
            }
        }

        cout << count + (open >> 1) << endl;
    }
    return 0;
}