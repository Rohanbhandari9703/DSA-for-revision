// //used to find the shortest path with negative cycles
// basic code {
//     class Solution {
// public:
    // Function to implement Bellman-Ford
    vector<int> bellman_ford(int V, vector<vector<int>>& edges, int S) {
        vector<int> dist(V, 1e8);
        dist[S] = 0;

        // Relax all edges V-1 times
        for(int i = 0; i < V - 1; i++) {
            for(auto it : edges) {
                int u = it[0];
                int v = it[1];
                int wt = it[2];
                if(dist[u] != 1e8 && dist[u] + wt < dist[v]) {
                    dist[v] = dist[u] + wt;
                }
            }
        }

        // Check for negative weight cycles
        for(auto it : edges) {
            int u = it[0];
            int v = it[1];
            int wt = it[2];
            if(dist[u] != 1e8 && dist[u] + wt < dist[v]) {
                return {-1};  // Negative cycle detected
            }
        }

        return dist;
    }
};

// }
// //revision notes for later purposes
// //📝 Bellman-Ford Algorithm – Quick Revision Notes
// ✅ Purpose:
// Find shortest paths from a single source in a weighted graph (including negative weights).

// ✅ Works With:
// Directed / Undirected graphs

// Negative edge weights allowed

// Negative cycles detection

// 🔁 Steps:
// Initialize distance to all vertices as ∞ (1e8 here), except source S which is 0.

// Relax all edges V-1 times:

// For each edge u → v with weight wt:

// If dist[u] + wt < dist[v], update dist[v] = dist[u] + wt

// Negative Cycle Check:

// Do one more pass on all edges. If any distance still reduces, there's a negative cycle.

// 📦 Time Complexity:
// O(V * E)

// 🧠 Edge Format:
// edges is a vector of vectors: edges[i] = {u, v, wt}

// 🔍 Used When:
// Graph has negative weights.

// Dijkstra's algorithm cannot be used (because Dijkstra fails with negative weights).
