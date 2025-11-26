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
    vector<ll> a(n),b(n);
    ia(a, n);
    ia(b, n);
    
    ll sum = 0;
    f(i,0,n){
        sum ^= (a[i] ^ b[i]);
    }

    if(sum==0){
        cout << "Tie" << endl;
        return;
    }

    ll k = 0;
    f(i,0,22){
        if((1<<i)&sum)
            k = i;
    }

    for (int i = n - 1; i >= 0; i--){
        if((1<<k)&(a[i]^b[i])){
            if(i&1)
                cout << "Mai" << endl;
            else
                cout << "Ajisai" << endl;

            return;
        }
    }

    cout << "Tie" << endl;
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