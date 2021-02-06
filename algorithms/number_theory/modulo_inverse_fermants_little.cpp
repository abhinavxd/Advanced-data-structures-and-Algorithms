#include <bits/stdc++.h>

using namespace std;
#define fast ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#define ll long long int
#define pb push_back

int power(int a, int n, int m) {
    int res = 1;
    while(n) {
        if (n % 2) {
            res = (res * a) % m;
            n--;
        } else {
            n /= 2;
            a = (a*a) % m;
        }
    }
    return res;
}

int main() {
	fast
	#ifndef ONLINE_JUDGE 
    // For getting input from input.txt file 
    freopen("input.txt", "r", stdin); 
    // Printing the Output to output.txt file 
    freopen("output.txt", "w", stdout); 
	#endif 


    int t, a, m;
    cin>>t;
    // here M must be prime
    // And 'a' and 'm' must be coprime to each other, i.e their GCD should be equal to 1
    while(t--) {
        cin>> a >> m;
        cout<< "a^-1 = "  << power(a, m-2, m) <<"\n";
    }
	
	
	return 0;
}

