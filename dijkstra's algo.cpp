#include <iostream>
#include <vector>
#include <queue>

using namespace std;

typedef pair<int, int> pii; // (distance, node)

vector<int> dijkstra(int V, vector<vector<pii>>& adj, int source) {
    vector<int> dist(V, INT_MAX);
    priority_queue<pii, vector<pii>, greater<pii>> pq;

    dist[source] = 0;
    pq.push({0, source});

    while (!pq.empty()) {
        int currDist = pq.top().first;
        int u = pq.top().second;
        pq.pop();

        for (auto [v, weight] : adj[u]) {
            if (dist[v] > currDist + weight) {
                dist[v] = currDist + weight;
                pq.push({dist[v], v});
            }
        }
    }

    return dist;
}
