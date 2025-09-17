#include <bits/stdc++.h>
using namespace std;
#define fastIO ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)
#define endl "\n"
#define yes cout << "Yes\n"
#define no cout << "No\n"
typedef long long int ll;
const int MOD = 1000000007;

void solve()
{
            ll n,k;
            cin >> n>>k;
            vector<ll> a(n);
            for (int i = 0; i < n; i++)
            {
                // cin >> a[i];
                a[i] = i + 1;
            }
            if(k%2)
            {
                no;
                return;
            }
            for (int i = 0; i < n/2; i++)
            {
                if(k<(a[n-i-1]-a[i])*2)
                {
                    swap(a[i], a[k/2 +i]);
                    // k -= (a[i] - 1) * 2;
                    k = 0;
                    break;
                }
                else
                {
                    k -= (a[n - i - 1]-a[i]) * 2;
                    swap(a[i], a[n - i - 1]);
                    
                    // cout << k << endl;
                }
                if(k==0)break;
            }

            if(k!=0)
                no;
            else
            {
                yes;
                for(auto u:a)
                    cout << u << ' ';

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