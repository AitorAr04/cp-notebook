// Orders nodes such that if a path a-b exists, a goes before b.
// Only works for Directed Acyclic Graphs (i.e. no cycle exists).

vector<vector<int>> adj; // Adjacency list
vector<bool> vis; // Visited nodes
int n; // Number of nodes
vector<int> ans; // Vector which will hold our toposort

void dfs (int source) {
    vis[source] = true;

    for (int neigh: adj[v]) {
        if (!vis[neigh]) {
            dfs(neigh);
        }
    }
    ans.push_back(source);

}
int main() {
    // Assume initialized graph
    vis.assign(n, false);
    for (int i = 0; i < n; i++) {
        if (!visited[i]) {
            dfs(i);
        }
    }

    reverse(ans.begin(), ans.end());
}
