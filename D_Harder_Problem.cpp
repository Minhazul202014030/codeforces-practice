#include <bits/stdc++.h>
using namespace std;
#define FastIO ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)
#define endl "\n"
typedef long long int ll;

void solve()
{
    set<int> st;

    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        st.insert(i);
    }
    vector<int> v(n);
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
    }
    for (int i = 0; i < n; i++)
    {
        if (st.find(v[i]) != st.end())
        {
            cout << v[i] << " ";
            // auto u = st.find(v[i]);
            st.erase(*st.find(v[i]));
        }
        else
        {
            cout << *st.begin() << " ";
            st.erase(*st.begin());
        }
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