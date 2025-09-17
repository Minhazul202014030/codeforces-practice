#include <bits/stdc++.h>
using namespace std;
#define fastIO ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)
#define endl "\n" 
#define yes cout << "YES\n"
#define no cout << "NO\n"
typedef long long int ll;
const int MOD = 1000000007;

void solve()
{
    ll n;
    cin >> n;
    vector<ll> a(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
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

//--------------------------- Dsu template  using map ----------------------------------

class DSU
{
public:
    unordered_map<int, int> parent; // Parent of each node
    unordered_map<int, int> size;   // Size of each set

    // Find with path compression
    int find(int x)
    {
        if (parent[x] != x)
        {
            parent[x] = find(parent[x]); // Path compression
        }
        return parent[x];
    }

    // Union by size
    void unionSets(int x, int y)
    {
        int rootX = find(x);
        int rootY = find(y);

        if (rootX != rootY)
        {
            if (size[rootX] < size[rootY])
            {
                swap(rootX, rootY); // Ensure rootX is the larger tree
            }
            parent[rootY] = rootX;      // Merge rootY into rootX
            size[rootX] += size[rootY]; // Update size of the root set
        }
    }

    // Add a new element to the DSU
    void add(int x)
    {
        if (parent.find(x) == parent.end())
        {
            parent[x] = x;
            size[x] = 1;
        }
    }
};

//------------------------------ Dsu template using vector -----------------------------
class DSU
{
public:
    vector<int> parent; // Stores the parent of each node
    vector<int> size;   // Stores the size of each set (for union by size)

    // Constructor to initialize DSU with 'n' elements
    DSU(int n)
    {
        parent.resize(n);
        size.resize(n, 1);
        for (int i = 0; i < n; i++)
        {
            parent[i] = i; // Each element is its own parent initially
        }
    }

    // Find the representative (root) of the set containing 'x'
    int find(int x)
    {
        if (parent[x] != x)
        {
            parent[x] = find(parent[x]); // Path compression
        }
        return parent[x];
    }

    // Union of two sets containing 'x' and 'y'
    void unionSets(int x, int y)
    {
        int rootX = find(x);
        int rootY = find(y);

        if (rootX != rootY)
        {
            // Union by size: attach the smaller tree under the larger one
            if (size[rootX] < size[rootY])
            {
                swap(rootX, rootY);
            }
            parent[rootY] = rootX;
            size[rootX] += size[rootY]; // Update the size of the merged set
        }
    }

    // Check if 'x' and 'y' are in the same set
    bool isConnected(int x, int y)
    {
        return find(x) == find(y);
    }
};

//----------------------------------------seive -------------------------------------------
set<int> sieve(int n)
{
    vector<bool> primes(n + 1, true);
    primes[0] = primes[1] = false;
    for (int i = 2; i * i <= n; i++)
    {
        if (primes[i])
        {
            for (int j = i * i; j <= n; j += i)
            {
                primes[j] = false;
            }
        }
    }
    set<int> ans;
    for (int i = 0; i <= n; i++)
    {
        if (primes[i])
            ans.insert(i);
    }
    return ans;
}