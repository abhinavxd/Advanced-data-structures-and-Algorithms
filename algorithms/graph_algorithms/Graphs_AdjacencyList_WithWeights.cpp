#include <bits/stdc++.h>

using namespace std;

int main(){


	#ifndef ONLINE_JUDGE 
  
    //For getting input from input.txt file 
    freopen("input.txt", "r", stdin); 
  
    //Printing the Output to output.txt file 
   freopen("output.txt", "w", stdout); 
  
	#endif 

	cout<<"okkk"<<endl;

	int N = 10;

	int arr[100][100];

	int n;
	cin>>n;

	vector<pair<int,int>> adj[N];

	//bool visited[N];
	
	while( n-- ){
		int a,b,c;
		cin>>a>>b>>c;
		cout<<a<<"  "<<b<<endl;
		adj[a].push_back({b,c});
	}


	for(int i = 0 ; i < 10; i++){
		for(auto u : adj[i]){
			cout<<u.first<< " " <<u.second<< "  ";
		}
		cout<<endl;
	}


	// cout<<"hello!"<<endl;

}