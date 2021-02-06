#include <bits/stdc++.h>

using namespace std;
#define fast ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#define int long long int
#define pb push_back

const int mod = 1000000007;

int arr[3];
int I[3][3];
int T[3][3];

void mul(int a[3][3],int b[3][3], int dim) 
{
	int res[dim+1][dim+1];

	for(int i = 1; i <= dim; i++) {
		for(int j = 1; j <= dim; j++) {
			res[i][j] = 0;
			for(int k = 1; k <= dim; k++) {
				int tmp =(a[i][k]* b[k][j]) % mod;
				res[i][j] = (res[i][j] + tmp) % mod;
			}
		}
	}
	for(int i = 1; i <= dim ; i++) {
		for(int j = 0; j <= dim ; j++) {
			a[i][j] = res[i][j];
		}
	}
}

int getFib(int n){
	if (n <= 2) {
		return arr[n];
	}
	// identity matrix
	I[1][1] = I[2][2] = 1;
	I[1][2] = I[2][1] = 0;

	// transition matrix
	T[1][1] = 0;
	T[1][2] = T[2][1] = T[2][2] = 1;

	n = n-1;
	int dim = 2;
	while(n) {
		if (n % 2){
			mul(I, T, dim);
			n--;
		} else {
			mul(T, T, dim);
			n /= 2;
		}
	}
	
	int fn = (arr[1] * I[1][1] + arr[2] * I[2][1]) % mod;
	return fn;
}

signed main() {
	fast
	#ifndef ONLINE_JUDGE 
  
    // For getting input from input.txt file 
    freopen("input.txt", "r", stdin); 
  
    // Printing the Output to output.txt file 
    freopen("output.txt", "w", stdout); 
  
	#endif 
	
	// Using matrix exponetiation :) 
	// problem solve in this file: https://www.hackerrank.com/challenges/fibonacci-finding-easy/problem

	int t,n;
	cin>>t;
	while(t--) {
		cin>>arr[1]>>arr[2]>>n;
		n++;
		cout<<getFib(n)<<"\n";
	}
	
	
	return 0;
}

