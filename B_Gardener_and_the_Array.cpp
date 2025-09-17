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
    vector<vector<ll>> a(n);
    unordered_map<ll,ll> mp;
    for (int i = 0; i < n; i++)
    {
        int k;
        cin >> k;
        while(k--)
        {
            int x;
            cin >> x;
            mp[x]++;
            a[i].push_back(x);
        }
    }
    
    for(auto &u:a)
    {
        bool valid = true;
        for(auto &v:u)
        {
            if(mp[v]==1)
            {
                valid = false;
                break;
            }
        }
        if(valid)
        {
            cout << "Yes" << endl;
            return;
        }
       
    }
    cout << "No" << endl;
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