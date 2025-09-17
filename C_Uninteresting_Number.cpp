#include <bits/stdc++.h>
using namespace std;
#define FastIO ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)
#define endl "\n"
typedef long long int ll;

void solve()
{
    string s;
    cin >> s;
    int n = s.length();
    vector<vector<bool>> dp(n + 1, vector<bool>(9, false));
    dp[0][0] = true;

    for (int i = 0; i < n; i++)
    {
        int digit = s[i] - '0';
        for (int rem = 0; rem < 9; rem++)
        {
            if (dp[i][rem] == true)
            {
                int rem_so_far = ((rem * 10) + digit) % 9;
                dp[i + 1][rem_so_far] = true;
                if (digit == 2 || digit == 3)
                {
                    rem_so_far = ((rem * 10) + (digit * digit)) % 9;
                    dp[i + 1][rem_so_far] = true;
                }
            }
        }
    }
    if (dp[n][0] == true)
        cout << "YES" << endl;
    else
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
