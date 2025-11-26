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
    ll n, k;
    cin >> n >> k;
    string s;
    cin >> s;

    ll ans = 0;
    for (int i = 0; i < n; i++)
    {
        if (s[i] == '0')
            continue;
        ll cnt = 0;
        for (int j = 1; j<k; j++)
        {
            if(i-j>=0 )
            {
                if (s[i - j] == '0')
                    cnt++;
                else break;
                
            }
            if(cnt==k-1 || i-j<0){
                ans++;
                break;
            }
        }
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