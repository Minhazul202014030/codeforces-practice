#include <bits/stdc++.h>
using namespace std;
#define fastIO ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)
#define endl "\n"
typedef long long int ll;
const int MOD = 1000000007;

void solve()
{
    int n;
    string s;
    cin >> n >> s;
    if(s[0]==s[n-1])
    {
        if(s[0]=='A')
            cout << "Alice";
        else
            cout << "Bob";
        cout << endl;
        return;
    }
    if(s[0]=='A'){
        int r = n - 1, r1 = -1;
        for (int i = n - 2; i >= 0; i--)
        {
            if (s[n - 1] == s[i])
            {
                r1 = i;
                break;
            }
        }
        if (r1 != -1)
        {
            cout << "Bob";
           
        }
        else
        {
            cout << "Alice";
           
        }
        cout << endl;
        
    }
    else{ //bob at s[0]
        if (s[n - 2] == 'B')
            cout << "Bob";
        else
            cout << "Alice";
        cout << endl;
    }
    
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