#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
#include <cstring>
#include <iomanip>
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
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    char s1[15], s2[15];

    cin >> s1 >> s2;

    int n = strlen(s1);

    int answerPosition = 0;
    for (int i = 0; i < n; i++)
        answerPosition += (s1[i] == '+' ? 1 : -1);

    int finalPosition = 0;
    int moves = 0;
    for (int i = 0; i < n; i++)
    {
        if (s2[i] == '?')
            moves++;
        else
            finalPosition += (s2[i] == '+' ? 1 : -1);
    }

    int distance = answerPosition - finalPosition;
    double answer;
    if ((distance + moves) % 2 != 0 || moves < abs(distance))
        answer = 0;
    else
    {
        int m = (moves + abs(distance)) / 2;

        int c = 1;
        for (int i = 0; i < m; i++)
            c *= moves - i;
        for (int i = 2; i <= m; i++)
            c /= i;
        answer = (double)c / (1 << moves);
    }

    cout << fixed << setprecision(12) << answer << "\n";

    return 0;
}