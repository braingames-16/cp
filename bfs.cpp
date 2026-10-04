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

//multi-sourced bfs
vector<int> adj[N + 1];
bool visited[N + 1];
int dist[N + 1];

void multi_source_bfs(vector<int>& sources) {
    queue<int> q;

    // Push all sources onto the queue with distance 0.
    for (int s : sources) {
        if (!visited[s]) {
            visited[s] = true;
            dist[s] = 0;
            q.push(s);
        }
    }

    while (!q.empty()) {
        int node = q.front();
        q.pop();

        for (int neighbor : adj[node]) {
            if (!visited[neighbor]) {
                visited[neighbor] = true;
                dist[neighbor] = dist[node] + 1;
                q.push(neighbor);
            }
        }
    }
}
