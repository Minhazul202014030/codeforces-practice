#include <bits/stdc++.h>
using namespace std;
#define fastIO ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)
typedef long long int ll;
#define f(i, x, y) for (int i = x; i < y; i++)
#define ia(a, n)                \
    for (int i = 0; i < n; i++) \
    cin >> a[i]
#define ia1(a, n)                \
    for (int i = 1; i <= n; i++) \
    cin >> a[i]
#define endl "\n"
#define yes cout << "YES\n"
#define no cout << "NO\n"

const int MOD = 1000000007;

void solve()
{
    ll n;
    cin >> n;
    vector<ll> a(n+1),p(n+1,0);
    ia1(a, n);

    f(i,1,n+1){
        p[i] = p[i-1] + a[i];
    }

    ll mxr = -1e18, mxl = -1e18,mxi=0;

    f(i,1,n+1){
        // mxr = max(mxr, (i * i) + i - p[i]);
        mxl = max(mxl, -(ll)i*i + i + p[i - 1]);
        ll r = (ll)i*i + i - p[i] + mxl;
        mxi = max(mxi, r);
    }

    cout << p[n] + mxi << endl;
    // cout << max(p[n], p[n] + mxr + mxl) << endl;
    // cout << mxr<<' '<<mxl;
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