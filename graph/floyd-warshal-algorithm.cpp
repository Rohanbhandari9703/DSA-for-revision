//used for negative 
//and it is used to loop for every node to every node using a via intermediate matrixk
code{
    for (int k = 0; k < n; k++) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            matrix[i][j] = min(matrix[i][j], matrix[i][k] + matrix[k][j]);
        }
    }
}

}
// 📝 Floyd-Warshall Algorithm – Quick Revision Notes
// ✅ Purpose:
// Find all pairs shortest paths in a weighted graph (including negative weights).

// 🧱 Works With:
// Directed or undirected graphs

// Negative weights allowed

// No negative cycles allowed (can detect them too)

// 🔁 Logic:
// Use each node k as an intermediate node.

// For every pair (i, j), update:

// lua
// Copy
// Edit
// dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
// 📦 Time Complexity:
// O(N³) – where N is the number of vertices

// ❗ Special Case – Detecting Negative Cycle:
// cpp
// Copy
// Edit
// for (int i = 0; i < n; i++) {
//     if (matrix[i][i] < 0) {
//         // Negative cycle exists
//     }
// }
// 🧠 Use Case:
// When you need shortest paths between all nodes

// Simpler implementation than running Dijkstra for all nodes

