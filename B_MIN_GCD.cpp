#include <bits/stdc++.h>
using namespace std;
#define fastIO ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)
#define endl "\n"
typedef long long int ll;
const int MOD = 1000000007;

void solve()
{

    ll n;
    cin >> n;
    vector<ll> v(n);
    map<ll, ll> mp;
    for (ll i = 0; i < n; i++)
    {
        cin >> v[i];
        mp[v[i]]++;
    }
    sort(v.begin(), v.end());
    // cout << mp[1];
    if (mp[v[0]] > 1)
    {
        cout << "Yes" << endl;
        return;
    }
    ll a = 0, b;
    for (ll i = 1; i < n; i++)
    {
        if (v[i] % v[0] == 0)
        {
            if (a == 0)
                a = v[i];
            else
            {
                a = __gcd(a, v[i]);
                if (a == v[0])
                {
                    cout << "Yes" << endl;
                    return;
                }
            }
        }
        // else if (v[i] % v[0] == 0 && v[i] % a != 0)
        // {
        //     cout << "Yes" << endl;
        //     return;
        // }
    }
    cout << "No" << endl;
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