#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
#include <string>
#include <cstring>
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

string caseSort(string s, int n)
{
    string lower, upper;

    // 0 will represent lowercase 1 will represent uppercase
    int first = 0;
    int len = 0;
    vector<pair<int, int>> posLen;

    for (int i = 0; i < n; i++)
    {
        if (isupper(s[i]) && first == 0)
        {
            upper += s[i];
            posLen.push_back({first, len});
            first = 1;
            len = 1;
        }
        else if (isupper(s[i]) && first == 1)
        {
            upper += s[i];
            len++;
        }
        else if (islower(s[i]) && first == 0)
        {
            lower += s[i];
            len++;
        }
        else if (islower(s[i]) && first == 1)
        {
            lower += s[i];
            posLen.push_back({first, len});
            first = 0;
            len = 1;
        }
    }
    posLen.push_back({first, len});

    sort(lower.begin(), lower.end(), greater<char>());
    sort(upper.begin(), upper.end(), greater<char>());

    string res;
    for (int i = 0; i < posLen.size(); i++)
    {

        // cout << "getting here";

        // cout << posLen[i].first << " " << posLen[i].second << "\n";

        if (posLen[i].first == 0)
        {
            int size = posLen[i].second;

            for (int k = 0; k < size; k++)
            {
                res += lower.back();
                lower.pop_back();
            }
        }

        if (posLen[i].first == 1)
        {
            int size = posLen[i].second;

            for (int k = 0; k < size; k++)
            {
                res += upper.back();
                upper.pop_back();
            }
        }
    }

    return res;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n;
    string s;
    cin >> n >> s;
    // cout << lower << "\n"
    //      << upper;
    caseSort(s, n);
    return 0;
}