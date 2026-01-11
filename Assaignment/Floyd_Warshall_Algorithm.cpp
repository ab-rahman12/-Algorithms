#include <bits/stdc++.h>
using namespace std;

const long long INF = 1e18; // Infinity for unreachable paths

int main()
{
    int n, m;
    cin >> n >> m; // n = number of nodes, m = number of edges

    // Create distance matrix
    vector<vector<long long>> dist(n + 1, vector<long long>(n + 1, INF));

    // Initialize distances
    for (int i = 1; i <= n; i++)
        dist[i][i] = 0; // Distance to self is 0

    // Read edges
    for (int i = 0; i < m; i++)
    {
        int u, v;
        long long w;
        cin >> u >> v >> w;
        dist[u][v] = w; // Distance from u to v is w
        // If graph is undirected, uncomment:
        // dist[v][u] = w;
    }

    // Floyd–Warshall main loop
    for (int k = 1; k <= n; k++)        // Intermediate node
    {
        for (int i = 1; i <= n; i++)    // Start node
        {
            for (int j = 1; j <= n; j++)// End node
            {
                // Check if path i->k->j is shorter than i->j
                if (dist[i][k] != INF && dist[k][j] != INF)
                    dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
            }
        }
    }

    // Print all-pairs shortest path
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (dist[i][j] == INF)
                cout << "INF ";
            else
                cout << dist[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}
/*
input
4 5
1 2 5
1 3 3
2 3 2
3 4 7
2 4 4

output
0 5 3 9
INF 0 2 4
INF INF 0 7
INF INF INF 0
*/

