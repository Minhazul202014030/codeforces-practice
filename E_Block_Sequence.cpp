#include <bits/stdc++.h>
using namespace std;
#define FastIO ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)
#define endl "\n"
typedef long long int ll;
const ll inf = 1e18 + 20;

ll recursiveDP(vector<ll> &a, vector<ll> &dp, ll i)
{

    if (i == a.size())
        return 0;
    if (dp[i] != -1)
        return dp[i];

    ll minDeletions = inf;
    minDeletions = min(minDeletions, 1 + recursiveDP(a, dp, i + 1));
    if (i + 1 + a[i] <= a.size())
        minDeletions = min(minDeletions, recursiveDP(a, dp, i + 1 + a[i]));

    return dp[i] = minDeletions;
}

void solve()
{
    ll n;
    cin >> n;
    vector<ll> a(n);
    for (ll i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    vector<ll> dp(n + 1, -1);
    cout << recursiveDP(a, dp, 0) << endl;
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
