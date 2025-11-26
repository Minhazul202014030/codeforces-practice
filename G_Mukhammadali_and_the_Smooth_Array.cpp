#include <bits/stdc++.h>
using namespace std;
#define fastIO ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)
#define endl "\n"
#define yes cout << "YES\n"
#define no cout << "NO\n"
typedef long long int ll;
const int MOD = 1000000007;

void solve()
{
    ll n;
    cin >> n;
    vector<ll> a(n), c(n);
    for (ll i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    ll t = 0;
    for (ll i = 0; i < n; i++)
    {
        cin >> c[i];
        t += c[i];
    }

    vector<ll> dp(n);

    for (int i = 0; i < n; i++)
    {
        dp[i] = c[i];
        for (int j = 0; j < i; j++)
        {
            if (a[j] <= a[i])
                dp[i] = max(dp[i], c[i] + dp[j]);
        }
    }

    ll mx = 0;
    for (int i = 0; i < n; i++)
    {
        mx = max(mx, dp[i]);
    }

    cout << t - mx << endl;
}

int main()
{
    fastIO;
    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }

    return 0;
}