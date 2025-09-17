#include <bits/stdc++.h>
using namespace std;
#define FastIO ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)
#define endl "\n"
typedef long long int ll;

bool check(ll mid, vector<ll> &v, ll k)
{
    vector<ll> tmp;
    tmp = v;
    ll n = v.size();
    ll tmpk = k;
    for (ll i = 0; i < n - 1; i++)
    {
       
        ll x ;
        
        tmp[i] = mid;
        k -= (mid - v[i]);
      
        ll j = i + 1;
        while (j < n && k>=0)
        {
            // mid--;
            x = (tmp[j - 1] - 1) - tmp[j];
            if (x <= 0)
                return true;

            if (k < x)
            {
               
                break;
            }
            tmp[j] = tmp[j - 1] - 1;
            k -= (tmp[j - 1] - 1 - v[j]);
            j++;
        }
        k = tmpk;
        tmp = v;
        // }
    }
    return false;
}

void solve()
{
    ll n, k;
    cin >> n >> k;
    vector<ll> v(n);
    for (ll i = 0; i < n; i++)
    {
        cin >> v[i];
    }
    ll ans = 0;
    for (ll i = 0; i < n; i++)
    {
        ans = max(ans, v[i]);
    }
    ll lo = ans,  hi = ans+k;
    while (lo <= hi)
    {
        ll mid = lo + (hi - lo) / 2;
        if (check(mid, v, k) == true)
        {
            ans = mid;
            lo = mid + 1;
        }
        else
        {
            hi = mid - 1;
        }
    }
    cout << ans;
    cout << endl;
}

int main()
{
    FastIO;
    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }

    return 0;
}