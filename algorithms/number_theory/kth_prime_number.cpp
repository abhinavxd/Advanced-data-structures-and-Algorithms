#include <bits/stdc++.h>

using namespace std;
#define fast ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#define ll long long int
#define pb push_back


vector<int> primes;
bool a[90000001];

void seive() {
    int maxN = 90000000;
    a[0] = a[1] = true;
    for(int i = 2; i*i < maxN; i++) {
        if (a[i] == false) {
            for(int j = i*2; j <= maxN; j+=i) {
                a[j] = true;
            }
        }
    }
    for(int i = 2; i <= maxN; i++) {
        if (a[i] == false) {
            primes.pb(i);
        }
    }
}

int main() {
	fast
	// #ifndef ONLINE_JUDGE 
  
    // // For getting input from input.txt file 
    // freopen("input.txt", "r", stdin); 
  
    // // Printing the Output to output.txt file 
    // freopen("output.txt", "w", stdout); 
  
	// #endif 

    int q, n;
    cin>>q;
    seive();
    while(q--) {
        cin>>n;
        cout<<primes[n-1]<<"\n";
    }
	
	return 0;
}

