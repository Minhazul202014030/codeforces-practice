#include <bits/stdc++.h>
using namespace std;
#define fastIO ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)
typedef long long int ll;
#define f(i, x, y) for (int i = x; i < y; i++)
#define ia(a, n)                \
    for (int i = 0; i < n; i++) \
    cin >> a[i]
#define ia1(a, n)                \
    for (int i = 1; i <= n; i++) \
    cin >> a[i]
#define endl "\n"
#define yes cout << "YES\n"
#define no cout << "NO\n"

const int MOD = 1000000007;

void solve()
{
    ll n;
    cin >> n;
    vector<ll> a(n);
    ia(a, n);
    map<ll, ll> cnt;
    f(i,0,n)
    {
        cnt[a[i]]++;
    }
    ll ans = 0;
    for(auto u:cnt){
        if(u.first>u.second)
            ans += u.second;
        else
            ans += (u.second - u.first);
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