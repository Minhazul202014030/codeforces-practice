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
    vector<ll> a(n), suf(n + 1, 0), b(n);
    multiset<ll> st;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        st.insert(a[i]);
    }
    // b = a;
    // sort(b.begin(), b.end());
    for (int i = n - 1; i >= 0; i--)
    {
        suf[i] = a[i] + suf[i + 1];
    }
    // for (int i = n - 1; i >= 0; i--)
    // {
    //     cout << suf[i] << ' ';
    // }
    int j = n - 1;
    for (int i = 0; i < n; i++)
    {
        ll x = *st.rbegin();
        cout << max(suf[n - i - 1], suf[n - i] + x) << ' ';
        // st.erase(a[n - i - 1]);
        st.erase(st.find(a[n - i - 1]));
    }
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