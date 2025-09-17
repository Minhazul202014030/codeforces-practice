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
    vector<ll> a(n);
    map<int, int> f;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        f[a[i]]++;
    }
    sort(a.begin(), a.end());

    if (a[n - 1] - a[0] - 1 > k)
    {
        cout << "Jerry" << endl;
    }
    else if (f[a[n - 1]] > 1 && ((a[n - 1] - a[0] - 1) == k))
    {
        cout << "Jerry" << endl;
    }
    else
    {
        ll sum = 0;
        for (int i = 0; i < n; i++)
            sum += a[i];
        if (sum % 2)
            cout << "Tom" << endl;
        else
            cout << "Jerry" << endl;
    }
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