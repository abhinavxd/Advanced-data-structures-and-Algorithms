#include <bits/stdc++.h>

using namespace std;

#define N 100


//int arr[100][100];

vector<int> adj[N];

bool visited[N];
bool visited_BFS[N];

queue<int> q;
int my_distance[N]; 

void dfs(int s){
	if(visited[s]) return;

	visited[s] = true;
	cout<<s<<" ";
	for(auto u : adj[s]){
		dfs(u);
	}
}

void bfs(int x){
	visited_BFS[x] = true;
	my_distance[x] = 0;
	q.push(x);
	cout<<"  Node "<<" Distance "<<endl;
	while(!q.empty()){
		int s = q.front();
		q.pop();

		cout<<"\t"<<s<<"\t" << my_distance[s]<<endl;
		for(auto u : adj[s]){
			if(visited_BFS[u]) 
				continue;
			visited_BFS[u] = true;
			my_distance[u] = my_distance[s] + 1;
			q.push(u);
		}
	}
}

int main(){



	int n;
	cin>>n;

	
	while( n-- ){
		int a,b;
		cin>>a>>b;
		//cout<<a<<"  "<<b<<endl;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}

	//Printing
	for(int i = 0 ; i < 10; i++){
		for(int u : adj[i]){
			cout<<u<< " ";
		}
		cout<<endl;
	}
	cout<<endl;

	cout<<"DFS FOR the graph! "<<endl;
	dfs(1);
	cout<<endl<<endl;



	cout<<"BFS for graph!" <<endl;
	bfs(1);



	// cout<<"hello!"<<endl;


}