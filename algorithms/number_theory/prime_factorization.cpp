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
  
    // Printing the 5Output to output.txt file 
    freopen("output.txt", "w", stdout); 
  
	#endif 
	
	int n;
	cin>>n;
	
	for(int i = 2; i*i <= n; i++) {
		if (n % i == 0) {
			int cnt = 0;
			while(n % i == 0) {
				cnt++;
				n /= i;
			}
			cout<< i << "^" << cnt << endl;
		}
	}
	if (n > 1)
		cout<< n << "^" << 1 << endl;
	
	
	return 0;
}

