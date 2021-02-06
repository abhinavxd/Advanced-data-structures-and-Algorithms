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
	
	int a,n;
	cin>>a>>n;
	
	int res = 1;
	
	// for modulo just add res = (res*a) % p;
	// for modulo just add res = (a*a) % p;
	while(n) {
		if (n % 2) {			
			res *= a;
			n--;
		} else {
			a *= a;
			n /= 2;
		}
	}
	cout<<res<<"\n";
	
	return 0;
}

