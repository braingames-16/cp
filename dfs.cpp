// dfs for graph
vector<int> adj[N + 1];
bool visited[N + 1];
int parent[N + 1];
int depth[N + 1];

void dfs(int node, int par, int d) {
    visited[node] = true;
    parent[node] = par;
    depth[node] = d;

    for (int neighbor : adj[node]) {
        if (!visited[neighbor]) {
            dfs(neighbor, node, d + 1);
        }
    }
}

// Initial call for one DFS from a chosen root:
// dfs(root, -1, 0);

// dfs for tree 
vector<int> adj[N + 1];
int parent[N + 1];
int depth[N + 1];

void dfs(int node, int par, int d) {
    parent[node] = par;
    depth[node] = d;

    for (int neighbor : adj[node]) {
        if (neighbor != par) {
            dfs(neighbor, node, d + 1);
        }
    }
}
