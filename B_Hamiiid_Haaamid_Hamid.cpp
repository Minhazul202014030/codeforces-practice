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
    ll n,x;
    cin >> n>>x;
    string s;
    cin >> s;
    int i=0, cnt = 0;
    while(i<n){
        if(s[i]=='#')
            cnt++;

        i++;
    }
    if(cnt<1){
        cout << 1 << endl;
        return;
    }
    int l = x;
    int r = n - x + 1;
    cout << min(l, r) << endl;
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