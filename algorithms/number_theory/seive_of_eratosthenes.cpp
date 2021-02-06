#include <bits/stdc++.h>

using namespace std;
#define fast ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#define ll long long int
#define pb push_back


int main() {
	fast
	#ifndef ONLINE_JUDGE 
  
    // For getting input from input.txt file 
    freopen("input.txt", "r", stdin); 
  
    // Printing the Output to output.txt file 
    freopen("output.txt", "w", stdout); 
  
	#endif 
	
	ll n;
	cin>>n;
	vector<bool> isThisPrime(n+1, true);
	
	isThisPrime[0] = false;
	isThisPrime[1] = false;
	
	for(int i = 2; i < n; ++i) {
		if (isThisPrime[i]) {
			for(int j = i*2; j <= n; j+=i) {
				isThisPrime[j] = false;
			}
		}
	}
	ll y;
	cin>>y;
	cout<<isThisPrime[y]; 
	
	return 0;
}

