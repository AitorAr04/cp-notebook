// Finds all pairs of shortest paths (cost of O(V^3))

int inf = 1e9; // Can be adjusted to boundaries of the problem
vector<vector<int>> dist; // dist[a][b] = distance from a to b
                                // initially inf, if there's no edge
                                // dist[i][i]=0 for all i

int n; // Amount of nodes

void floyd_warshall() {
    for (int k = 0; k < n; k++) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (dist[k][j]==inf || dist[i][k]==inf) {
                    continue;
                }
                dist[i][j] = min(dist[i][j], dist[i][k]+dist[k][j]);
            }
        }
    }
}

int main() {
    // Assume initialized graph

    floyd_warshall();
    cout << dist[a][b] << '\n'; // Shortest distance from a to b    
}
