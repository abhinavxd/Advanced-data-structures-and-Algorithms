#include <bits/stdc++.h>

using namespace std;
#define fast ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#define ll long long int
#define pb push_back
#define N 10000000


int ar[N+1];

void seive() {
	int maxN = N;
	for(int i = 1; i <= maxN; i++) {
		ar[i] = -1;
	}
	for(int i = 2; i <= maxN; i++) {
		if (ar[i] == -1){
			for(int j = i; j <= maxN; j+=i) {
				if (ar[j] == -1) {
					ar[j] = i;
				}
			}
		}
	}
}

vector<int> getFact(int val) {
	vector<int> res;
	while(ar[val] != -1) {
		res.pb(ar[val]);
		val = val / ar[val];
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
	seive();
	int x;
	cin>>x;

	vector <int> p = getFact(x); 

  
    for (int i=0; i<p.size(); i++) 
        cout << p[i] << " "; 
    cout << endl; 
	
	
	return 0;
}

