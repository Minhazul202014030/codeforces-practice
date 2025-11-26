#include <bits/stdc++.h>
using namespace std;

#define fastIO ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)
typedef long long int ll;

#define f(i, x, y) for (int i = x; i < y; i++)
#define ia(a, n)                \
    for (int i = 0; i < n; i++) \
    cin >> a[i]
#define ia1(a, n)                \
    for (int i = 1; i <= n; i++) \
    cin >> a[i]

#define endl "\n"
#define yes cout << "YES\n"
#define no cout << "NO\n"

const int MOD = 1000000007;

void solve()
{
    ll n;
    cin >> n;
    ll m = n;
    n *= 2;
    vector<ll> a(n);
    ia(a, n);
    ll sum = 0;
    f(i,0,n){
        if(i&1)
            sum += a[i];
        else
            sum -= a[i];
    }
    vector<ll> ans1, ans2;
    ans1.push_back(sum);
    ll sum1 = 0;
    if(m>=2)
        sum1 = -a[0] - a[1] + a[n-1] + a[n-2];
    
    // if(m==1){
    //     cout << sum << endl;
    //     return;
    // }
    // if(m==2){
    //     cout << sum << ' ' << sum1 << endl;
    //     return;
    // }
    f(i,2,n-2){
        if (i & 1)
            sum1 -= a[i];
        else
            sum1 += a[i];
    }
    ans2.push_back(sum1);

    f(i,1,m-1){
        if(i&1){
            ans1.push_back(ans1.back() - 2 * a[i] + 2 * a[n - 1 - i]);
        }
        else{
            ans2.push_back(ans2.back() - 2 * a[i] + 2 * a[n - 1 - i]);
        }
    }

    f(i,0,m/2){
        cout << ans1[i] << ' ' << ans2[i] << ' ';
    }
    if(m&1)
        cout << ans1.back();

    cout << endl;

    // cout << sum << endl;

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