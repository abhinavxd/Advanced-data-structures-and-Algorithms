#include <bits/stdc++.h>

using namespace std;
#define fast ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#define ll long long int
#define pb push_bac

int kp(int wt[], int val[], int n, int w) {
	if (w == 0 || n == 0) 
		return 0;
	if (wt[n-1] <= w) {
		return max(val[n-1] + kp(wt, val, n-1, w-wt[n-1]), kp(wt, val, n-1, w));
	} else {
		return kp(wt, val, n-1, w);
	}
}

int main() {
	fast
	#ifndef ONLINE_JUDGE 
  
    // For getting input from input.txt file 
    freopen("input.txt", "r", stdin); 
  
    // Printing the Output to output.txt file 
    freopen("output.txt", "w", stdout); 
  
	#endif 
	
	
	int val[] = { 20, 5, 10, 40, 15, 25 }; 
    int wt[] = {1, 2, 3, 8, 7, 4 }; 
    int n = sizeof(val) / sizeof(val[0]);
    int W = 10; 
    cout<< kp(wt, val, n, W)<<endl;
	
	return 0;
}

