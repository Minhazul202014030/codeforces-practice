#include <bits/stdc++.h>
using namespace std;
#define fastIO ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)
#define endl "\n" 
#define yes cout << "YES\n"
#define no cout << "NO\n"
typedef long long int ll;
const int MOD = 1000000007;

vector<ll> powr(32, 0);

void solve()
{
    ll x,y,z;
    cin >> x >> y >> z;
    ll ans = x ^ y ^ z;
    ll mx = max({x, y, z});
    ll mn = min({x, y, z});
    // ll p = log2(mx) + 1;

    if(mx==0){
        yes;
        return; 
    }
    if(mn==0){
        no;
        return;
    }

    ll p = 0;

    for (int i = 0; i <= 30; i++)
    {
        if((mx&(1<<i)) !=0)
            p = i;
    }
    

    ll a = powr[p+1]-1;

    if(ans==a)
        yes;
    else
        no;

    // cout << a << endl;
}

int main()
{
    fastIO;
    int t;

    powr[0] = 1;
    for (int i = 1; i <= 31; i++)
    {
        powr[i] = powr[i - 1] * 2;
    }
    

    cin >> t;
    while (t--)
    {
        solve();
    }

    return 0;
}