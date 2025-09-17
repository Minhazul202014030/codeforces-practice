#include <bits/stdc++.h>
using namespace std;
#define FastIO ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)
#define endl "\n"
typedef long long int ll;

ll f(int i, int mex, unordered_map<int, int> &mp, vector<vector<ll>> &dp)
{

    if (i == 0)
    {
        return (mp[0] - 1) * mex;
    }
    if (dp[i][mex] != -1)
        return dp[i][mex];

    ll nottake = f(i - 1, mex, mp, dp);
    // ll take = 1e18 + 10;

    ll take = (mp[i] - 1) * mex + i + f(i - 1, i, mp, dp);
    return dp[i][mex] = min(nottake, take);
}

void solve()
{
    int n;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    unordered_map<int, int> mp;
    for (int i = 0; i < n; i++)
    {
        if (a[i] < n)
            mp[a[i]]++;
    }
    // n = 5000;
    int max_mex = 0;
    while (mp[max_mex] > 0)
        max_mex++;

    if (max_mex == 0)
    {
        cout << 0 << endl;
        return;
    }
    vector<vector<ll>> dp(max_mex, vector<ll>(max_mex + 1, 0));
    // ll dp[5000][5001] = {-1};
    // cout << f(max_mex - 1, max_mex, mp, dp) << endl;

    for (int mex = 0; mex <= max_mex; mex++)
    {
        dp[0][mex] = (mp[0] - 1) * mex;
    }
    for (int i = 1; i < max_mex; i++)
    {
        for (int mex = 0; mex <= max_mex; mex++)
        {
            ll nottake = dp[i - 1][mex]; // f(i - 1, mex, mp, dp);

            ll take = (mp[i] - 1) * mex + i + dp[i - 1][i]; //(mp[i] - 1) * mex + i + f(i - 1, i, mp, dp);
            dp[i][mex] = min(nottake, take);
        }
    }
    cout << dp[max_mex - 1][max_mex] << endl;
}

int main()
{
    FastIO;
    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }

    return 0;
}