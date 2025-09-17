#include <bits/stdc++.h>
using namespace std;
#define FastIO ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)
#define endl "\n"
typedef long long int ll;

void solve()
{
    int n;
    cin >> n;
    if (n < 5)
        cout << "-1" << endl;
    else
    {
        vector<int> v;
        for (int i = 1; i <= n; i++)
        {
            if(i%2==1 && i!=5)
            {
                v.push_back(i);
            }
        }
        v.push_back(5);
        v.push_back(4);
        for (int i = 1; i <= n; i++)
        {
            if (i % 2 == 0 && i != 4)
            {
                v.push_back(i);
            }
        }
        for(auto u:v)
        {
            cout << u << " ";
        }
        cout << endl;
    }
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
