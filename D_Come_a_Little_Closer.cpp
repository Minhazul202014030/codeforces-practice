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
    vector<pair<ll, ll>> v1, v2;
    for (int i = 0; i < n; i++)
    {
        ll x, y;
        cin >> x >> y;
        v1.push_back({x, y});
        v2.push_back({y, x});
    }
    sort(v1.begin(), v1.end());
    sort(v2.begin(), v2.end());
    multiset<ll> a, b;
    for (int i = 0; i < n; i++)
    {
        a.insert(v1[i].first);
        b.insert(v1[i].second);
    }
    if (n == 1)
    {
        cout << 1 << endl;
        return;
    }
    ll ans = 1e18;
    // row

    if (v1[0].first != v1[1].first)
    {
        a.erase(a.find(v1[0].first));
        b.erase(b.find(v1[0].second));
        ll c = (*a.rbegin() - *a.begin() + 1) * (*b.rbegin() - *b.begin() + 1);

        if (c == n - 1)
        {
            c += min(*a.rbegin() - *a.begin() + 1, *b.rbegin() - *b.begin() + 1);
        }
        ans = min(ans, c);
        a.insert(v1[0].first);
        b.insert(v1[0].second);
    }

    if (v1[n - 1].first != v1[n - 2].first)
    {
        a.erase(a.find(v1[n - 1].first));
        b.erase(b.find(v1[n - 1].second));
        ll c = (*a.rbegin() - *a.begin() + 1) * (*b.rbegin() - *b.begin() + 1);
        if (c == n - 1)
        {
            c += min(*a.rbegin() - *a.begin() + 1, *b.rbegin() - *b.begin() + 1);
        }
        // cout << c <<" nnn"<< endl;
        ans = min(ans , c);
        a.insert(v1[n - 1].first);
        b.insert(v1[n - 1].second);
    }

    // col

    if (v2[0].first != v2[1].first)
    {
        a.erase(a.find(v2[0].first));
        b.erase(b.find(v2[0].second));
        ll c = (*a.rbegin() - *a.begin() + 1) * (*b.rbegin() - *b.begin() + 1);

        if (c == n - 1)
        {
            c += min(*a.rbegin() - *a.begin() + 1, *b.rbegin() - *b.begin() + 1);
        }
        ans = min(ans, c);
        a.insert(v2[0].first);
        b.insert(v2[0].second);
    }
    if (v2[n - 1].first != v2[n - 2].first)
    {
        a.erase(a.find(v2[n - 1].first));
        b.erase(b.find(v2[n - 1].second));
        ll c = (*a.rbegin() - *a.begin() + 1) * (*b.rbegin() - *b.begin() + 1);
        if (c == n - 1)
        {
            c += min(*a.rbegin() - *a.begin() + 1, *b.rbegin() - *b.begin() + 1);
        }
        ans = min(ans, c);
        a.insert(v2[n - 1].first);
        b.insert(v2[n - 1].second);
    }

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