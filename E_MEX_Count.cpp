#include <bits/stdc++.h>
#include <numeric>
using namespace std;
#define fastIO ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)
#define endl "\n"
typedef long long int ll;
const int MOD = 1000000007;

void solve()
{

    ll n;
    cin >> n;
    vector<ll> a(n);
    // ll f[n + 1] = {0};
    for (ll i = 0; i < n; i++)
    {
        cin >> a[i];
        // f[a[i]]++;
    }
    sort(a.begin(), a.end());

    ll m = 0;
    for (ll i = 0; i < n; i++)
    {
        if (a[i] == m)
            m++;
    }
    unordered_map<ll, ll> f;
    for (int i = 0; i < n; i++)
    {
        if (a[i] > m)
            break;
        f[a[i]]++;
    }
    unordered_map<ll, ll> cnt;
    for (auto u : f)
    {
        cnt[u.second]++;
    }

    ll ans[n + 1];
    ans[0] = 1;
    for (int i = 1; i < n - m + 1; i++)
    {
        ans[i] = ans[i - 1] + cnt[i];
    }
    for (int i = n - m + 1; i < n + 1; i++)
    {
        ans[i] = m;
        m--;
    }

    for (auto u : ans)
        cout << u << ' ';
    cout << endl;

    // cout << gcd(2, 3) << endl;
}

int main()
{
    fastIO;
    int t;
    cin >> t;
    // cout << lcm(2,2) << endl;
    // cout << "jjjfojoj" << endl;
    while (t--)
    {
        solve();
    }

    return 0;
}