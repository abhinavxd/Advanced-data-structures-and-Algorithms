#include <bits/stdc++.h>

using namespace std;
#define fast ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#define int long long
#define pb push_back
#define N 101

const int mod = 1000000007;

int ar[N][N], I[N][N];

void print(int A[][N], int dim)
{
    for (int i = 0; i < dim; i++)
    {
        for (int j = 0; j < dim; j++)
        {
            cout << A[i][j] % mod <<" ";
        }
        cout<<"\n";
    }
}

void mul(int A[][N], int B[][N], int dim)
{
    int res[dim + 1][dim + 1];
    for (int i = 0; i < dim; i++)
    {
        for (int j = 0; j < dim; j++)
        {
            res[i][j] = 0;
            for (int k = 0; k < dim; k++)
            {
                res[i][j] = (res[i][j]%mod + (A[i][k] % mod  * B[k][j] % mod)%mod)%mod;                
            }
        }
    }


    // copying back
    for (int i = 0; i < dim; i++)
    {
        for (int j = 0; j < dim; j++)
        {
            A[i][j] = res[i][j];
        }
    }
}

void power(int dim, int n)
{
    //identity matrix
    for (int i = 0; i < dim; i++)
    {
        for (int j = 0; j < dim; j++)
        {
            if (i == j)
            {
                I[i][j] = 1;
            }
            else
            {
                I[i][j] = 0;
            }
        }
    }

    // O(N)
    // for (int i = 0; i < n; i++)
    // {
    //     mul(I, ar, dim);
    // }

    // O(log(N))
    while(n) {
        if(n%2) {
            mul(I, ar, dim), n--;
        } else {
            mul(ar, ar, dim);
            n/=2;
        }
    }

    for (int i = 0; i < dim; i++)
    {
        for (int j = 0; j < dim; j++)
        {
            ar[i][j] = I[i][j];
        }
    }
}

signed main()
{
    fast

    #ifndef ONLINE_JUDGE 
  
    // For getting input from input.txt file 
    freopen("input.txt", "r", stdin); 
  
    // Printing the Output to output.txt file 
    freopen("output.txt", "w", stdout); 
  
	#endif

    int t, dim, n;
    cin >> t;
    while (t--)
    {
        cin >> dim >> n;
        for (int i = 0; i < dim; i++)
        {
            for (int j = 0; j < dim; j++)
            {
                cin >> ar[i][j];
            }
        }
        power(dim, n);
        print(ar, dim);
    }

    return 0;
}
