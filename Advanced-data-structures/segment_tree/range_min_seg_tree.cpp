/**
 * Segment tree - Range minimum query
 * 
 * Input -
	6 12
	1 3 2 7 9 11
	1 1 5
	1 2 5
	2 3 6
	1 2 5
	1 4 6
	2 4 3
	1 4 6
	1 5 6
	1 1 1
	2 1 5
	1 1 1
	1 1 6
 *
 * 
 * Time complexity - 
 * 		For building: O(N)
 * 		For range min query: O(LogN)
 * 		For point update: O(LogN)
 * Space complexity - O(N)
 * 
 * */
#include "bits/stdc++.h"
using namespace std;
const int N = 1e5;

// if there are N nodes at the leaf of the tree
// then there will be N-1 internal nodes of tree
// Total nodes required are N + (N-1) = 2N-1
int tree[2*N];
int tree1[2*N];

void update(int low, int high, int pos, int index, int value) {
	if (index < low || index > high)
		return;
	if (low == high) {
		tree[pos] = value;
		return;
	}
	int mid = (low+high)/2;
	update(low, mid, 2*pos, index, value);
	update(mid+1, high, 2*pos+1, index, value);
	tree[pos] = min(tree[2*pos], tree[2*pos+1]);
}

int rangeMin(int qlow,int qhigh,int low,int high,int pos){
    if(qlow <= low && qhigh >= high){  //total overlap
        return tree[pos];
    }
    if(qlow > high || qhigh < low){   // no overlap
        return INT_MAX;
    }
    int mid = (low+high)/2;
    return min(rangeMin(qlow, qhigh, low, mid, 2 * pos),
            rangeMin(qlow, qhigh, mid+1, high, 2 * pos+1));
}

int sum(int v, int tl, int tr, int l, int r) {
    if (l > r) 
        return 0;
    if (l == tl && r == tr) {
        return tree1[v];
    }
    int tm = (tl + (tr-tl)/2);
    return sum(v*2, tl, tm, l, min(r, tm))
           + sum(v*2+1, tm+1, tr, max(l, tm+1), r);
}

void buildTreeSum(int* arr, int v, int start, int end) {
	if (start == end) {
		tree1[v] = arr[start];
		return;
	}
	// to avoid integer overflow
	int mid = (start + (end-start)/2);
	buildTreeSum(arr, 2*v, start, mid);
	buildTreeSum(arr, 2*v+1, mid+1, end);
	
	tree1[v] = tree1[2*v] + tree1[2*v+1];
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
	
	tree[v] = min(tree[2*v], tree[2*v+1]);
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
			cout<<rangeMin(a, b, 1, n, 1)<<endl;
		} else {
			update(1, n, 1, a, b);
		}
	}
}

