#include <bits/stdc++.h>
using namespace std;
#define fastIO ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)
#define endl "\n"
#define yes cout << "YES\n"
#define no cout << "NO\n"
typedef long long int ll;
const int MOD = 1000000007;

class DSU
{
public:
    vector<int> parent; 
    vector<int> size;   

    
    DSU(int n)
    {
        parent.resize(n);
        size.resize(n, 1);
        for (int i = 0; i < n; i++)
        {
            parent[i] = i; 
        }
    }

   
    int find(int x)
    {
        if (parent[x] != x)
        {
            parent[x] = find(parent[x]); 
        }
        return parent[x];
    }

    
    void unionSets(int x, int y)
    {
        int rootX = find(x);
        int rootY = find(y);

        if (rootX != rootY)
        {
            
            if (size[rootX] < size[rootY])
            {
                swap(rootX, rootY);
            }
            parent[rootY] = rootX;
            size[rootX] += size[rootY]; 
        }
    }

   
    bool isConnected(int x, int y)
    {
        return find(x) == find(y);
    }
};

void solve()
{
    ll n;
    cin >> n;
    DSU d(2 * n + 1);
    vector<int> ans;

    for (int i = 0; i < n; i++)
    {

        int x, y;
        cin >> x >> y;
        if (d.find(x) != d.find(y))
        {
            // cout << i + 1 << ' ';
            ans.push_back(i + 1);
        }
        d.unionSets(x, y);
    }

    cout << ans.size() << endl;
    for (auto u : ans)
        cout << u << ' ';
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