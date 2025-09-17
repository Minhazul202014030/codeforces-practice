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
    vector<ll> a(n);

    ll sum = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        sum += a[i];
    }
    sort(a.begin(), a.end());
    ll ans = 0, x = 0;
    int i = 0, j = n - 1;
    ll k = sum / 2;

    if (sum % 2 == 1)
        k++;

    ll s = 0;
    while (s + a[i] <= k)
    {
        s += a[i];
        i++;
    }
    ans = k + (n - i);
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