#include <bits/stdc++.h>
using namespace std;
#define FastIO ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)
#define endl "\n"
typedef long long int ll;

void solve()
{
    int n;
    cin >> n;
    string s;
    cin >> s;
    map<char, int> mp;
    for (int i = 0; i < n; i++)
    {
        mp[s[i]]++;
    }
    char c;
    int mx = -1;
    for(auto u:mp)
    {
        if(mx<u.second)
        {
            c = u.first;
        }
    }
    for (int i = 0; i < n; i++)
    {
        if(c!=s[i])
        {
            s[i] = c;
            break;
        }
    }
    cout << s;
    cout << endl;
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
