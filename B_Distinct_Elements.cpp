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
    for (ll i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    ll ans[n];
    ll cnt = 1;
    ans[0] = 1;
    for (int i = 1; i < n; i++)
    {
        ll dif = a[i] - a[i - 1];
        if(i-dif>=0)
            ans[i] = ans[i - dif];
        else{
            cnt++;
            ans[i] = cnt;
        }
    }

    for (auto u:ans){
        cout << u << ' ';
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