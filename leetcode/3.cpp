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

int lengthOfLongestSubstring(string s)
{

    int count[256] = {0};
    int maxSize = 0;

    int i = 0, j = 0;

    while (j < s.length())
    {

        count[s[j]]++;

        while (count[s[j]] > 1)
        {

            count[s[i]]--;
            i++;
        }

        j++;
        maxSize = max(maxSize, j - i);
    }
    return maxSize;
}

int main()
{
    string s;
    cin >> s;
    cout << lengthOfLongestSubstring(s);

    return 0;
}