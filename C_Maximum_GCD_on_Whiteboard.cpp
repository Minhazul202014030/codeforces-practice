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
        ll n, k;
        cin >> n >> k;
        vector<ll> a(n);
        map<ll, ll> f;

        for (ll i = 0; i < n; i++)
        {
            cin >> a[i];
            f[a[i]]++;
        }

        sort(a.begin(), a.end());

        ll ans = 1;
        for (int i = n; i >= 2; i--)
        {

            ll id = lower_bound(a.begin(), a.end(), 4 * i) - a.begin();
            ll s = f[i] + f[2 * i] + f[3 * i] + n - id;

            if (k >= n - s)
            {
                cout << i << endl;
                return;
            }
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