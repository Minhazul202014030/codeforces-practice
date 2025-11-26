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
    ll n, k, q;
    cin >> n >> k >> q;

    vector<pair<ll, ll>> a, b;
    while (q--){
        ll c, l, r;
        cin >> c >> l >> r;
        if(c==1)
            a.push_back({l - 1, r - 1});
        else
            b.push_back({l - 1, r - 1});
    }
    vector<ll> ans(n, 0);
    for(auto &[x,y]:a){
        f(i, x, y + 1) ans[i] = k;
    }

    auto t = ans;
    for(auto &[x,y]:b){
        f(i,x,y+1){
            if(t[i]==k)
                ans[i] = k + 1;
            else
                ans[i] = i % k;
        }
    }

    for(auto u:ans)
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