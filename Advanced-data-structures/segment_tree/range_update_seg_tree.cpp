// Range sum and update

#include "bits/stdc++.h"
using namespace std;

vector<long long> tree;

/**
 * Complexity O(LogN)
 **/
long long getValueAtIndex(int node, int node_low, int node_high, int query_low, int query_high)
{
    // Total overlap
    if (query_low <= node_low && query_high >= node_high)
    {
        return tree[node];
    }
    if (query_high < node_low || query_low > node_high)
    {
        return 0;
    }
    int lastLeft = (node_low + node_high) / 2;
    long long result = getValueAtIndex(2 * node, node_low, lastLeft, query_low, query_high) + getValueAtIndex(2 * node + 1, lastLeft + 1, node_high, query_low, query_high);
    return (result + tree[node]);
}

/**
 *  Recursive range update 
 * 	Complexity O(Logn)
 **/
void updateRecursive(int node, int node_low, int node_high, int query_low, int query_high, int val)
{
    if (query_low <= node_low && query_high >= node_high)
    {
        // Leaf
        tree[node] += val;
        return;
    }
    if (query_high < node_low || query_low > node_high)
    {
        return;
    }
    int lastLeft = (node_low + node_high) / 2;
    // Go to left child
    updateRecursive(2 * node, node_low, lastLeft, query_low, query_high, val);
    // Go to right child
    updateRecursive(2 * node + 1, lastLeft + 1, node_high, query_low, query_high, val);
}

void solve()
{
    int n, q;
    cin >> n >> q;

    vector<int> v(n);

    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
    }
    // Increase n till next power of 2
    while (__builtin_popcount(n) != 1)
    {
        v.push_back(0);
        n++;
    }
    // n nodes on leaf, n/2 nodes above it and so on.
    tree.resize(2 * n);

    // Build the tree
    for (int i = 0; i < n; i++)
    {
        tree[n + i] = v[i];
    }
    while (q--)
    {
        int type;
        cin >> type;
        if (type == 1)
        {
            int a, b, u;
            cin >> a >> b >> u;
            a--;
            b--;
            updateRecursive(1, 0, n - 1, a, b, u);
        }
        else
        {
            // val at pos k
            int k;
            cin >> k;
            k--;
            cout << getValueAtIndex(1, 0, n - 1, k, k) << "\n";
        }
    }
}

signed main()
{
#ifndef ONLINE_JUDGE

    // For getting input from input.txt file
    freopen("input.txt", "r", stdin);

    // Printing the Output to output.txt file
    freopen("output.txt", "w", stdout);

#endif
    cout << setprecision(12);
    cout << fixed;

    int t = 1;
    // cin >> t;
    while (t--)
        solve();

    return 0;
}
