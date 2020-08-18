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

vector<string> letterCombinations(string digits)
{
    vector<string> mapping = {'abc', 'def', 'ghi', 'jkl', 'mno', 'pqr', 'tuv', 'wxyz'};

    vector<string> res;

    string toAdd;
    for (char ch : digits)
    {
        string temp = mapping[ch - '0' - 1];

        if (res.empty())
        {
            for (char a : temp)
            {
                string first;
                first += a;
                res.push_back(first);
            }
        }
        else
        {

            string
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    return 0;
}