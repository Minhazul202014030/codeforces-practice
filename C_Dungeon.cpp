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
    ll n,m;
    cin >> n >>m;
    multiset<ll> a;
    for (ll i = 0; i < n; i++)
    {

        ll x;
        cin >> x;
        a.insert(x);
    }

    vector<pair<ll, ll>> b(m);
    for (int i = 0; i < m; i++)
    {
        cin >> b[i].first;
    }
    for (int i = 0; i < m; i++)
    {
        cin >> b[i].second;
    }

    sort(b.begin(), b.end());
    ll ans = 0;

    for (int i = 0; i < m; i++)
    {
        if(b[i].second==0)continue;

        auto it = a.lower_bound(b[i].first);
        if(it==a.end())
            break;

        ll x = *it;
        a.erase(it);
        a.insert(max(x, b[i].second));
        ans++;
    }
    for (int i = 0; i < m; i++)
    {
        if(b[i].second>0)continue;

        auto it = a.lower_bound(b[i].first);
        if (it == a.end())
            break;
            
        a.erase(it);        
        ans++;
    }
    

    
    cout << ans << endl;
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