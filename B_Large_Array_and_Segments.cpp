#include <bits/stdc++.h>
using namespace std;
#define FastIO ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)
#define endl "\n"
typedef long long int ll;
const int mod = 1e9 + 7;

void solve()
{

    ll n, k, x;
    cin >> n >> k >> x;
    vector<ll> v(n + 1), pre(n + 1, 0);
    for (int i = 1; i <= n; i++)
    {
        cin >> v[i];
    }
    for (int i = 1; i <= n; i++)
    {
        pre[i] = pre[i - 1] + v[i];
    }
    // for(auto u:pre)
    //     cout << u << ' ';
    ll r = pre[n] * k;
    ll cnt = (r - x + pre[n] - 1) / pre[n];

    // cout << cnt << endl;
    cnt = max(1ll, cnt);

    ll ans = (cnt - 1) * n;
    for (ll i = 0; i <= n; i++)
    {

        ll l = pre[i] + (pre[n] * (cnt - 1));
        ll d = r - l;
        if (d >= x)
            ans++;
    }
    cout << ans << endl;
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