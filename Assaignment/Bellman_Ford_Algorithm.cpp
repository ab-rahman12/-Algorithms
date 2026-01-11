#include <bits/stdc++.h>
using namespace std;

struct Edge {
    int u, v, w;   // edge from u to v with weight w
};

int main()
{
    int n, m;
    cin >> n >> m;
    // n = number of nodes
    // m = number of edges

    vector<Edge> edges(m);

    // Read all edges
    for (int i = 0; i < m; i++)
    {
        cin >> edges[i].u >> edges[i].v >> edges[i].w;
        // Edge from edges[i].u to edges[i].v with weight edges[i].w
    }

    int src;
    cin >> src;  // Source node

    vector<long long> dist(n + 1, LLONG_MAX);
    // Distance array initialized to "infinity"

    dist[src] = 0;  // Distance to source is 0

    // Relax all edges (n-1) times
    for (int i = 1; i <= n - 1; i++)
    {
        for (auto e : edges)
        {
            int u = e.u, v = e.v, w = e.w;
            if (dist[u] != LLONG_MAX && dist[u] + w < dist[v])
            {
                dist[v] = dist[u] + w;  // Relaxation step
            }
        }
    }

    // Check for negative weight cycle
    bool negativeCycle = false;
    for (auto e : edges)
    {
        int u = e.u, v = e.v, w = e.w;
        if (dist[u] != LLONG_MAX && dist[u] + w < dist[v])
        {
            negativeCycle = true;
            break;
        }
    }

    if (negativeCycle)
    {
        cout << "Graph contains a negative weight cycle\n";
    }
    else
    {
        // Print shortest distances from source
        for (int i = 1; i <= n; i++)
        {
            if (dist[i] == LLONG_MAX)
                cout << "INF ";
            else
                cout << dist[i] << " ";
        }
        cout << endl;
    }

    return 0;
}
/*
input
5 8
1 2 -1
1 3 4
2 3 3
2 4 2
2 5 2
4 2 1
5 4 -3
3 5 4
1
output
0 -1 2 -2 1
*/
