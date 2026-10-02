//recursive dfs fine till N of order 10^5

//recursive dfs for graph
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

//recursive dfs for tree 
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

// N of order 10^6 then use iterative dfs

// basic template
vector<int> order;
stack<int> st;
st.push(start);

while (!st.empty()) {
    int node = st.top();
    st.pop();

    if (visited[node]) continue;
    visited[node] = true;
    order.push_back(node);

    for (int neighbor : adj[node]) {
        if (!visited[neighbor]) {
            st.push(neighbor);
        }
    }
}

// Second pass: iterate the recorded order in reverse for postorder work
for (int i = (int)order.size() - 1; i >= 0; i--) {
    int node = order[i];
    // by now, all descendants of node have been processed
    // do the postorder work here
}

//iterative dfs with parents and depth
vector<int> adj[N + 1];
bool visited[N + 1];
int parent[N + 1];
int depth[N + 1];

void dfs(int start) {
    stack<tuple<int, int, int>> st;  // {node, parent, depth}
    st.push({start, -1, 0});

    while (!st.empty()) {
        auto [node, par, d] = st.top();
        st.pop();

        if (visited[node]) continue;
        visited[node] = true;
        parent[node] = par;
        depth[node] = d;

        for (int neighbor : adj[node]) {
            if (!visited[neighbor]) {
                st.push({neighbor, node, d + 1});
            }
        }
    }
}

// for trees
void dfs(int start) {
    stack<pair<int, int>> st; // {node, parent}
    st.push({start, -1});

    while (!st.empty()) {
        auto [node, par] = st.top();
        st.pop();

        parent[node] = par;

        for (int neighbor : adj[node]) {
            if (neighbor != par) {
                st.push({neighbor, node});
            }
        }
    }
}
