#include "bits/stdc++.h"
using namespace std;
void solve()
{
    int n = 3;

    for (int i = 0; i < (1 << n); i++)
    {
        for (int j = 0; j < n; j++)
        {
            if ((1 << j) & i)
            {
                cout << (j + 1) << " ";
            }
        }
        cout << "\n";
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
