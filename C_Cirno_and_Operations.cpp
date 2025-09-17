#include <bits/stdc++.h>
using namespace std;
#define FastIO ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)
#define endl "\n"
typedef long long int ll;

void solve()
{
    int n;
    cin >> n;
    vector<ll> a(n);
    ll ans = -1e18, sum = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        sum += a[i];
    }
    // ans = max(sum, ans);
    int i = n, k = n;
    vector<ll> v1, v2;
    while (i > 0)
    {
        sum = 0;
        for (int j = 0; j < k; j++)
        {
            sum += a[j];
        }
        
        if (i == n)
        {
            ans = max(ans, sum);
        }
        else
        {
            ans = max(ans, sum);
            ans = max(sum * -1, ans);
        }

        for (int j = 0; j < k - 1; j++)
        {
            a[j] = a[j + 1] - a[j];
        }
        k--;
        i--;
    }
    cout << ans << endl;
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