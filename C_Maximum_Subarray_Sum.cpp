#include <bits/stdc++.h>
using namespace std;
#define fastIO ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)
#define endl "\n"
typedef long long int ll;
const int MOD = 1000000007;

void solve()
{

    ll n, k;
    cin >> n >> k;
    string s;
    cin >> s;
    vector<ll> a(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    ll mxsum = 0, sum = 0;
    for (int i = 0; i < n; i++)
    {
        sum = max(a[i], sum + a[i]);
        mxsum = max(sum, mxsum);
        if (s[i] == '0')
        {
            sum = 0;
        }
    }
    mxsum = max(sum, mxsum);
    if (mxsum > k)
    {
        cout << "No" << endl;
        return;
    }
    else if (mxsum == k)
    {
        for (int i = 0; i < n; i++)
        {

            if (s[i] == '0')
            {
                a[i] = -1e18;
            }
        }
        cout << "Yes" << endl;
        for (auto u : a)
            cout << u << ' ';

        cout << endl;
        return;
    }

    int z_id = -1;
    for (int i = 0; i < n; i++)
    {
        if (s[i] == '0' && z_id == -1)
        {
            z_id = i;
        }
    }
    if (z_id == -1)
    {
        cout << "No" << endl;
        return;
    }
    ll pre = 0, suf = 0, mxpre = 0, mxsuf = 0;
    for (int i = z_id - 1; i >= 0; i--)
    {
        pre += a[i];
        mxpre = max(pre, mxpre);
    }
    for (int i = z_id + 1; i < n; i++)
    {
        if (s[i] == '0')
            break;
        suf += a[i];
        mxsuf = max(suf, mxsuf);
    }

    for (int i = 0; i < n; i++)
    {
        if (s[i] == '0')
        {
            a[i] = -1e18;
        }
    }

    ll x = k - (mxpre + mxsuf);
    a[z_id] = x;
    cout << "Yes" << endl;
    for (auto u : a)
        cout << u << ' ';

    cout << endl;
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