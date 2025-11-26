#include <bits/stdc++.h>
using namespace std;

#define fastIO ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)
typedef long long int ll;

#define f(i, x, y) for (int i = x; i < y; i++)
#define ia(a, n) for (int i = 0; i < n; i++) cin >> a[i]
#define ia1(a, n) for (int i = 1; i <= n; i++) cin >> a[i]

#define endl "\n"
#define yes cout << "YES\n"
#define no cout << "NO\n"

const int MOD = 1000000007;

void solve() {
    ll n,x;
    cin >> n >> x;
    vector<ll> a(n);
    ia(a, n);
    ll ans1 = 0, ans2 = 0;
    f(i,0,n){
        if(a[i]<x)
            ans1++;
        else if(a[i]>x)
            ans2++;
    }
   
    cout << (ans1 > ans2 ? x - 1 : x + 1) << endl;
}

int main() {
    fastIO;
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}