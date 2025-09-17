#include <bits/stdc++.h>
using namespace std;
#define fastIO ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)
#define endl "\n"
typedef long long int ll;

void dfs(ll node, vector<vector<ll>> &adj, vector<ll> &visited, map<ll, ll> &inDegree, ll level, ll &maxLevel)
{
    visited[node] = 1;
    maxLevel = max(maxLevel, level);

    for (auto child : adj[node])
    {
        inDegree[child]--;
        if (inDegree[child] == 0 && !visited[child])
        {
            dfs(child, adj, visited, inDegree, level + 1, maxLevel);
        }
    }
}

void solve()
{
    ll n;
    cin >> n;
    vector<ll> v(n);
    for (ll i = 0; i < n; i++)
    {
        cin >> v[i];
    }
    vector<vector<ll>> adj(n + 1);
    map<ll, ll> inDegree;
    for (ll i = 0; i < n; i++)
    {
        adj[i + 1].push_back(v[i]);
        inDegree[v[i]]++;
    }
    vector<ll> visited(n + 1, 0);
    ll maxLevel = 0;
    for (ll i = 1; i <= n; i++)
    {
        if (inDegree[i] == 0 && !visited[i])
        {
            dfs(i, adj, visited, inDegree, 1, maxLevel);
        }
    }
    cout << maxLevel + 2 << endl;
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
