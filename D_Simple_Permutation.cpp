#include <bits/stdc++.h>
using namespace std;

const int MAX_N = 200005;
vector<bool> is_prime(MAX_N, true);
vector<int> primes;


void sieve()
{
    is_prime[0] = is_prime[1] = false;
    for (int i = 2; i < MAX_N; i++)
    {
        if (is_prime[i])
        {
            primes.push_back(i);
            for (int j = 2 * i; j < MAX_N; j += i)
                is_prime[j] = false;
        }
    }
}


vector<int> f(int n)
{
    set<int> st;
    for (int i = 1; i <= n; i++)
        st.insert(i);

    vector<int> p;
    int sum = 0, prime_count = 0;
    int required_primes = max(0, (n / 3) - 1);

    for (int i = 1; i <= n; i++)
    {
        bool found = false;
        for (int x : st)
        { 
            int new_sum = sum + x;
            int c_i = (new_sum + i - 1) / i; 
            if (is_prime[c_i])
            {
                p.push_back(x);
                st.erase(x);
                sum = new_sum;
                prime_count++;
                found = true;
                break;
            }
        }
        if (!found)
        { 
            int x = *st.begin();
            p.push_back(x);
            st.erase(x);
            sum += x;
        }
    }
    return p;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    sieve(); 
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<int> perm = f(n);
        for (int x : perm)
            cout << x << " ";
        cout << "\n";
    }
}
