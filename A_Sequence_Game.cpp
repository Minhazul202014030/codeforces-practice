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
    ll n, x;
    cin >> n;
    vector<ll> a(n);
    for (ll i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    cin >> x;
    ll cnt = 0;
    
    for (int i = 0; i < n - 1; i++)
    {
        if (x >= min(a[i], a[i + 1]) && x <= max(a[i], a[i + 1]))
        {
            cnt = 0;
        }
        else{
            cnt++;
            if(cnt==2){
                no;
                return;
            }
        }
    }
    yes;
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