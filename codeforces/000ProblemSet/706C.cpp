#include <bits/stdc++.h>

#define REP(i, n) for (int i = 0; i < n; i++)
#define trace1(x) cerr << #x << ": " << x << "\n"
#define trace2(x, y) cerr << #x << ": " << x << " | " << #y << ": " << y << "\n"
#define trace3(x, y, z) cerr << #x << ":" << x << " | " << #y << ": " << y << " | " << #z << ": " << z << "\n"
#define trace4(a, b, c, d) cerr << #a << ": " << a << " | " << #b << ": " << b << " | " << #c << ": " << c << " | " << #d << ": " << d << "\n"
#define trace5(a, b, c, d, e) cerr << #a << ": " << a << " | " << #b << ": " << b << " | " << #c << ": " << c << " | " << #d << ": " << d << " | " << #e << ": " << e << "\n"
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
const int MAX = (int)1e5 + 5;

int c[MAX];
int dp[MAX][2];
void solveTestCases()
{
    int n;
    cin>>n;

    REP(i, n){
        cin>>c[i];
    }

    vector<string> Q(n);

    for(int i = 1; i<=n; i++){

        dp[i][0] = INT_MAX;
        dp[i][1] = INT_MAX;
    }
    dp[0][0] = 0;
    dp[0][1] = 0;
    for(int i = 1; i<=n; i++){

        if(Q[i] > Q[i-1]){
            dp[i][0] = min(dp[i][0], dp[i-1][0]);
            dp[i][0] = min(dp[i][0], dp[i-1][1]);
        }

        string rev_s = reverse(Q[i].begin(), Q[i].end());

        if(rev_s > Q[i-1]){
            dp[i][1] = min(dp[i][0], dp[i-1][0] + c[i]);
            dp[i][1] = min(dp[i][0], dp[i-1][1] + c[i]);

        }
    }

    cout<<min(dp[n][0], dp[n][1])<<"\n";


}

int main()
{
    IOS;
    int t;
    t =1;
    while (t--)
    {
        solveTestCases();
    }

    return 0;
}