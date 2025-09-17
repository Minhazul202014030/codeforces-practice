#include <bits/stdc++.h>
using namespace std;
#define fastIO ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)
#define endl "\n"
typedef long long int ll;
const int MOD = 1000000007;

ll f(vector<ll> &a, vector<ll> &b, ll l, ll r, vector<ll> &dp, ll i)
{
    if (i == 0)
    {
        if (a[0] <= r)
        {
            return b[0];
        }
        else
            return 0;
    }

    if (dp[i] != -1)
        return dp[i];

    ll nottake = 0 + f(a, b, l, r, dp, i - 1);
    ll take = INT_MIN;
    if (a[i] <= r)
    {
        take = b[i] + f(a, b, l, r - a[i], dp, i - 1);
    }

    return dp[i] = max(take, nottake);
}

void solve()
{

    ll n, q;
    cin >> n >> q;
    vector<ll> a(n), b(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i] >> b[i];
    }
    
    while (q--)
    {
        ll l, r;
        cin >> l >> r;
        // ll dp[n+1]=
        vector<ll> dp(n + 1, -1);
        cout << f(a, b, l, r, dp, n - 1) << endl;
    }
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