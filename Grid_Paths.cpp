#include <bits/stdc++.h>
using namespace std;
#define FastIO ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)
#define endl "\n"
typedef long long int ll;
const int mod = 1e9 + 7;

void solve()
{
    int n;
    cin >> n;
    char c[n][n];
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> c[i][j];
        }
    }
    vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0));
    if (c[0][0] != '*')
        dp[0][0] = 1;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (c[i][j] != '*' && j - 1 >= 0)
            {
                dp[i][j] = (dp[i][j] + dp[i][j - 1]) % mod;
            }
            if (c[i][j] != '*' && i - 1 >= 0)
            {
                dp[i][j] = (dp[i][j] + dp[i - 1][j]) % mod;
            }
        }
    }
    // for (int i = 0; i < n; i++)
    // {
    //     for (int j = 0; j < n; j++)
    //     {
    //         cout << dp[i][j] << ' ';
    //     }
    //     cout << endl;
    // }
    cout << dp[n - 1][n - 1] << endl;

    // cout << endl;
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