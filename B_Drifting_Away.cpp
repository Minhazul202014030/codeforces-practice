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
    string s;
    cin >> s;
    ll c1, c2, c3;
    c1 = c2 = c3 = 0;
    ll n = s.length();
    f(i,0,n){
        if(s[i]=='<')
            c1++;
        else if(s[i]=='>')
            c3++;
        else if(s[i]=='*')
            c2++;
    }
    string ck = string(c1, '<') + string(c2, '*') + string(c3, '>');

    if(s!=ck || c2>1)
        cout << -1 << endl;
    else
        cout << max(c1 + c2, c2 + c3) << endl;
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