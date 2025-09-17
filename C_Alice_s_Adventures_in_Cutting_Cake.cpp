#include <bits/stdc++.h>
using namespace std;
#define FastIO ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)
#define endl "\n"
typedef long long int ll;

void solve()
{
    ll n, m, v;
    cin >> n >> m >> v;
    vector<ll> a;
    a.push_back(0);
    for (ll i = 0; i < n; i++)
    {
        ll x;
        cin >> x;
        a.push_back(x);
    }
    a.push_back(0);
    ll sz = a.size();
    vector<ll> prefix(sz, 0);
    for (ll i = 1; i < sz; i++)
    {
        prefix[i] = prefix[i - 1] + a[i];
    }
    ll sum = 0, cnt = 0;

    for (ll i = 0; i < sz; i++)
    {
        sum += a[i];
        if (sum >= v)
        {
            cnt++;
            sum = 0;
        }
    }
    if (cnt < m)
    {
        cout << "-1" << endl;
        return;
    }
    // for(auto u:a)
    // {
    //     cout << u << ' ';
    // }
    // vector<ll> left(m, 0), right(m, 0);
    ll left[m + 1];
    ll right[m + 1];
    // map<ll, ll> left, right;
    sum = 0;
    ll idx = 1;
    left[0] = 0;
    for (ll i = 1; i < sz - 1; i++)
    {
        sum += a[i];
        if (sum >= v && idx <= m)
        {
            sum = 0;
            left[idx] = i;
            idx++;
        }
        // if (idx > m)
        //     break;
    }
    sum = 0;
    idx = 1;
    right[0] = sz - 1;
    for (ll i = sz - 2; i >= 0; i--)
    {
        sum += a[i];
        if (sum >= v && idx <= m)
        {
            sum = 0;
            right[idx] = i;
            idx++;
        }
    }
    // for (ll i = 0; i <= m; i++)
    // {
    //     cout << left[i] << " ";
    //     // cout << a[i];
    // }
    // cout << endl;
    // for (ll i = 0; i <= m; i++)
    // {
    //     cout << right[i] << " ";
    // }
    ll ans = 0;
    for (ll i = 0; i <= m; i++)
    {
        ll x = left[i];
        ll y = right[m - i];
        ans = max(ans, prefix[y - 1] - prefix[x]);
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
