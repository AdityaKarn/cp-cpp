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

string longestPalindrome(string s)
{
    int maxlength = 0, j;
    int n = s.length();
    string ans;

    for (int i = 0; i < n; i++)
    {
        j = 0;
        while (i - j >= 0 && i + j < n && s[i - j] == s[i + j])
        {
            if (maxlength < 2 * j + 1)
            {
                maxlength = 2 * j + 1;
                ans = s.substr(i - j, 2 * j + 1);
            }
            j++;
        }

        j = 1;
        while (i - j + 1 >= 0 && i + j < n && s[i - j + 1] == s[i + j])
        {
            if (maxlength < 2 * j)
            {
                maxlength = 2 * j;
                ans = s.substr(i - j + 1, 2 * j);
            }
            j++;
        }
    }
    return ans;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    string s;

    cin >> s;
    cout << longestPalindrome(s);

    return 0;
}