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
    for (int i = 0; i < n; i++)
        cin >> a[i];
    
    for (int i = 0; i < n-1; i++)
    {
        if(abs(a[i]-a[i+1])<=1)
        {
            cout << 0 << endl;
            return;
        }
    }
    for (int i = 0; i < n - 2; i++)
    {

        ll mn = min(a[i + 1], a[i + 2]);
        ll mx = max(a[i + 1], a[i + 2]);
        
        if ((a[i] >= mn && a[i] <= mx) || ((a[i]-1) >= mn && (a[i]-1) <= mx) || 
        ((a[i]+1) >= mn && (a[i]+1) <= mx))
        {
            cout << 1 << endl;
            return;
        }

        
    }
    for (int i = 2; i < n; i++)
    {

        ll mn = min(a[i - 1], a[i - 2]);
        ll mx = max(a[i - 1], a[i - 2]);

        if ((a[i] >= mn && a[i] <= mx) || ((a[i] - 1) >= mn && (a[i] - 1) <= mx) ||
            ((a[i] + 1) >= mn && (a[i] + 1) <= mx))
        {
            cout << 1 << endl;
            return;
        }
    }
    cout << -1 << endl;
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

