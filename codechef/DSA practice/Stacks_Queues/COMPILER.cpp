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

// bool isValid(string exp)
// {
//     stack<char> op;
//     bool p = true;
//     for (char ch : exp)
//     {

//         if (ch == '<')
//         {
//             op.push(ch);
//         }
//         else if (ch == '>')
//         {
//             if (!op.empty() && op.top() == '<')
//             {
//                 op.pop();
//             }
//             else
//             {
//                 p = false;
//             }
//         }
//     }

//     if (!op.empty())
//     {
//         p = false;
//     }

//     return p;
// }

int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        string s;

        cin >> s;
        int res = 0;
        int t = 0;

        for (int i = 0; i < s.size(); i++)
        {
            if (s[i] == '>')
            {
                t--;
            }
            else if (s[i] == '<')
            {
                t++;
            }

            if (t == 0)
            {
                res = i + 1;
            }
            else if (t < 0)
            {
                break;
            }
        }

        cout << res << "\n";
    }

    return 0;
}