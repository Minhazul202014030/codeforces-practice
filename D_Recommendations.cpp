#include <bits/stdc++.h>
using namespace std;
#define FastIO ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)
#define endl "\n"
typedef long long int ll;

bool comp(pair<ll, ll> &a, pair<ll, ll> &b)
{
    if (a.first == b.first)
        return a.second > b.second;
    return a.first < b.first;
}

bool comp2(pair<ll, ll> &a, pair<ll, ll> &b)
{
    if (a.second == b.second)
        return a.first < b.first;
    return a.second > b.second;
}

void solve()
{
    ll n;
    cin >> n;
    vector<pair<ll, ll>> v, temp;

    for (ll i = 0; i < n; i++)
    {
        ll x, y;
        cin >> x >> y;
        v.push_back({x, y});
        // rightmostLeft[y] = x;
    }
    temp = v;
    sort(v.begin(), v.end());

    // for(auto u:v)
    // {
    //     cout << u.first << " " << u.second << endl;
    // }
    map<pair<ll, ll>, ll> mp;
    multiset<int> r, l;
    // mp[{v[0].first, v[0].second}] = 0;
    // r.insert(v[0].second);
    map<ll, ll> vis;
    for (ll i = 0; i < n; i++)
    {
        if(!vis[i])
        {
            vis[i] = 1;
            r.insert(v[i].second);
            for (ll j = i + 1; j < n;j++)
            {
                if(v[i].first==v[j].first)
                {
                    vis[j] = 1;
                    r.insert(v[j].second);

                }
                else{
                    break;
                }
            }
        }
        ll ans = 0;
        auto it = r.lower_bound(v[i].second);
        it++;
        if(it!=r.end())
        {
            ans = *it - v[i].second;
        }
        mp[{v[i].first, v[i].second}] = ans;
    }

    sort(v.begin(), v.end(), comp2);
    // for(auto u:v)
    // {
    //     cout << u.first << " " << u.second << endl;
    // }

    // l.insert(v[0].first);
    vis.clear();
    for (ll i = 0; i < n; i++)
    {
        if(!vis[i])
        {
            vis[i] = 1;
            l.insert(v[i].first);
            for (ll j = i+1; j < n; j++)
            {
                if(v[i].second==v[j].second)
                {
                    vis[j] = 1;
                    l.insert(v[j].first);
                }
                else{
                    break;
                }
            }
            
        }
        auto it = l.upper_bound(v[i].first);
        it--;
        ll ans = 0;
        if(it!=l.begin())
        {
            it--;
            ans = v[i].first - *it;
        }
        mp[{v[i].first, v[i].second}] += ans;
    }
    for (auto u : temp)
    {
        cout << mp[{u.first, u.second}] << endl;
    }
    // cout << endl;
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


