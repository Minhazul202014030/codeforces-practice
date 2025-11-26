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
    string s;
    cin >> s;
    vector<ll> pa(n, 0), pb(n, 0), cnta(n, 0), scnta(n, 0), sa(n, 0), sb(n, 0);
    cnta[0] = s[0] == 'a';
    for (int i = 1; i < n; i++)
    {
        pa[i] = pa[i - 1];
        pb[i] = pb[i - 1];
        cnta[i] = cnta[i - 1];
        if(s[i]=='a'){
            cnta[i]++;
            pb[i] += i + 1 - cnta[i];
        }
        else{
            pa[i] += cnta[i];
        }
    }
    scnta[n - 1] = s[n - 1] == 'a';
    for (int i = n - 2; i >= 0; i--){
        sa[i] = sa[i + 1];
        sb[i] = sb[i + 1];
        scnta[i] = scnta[i + 1];

        if(s[i]=='a'){
            scnta[i]++;
            sb[i] += n - i - scnta[i];
        }
        else{
            sa[i] += scnta[i];
        }
    }

    ll ans = 1e18;
    for (int i = 0; i < n; i++)
    {
        ans = min({ans, pa[i] + sa[i], pb[i] + sb[i]});
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