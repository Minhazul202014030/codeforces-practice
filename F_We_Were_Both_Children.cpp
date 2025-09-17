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
    vector<ll> a(n),cnt(n+1,0);
    ll f[n + 1] = {0};
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        if (a[i] <= n)
            f[a[i]]++;
    }
    // ll cnt[n + 1] = {0};
    
    for (int i = 1; i <= n; i++)
    {
        int j = 1;
        while (i * j <= n)
        {
            cnt[i * j] += f[i];
            j++;
        }
       
    }

    ll ans = *max_element(cnt.begin(),cnt.end());
    
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