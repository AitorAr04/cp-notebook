// Find the shortest path from node a to all other nodes
// Can be changed to return the vector of all distances

vector<vector<int>> adj;

int dijkstra(int source, int dest) {
    vector<int> distance(n, 1e9); // 1e9 can be adjusted to larger 'infinities'
    priority_queue<int, int> pq; // pq will store <-length, node>

    pq.push({0, source});

    while (!pq.empty()) {
        int dist = pq.top().first;
        int node = pq.top().second;

        pq.pop();

        if (dist < distance[node]) {
            continue;
        }

        for (int neigh: adj[node]) {
            int neighLen = distance[neigh];
            int sum = distance[node] + neighLen;
            if (sum < distance[neigh]) {
                distance[neigh] = sum;
                pq.push({-sum, neigh});
            }
        }
    }

    return distance[dest];
}

int main() {
    // Initialize the graph
    int distanceAtoB = dijkstra(a, b);
}

