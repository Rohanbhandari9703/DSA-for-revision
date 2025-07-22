//used to find minimum distance
//not used for negative cycles
//can be done using three ways, 1.priority_quete 2.sets 3.queue
//sets is the best then priority queue
//basic code for the following 
vector<int> dijkstra(int V, vector<vector<pair<int, int>>>& adj, int S) {
    vector<int> dist(V, 1e9);
    dist[S] = 0;
    
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({0, S});
    
    while (!pq.empty()) {
        int d = pq.top().first;
        int u = pq.top().second;
        pq.pop();
        
        for (auto it : adj[u]) {
            int v = it.first;
            int wt = it.second;
            if (dist[u] + wt < dist[v]) {
                dist[v] = dist[u] + wt;
                pq.push({dist[v], v});
            }
        }
    }
    
    return dist;
}

//revision notes 
// 📝 Dijkstra’s Algorithm – Quick Revision Notes
// ✅ Purpose:
// Find shortest paths from a source node to all other nodes in a graph with non-negative edge weights.

// 🚫 Doesn't Work With:
// Negative weights (use Bellman-Ford instead)

// ⚙️ Input Structure:
// V = Number of vertices

// adj = Adjacency list of form:
// adj[u] = {{v1, wt1}, {v2, wt2}, ...}
// meaning: edge from u to v with weight wt

// 🔁 Algorithm Steps:
// Initialize distance array dist[] with large values.

// Set dist[S] = 0 for source.

// Use a min-heap (priority queue with greater<>) to always pick the node with minimum tentative distance.

// For each neighbor v of u, if going through u gives a shorter path to v, update it.

// ⏱ Time Complexity:
// O(E log V) with min-heap priority queue.

