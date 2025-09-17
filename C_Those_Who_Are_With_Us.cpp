#include <bits/stdc++.h>
using namespace std;
#define fastIO ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)
#define endl "\n"
typedef long long int ll;
const int MOD = 1000000007;

void solve()
{

    ll n, m;
    cin >> n >> m;
    // vector<ll> a(n);
    ll a[n][m];
    ll mx = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> a[i][j];
            mx = max(mx, a[i][j]);
        }
    }
    vector<pair<ll, ll>> vp;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (a[i][j] == mx)
            {
                vp.push_back({i, j});
            }
        }
    }

    if (vp.size() <= 2)
    {
        cout << mx - 1 << endl;
        return;
    }
    ll r = -1, c = -1;
    unordered_map<ll, ll> seen_r, seen_c;
    int sz = vp.size();
    for (int i = 0; i < sz; i++)
    {
        if (seen_r[vp[i].first])
        {
            r = vp[i].first;
            break;
        }
        seen_r[vp[i].first] = 1;
    }
    for (int i = 0; i < sz; i++)
    {
        if (seen_c[vp[i].second])
        {
            c = vp[i].second;
            break;
        }
        seen_c[vp[i].second] = 1;
    }

    if (r == -1)
    {
        for (int i = 0; i < sz; i++)
        {
            if (vp[i].second != c)
            {
                r = vp[i].first;
                break;
            }
        }
    }
    if (c == -1)
    {
        for (int i = 0; i < sz; i++)
        {
            if (vp[i].first != r)
            {
                c = vp[i].second;
                break;
            }
        }
    }
    for (int i = 0; i < m; i++)
    {
        a[r][i]--;
    }
    for (int i = 0; i < n; i++)
    {
        a[i][c]--;
    }

    mx = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            mx = max(mx, a[i][j]);
        }
    }

    cout << mx << endl;
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