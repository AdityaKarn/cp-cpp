#include <bits/stdc++.h>

#define REP(i, n) for (int i = 1; i <= n; i++)
#define trace1(x) cerr << #x << ": " << x << "\n"
#define trace2(x, y) cerr << #x << ": " << x << " | " << #y << ": " << y << "\n"
#define trace3(x, y, z) cerr << #x << ":" << x << " | " << #y << ": " << y << " | " << #z << ": " << z << "\n"
#define trace4(a, b, c, d) cerr << #a << ": " << a << " | " << #b << ": " << b << " | " << #c << ": " << c << " | " << #d << ": " << d << "\n"
#define trace5(a, b, c, d, e) cerr << #a << ": " << a << " | " << #b << ": " << b << " | " << #c << ": " << c << " | " << #d << ": " << d << " | " << #e << ": " << e << "\n"
#define mod 1000000007
#define pb push_back
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

struct node
{
    int ar[3];
};

node st[4 * MAX];
int lz[4 * MAX];

void shift(int v)
{
    int a = st[v].ar[2];
    st[v].ar[2] = st[v].ar[1];
    st[v].ar[1] = st[v].ar[0];
    st[v].ar[0] = a;
}

void update(int si, int ss, int se, int qs, int qe)
{
    if (lz[si] != 0)
    {
        int add = lz[si];
        lz[si] = 0;
        if (ss != se)
        {
            lz[2 * si] += add;
            lz[2 * si + 1] += add;
        }
        add %= 3;
        for (int i = 0; i < add; i++)
        {
            shift(si);
        }
    }
    if (ss > qe || se < qs)
        return;

    if (ss >= qs && se <= qe)
    {
        shift(si);
        if (ss != se)
        {
            lz[2 * si]++;
            lz[2 * si + 1]++;
        }
        return;
    }

    int mid = (ss + se) / 2;
    update(2 * si, ss, mid, qs, qe);
    update(2 * si + 1, mid + 1, se, qs, qe);

    st[si].ar[0] = st[2 * si].ar[0] + st[2 * si + 1].ar[0];
    st[si].ar[1] = st[2 * si].ar[1] + st[2 * si + 1].ar[1];
    st[si].ar[2] = st[2 * si].ar[2] + st[2 * si + 1].ar[2];
}

int query(int si, int ss, int se, int qs, int qe)
{
    if (lz[si] != 0)
    {
        int add = lz[si];
        lz[si] = 0;
        if (ss != se)
        {
            lz[2 * si] += add;
            lz[2 * si + 1] += add;
        }
        add %= 3;
        for (int i = 0; i < add; i++)
        {
            shift(si);
        }
    }

    if (ss > qe || se < qs)
    {
        return 0;
    }

    if (ss >= qs && se <= qe)
    {
        return st[si].ar[0];
    }

    int mid = (ss + se) / 2;
    int l = query(2 * si, ss, mid, qs, qe);
    int r = query(2 * si + 1, mid + 1, se, qs, qe);

    return l + r;
}
void build(int si, int ss, int se)
{
    if (ss == se)
    {
        st[si].ar[0] = 1;
        st[si].ar[1] = 0;
        st[si].ar[2] = 0;
        return;
    }

    int mid = (ss + se) / 2;
    build(2 * si, ss, mid);
    build(2 * si + 1, mid + 1, se);
    st[si].ar[0] = st[2 * si].ar[0] + st[2 * si + 1].ar[0];
    st[si].ar[1] = st[2 * si].ar[1] + st[2 * si + 1].ar[1];
    st[si].ar[2] = st[2 * si].ar[2] + st[2 * si + 1].ar[2];
}

void solveTestCases()
{
    int n, q;
    cin >> n >> q;

    build(1, 1, n);

    while (q--)
    {
        int c, a, b;
        cin >> c >> a >> b;

        if (c == 0)
        {
            update(1, 1, n, a + 1, b + 1);
        }
        else
        {
            cout << query(1, 1, n, a + 1, b + 1) << "\n";
        }
    }
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