#include <bits/stdc++.h>
using namespace std;
#define fastIO ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)
#define endl "\n"
typedef long long int ll;
const int MOD = 1000000007;

void solve()
{

    string s;
    cin >> s;
    int cnt = 0;
    int open = 0;
    int n = s.length();
    for (int i = 0; i < n; i++)
    {
        if(s[i]=='(')
            open++;
        else
            open--;
        if(open==0)
            cnt++;
        if(cnt>=2)
        {
            cout << "YES" << endl;
            return;
        }
    }
    cout << "NO" << endl;
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