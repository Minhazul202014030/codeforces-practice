#include <bits/stdc++.h>
using namespace std;
#define fastIO ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)
#define endl "\n"
typedef long long int ll;
const int MOD = 1000000007;

void solve()
{

    int n, k;
    cin >> n >> k;
    // vector<ll> a(n);
    string s;
    cin >> s;
    int cnt0 = 0, cnt1 = 0;

    for (int i = 0; i < n; i++)
    {
        if (s[i] == '0')
            cnt0++;
        else
            cnt1++;
    }

    int k0 = cnt0 / 2;
    int k1 = cnt1 / 2;

    if (k > k0 && k > k1)
    {
        k -= k0;
        k0 = 0;
        if (k <= k1)
        {
            k1 -= k;
            k = 0;
        }
    }
    else if (k0 > k1 && k0 >= k)
    {
        k0 -= k;
        k = 0;
    }
    else if (k1 >= k0 && k1 >= k)
    {
        k1 -= k;
        k = 0;
    }

    if (k != 0 || k1 != k0)
        cout << "NO" << endl;
    else
        cout << "YES" << endl;
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