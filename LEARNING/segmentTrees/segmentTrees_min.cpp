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

int arr[] = {1, 2, -3};

int st[10];

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

    st[si] = min(st[2 * si], st[(2 * si) + 1]);
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

    st[si] = min(st[2 * si], st[(2 * si) + 1]);
}

int query(int si, int ss, int se, int qs, int qe)
{
    if (ss > qe || se < qs)
        return INF;

    if (ss >= qs && se <= qe)
        return st[si];

    int mid = (se + ss) / 2;

    int l = query(2 * si, ss, mid, qs, qe);
    int r = query(2 * si + 1, mid + 1, se, qs, qe);

    return min(l, r);
}

int main()
{

    buildTree(1, 1, 2);

    cout << query(1, 1, 2, 0, 1);
}
