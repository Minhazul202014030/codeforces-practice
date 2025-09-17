#include <bits/stdc++.h>
using namespace std;
#define fastIO ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)
#define endl "\n"
#define yes cout << "YES\n"
#define no cout << "NO\n"
typedef long long int ll;
const int MOD = 1000000007;

void solve()
{
    ll n;
    cin >> n;
    vector<ll> a(n);
    set<int> st;
    int cnt = 0;
    for (ll i = 0; i < n; i++)
    {
        cin >> a[i];
        if (a[i] > 0)
            st.insert(a[i]);
        if (a[i] == 0)
        {
            cnt++;
        }
    }
    if (cnt > 0)
        no;
    else if (st.size() <=1)
        yes;
    else
        no;
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