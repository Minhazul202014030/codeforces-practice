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
    vector<ll> a1(n),a2(n);
    for (ll i = 0; i < n; i++)
    {
        cin >> a1[i];
    }
    for (ll i = 0; i < n; i++)
    {
        cin >> a2[i];
    }

    vector<ll> sufmn(n), sufmx(n);
    sufmn[n - 1] = a2[n - 1];
    sufmx[n - 1] = a2[n - 1];
    for (int i = n-2; i >=0; i--)
    {
        sufmn[i] = min(a2[i], sufmn[i + 1]);
        sufmx[i] = max(a2[i], sufmx[i + 1]);
    }

    ll pmn = a1[0], pmx = a1[0];
    vector<ll> r(2 * n, 2 * n);
    for (int i = 0; i < n; i++)
    {
        pmn = min(pmn, a1[i]);
        pmx = max(pmx, a1[i]);
        ll mn = min(pmn, sufmn[i]);
        ll mx = max(pmx, sufmx[i]);

        r[mn - 1] = min(r[mn - 1], mx - 1);
    }

    for (int i = 2*n-2; i >=0; i--)
    {
        r[i] = min(r[i], r[i + 1]);
    }
    ll ans = 0;
    for(auto u:r)
        ans += (2 * n - u);

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