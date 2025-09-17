#include <bits/stdc++.h>
using namespace std;
#define fastIO ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)
#define endl "\n"
#define yes cout << "YES\n"
#define no cout << "NO\n"
typedef long long int ll;
const int MOD = 1000000007;

int z = 1e7 + 5;
vector<int> primes(z + 1, -1);
void sieve()
{

    primes[0] = primes[1] = 0;
    for (int i = 2; i <= z; i++)
    {
        if (primes[i] == -1)
        {
            for (int j = i; j <= z; j += i)
            {
                if (primes[j] == -1)
                    primes[j] = i;
            }
        }
    }
}

void solve()
{

        int n, m;
        cin >> n >> m;

        if (m == 1 || n == 1)
        {
            yes;
            return;
        }

        if (primes[n] <= m)
            no;
        else
            yes;
}

int main()
{
        fastIO;
        sieve();
        int t;
        cin >> t;
        while (t--)
        {
            solve();
        }

        return 0;
}