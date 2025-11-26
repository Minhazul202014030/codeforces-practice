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
    ll r, x, d, n;
    cin >> r >> x >> d >> n;
    string s;
    cin >> s;

    ll cnt = 0;

    int ans = n;

    if(s[0]=='2' && r>=2100){
        ll i = 0;
        ll cnt = 0;
        while(s[i]!='1' && i<n){
            cnt++;
            i++;
        }
        ans = n - cnt;
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