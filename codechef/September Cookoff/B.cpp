#include <iostream>
#include <vector>
#include <algorithm>
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
#define IOS                  \
    ios::sync_with_stdio(0); \
    cin.tie(0);              \
    cout.tie(0);

using namespace std;

void solveTestCases()
{
    int n, k;
    cin >> n >> k;

    string s;
    cin >> s;

    int res = 0;
    vector<int> contiguousZeros;

    bool zerosStart = (s[0] == '0');
    int size = 0;
    int startzeros = 0, endzeros = 0;
    int l, r;

    for (char ch : s)
    {
        if (ch == '0')
        {
            res++;
        }
    }

    for (int i = 0; i < n; i++)
    {
        if (s[i] == '0')
        {
            startzeros++;
        }
        else
        {
            l = i;
            break;
        }
    }
    for (int i = n - 1; i >= 0; i--)
    {
        if (s[i] == '0')
        {
            endzeros++;
        }
        else
        {
            r = i;
            break;
        }
    }
    // cout << startzeros << "  " << endzeros << "\n";
    if (startzeros == n)
    {
        cout << "0\n";
        return;
    }

    for (int i = l; i <= r; i++)
    {
        char ch = s[i];
        if (ch == '0' && zerosStart == false)
        {

            zerosStart = true;
            size = 1;
        }
        else if (ch == '0' && zerosStart == true)
        {

            size++;
        }
        else if (ch == '1' && zerosStart == true)
        {
            zerosStart = false;
            contiguousZeros.push_back(size);
            size = 0;
        }
        else
        {
            continue;
        }
    }

    if (zerosStart == true)
    {
        contiguousZeros.push_back(size);
    }

    // for (auto s : contiguousZeros)
    // {
    //     cout << s << " ";
    // }

    sort(contiguousZeros.begin(), contiguousZeros.end());
    bool startUsed = false, endUsed = false;

    if (k % 2 == 1)
    {

        int biggestInBetween = 0;

        if (!contiguousZeros.empty())
        {
            biggestInBetween = max(biggestInBetween, contiguousZeros[contiguousZeros.size() - 1]);
        }
        int OptimalMove = biggestInBetween;
        if (startUsed == false)
        {
            OptimalMove = max(OptimalMove, startzeros);
        }
        if (endUsed == false)
        {
            OptimalMove = max(OptimalMove, endzeros);
        }

        if (OptimalMove == startzeros)
        {
            res -= startzeros;
            startUsed = true;
            k--;
        }
        else if (OptimalMove == endzeros)
        {
            res -= endzeros;
            endUsed = true;
            k--;
        }
    }
    while (k)
    {
        if (k >= 2)
        {
            if (!contiguousZeros.empty())
            {
                int biggestInBetween = contiguousZeros[contiguousZeros.size() - 1];
                int OptimalMove = biggestInBetween;
                if (startUsed == false)
                {
                    OptimalMove = max(OptimalMove, startzeros);
                }
                if (endUsed == false)
                {
                    OptimalMove = max(OptimalMove, endzeros);
                }
                // cout << "o " << OptimalMove << " ";
                if (OptimalMove == startzeros && startUsed == false)
                {
                    // cout << "a";
                    res -= startzeros;
                    startUsed = true;
                    k--;
                }
                else if (OptimalMove == endzeros && endUsed == false)
                {
                    // cout << "b";
                    res -= endzeros;
                    endUsed = true;
                    k--;
                }
                else
                {
                    res -= biggestInBetween;
                    contiguousZeros.pop_back();
                    k -= 2;
                }
            }
            else
            {
                int OptimalMove = 0;
                if (startUsed == false)
                {
                    OptimalMove = max(OptimalMove, startzeros);
                }
                if (endUsed == false)
                {
                    OptimalMove = max(OptimalMove, endzeros);
                }

                if (OptimalMove == startzeros && startUsed == false)
                {
                    res -= startzeros;
                    startUsed = true;
                    k--;
                }
                else if (OptimalMove == endzeros && endUsed == false)
                {
                    res -= endzeros;
                    endUsed = true;
                    k--;
                }
                else
                {
                    break;
                }
            }
        }
        else if (k == 1)
        {
            int Optimal = 0;
            if (startUsed == false)
            {
                Optimal = max(Optimal, startzeros);
            }
            if (endUsed == false)
            {
                Optimal = max(Optimal, endzeros);
            }
            res -= Optimal;
            k--;
        }
    }

    cout << res << "\n";
}

int main()
{
    // IOS;
    int t;
    cin >> t;

    while (t--)
    {
        solveTestCases();
    }

    return 0;
}