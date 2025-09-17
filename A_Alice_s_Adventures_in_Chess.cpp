#include <bits/stdc++.h>
using namespace std;
#define FastIO ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)
#define endl "\n"
typedef long long int ll;

void solve()
{
    int n, a, b;
    cin >> n >> a >> b;
    string s;
    cin >> s;
    int x = 0, y = 0;
    int flag = 0;
    while (x < a && y < b)
    {
        for (int i = 0; i < n; i++)
        {
            if (s[i] == 'N')
            {
                y = y + 1;
            }
            else if (s[i] == 'S')
            {
                y = y - 1;
            }
            else if (s[i] == 'E')
            {
                x += 1;
            }
            else if (s[i] == 'W')
            {
                x -= 1;
            }
            if (x == a && y == b)
            {
                // cout << "YES" << endl;
                flag = 1;
                break;
                // return;
            }
        }

        if (flag)
        {
            cout << "YES" << endl;
            // flag = 1;
            // break;r
            return;
        }
        else if (x == 0 && y == 0)
            break;
    }
    cout << "NO" << endl;
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
