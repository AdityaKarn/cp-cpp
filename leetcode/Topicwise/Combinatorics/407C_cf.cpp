#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int maxd = 1e5 + 100;
const int mod = 1e9 + 7;
typedef long long LL;
int n, m;
long long a[maxd], c[maxd][105], ans[maxd][105];
void init()
{
    c[0][0] = 1ll;
    for (int i = 1; i < maxd; ++i)
    {
        c[i][0] = 1ll;
        for (int j = 1; j <= i && j < 105; ++j)
        {
            c[i][j] = (1ll * c[i - 1][j - 1] + c[i - 1][j]) % mod;
        }
    }
}
int main()
{

    init();
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i++)
        scanf("%lld", &a[i]);
    for (int j = 1; j <= m; j++)
    {
        int l, r, k;
        scanf("%d %d %d", &l, &r, &k);
        //
        for (int i = 0; i <= k; i++)
            ans[l][i] = (1ll * ans[l][i] + c[k][k - i]) % mod;
        for (int i = 0; i <= k; i++)
            ans[r + 1][i] = (1ll * ans[r + 1][i] - c[r - l + k + 1][k - i]) % mod;
    }
    for (int i = 1; i < n; ++i)
        for (int j = 101; j >= 1; --j)
            ans[i + 1][j - 1] = (1ll * ans[i + 1][j - 1] + ans[i][j] + ans[i][j - 1]) % mod;
    for (int i = 1; i <= n; ++i)
        printf("%lld ", ((ans[i][0] + a[i]) % mod + mod) % mod);
    return 0;
}