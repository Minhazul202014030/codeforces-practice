#include <bits/stdc++.h>
using namespace std;
#define fastIO ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)
#define endl "\n"
typedef long long int ll;

ll solve(vector<ll> g[], vector<ll> les[], vector<vector<ll>> &v, ll n, ll k)
{
    // ll sz = g;
    for (ll i = 0; i < k; i++)
    {
        ll x = -1;
        ll y = -1;
        if (!g[i].empty())
        {
            sort(g[i].begin(), g[i].end());
            x = g[i].back();
        }
        if (!les[i].empty())
        {
            sort(les[i].begin(), les[i].end());
            y = les[i].front();
        }
        // cout << x << " " << y << endl;
    }
    // cout << g[0][g[0].size() - 1];

    return 1;
}

int main()
{
    fastIO;
    ll t, n, k;
    cin >> n >> k >> t;
    vector<vector<ll>> v(n, vector<ll>(k, 0));
    for (ll i = 0; i < n; i++)
    {
        for (ll j = 0; j < k; j++)
        {
            cin >> v[i][j];
        }
    }
    for (ll i = 1; i < n; i++)
    {
        for (ll j = 0; j < k; j++)
        {
            v[i][j] = v[i-1][j] | v[i][j];
        }
    }
    // for(auto u:v)
    // {
    //     for(auto w:u)
    //     {
    //         cout << w << " ";
    //     }
    //     cout << endl;
    // }

    while (t--)
    {
        // solve(n,k,v);
        ll m;
        cin >> m;
        vector<ll> greater_arr[k], lesser_arr[k];
        while (m--)
        {
            ll r, c;
            char ch;
            cin >> r >> ch >> c;
            // cout << r << ch << c << endl;

            if (ch == '>')
            {
                greater_arr[r - 1].push_back(c);
            }
            else if (ch == '<')
            {
                lesser_arr[r - 1].push_back(c);
            }
        }
        ll ans = solve(greater_arr, lesser_arr, v, n, k);
    }

    return 0;
}
