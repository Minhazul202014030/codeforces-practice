#include <bits/stdc++.h>
using namespace std;
#define fastIO ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)
#define endl "\n"
typedef long long int ll;
const int MOD = 1000000007;

ll pre[200001][30];

void precompute()
{
    for (int i = 0; i < 30;i++)
    {
        for (int j = 1; j < 200001; j++)
        {
            if((j & (1LL<<i))==0)
            {
                pre[j][i] = pre[j - 1][i] + 1;
            }
            else
                pre[j][i] = pre[j - 1][i];
        }
        
    }
}

void solve()
{

    ll l,r;
    cin >> l >> r;
    //vector<ll> a(n);
    /*
    ll f[18]={0};

    for (int i = l; i <=r; i++)
    {
        for (int j = 0; j < 18; j++)
        {
            if((i & (1LL<<j)) == 0)
                f[j]++;
        }
    }
    ll mn = 1e9;
    for (int i = 0; i < 18; i++)
    {
        mn = min(mn, f[i]);
    }

    cout << mn << endl;

    */
    ll mn = 1e9;
    for (int i = 0; i < 30; i++)
    {
        ll ans = pre[r][i] - pre[l - 1][i];
        mn = min(ans, mn);
    }

    cout << mn << endl;
}

int main()
{
    fastIO;
    int t;
    cin >> t;
    precompute();
    while (t--)
    {
        solve();
    }

    return 0;
}