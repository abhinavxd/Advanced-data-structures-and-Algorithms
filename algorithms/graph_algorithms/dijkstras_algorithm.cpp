/**
Find shortest path from Node 1 to all other nodes

Input:
3 4
1 2 6
1 3 2
3 2 3
1 3 4

Output:
0 5 2
**/
#include <bits/stdc++.h>
#define int long long

using namespace std;

const int N = 2e5 + 5;
const int INF = 1e18;

int dist[N];
bool visited[N];
vector<pair<int, int>> adj[N];

signed main()
{
#ifndef ONLINE_JUDGE
    //For getting input from input.txt file
    freopen("input.txt", "r", stdin);

    //Printing the Output to output.txt file
    freopen("output.txt", "w", stdout);
#endif

    int n, m;
    cin >> n >> m;
    for (int i = 0; i < m; i++)
    {
        int a, b, c;
        cin >> a >> b >> c;
        adj[a].push_back({b, c});
    }

    // queue
    priority_queue<pair<int, int>> q;
    for (int i = 0; i < N; i++)
    {
        dist[i] = INF;
        visited[i] = false;
    }
    int startingCity = 1;
    dist[startingCity] = 0;
    q.push({0, startingCity});
    while (!q.empty())
    {
        int a = q.top().second;
        q.pop();
        if (visited[a])
            continue;
        visited[a] = true;
        for (auto u : adj[a])
        {
            int b = u.first;
            int w = u.second;
            if (dist[a] + w < dist[b])
            {
                dist[b] = dist[a] + w;
                q.push({-dist[b], b});
            }
        }
    }
    for (int i = 1; i <= n; i++)
    {
        cout << dist[i] << " ";
    }
    cout << "\n";
}