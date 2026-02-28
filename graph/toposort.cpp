// 🧠 Topological Sort (DAG only)

// Topological Sort = Linear ordering of vertices such that
// 👉 For every directed edge u → v, u comes before v

// ⚠️ Works only for Directed Acyclic Graph (DAG)


// for dfs create a stack and then push the nodes in stack after visiting all its neighbours. then pop the stack to get the topological sort order.
// Maintain visited[]

// Run DFS from every unvisited node

// After visiting all neighbors → push node to stack

// Reverse stack = topo order

//code 
#include <bits/stdc++.h>
using namespace std;

void dfs(int node, vector<vector<int>>& adj,
         vector<int>& vis, stack<int>& st) {

    vis[node] = 1;

    for (auto nbr : adj[node]) {
        if (!vis[nbr]) {
            dfs(nbr, adj, vis, st);
        }
    }

    st.push(node);   // push AFTER visiting neighbors
}

vector<int> topoSortDFS(int V, vector<vector<int>>& adj) {
    vector<int> vis(V, 0);
    stack<int> st;

    for (int i = 0; i < V; i++) {
        if (!vis[i]) dfs(i, adj, vis, st);
    }

    vector<int> ans;

    while (!st.empty()) {
        ans.push_back(st.top());
        st.pop();
    }

    return ans;
}

//for bfs we use kahn's algorithm
// 1. Calculate in-degrees of all vertices
// 2. Enqueue vertices with in-degree 0
// 3. While queue not empty:
//    a. Dequeue vertex u, add to topo order
//    b. For each neighbor v of u:
//       i. Decrease in-degree of v by 1
//       ii. If in-degree of v becomes 0, enqueue v
    #include <bits/stdc++.h>
using namespace std;

vector<int> topoSortBFS(int V, vector<vector<int>>& adj) {

    vector<int> indegree(V, 0);

    // calculate indegree
    for (int i = 0; i < V; i++) {
        for (auto nbr : adj[i]) {
            indegree[nbr]++;
        }
    }

    queue<int> q;

    // push nodes with indegree 0
    for (int i = 0; i < V; i++) {
        if (indegree[i] == 0) q.push(i);
    }

    vector<int> ans;

    while (!q.empty()) {
        int node = q.front();
        q.pop();

        ans.push_back(node);
y
        for (auto nbr : adj[node]) {
            indegree[nbr]--;
            if (indegree[nbr] == 0) q.push(nbr);
        }
    }

    return ans;
}