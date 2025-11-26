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
    string s;
    cin >> s;
    vector<ll> d(n + 1, 0);
    ll cnta = 0, cntb = 0;
    for (ll i = 0; i < n; i++)
    {
        if (s[i] == 'a')
            cnta++;
        else
            cntb++;
        d[i + 1] = (cnta - cntb);
    }
    unordered_map<ll, ll> mp;
    mp[0] = 0;
    ll ans = 1e9;
    for (int i = 1; i <= n; i++)
    {
        mp[d[i]] = i;
        if (mp.find(d[i] - d[n]) != mp.end())
        {
            // cout << d[n] << endl;
            // cout << i << endl;
            // return;
            ans = min(ans, i - mp[d[i] - d[n]]);
            // cout<<i<<": " << i - mp[d[i] - d[n]] << endl;
        }
    }
    if (ans >= n)
        cout << -1 << endl;
    else
        cout << ans << endl;
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