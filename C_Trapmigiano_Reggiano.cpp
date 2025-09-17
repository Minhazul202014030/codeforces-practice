#include <bits/stdc++.h>
using namespace std;
#define FastIO ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)
#define endl "\n"
typedef long long int ll;
const int mod = 1e9 + 7;

void dfs(int node, vector<int> &vis, unordered_map<int, vector<int>> &adj)
{
    vis[node] = 1;
    for(auto &ch:adj[node])
    {
        if(!vis[ch])
        {
            dfs(ch, vis, adj);
        }
    }
    cout << node << ' ';
}

void solve()
{
    int n, st, en;
    cin >> n >> st >> en;
    unordered_map<int, vector<int>> adj;
    for (int i = 1; i <= n - 1; i++)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    vector<int> vis(n + 1, 0);
    dfs(en, vis, adj);

    cout << endl;
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