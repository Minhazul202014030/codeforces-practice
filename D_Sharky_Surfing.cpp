#include <bits/stdc++.h>
using namespace std;
#define FastIO ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)
#define endl "\n"
typedef long long int ll;

void solve()
{
    ll n, m, l;
    cin >> n >> m >> l;
    vector<pair<ll, ll>> vp, vh;

    map<ll, ll> mp;
    for (ll i = 0; i < n; i++)
    {
        ll x, y;
        cin >> x >> y;
        mp[x] = 1;
        vp.push_back({x, y});
    }
    for (ll i = 0; i < m; i++)
    {
        ll x, y;
        cin >> x >> y;
        vp.push_back({x, y});
    }
    sort(vp.begin(), vp.end());
    priority_queue<ll> pq;
    ll cur = 1;
    ll cnt = 0;
    for (ll i = 0; i < n + m; i++)
    {
        if (mp[vp[i].first] == 1)
        {
            if (cur < vp[i].second - vp[i].first + 2)
            {
                while (!pq.empty())
                {
                    cur += pq.top();
                    cnt++;
                    pq.pop();
                    if (cur >= vp[i].second - vp[i].first + 2)
                        break;
                }
                if (cur < vp[i].second - vp[i].first + 2)
                {
                    cout << "-1" << endl;
                    return;
                }
            }

        }
        else
        {
            pq.push(vp[i].second);
        }
    }
    cout << cnt << endl;
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
