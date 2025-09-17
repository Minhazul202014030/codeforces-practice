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
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    sort(a.begin(), a.end());

    if(n==1)
    {
        cout << 1 << endl;
        return;
    }
    if(n==2)
    {
        cout << 3 << endl;
        return;
    }

    ll g = gcd(a[n - 1] - a[0], a[n - 1]- a[1]);

    for (int i = 2; i < n-1; i++)
    {
        g = gcd(g, a[n - 1]- a[i]);
    }

    ll cnt = 1;
    ll ans = 0;
    for (int i = n-1; i >=1; i--)
    {
        if(abs(a[i]-a[i-1])>g)
        {
            ans += cnt;
            break;
        }
        else
            cnt++;
    }

    if(ans==0)
        a.push_back(a[n - 1] + g);

    ll sz = a.size();

    for (int i = 0; i < sz-1; i++)
    {
        ans += (abs(a[sz - 1] - a[i]) / g);
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