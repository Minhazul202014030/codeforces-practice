#include <bits/stdc++.h>
using namespace std;
#define FastIO ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)
#define endl "\n"
typedef long long int ll;
const int mod = 1e9 + 7;

void solve()
{

    ll n;
    cin >> n;
    set<ll> st;
    for (ll i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        st.insert(x);
    }
    vector<ll> a;
    for (auto &u : st)
        a.push_back(u);

    ll l = 0, r = a.size() - 1;
    ll ans = 1;
    // cout << l << ' ' << r << endl;
    ll m = a.size();
    for (ll i = 0; i < m; i++)
    {
        ll d = upper_bound(a.begin(), a.end(), a[i] + n)-a.begin();
        // cout << d << endl;
        if(a[d-1]-a[i]<n)
        {
            ans = max(ans, d - i);
        }
    }
    
    cout << ans << endl;
    // for(auto u:a)
    //     cout << u << ' ';
    // cout << endl;
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