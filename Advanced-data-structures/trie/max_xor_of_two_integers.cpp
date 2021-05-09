// https://binarysearch.com/problems/Max-XOR-of-Two-Integers

#include <bits/stdc++.h>
using namespace std;

int solve(vector<int> &nums)
{
    // build a trie
    vector<vector<int>> tree(1, vector<int>(2));
    int N = 0;

    for (int x : nums)
    {
        string s = bitset<31>(x).to_string();
        int node = 0;
        for (char c : s)
        {
            if (tree[node][c - '0'] == 0)
            {
                tree.push_back(vector<int>(2));
                tree[node][c - '0'] = ++N;
            }
            node = tree[node][c - '0'];
        }
    }
    int ans = 0;
    for (int x : nums)
    {
        int node = 0;
        int y = 0;

        // Use this string to create string with inverted bit
        string y1 = "";

        for (int j = 30; j >= 0; j--)
        {
            if (x & 1 << j)
            {
                // If bit is set
                if (tree[node][0] != 0)
                {
                    node = tree[node][0];
                    y1 += "0";
                }
                else
                {
                    node = tree[node][1];
                    y1 += "1";
                }
            }
            else
            {
                // bit not set
                if (tree[node][1] != 0)
                {
                    node = tree[node][1];
                    y1 += "1";
                }
                else
                {
                    node = tree[node][0];
                    y1 += "0";
                }
            }
        }
        bitset<31> bs(y1);
        y = (int)(bs.to_ulong());
        ans = max(ans, x ^ y);
    }
    return ans;
}

int main()
{
    return 0;
}