vector<vector<int>> adj;
vector<vector<int>> adj_rev;
vector<vector<int>> SCC;
int scc_amount = 0;
int n; // Amount of nodes
stack<int> nodes;
vector<bool> visited;


void dfs2(int node, int cc) {
    visited[node] = true;
    SCC[cc].push_back(node);

    for (int neigh: adj_rev[node]) {
        if (!visited[neigh]) {
            dfs2(neigh, cc);
        }
    }
}

void dfs1(int node) {
    visited[node] = true;
    for (int neigh: adj[node]) {
        if (!visited[neigh]) {
            dfs1(neigh);
        }
    }

    nodes.push(node);
}

int main() {
    // WHEN CONSTRUCTING THE GRAPH: for each edge a->b stored in adj, store the opposite edge b-> on adj_rev
    
    for (int i = 0; i < n; i++) {
        if (!visited[i]) {
            dfs1(i);
        }
    }

    int size = nodes.size();

    visited.assign(n, false);

    for (int i = 0; i < size; i++) {
        int node_stack = nodes.top();
        nodes.pop();
        if (!visited[node_stack]) {
            SCC.push_back({});
            dfs2(node_stack, scc_amount);
            scc_amount++;
        }
    }

}
