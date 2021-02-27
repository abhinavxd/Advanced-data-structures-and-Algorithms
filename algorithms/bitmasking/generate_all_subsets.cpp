#include "bits/stdc++.h"
using namespace std;
void solve()
{
    vector<int> arr = {55, 988, 1230};
    int n = (int)arr.size();
    for (int mask = 0; mask < pow(2, n) - 1; mask++)
    {
        for (int i = 0; i < n; i++)
        {
            if (mask & (1 << i))
            {
                printf("%d ", arr[n - i - 1]);
            }
        }
        printf("\n");
    }
}

signed main()
{
    int t = 1;
    // cin >> t;
    while (t--)
        solve();

    return 0;
}
