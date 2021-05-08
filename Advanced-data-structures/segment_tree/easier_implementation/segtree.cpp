// Range sum and update

#include "bits/stdc++.h"
using namespace std;

vector<long long> tree;

/**
 * (2 * Log(N)) * 2
 * Complexity O(LogN)
 **/
long long sum(int node, int node_low, int node_high, int query_low, int query_high)
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
	return sum(2 * node, node_low, lastLeft, query_low, query_high) + sum(2 * node + 1, lastLeft + 1, node_high, query_low, query_high);
}

/**
 *  Recursive update 
 * 	Complexity O(Logn)
 **/
void updateRecursive(int node, int node_low, int node_high, int query_low, int query_high, int val)
{
	if (query_low <= node_low && query_high >= node_high)
	{
		// Leaf
		tree[node] = val;
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

	// Now left and right child would be computed
	// update the node value to sum of its children
	tree[node] = tree[2 * node] + tree[2 * node + 1];
}

/**
 *  Iterative update, Prefer this easier to implement
 * 	Complexity O(Logn)
 **/
void updateIterative(int i, int v, int n)
{
	tree[n + i] = v;

	for (int j = (n + i) / 2; j >= 1; j /= 2)
	{
		tree[j] = tree[2 * j] + tree[2 * j + 1];
	}
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
	// resize fills with 0 zero by default
	tree.resize(2 * n);

	// Build the tree
	for (int i = 0; i < n; i++)
	{
		tree[n + i] = v[i];
	}
	for (int i = n - 1; i >= 1; i--)
	{
		tree[i] = tree[i * 2] + tree[i * 2 + 1];
	}

	while (q--)
	{
		int type;
		cin >> type;
		if (type == 1)
		{
			int a, b;
			cin >> a >> b;
			a--;
			// updateIterative(a, b, n);
			updateRecursive(1, 0, n - 1, a, a, b);
		}
		else
		{
			int a, b;
			cin >> a >> b;
			a--;
			b--;
			cout << sum(1, 0, n - 1, a, b) << "\n";
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
