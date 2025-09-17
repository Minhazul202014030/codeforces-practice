#include <bits/stdc++.h>
using namespace std;
#define fastIO ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)
#define endl "\n"
typedef long long int ll;
const int MOD = 1000000007;

void solve()
{

    ll n, q;
    cin >> n >> q;
    vector<ll> a(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    vector<ll> pre(n, 0);
    pre[0] = a[0];
    ll g = __gcd(a[0], a[1]);
    pre[1] = pre[0] + g;
    
    for (int i = 2; i < n; i++)
    {
        g = __gcd(g, a[i]);
        pre[i] = pre[i - 1] + g;
    }
    for (int i = 0; i < q; i++)
    {
        ll l, r;
        cin >> l >> r;
        
    }
    
}

int main()
{
    fastIO;
    int t = 1;
    // cin >> t;
    while (t--)
    {
        solve();
    }

    return 0;
}