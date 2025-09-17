#include <bits/stdc++.h>
using namespace std;
#define fastIO ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)
#define endl "\n"
typedef long long int ll;
const int MOD = 1000000007;

void dfs(ll u, ll p, vector<ll> &a, vector<ll> &vis, vector<ll> &mx, vector<ll> &mn, unordered_map<ll, vector<ll>> &g)
{
    mx[u] = max(a[u], a[u] - mn[p]);
    mn[u] = min(a[u], a[u] - mx[p]);
    vis[u] = 1;
    for (auto i : g[u])
    {
        if (!vis[i])
        {
            dfs(i, u, a, vis, mx, mn, g);
        }
    }
}

void solve()
{

    ll n;
    cin >> n;
    vector<ll> a(n + 1), mx(n + 1, 0), mn(n + 1, 0), vis(n + 1, 0);
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    unordered_map<ll, vector<ll>> g;
    for (int i = 0; i < n - 1; i++)
    {
        ll x, y;
        cin >> x >> y;
        g[x].push_back(y);
        g[y].push_back(x);
    }
    dfs(1, 0, a, vis, mx, mn, g);

    for (int i = 1; i <= n; i++){
        cout << mx[i] << ' ';
    }
    cout << endl;
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