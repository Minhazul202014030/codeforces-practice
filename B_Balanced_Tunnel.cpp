#include <bits/stdc++.h>
using namespace std;
#define fastIO ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)
#define endl "\n"
typedef long long int ll;
const int MOD = 1000000007;

void solve()
{

    ll n;
    cin >> n;
    vector<int> a(n), b(n), seen(n + 1, 0);
    queue<int> q;
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        q.push(x);
    }
    for (int i = 0; i < n; i++)
    {
        cin >> b[i];
    }
    int cnt = 0;
    int i = 0;
    while (!q.empty() && i < n)
    {
        int cur = q.front();
        if (seen[cur])
        {
            
        }
        else if (cur == b[i])
            q.pop();
        else
        {
            cnt++;
            seen[b[i]] = 1;
        }
        i++;
    }

    cout << cnt << endl;
}

int main()
{
    fastIO;
    int t = 1;
    // cin >> t;
    while (t--)
    {
        solve();
    }

    return 0;
}