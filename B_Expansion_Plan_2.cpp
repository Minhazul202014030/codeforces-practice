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
    ll n, x, y;
    cin >> n >> x >> y;

    x = abs(x);
    y = abs(y);

    string s;
    cin >> s;
    ll a = 0, b = 0;
    for(auto u:s){
        if(u=='8')
            b += 2;
        else
            b++;
        a++;
    }
    if(x+y<=b && x<=a && y<=a)
        yes;
    else
        no;
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