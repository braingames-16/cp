vector<int> adj[N + 1];
bool visited[N + 1];
int parent[N + 1];
int dist[N + 1]; //distance from starting node

void bfs(int start) {
    queue<int> q;
    q.push(start);
    visited[start] = true;
    parent[start] = -1;
    dist[start] = 0;
      
    while (!q.empty()) {
        int node = q.front();
        q.pop();

        for (int neighbor : adj[node]) {
            if (!visited[neighbor]) {
                visited[neighbor] = true;
                parent[neighbor] = node;
                dist[neighbor] = dist[node] + 1;
                q.push(neighbor);
            }
        }
    }
}
