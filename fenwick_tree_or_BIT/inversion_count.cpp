/*
Find inversion count of array
Input :
N - Number of elements of an array
Example :
5
8 4 9 2 8
Output : 
5
Large input : 
5
100000000 10000 10000000000 10 100000000
Output : 
5
*/
#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10;
int bit[N];

void update(int i, int x)
{
    for (; i < N; i += (i & -i))
        bit[i] += x;
}

int sum(int i)
{
    int ans = 0;
    for (; i > 0; i -= (i & -i))
        ans += bit[i];
    return ans;
}

int main()
{
#ifndef ONLINE_JUDGE
    // For getting input from input.txt file
    freopen("input.txt", "r", stdin);

    // Printing the Output to output.txt file
    freopen("output.txt", "w", stdout);
#endif

    int n;
    cin >> n;
    long long a[n + 10];
    map<long long, int> mp;
    for (int i = 1; i <= n; ++i)
    {
        cin >> a[i];
        mp[a[i]];
    }
    // Compression of numbers for the case where a[i] > 10 ^ 6
    // Because we can't store that big array in memory.
    int ptr = 1;
    for (auto &pr : mp)
        pr.second = ptr++;

    for (int i = 1; i <= n; ++i)
        a[i] = mp[a[i]];

    int inversion_ct = 0;
    for (int i = 1; i <= n; ++i)
    {
        inversion_ct += (sum(N - 5) - sum(a[i]));
        update(a[i], 1);
    }
    cout << inversion_ct << endl;
}