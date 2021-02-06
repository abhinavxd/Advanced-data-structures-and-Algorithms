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

    // problem statement//
    // Given prime factorization, find total number of divisor

    // combinatorics
    int t;
    cin>>t;
    int res = 1;
    while(t--) {
        int a,b;
        cin>>a>>b;
        res *= (b+1);
    }
    cout<<res<<"\n";
	return 0;
}

