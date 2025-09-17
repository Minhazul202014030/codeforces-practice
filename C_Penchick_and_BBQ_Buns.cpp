#include <bits/stdc++.h>
using namespace std;
#define FastIO ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)
#define endl "\n"
typedef long long int ll;

void solve()
{
    int n;
    cin >> n;
    vector<int> v, v1;
    if (n % 2)
    {
        cout << "-1" << endl;
        return;
    }
    for (int i = 0; i < n / 2; i++)
    {
        cout << i + 1 << " " << i + 1 << " ";
    }
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
