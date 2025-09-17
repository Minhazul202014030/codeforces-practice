#include <bits/stdc++.h>
using namespace std;
#define FastIO ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)
#define endl "\n"
typedef long long int ll;
ll mod = 998244353;
void solve()
{
    ll n;
    cin >> n;
    vector<ll> a(n);
    for (ll i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    if (n == 1)
    {
        if (a[0] == 0)
        {
            cout << 2 << endl;
        }
        else
        {
            cout << 1 << endl;
        }
        return;
    }
    vector<vector<ll>> odp(n + 5, vector<ll>(2, 0));
    if (a[0] == 0)
    {
        odp[0][0] = 1;
        odp[1][1] = 1;
    }
    else
    {
        odp[1][1] = 1;
    }
    for (int i = 1; i < n; i++)
    {
        vector<vector<ll>> dp(n + 5, vector<ll>(2, 0));
        dp[a[i]][0] = (odp[a[i]][0] + odp[a[i]][1])%mod;
        dp[a[i - 1] + 1][1] = (odp[a[i - 1]][0])%mod;
        // cout << dp[a[i]][0] + dp[a[i - 1] + 1][1] << endl;
        odp = dp;
    }
    cout << (odp[a[n - 1]][0] + odp[a[n - 2] + 1][1])%mod << endl;
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
