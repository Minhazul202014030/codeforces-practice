#include <bits/stdc++.h>
using namespace std;
#define fastIO ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)
#define endl "\n" 
#define yes cout << "YES\n"
#define no cout << "NO\n"
typedef long long int ll;
const int MOD = 1000000007;

void solve()
{
    ll n;
    cin >> n;
    vector<ll> a(n);
    ll e1 = -1, e2 = -1;
    for (ll i = 0; i < n; i++)
    {
        cin >> a[i];
        if(a[i]%2==0){
            if(e1==-1)
                e1 = a[i];
            else
                e2 = a[i];
        }
    }

    if(e1!=-1 && e2!=-1){
        cout << e1 << ' ' << e2 << endl;
        return;
    }
    if(e1!=-1){
        for (ll i = 0; a[i] < e1; i++){
            if(a[i]!=e1 && (e1%a[i])%2==0){
                cout << a[i] << ' ' << e1 << endl;
                return;
            }
        }
    }
    if(n<30){
        for (int i = 0; i < n-1; i++)
        {
            for (int j = i+1; j < n; j++)
            {
                if((a[j]%a[i])%2==0){
                    cout << a[i] << ' ' << a[j] << endl;
                    return;
                }
            }
            
        }
        cout << -1 << endl;
    }
    else{
        for (int i = 0; i < n - 1; i++){
            if((a[i+1]%a[i])%2==0){
                cout << a[i] << ' ' << a[i + 1] << endl;
                return;
            }
        }
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