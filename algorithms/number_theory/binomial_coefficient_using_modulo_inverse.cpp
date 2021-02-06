#include <bits/stdc++.h>

using namespace std;
#define fast ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#define ll long long int
#define pb push_back
const int mod = 1000000007;
int F[1000001];

int power(int a, int n)
{
    int res = 1;
    while (n)
    {
        if (n % 2)
        {
            res = (res * 1LL * a) % mod;
        }
        // N must be even
        n = n >> 1; // n/=2
        // change a to a^2
        a = (a * 1LL * a) % mod;
    }
    return res;
}

/**
 * n choose k
 * */
int C(int n, int k)
{
    if (k > n)
        return 0;
    int res = F[n];
    res = (res * 1LL * power(F[k], mod - 2)) % mod;
    res = (res * 1LL * power(F[n - k], mod - 2)) % mod;
    return res;
}

int main()
{
    fast
#ifndef ONLINE_JUDGE

        // For getting input from input.txt file
        freopen("input.txt", "r", stdin);

    // Printing the Output to output.txt file
    freopen("output.txt", "w", stdout);

#endif

    F[0] = F[1] = 1;
    for (int i = 2; i <= 1000000; i++)
    {
        F[i] = (F[i - 1] * i) % mod;
    }

    int q;
    cin >> q;
    int n, k;
    while (q--)
    {
        cin >> n >> k;
        cout << C(n, k) << "\n";
    }

    return 0;
}
