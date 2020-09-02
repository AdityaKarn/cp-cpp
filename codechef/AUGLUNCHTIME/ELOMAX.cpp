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

using namespace std;

int main()
{
    // ios_base::sync_with_stdio(false);
    // cin.tie(0);

    int t, n, m;
    cin >> t;

    while (t--)
    {
        cin >> n >> m;

        vector<vector<int>> rating(n + 1, vector<int>(m + 1));
        vector<int> maxRatingReached(n + 1); //stores month
        vector<vector<int>> ranking(n + 1, vector<int>(m + 1));
        vector<int> bestRanking(n + 1); //stores first month in which best rank acheived

        for (int i = 1; i <= n; i++)
        {
            cin >> rating[i][0];
        }

        // make Rating per month
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= m; j++)
            {
                int change;
                cin >> change;

                rating[i][j] = rating[i][j - 1] + change;
            }

            int MaxRating = -100000, id = 1;

            for (int j = 1; j <= m; j++)
            {
                if (rating[i][j] > MaxRating)
                {
                    MaxRating = rating[i][j];
                    id = j;
                }
            }
            maxRatingReached[i] = id;
        }

        for (int i = 1; i <= n; i++)
        {
            cout << maxRatingReached[i] << " ";
        }
        cout << "\n";

        //make Ranking per month
        for (int j = 1; j <= m; j++)
        {
            vector<pair<int, int>> Rating_id(n);
            for (int i = 1; i <= n; i++)
            {
                Rating_id[i - 1].first = rating[i][j];
                Rating_id[i - 1].second = i;
            }

            sort(Rating_id.rbegin(), Rating_id.rend());

            int cur_rank = 1, prev = Rating_id[0].first, next_rank = 2;

            for (int i = 0; i < n; i++)
            {
                if (prev == Rating_id[i].first)
                {
                    ranking[Rating_id[i].second][j] = cur_rank;
                    next_rank++;
                }
                else
                {
                    cur_rank = next_rank;
                    next_rank++;
                    ranking[Rating_id[i].second][j] = cur_rank;
                    prev = Rating_id[i].first;
                }
            }
        }

        for (int i = 1; i <= n; i++)
        {
            int best_ranking = 10000, id = 1;
            for (int j = 1; j <= m; j++)
            {
                if (best_ranking > ranking[i][j])
                {
                    best_ranking = ranking[i][j];
                    id = j;
                }
            }
            bestRanking[i] = id;
        }

        int ans = 0;
        for (int i = 1; i <= n; i++)
        {
            cout << bestRanking[i] << " ";
        }
        cout << "\n";
        for (int i = 1; i <= n; i++)
        {
            if (maxRatingReached[i] != bestRanking[i])
            {
                ans++;
            }
        }

        cout << ans << "\n";
    }

    return 0;
}