//For minimum query
#include <iostream>
#include <vector>
#include <algorithm>

#define REP(i, n) for (int i = 1; i <= n; i++)

#define mod 1000000007
#define pb push_back
#define ii pair<int, int>
#define vi vector<int>
#define vii vector<ii>
#define lli long long int
#define INF 1000000000

using namespace std;

int arr[] = {1, 3, -2, 8, -7};

int st[21];

void update(int si, int ss, int se, int qi)
{
    if (ss == se)
    {
        st[si] = arr[ss];
        return;
    }

    int mid = (ss + se) / 2;

    if (qi <= mid)
        update(2 * si, ss, mid, qi);
    else
        update(2 * si + 1, mid + 1, se, qi);

    st[si] = st[2 * si] + st[(2 * si) + 1];
}

void buildTree(int si, int ss, int se)
{
    if (ss == se)
    {
        st[si] = arr[ss];
        return;
    }

    int mid = (ss + se) / 2;

    buildTree(2 * si, ss, mid);
    buildTree(2 * si + 1, mid + 1, se);

    st[si] = st[2 * si] + st[(2 * si) + 1];
}

int query(int si, int ss, int se, int l, int r)
{
    if (l > r)
        return 0;

    if (l == ss && r == se)
        return st[si];

    int mid = (se + ss) / 2;

    int le = query(2 * si, ss, mid, l, min(r, mid));
    int ri = query(2 * si + 1, mid + 1, se, max(l, mid + 1), r);

    return le + ri;
}

int main()
{

    buildTree(1, 1, 5);

    int l, r;

    cin >> l >> r;

    cout << endl
         << query(1, 1, 5, l, r);
}