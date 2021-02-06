/**
 * Segment tree - Range sum
 * 
 * Input -
 * 10 6
 * 1 2 3 4 5 6 7 8 9 10
 * 1 1 5
 * 1 2 7
 * 2 3 10
 * 1 2 5
 * 2 7 7
 * 1 5 10
 * 
 * Time complexity - 
 * 		For building: O(N)
 * 		For range sum query: O(LogN)
 * 		For point update: O(LogN)
 * Space complexity - O(N)
 * 
 * */
#include "bits/stdc++.h"
using namespace std;
const int N = 1e5;

// since there are N nodes at the leaf of the tree
// and there are N-1 internal nodes of tree
// Total nodes required are N + (N-1) = 2N-1
int tree[2*N];

void update(int v, int tl, int tr, int pos, int new_val) {
    if (tl == tr) {
        tree[v] = new_val;
    } else {
        int tm = (tl + (tr-tl)/2);
        if (pos <= tm)
            update(v*2, tl, tm, pos, new_val);
        else
            update(v*2+1, tm+1, tr, pos, new_val);
        tree[v] = tree[v*2] + tree[v*2+1];
    }
}

int sum(int v, int tl, int tr, int l, int r) {
    if (l > r) 
        return 0;
    if (l == tl && r == tr) {
        return tree[v];
    }
    int tm = (tl + (tr-tl)/2);
    return sum(v*2, tl, tm, l, min(r, tm))
           + sum(v*2+1, tm+1, tr, max(l, tm+1), r);
}

void buildTree(int* arr, int v, int start, int end) {
	if (start == end) {
		tree[v] = arr[start];
		return;
	}
	// to avoid integer overflow
	int mid = (start + (end-start)/2);
	buildTree(arr, 2*v, start, mid);
	buildTree(arr, 2*v+1, mid+1, end);
	
	tree[v] = tree[2*v] + tree[2*v+1];
}

int main() {
	#ifndef ONLINE_JUDGE 
  
    // For getting input from input.txt file 
    freopen("input.txt", "r", stdin); 
  
    // Printing the Output to output.txt file 
    freopen("output.txt", "w", stdout); 
  
	#endif 
	///////////////////////////////
	
	int n, q;
	cin>>n;
	cin>>q;
	
	int arr[n+1];
	
	for(int i = 1 ; i <= n; ++i) {
		cin>>arr[i];
	}
	
	buildTree(arr, 1, 1, n);
		
	int queryType, a, b;
	while(q--) {
		cin>>queryType>>a>>b;
		if (queryType == 1) {
			cout<<sum(1, 1, n, a, b)<<endl;
		} else {
			update(1, 1, n, a, b);
		}
	}
}

