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

char gr[1001][1001];
bool visited[1001][1001];
int n, m;
lli a, b,c,d;
int dx[] = {0,0,1,-1};
int dy[] = {1, -1, 0,0};

void solveTestCases()
{
    cin >> n >> m;

    for (int i = 0; i < n; i++)
    {
        string s;
        cin >> s;
        for (int j = 0; j < m; j++)
        {
            gr[i][j] = s[j];
            if (s[j] == 'A')
            {
                a = i, b = j;
            }   
            if (s[j] == 'B')
            {
                c = i, d = j;
            }

            visited[i][j] = false;
        }
    }

    vector<vector<lli>> dist(n, vector<lli> (m, INF));

    dist[a][b] = 0;
    queue<pair<lli, lli>> q;

    q.push({a, b});


    while(!q.empty()){
        pair<lli, lli > u = q.front();
        q.pop();
        lli x = u.first, y = u.second;

        if(x == c && y == d){
            cout<<"YES\n";

            lli k = dist[x][y];

            cout<<k<<"\n";
            string ans;

            while(k!=0){
                if(x>0 && dist[x-1][y] == k-1){
                    ans.pb('D');
                    x--;
                }
                else if(x<n-1 && dist[x+1][y]== k-1){
                    ans.pb('U');
                    x++;

                }
                if(y>0 && dist[x][y-1] == k-1){
                    ans.pb('R');
                    y--;
                }
                else if(y<m-1 && dist[x][y+1]== k-1){
                    ans.pb('L');
                    y++;
                }
                k--;
            }

            reverse(ans.begin(), ans.end());
            cout<<ans<<"\n";
            return;
        }
        
        for(int j = 0; j<4; j++){

            int nx = x + dx[j], ny = y + dy[j];

            if(nx>=0 && nx<n && ny>=0 && ny<m && dist[nx][ny] == INF && gr[nx][ny] != '#'){
                dist[nx][ny] = dist[x][y] + 1;
                q.push({nx, ny});
            }
        }

    }
    cout<<"NO\n";


    
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