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

int exist(string s, vector<int> p, string t, int n)
{
    int len = t.length();
    int l = 0, r = n;

    while (l <= r)
    {
        int mid = (l + r) / 2;

        string cur = s.substr(p[mid], p[mid] + n);

        int res = t.compare(cur.substr(0, len));

        if (res == 0)
        {
            return mid;
        }
        else if (res < 0)
        {
            r = mid - 1;
        }
        else
        {
            l = mid + 1;
        }
    }
    return -1;
}

void count_sort(vector<int> &p, vector<int> &c)
{

    int n = p.size();

    vector<int> cnt(n);
    for (auto x : c)
    {
        cnt[x]++;
    }
    vector<int> p_new(n);
    vector<int> pos(n);
    pos[0] = 0;

    for (int i = 1; i < n; i++)
    {
        pos[i] = pos[i - 1] + cnt[i - 1];
    }

    for (auto x : p)
    {
        int i = c[x];
        p_new[pos[i]] = x;
        pos[i]++;
    }
    p = p_new;
}
int main()
{
    string s;
    cin >> s;

    s += "$";
    int n = s.size();

    vector<int> p(n), c(n);
    {
        //k = 0
        vector<pair<char, int>> a(n);
        for (int i = 0; i < n; i++)
        {
            a[i] = {s[i],
                    i};
        }

        sort(a.begin(), a.end());
        for (int i = 0; i < n; i++)
        {
            p[i] = a[i].second;
        }

        c[p[0]] = 0;

        for (int i = 1; i < n; i++)
        {
            if (a[i].first == a[i - 1].first)
            {
                c[p[i]] = c[p[i - 1]];
            }
            else
            {
                c[p[i]] = c[p[i - 1]] + 1;
            }
        }
    }
    //k>0

    int k = 0;

    while ((1 << k) < n)
    {
        for (int i = 0; i < n; i++)
        {
            p[i] = (p[i] - (1 << k) + n) % n;
        }

        count_sort(p, c);

        vector<int> c_new(n);
        c_new[p[0]] = 0;

        for (int i = 1; i < n; i++)
        {
            pair<int, int> prev = {c[p[i - 1]],
                                   c[(p[i - 1] + (1 << k)) % n]};
            pair<int, int> now = {c[p[i]],
                                  c[(p[i] + (1 << k)) % n]};
            if (now == prev)
            {
                c_new[p[i]] = c_new[p[i - 1]];
            }
            else
            {
                c_new[p[i]] = c_new[p[i - 1]] + 1;
            }
        }
        c = c_new;
        k++;
    }
    int que;
    cin >> que;

    while (que--)
    {
        string t;
        cin >> t;
        int pos = exist(s, p, t, n);
        int temppos = pos;
        int len = t.length();
        int countsub = 1;
        //forward search
        if (pos != -1)
        {
            while (pos + 1 < n)
            {
                pos++;
                string cur = s.substr(p[pos], p[pos] + n);
                int res = t.compare(cur.substr(0, len));

                if (res == 0)
                {
                    countsub++;
                }
                else
                {
                    break;
                }
            }
            while (pos - 1 >= 0)
            {
                temppos--;
                string cur = s.substr(p[temppos], p[temppos] + n);
                int res = t.compare(cur.substr(0, len));

                if (res == 0)
                {
                    countsub++;
                }
                else
                {
                    break;
                }
            }
        }
        if (pos == -1)
            cout << "0\n";
        else
            cout << countsub << "\n";
    }

    return 0;
}