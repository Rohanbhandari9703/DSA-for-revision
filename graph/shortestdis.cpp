//for shortest distance in a dag we can use topo sort insert in a stack and then pop the stack and relax the edges. we can also use bfs to find the shortest distance in a dag by using kahn's algorithm and then relax the edges.
class Solution {
public:

    void dfs(int node,
             vector<vector<pair<int,int>>>& adj,
             stack<int>& st,
             vector<int>& vis)
    {
        vis[node] = 1;

        for (auto nbr : adj[node]) {
            int v = nbr.first;
            if (!vis[v]) {
                dfs(v, adj, st, vis);
            }
        }

        st.push(node);
    }

    vector<int> shortestPath(int V, int E, vector<vector<int>>& edges) {

        vector<vector<pair<int,int>>> adj(V);

        for (int i = 0; i < E; i++) {
            int u = edges[i][0];
            int v = edges[i][1];
            int w = edges[i][2];
            adj[u].push_back({v, w});
        }

        stack<int> st;
        vector<int> vis(V, 0);

        for (int i = 0; i < V; i++) {
            if (!vis[i]) {
                dfs(i, adj, st, vis);
            }
        }

        vector<int> mindis(V, INT_MAX);

        mindis[0] = 0;

        while (!st.empty()) {

            int currnode = st.top();
            st.pop();

            if (mindis[currnode] != INT_MAX) {

                for (auto it : adj[currnode]) {
                    int cn = it.first;
                    int wt = it.second;

                    if (mindis[cn] > wt + mindis[currnode]) {
                        mindis[cn] = wt + mindis[currnode];
                    }
                }
            }
        }
        for(auto &it: mindis){
            if(it == INT_MAX){
                it = -1;
            }
        }

        return mindis;
    }
};
//code for that...