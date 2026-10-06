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

// multi-source bfs on 2d grid of size n*m
string grid[1001];
vector <bool> visited[1001];
vector <bool> starter[1001];
vector <char> prev_dir[1001]; 

ll n,m;
int dx[] = {1,-1,0,0};
int dy[] = {0,0,1,-1};
char dir[] = {'D','U','R','L'};

void multi_source_bfs(vector<pair<int,int>>& sources){
    queue <pair <int,int> > q;


    for (auto [i,j] : sources) {
        //if (!visited[i][j]) {
            visited[i][j] = true;
            q.push({i,j});
        //}
    }

    while (!q.empty()) {
        auto [i,j] = q.front();
        q.pop();
        
        for(int k = 0;k < 4;k++){
            if((i+dx[k]>=0)&&(j+dy[k]>=0)&&(i+dx[k]<n)&&(j+dy[k]<m)){
                if(!visited[i+dx[k]][j+dy[k]]){
                    visited[i+dx[k]][j+dy[k]] = true;
                    q.push({i+dx[k],j+dy[k]});
                }
            }
        }
    }
}

