/**
 * 	
 * Given an array of n integers. Let's say that a segment of this array a[l..r] (1≤l≤r≤n) is good 
 * if the GCD of all numbers on this segment is 1. 
 * Your task is to find the shortest good segment.
 * 
 * Input - 
 *  5
 *	4 6 9 3 6
 * Output-
 * 	3
 * 
 * */

#include "bits/stdc++.h"
using namespace std;

const int N = 1e5 + 5;

int n;

int seg[3 * N];

int build(int l, int r, int in, int *arr)
{
	if (l == r)
		return seg[in] = arr[l];

	int mid = (l + r) / 2;

	return seg[in] = __gcd(build(l, mid, 2 * in + 1, arr),
						   build(mid + 1, r, 2 * in + 2, arr));
}

int query(int l, int r, int l1, int r1, int in)
{
	if (l1 <= l and r <= r1)
	{
		return seg[in];
	}
	if (l > r1 or r < l1)
	{
		return 0;
	}
	int mid = (l + r) / 2;

	// Calling left and right child
	return __gcd(query(l, mid, l1, r1, 2 * in + 1),
				 query(mid + 1, r, l1, r1, 2 * in + 2));
}

void solve()
{
	cin >> n;
	int arr[n];
	for (int i = 0; i < n; i++)
	{
		cin >> arr[i];
	}

	build(0, n - 1, 0, arr);

	int ans = INT_MAX;
	int i = 0, j = 0;
	while (i < n)
	{
		while (j < n and query(0, n - 1, i, j, 0) != 1)
		{
			j++;
		}
		if (j == n)
			break;

		ans = min(ans, (j - i + 1));
		i++;
		j = max(i, j);
	}
	if (ans == INT_MAX)
	{
		cout << -1 << "\n";
		return;
	}
	cout << ans << "\n";
}

signed main()
{
#ifndef ONLINE_JUDGE

	// For getting input from input.txt file
	freopen("input.txt", "r", stdin);

	// Printing the Output to output.txt file
	freopen("output.txt", "w", stdout);

#endif
	cout << setprecision(15);
	cout << fixed;

	int t = 1;
	// cin >> t;
	while (t--)
		solve();

	return 0;
}
