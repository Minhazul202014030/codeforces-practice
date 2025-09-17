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
    unordered_map<ll, ll> cnt;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        cnt[a[i]]++;
    }

    if (n % 2 == 1)
    {
        cout << "No" << endl;
        return;
    }
    else
    {
        if (cnt[1] > n / 2 || cnt[2] > n / 2)
            cout << "No" << endl;
        else
            cout << "Yes" << endl;
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