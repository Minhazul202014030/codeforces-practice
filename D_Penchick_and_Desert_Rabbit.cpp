// #include <bits/stdc++.h>
// using namespace std;
// #define FastIO ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)
// #define endl "\n"
// typedef long long int ll;

// class DSU
// {
// public:
//     unordered_map<int, int> parent; // Parent of each node
//     unordered_map<int, int> size;   // Size of each set

//     // Find with path compression
//     int find(int x)
//     {
//         if (parent[x] != x)
//         {
//             parent[x] = find(parent[x]); // Path compression
//         }
//         return parent[x];
//     }

//     // Union by size
//     void unionSets(int x, int y)
//     {
//         int rootX = find(x);
//         int rootY = find(y);

//         if (rootX != rootY)
//         {
//             if (size[rootX] < size[rootY])
//             {
//                 swap(rootX, rootY); // Ensure rootX is the larger tree
//             }
//             parent[rootY] = rootX;      // Merge rootY into rootX
//             size[rootX] += size[rootY]; // Update size of the root set
//         }
//     }

//     // Add a new element to the DSU
//     void add(int x)
//     {
//         if (parent.find(x) == parent.end())
//         {
//             parent[x] = x;
//             size[x] = 1;
//         }
//     }
// };

// void solve()
// {
//     DSU ds;
//     int n;
//     cin >> n;
//     vector<int> v;
//     int mx = 0;
//     int max_first_occr = -1;
//     for (int i = 0; i < n; i++)
//     {
//         int x;
//         cin >> x;
//         v.push_back(x);
//         ds.add(x);
//         if (x > mx)
//         {
//             mx = x;
//             // if (max_first_occr == -1)
//             max_first_occr = i;
//         }
//     }
//     // cout << max_first_occr <<endl;
//     set<int> max_er_pore;
//     stack<int> max_er_age;
//     max_er_pore.insert(v[max_first_occr]);
//     for (int i = max_first_occr + 1; i < n; i++)
//     {
//         ds.unionSets(v[max_first_occr], v[i]);
//         max_er_pore.insert(v[i]);
//     }
//     for (int i = max_first_occr - 1; i >= 0; i--)
//     {
//         int u = *max_er_pore.begin();
//         if (v[i] > u)
//         {
//             ds.unionSets(u, v[i]);
//             if (!max_er_age.empty())
//             {
//                 int uu = max_er_age.top();
//                 ds.unionSets(v[i], uu);
//                 max_er_pore.insert(uu);
//                 max_er_age.pop();
//             }
//         }
//         else if (v[i] <= u)
//         {
//             if(!max_er_age.empty() && max_er_age.top()>v[i])
//             {
//                 v[i] = max_er_age.top();
//             }
//             max_er_age.push(v[i]);
//         }
//     }

//     int max2 = 0;
//     int sz = max_er_age.size();
//     // cout << sz;
//     while (!max_er_age.empty())
//     {
//         int u = max_er_age.top();
//         max2 = max(max2, u);

//         cout << max2 << " ";
//         max_er_age.pop();
//     }

//     for (int i = sz; i < n; i++)
//     {
//         cout << ds.parent[v[i]] << " ";
//     }

//     cout << endl;
// }

// int main()
// {
//     FastIO;
//     int t;
//     cin >> t;
//     while (t--)
//     {
//         solve();
//     }

//     return 0;
// }

#include <iostream>
#include <vector>
using namespace std;

vector<int> parent, csize, maxHeight;

// Find with path compression
int find(int x) {
    if (parent[x] != x) {
        parent[x] = find(parent[x]);  // Path compression
    }
    return parent[x];
}

// Union by size
void unite(int x, int y) {
    int rootX = find(x);
    int rootY = find(y);
    if (rootX != rootY) {
        if (csize[rootX] < csize[rootY]) {
            swap(rootX, rootY);
        }
        parent[rootY] = rootX;
        csize[rootX] += csize[rootY];
        maxHeight[rootX] = max(maxHeight[rootX], maxHeight[rootY]);
    }
}

void solve() {
    int n;
    cin >> n;
    vector<int> heights(n);
    
    // Initialize DSU structures
    parent.resize(n);
    csize.resize(n);
    maxHeight.resize(n);
    
    for (int i = 0; i < n; i++) {
        cin >> heights[i];
        parent[i] = i;
        csize[i] = 1;
        maxHeight[i] = heights[i];
    }
    
    // Left to right pass
    for (int i = 1; i < n; i++) {
        if (heights[i] <= heights[i - 1]) { // Jump condition (forward)
            unite(i, i - 1);
        }
    }

    // Right to left pass
    for (int i = n - 2; i >= 0; i--) {
        if (heights[i] <= heights[i + 1]) { // Jump condition (backward)
            unite(i, i + 1);
        }
    }

    // Output the max height in each component
    for (int i = 0; i < n; i++) {
        cout << maxHeight[find(i)] << " ";
    }
    cout << endl;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
