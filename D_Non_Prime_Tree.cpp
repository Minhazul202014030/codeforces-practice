// #include <bits/stdc++.h>
// using namespace std;

// // dfs(adj, a, st, ch, 1, primes);

// void dfs(const vector<vector<int>> &adj, vector<int> &a, int &st, int node, int parent, const set<int> &primes)
// {
//     while (primes.find(st - a[parent]) != primes.end())
//         st++;
//     a[node] = st;
//     st++;
//     for (auto ch : adj[node])
//     {
//         if (ch == parent)
//             continue;
//         dfs(adj, a, st, ch, node, primes);
//     }
// }

// set<int> sieve(int n)
// {
//     vector<bool> primes(n + 1, true);
//     primes[0] = primes[1] = false;
//     for (int i = 2; i * i <= n; i++)
//     {
//         if (primes[i])
//         {
//             for (int j = i * i; j <= n; j += i)
//             {
//                 primes[j] = false;
//             }
//         }
//     }
//     set<int> ans;
//     for (int i = 0; i <= n; i++)
//     {
//         if (primes[i])
//             ans.insert(i);
//     }
//     return ans;
// }

// int32_t main()
// {
//     ios::sync_with_stdio(false);
//     cin.tie(nullptr);
//     cout.tie(nullptr);

// // #ifndef ONLINE_JUDGE
// //     freopen("input.txt", "r", stdin);
// //     freopen("output.txt", "w", stdout);
// // #endif

//     int tc;
//     cin >> tc;
//     while (tc--)
//     {
//         int n;
//         cin >> n;
//         vector<vector<int>> adj(n + 1);
//         for (int i = 1; i < n; i++)
//         {
//             int u, v;
//             cin >> u >> v;
//             adj[u].push_back(v);
//             adj[v].push_back(u);
//         }
//         set<int> primes = sieve(2 * n);
//         vector<int> a(n + 1, 0);
//         int st = 2;
//         a[1] = 1;

//         for (auto ch : adj[1])
//         {
//             dfs(adj, a, st, ch, 1, primes);
//         }

//         for (int i = 1; i <= n; i++)
//         {
//             cout << a[i] << " ";
//         }
//         cout << endl;
//     }

//     return 0;
// }

// ---------------------------------------------------------------------------------------
#include <bits/stdc++.h>
using namespace std;
#define FastIO ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)
#define endl "\n"
typedef long long int ll;

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
void dfs(vector<vector<int>> &adj, vector<int> &ans, int &st, int node, int parent, set<int> &primes)
{
    while (primes.find(st - ans[parent]) != primes.end())
        st++;
    ans[node] = st;
    st++;
    for (auto ch : adj[node])
    {
        if (ch == parent)
            continue;
        dfs(adj, ans, st, ch, node, primes);
    }
}
void solve()
{
    int n;
    cin >> n;
    vector<vector<int>> adj(n + 1);
    // vector<int> adj[n + 1];
    vector<int> ans(n + 1, 0);
    for (int i = 1; i <= n - 1; i++)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    // for (int i = 1; i <= n; i++)
    // {
    //     cout << i<< " : ";
    //     for(auto u:adj[i])
    //     {
    //         cout << u << " ";
    //     }
    //     cout << endl;
    // }

    set<int> primes = sieve(2 * n);

    int st = 1;
    // ans[1] = 1;
    dfs(adj, ans, st, 1, 1, primes);
    // for (auto ch : adj[1])
    // {
    //     dfs(adj, a, st, ch, 1, primes);
    // }

    for (int i = 1; i <= n; i++)
    {
        cout << ans[i] << " ";
    }
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