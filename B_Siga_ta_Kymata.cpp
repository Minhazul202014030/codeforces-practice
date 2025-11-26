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
    vector<ll> a(n),mp(n+1);
    for (ll i = 0; i < n; i++)
    {
        cin >> a[i];
        mp[a[i]] = i;
    }
    string s;
    cin >> s;
    if (s[0] == '1' || s[n - 1] == '1' || s[mp[1]]=='1' || s[mp[n]]=='1')
    {
        cout << -1 << endl;
        return;
    }
    
    ll l = -1, r = -1;
    
    for (int i = 0; i < n; i++)
    {
        if (s[i] == '1')
        {
            if (l == -1)
            {
                l = i;
                r = i;
            }
            else
                r = i;
        }
    }
    if (l == -1 && r == -1)
    {
        cout << 0 << endl;
        return;
    }
    cout << 5 << endl;
    // cout << mp[a[0]] + 1 << ' ' << mp[1]+1 << endl;
    // cout << mp[1]+1 << ' ' << mp[n]+1 << endl;
    // cout << mp[n]+1 << ' ' << mp[a[n - 1]]+1 << endl;

    // cout << min(mp[a[0]] + 1, mp[1] + 1) << ' ' << max(mp[a[0]] + 1, mp[1] + 1) << endl;
    // cout << min(mp[1] + 1, mp[n] + 1) << ' ' << max(mp[1] + 1, mp[n] + 1) << endl;
    // cout << min(mp[n] + 1, mp[a[n - 1]] + 1) << ' ' << max(mp[n] + 1, mp[a[n - 1]] + 1) << endl;

    cout << 1 << ' ' << mp[1] + 1 << endl;
    cout << 1 << ' ' << mp[n] + 1 << endl;
    cout << min(mp[1] + 1, mp[n] + 1) << ' ' << max(mp[1] + 1, mp[n] + 1) << endl;
    cout << mp[n] + 1 << ' ' << n << endl;
    cout << mp[1] + 1 << ' ' << n << endl;
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