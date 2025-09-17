#include <bits/stdc++.h>
using namespace std;
#define fastIO ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)
#define endl "\n"
typedef long long int ll;
const int MOD = 1000000007;

vector<int> st;
vector<int> sieve(int n)
{
    vector<bool> primes(n + 1, true);
    primes[0] = primes[1] = false;
    for (int i = 2; i * i <= n; i++)
    {
        if (primes[i])
        {
            for (int j = i * i; j <= n; j += i)
            {
                primes[j] = false;
            }
        }
    }
    // set<int> ans;
    vector<int> ans;
    for (int i = 0; i <= n; i++)
    {
        if (primes[i])
            ans.push_back(i);
    }
    return ans;
}

void solve()
{

    ll n, k;
    cin >> n >> k;
    vector<int> a;
    if (n == 2)
    {
        cout << k << ' ' << 2 * k << endl;
        return;
    }
    if (n - 1 > k)
    {
        cout << -1 << endl;
        return;
    }
    // if (n == 3)
    // {
    //     cout << k << ' ' << 2 * k << endl;
    //     return;
    // }
    else
    {
        int p = n - 2;
        int g = k - p;
        int z = (n + g + g) / g;
        a.push_back(g * z);
        a.push_back(g * (z + 1));
        for (int i = 1; i <= p; i++)
        {
            a.push_back(i);
        }
        for (auto u : a)
            cout << u << ' ';

        cout << endl;
    }
}

int main()
{
    fastIO;
    int t;
    st = sieve(9 * 1e6);
    cin >> t;
    while (t--)
    {
        solve();
    }

    return 0;
}