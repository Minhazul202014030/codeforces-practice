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
    vector<ll> a(n);
    string s = "";
    for (ll i = 0; i < n; i++)
    {
        s = s + '?';
    }
    // cout << s << endl;

    string s1 = "";
    for (int i = 0; i < k; i++)
    {
        char c;
        cin >> c;
        s1 += c;
    }
    if(n==k)
    {
        s = "";
        for (ll i = 0; i < n; i++)
        {
            s = s + '-';
        }
        cout << s << endl;
        return;
    }
    ll cnt0 = 0, cnt1 = 0, cnt2 = 0;
    for (int i = 0; i < k; i++)
    {
        if (s1[i] == '0')
            cnt0++;
        if (s1[i] == '1')
            cnt1++;
        if (s1[i] == '2')
            cnt2++;
    }
    int i = 0;
    while(i<cnt0)
    {
        s[i] = '-';
        i++;
    }
    int j = n-1;
    i = 0;
    while (i < cnt1)
    {
        s[j] = '-';
        j--;
        i++;
    }
     i = 0;
    while(i<n)
    {
        if(i>=(cnt0+cnt2) && i< n-(cnt1+cnt2))
        {
            s[i] = '+';
        }
        i++;
    }

    cout << s << endl;
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