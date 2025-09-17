#include <bits/stdc++.h>
using namespace std;
#define FastIO ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)
#define endl "\n"
typedef long long int ll;
const int mod = 1e9 + 7;

void solve()
{
    int n, m;
    cin >> n >> m;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));
    if (a[0] != 0)
        dp[0][a[0]] = 1;
    if (a[0] == 0)
    {
        for (int i = 1; i <= m; i++)
        {
            dp[0][i] = 1;
        }
    }

    for (int i = 1; i < n; i++)
    {
        for (int k = 1; k <= m; k++)
        {
            if (a[i] == 0 || a[i] == k)
            {
                dp[i][k] = (dp[i][k] + dp[i - 1][k]) % mod;
                if (k - 1 > 0)
                    dp[i][k] = (dp[i][k] + dp[i - 1][k - 1]) % mod;
                if (k + 1 <= m)
                    dp[i][k] = (dp[i][k] + dp[i - 1][k + 1]) % mod;
            }
        }
    }
    int ans = 0;
    for (int i = 1; i <= m; i++)
    {
        ans = (ans + dp[n-1][i]) % mod;
    }
    cout << ans;

    cout << endl;
}

int main()
{
    FastIO;
    int t;
    // cin >> t;
    t = 1;
    while (t--)
    {
        solve();
    }

    return 0;
}
