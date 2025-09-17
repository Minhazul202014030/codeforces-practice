#include <bits/stdc++.h>
using namespace std;
#define FastIO ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)
#define endl "\n"
typedef long long int ll;
const int mod = 1e9 + 7;

void solve()
{
    int n;
    cin >> n;
    int ans=0;
    
    if (n < 3)
        ans = n+1;
    // else if (n >= 3 && n < 15)
    //     ans = 3;
    else
    {
        int m = n / 15;
        ans = (m - 1) * 3;
        if(n-(m*15)>=3)
            ans += 3;
        else
            ans += (n+1 - (m * 15));

        ans += 3;
    }
    cout << ans << endl;
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