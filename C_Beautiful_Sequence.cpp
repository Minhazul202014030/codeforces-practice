#include <bits/stdc++.h>
using namespace std;
#define FastIO ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)
#define endl "\n"
typedef long long int ll;
const int MOD = 998244353;

void solve()
{

    ll n;
    cin >> n;
    ll a[n];
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    vector<vector<ll>> dp(n + 1, vector<ll>(4, 0));
    dp[0][0] = 1;
    for (int i = 0; i < n; i++)
    {
        for (int len = 0; len < 4; len++)
        {
            dp[i + 1][len] = (dp[i + 1][len] + dp[i][len])%MOD;

            if (len == 0 && a[i] == 1)
            {
                dp[i + 1][1] = (dp[i + 1][1] + dp[i][0]) % MOD;
            }
            if (len == 1 && a[i] == 2)
            {
                dp[i + 1][2] = (dp[i + 1][2] + dp[i][1]) % MOD;
            }
            if (len == 2 && a[i] == 2)
            {
                dp[i + 1][2] = (dp[i + 1][2] + dp[i][2]) % MOD;
            }
            if (len == 2 && a[i] == 3)
            {
                dp[i + 1][3] = (dp[i + 1][3] + dp[i][2]) % MOD;
            }
        }
    }
    cout << dp[n][3] << endl;
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


