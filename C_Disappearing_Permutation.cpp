#include <bits/stdc++.h>
using namespace std;
#define FastIO ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)
#define endl "\n"
typedef long long int ll;
const int mod = 1e9 + 7;
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

    int n;
    cin >> n;
    int a[n + 1], q[n + 1];
    DSU d(n + 1);

    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];

        d.unionSets(i, a[i]);
    }

    unordered_map<int, int> vis;
    vector<int> ans;
    ans.push_back(0);
    for (int i = 1; i <= n; i++)
    {
        int x;
        cin >> x;
        int upar = d.find(a[x]);
        int sz = d.size[upar];
        if (!vis[upar])
        {
            ans.push_back(ans.back() + sz);
            vis[upar] = 1;
        }
        else
            ans.push_back(ans.back());
    }
    for (int i = 1; i <= n; i++)
    {
        cout << ans[i] << ' ';
    }

    // cout<<d.size[d.parent[7]];
    // cout << d.parent[5];

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



