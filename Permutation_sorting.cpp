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
    vector<ll> a(n), b(n, 0);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    if (n % 2 == 1 && a[n / 2] != ((n + 1) / 2))
    {
        cout << -1 << endl;
        return;
    }
    if (is_sorted(a.begin(), a.end()))
    {
        cout << 0 << endl;
        return;
    }
    int cnt = 0;
    while (1)
    {
        if (is_sorted(a.begin(), a.end()))
        {
            break;
        }
        for (int i = 0; i < n; i++)
        {
            b[i] = a[a[i]-1];
        }
        cnt++;
        a = b;
    }
    cout << cnt << endl;
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