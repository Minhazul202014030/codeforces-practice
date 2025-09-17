#include <bits/stdc++.h>
using namespace std;

const int INF = 1e9;
vector<int> d, a;
vector<vector<int>> dp;

int minCost(int pos, int skips)
{
    if (pos == 0)
        return 0; 

    if (dp[pos][skips] != -1)
        return dp[pos][skips];

    int cost = INF;
    for (int prev = 0; prev < pos; prev++)
    {
        int skipCost = pos - prev - 1; // Skipping cost
        if (skips - skipCost >= 0)
        {
            cost = min(cost, minCost(prev, skips - skipCost) + (d[pos] - d[prev]) * a[prev]);
        }
    }

    return dp[pos][skips] = cost; 
}

void solve()
{
    int n, l, k;
    cin >> n >> l >> k;

    d.resize(n + 1);
    a.resize(n);

    for (int i = 0; i < n; i++)
        cin >> d[i];
    for (int i = 0; i < n; i++)
        cin >> a[i];

    d[n] = l;       
    a.push_back(0); 

   
    dp.assign(n + 1, vector<int>(k + 1, -1));

    int result = minCost(n, k);
    dp[0][0] = 0;

    for (int i = 1; i <= n; i++)
    {
        for (int j = 0; j <= k; j++)
        {
            int cost = INF;
            for (int prev = 0; prev < i; prev++)
            {
                int skipCost = i - prev - 1; // Skipping cost
                if (j - skipCost >= 0)
                {
                    cost = min(cost, dp[prev][j - skipCost] + (d[i] - d[prev]) * a[prev]);
                }
            }
            dp[i][j] = cost;
        }
    }
    // int result = INF;
    // for (int i = 0; i <= k;i++)
    // {
    //     result = min(result, dp[n][i]);
    // }
    cout << result << endl;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
    return 0;
}
