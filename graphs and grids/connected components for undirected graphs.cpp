// counting and labelling connected components
vector<int> adj[N + 1];
bool visited[N + 1];
int comp[N + 1];

void dfs(int node, int id) {
    visited[node] = true;
    comp[node] = id;
    for (int neighbor : adj[node]) {
        if (!visited[neighbor]) {
            dfs(neighbor, id);
        }
    }
}

int label_components(int n) {
    int next_id = 0;
    for (int i = 1; i <= n; i++) {
        if (!visited[i]) {
            dfs(i, next_id);
            next_id++;
        }
    }
    return next_id; // total number of components
}

// for grids
int n, m;
vector<string> grid;
vector<vector<bool>> visited;

int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};

void dfs(int x, int y) {
    visited[x][y] = true;
    for (int i = 0; i < 4; i++) {
        int nx = x + dx[i];
        int ny = y + dy[i];
        if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
        if (grid[nx][ny] == '#' || visited[nx][ny]) continue;
        dfs(nx, ny);
    }
}

int count_regions() {
    int regions = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (grid[i][j] == '.' && !visited[i][j]) {
                dfs(i, j);
                regions++;
            }
        }
    }
    return regions;
}

// eight directions (including diagonals
int dx[] = {-1, -1, -1, 0, 0, 1, 1, 1};
int dy[] = {-1, 0, 1, -1, 1, -1, 0, 1};

// knight move in chess
int dx[] = {-2, -2, -1, -1, 1, 1, 2, 2};
int dy[] = {-1, 1, -2, 2, -2, 2, -1, 1};

//diagonals only movement(bishop)
int dx[] = {-1, -1, 1, 1};
int dy[] = {-1, 1, -1, 1};

// flood fill in 2d grid
int n, m;
vector<vector<int>> grid;
int old_color, new_color;

int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};

void flood_fill(int x, int y) {
    if (grid[x][y] != old_color) return;
    grid[x][y] = new_color;
    for (int i = 0; i < 4; i++) {
        int nx = x + dx[i];
        int ny = y + dy[i];
        if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
        flood_fill(nx, ny);
    }
}
