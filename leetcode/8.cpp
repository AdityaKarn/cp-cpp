#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <cstring>
#include <math.h>
#include <climits>
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

int myAtoi(string str)
{
    string finalStr;
    bool isNegative = false;
    bool numberFound = false;
    for (int i = 0; i < str.size(); i++)
    {
        char ch = str[i];

        if (ch == '-')
        {
            isNegative = true;
        }
        else if (isalnum(ch))
        {

            if (ch == '1' || ch == '2' || ch == '3' || ch == '4' || ch == '5' || ch == '6' || ch == '7' || ch == '8' || ch == '9' || ch == '0')
            {
                numberFound = true;
                finalStr += ch;
            }
            else if (numberFound == false)
            {
                return 0;
            }
        }
    }
    // cout << finalStr.size() << "\n";

    // // cout << finalStr[0] - '0';

    int sizeOfDigit = finalStr.size();
    lli res = 0;
    int i = 0;
    while (sizeOfDigit)
    {
        res += (pow(10, sizeOfDigit - 1) * (int)(finalStr[i] - '0'));
        sizeOfDigit--;
        i++;
    }

    if (isNegative)
        res *= -1;

    if (res > INT_MAX)
    {
        return INT_MAX;
    }
    else if (res < INT_MAX)
    {
        return INT_MIN;
    }
    return res;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cout << myAtoi("-91283472332");

    return 0;
}