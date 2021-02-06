/* 
Fenwick tree / Binary indexed tree 

Space complexity: O(N) 
Time complexity: O(logN) for update and sum query
 
Example input
5 4
3 4 5 6 3
2 2 4
1 2 6
2 2 4
2 1 5

*/
#include <bits/stdc++.h>

const int N = 1e5+10;
int bit[N];

using namespace std;

void update(int ind, int val) {
	while(ind < N) {
		bit[ind] += val;
		ind += (ind &- ind);
	}
}

int sum(int i) {
	int res = 0;
	while(i > 0) {
		res += bit[i];
		i -= (i & -i);
	}
	return res;
}

int main() {	
	#ifndef ONLINE_JUDGE 
  
    // For getting input from input.txt file 
    freopen("input.txt", "r", stdin); 
  
    // Printing the Output to output.txt file 
    freopen("output.txt", "w", stdout); 
  
	#endif 
	
	int n,q;
	cin>>n>>q;
	vector<int> v(n+1);
	
	// 1 based indexing
	for(int i = 1; i <= n; ++i) {
		cin>>v[i];
		update(i , v[i]);
	}
	
	while(q--) {
		int typeOfQuery;
		cin>>typeOfQuery;
		// Point update query
		if (typeOfQuery == 1) {
			int index, val;
			cin>>index>>val;
			update(index, val - v[index]);
			v[index] = val;
		} else {
			// Range sum query
			int l, r;
			cin>>l>>r;
			cout<<sum(r) - sum(l-1)<<"\n";
		}
	}
}
