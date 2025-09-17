#include <bits/stdc++.h>
using namespace std;
#define fastIO ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)
#define endl "\n"
typedef long long int ll;
const int MOD = 1000000007;

void solve()
{

    ll n,m;
    cin >> n >> m;
    // vector<ll> a(m);
    map<int, int> f;
    // int f[201] = {0};
    unordered_map<int, vector<int>> adj;
    for (int i = 0; i < m; i++)
    {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
        f[a]++;
        f[b]++;
    }
    int x, y;
    for (int i = 1; i <= n; i++)
    {
        if(f[i]==1)
        {
            int leaf_par = adj[i][0];
            y = f[leaf_par]-1;
            for(auto ch: adj[leaf_par])
            {
                if(f[ch]!=1)
                {
                    x = f[ch];
                    break;
                }
            }

            cout << x << ' ' << y << endl;
            return;
        }
    }
    
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