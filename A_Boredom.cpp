#include <bits/stdc++.h>
using namespace std;
#define fastIO ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)
#define endl "\n"
typedef long long int ll;
const int MOD = 1000000007;

void solve()
{

    ll n;
    cin >> n;
    vector<ll> a(n);
    unordered_map<ll, ll> cnt;
    for (ll i = 0; i < n; i++)
    {
        cin >> a[i];
        cnt[a[i]]++;
    }
    sort(a.begin(), a.end());
    vector<ll> b;
    b.push_back(0);
    b.push_back(a[0]);
    for (ll i = 0; i < n; i++)
    {
        if (a[i] == b.back())
            continue;
        b.push_back(a[i]);
    }
    // for (auto u : b)
    //     cout << u << ' ';
    ll m = b.size();
    vector<vector<ll>> dp(m + 1, vector<ll>(2, 0));
    dp[1][0] = 0;
    dp[1][1] = cnt[b[1]] * b[1];

    for (ll i = 2; i < m; i++)
    {
        dp[i][0] = max(dp[i - 1][0], dp[i - 1][1]);
        if (b[i] - b[i - 1] == 1)
        {
            dp[i][1] = dp[i - 1][0] + (cnt[b[i]] * b[i]);
        }
        else
        {
            dp[i][1] = max(dp[i - 1][0], dp[i - 1][1]) + (cnt[b[i]] * b[i]);
        }
    }

    cout << max(dp[m - 1][0], dp[m - 1][1]) << endl;
}

int main()
{
    fastIO;
    int t = 1;
    // cin >> t;
    while (t--)
    {
        solve();
    }

    return 0;
}
