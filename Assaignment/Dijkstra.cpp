#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, m;
    cin >> n >> m;
    // n = number of nodes
    // m = number of edges

    vector<vector<pair<int, int>>> adj(n + 1);
    // Adjacency list:
    // adj[u] contains (v, weight) meaning edge u -> v with cost = weight

    for (int i = 0; i < m; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        // Read edge from u to v with weight w

        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
        // Use this line only if the graph is undirected
    }

    int src;
    cin >> src;
    // Source node

    vector<int> dist(n + 1, INT_MAX);
    // dist[i] stores the shortest distance from src to node i

    priority_queue<pair<int, int>,
                   vector<pair<int, int>>,
                   greater<pair<int, int>>> pq;
    // Min-heap: (distance, node)

    dist[src] = 0;
    pq.push({0, src});
    // Distance to source is 0

    while (!pq.empty())
    {
        int curDist = pq.top().first;
        int u = pq.top().second;
        pq.pop();

        // If we already found a better path, skip
        if (curDist > dist[u])
            continue;

        // Relax all adjacent edges
        for (auto edge : adj[u])
        {
            int v = edge.first;
            int weight = edge.second;

            // Check if a shorter path is found
            if (dist[u] + weight < dist[v])
            {
                dist[v] = dist[u] + weight;
                pq.push({dist[v], v});
            }
        }
    }

    // Print shortest distance from source to every node
    for (int i = 1; i <= n; i++)
    {
        if (dist[i] == INT_MAX)
            cout << "INF ";
        else
            cout << dist[i] << " ";
    }

    cout << endl;
    return 0;
}
/*
input
5 6
1 2 2
1 3 4
2 3 1
2 4 7
3 5 3
4 5 1
1
output
0 2 3 9 6
*/

