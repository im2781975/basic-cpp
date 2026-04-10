//find a path from start to end. You can walk left, right, up and down. First print "YES", if there is a path, and "NO" otherwise.
//If there is a path, print the length of the shortest such path
const int MAX_N = 100;  // Adjust this according to the size of your labyrinth
const char WALL = '#';
const int dx[] = {1, -1, 0, 0};
const int dy[] = {0, 0, 1, -1};
const char moves[] = "RULD";
int n, m;
char labyrinth[MAX_N][MAX_N];
int dist[MAX_N][MAX_N];
pair<int, int> parent[MAX_N][MAX_N];
bool is_valid(int x, int y) {
    return x >= 0 && x < n && y >= 0 && y < m && labyrinth[x][y] != WALL;
}
void bfs(pair<int, int> start, pair<int, int> end) {
    queue<pair<int, int>> q;
    q.push(start);
    dist[start.first][start.second] = 0;
    while (!q.empty()) {
        pair<int, int> cur = q.front();
        q.pop();
        if (cur == end) {
            return; 
        }
        for (int i = 0; i < 4; i++) {
            int new_x = cur.first + dx[i];
            int new_y = cur.second + dy[i];

            if (is_valid(new_x, new_y) && dist[new_x][new_y] == -1) {
                q.push({new_x, new_y});
                dist[new_x][new_y] = dist[cur.first][cur.second] + 1;
                parent[new_x][new_y] = cur;
            }
        }
    }
}

string find_shortest_path(pair<int, int> start, pair<int, int> end) {
    if (dist[end.first][end.second] == -1) {
        return "NO";
    }
    string path;
    while (end != start) {
        pair<int, int> prev = parent[end.first][end.second];
        for (int i = 0; i < 4; i++) {
            int new_x = end.first + dx[i];
            int new_y = end.second + dy[i];
            if (new_x == prev.first && new_y == prev.second) {
                path = moves[i] + path;
                break;
            }
        }
        end = prev;
    }
    return "YES\n" + to_string(dist[start.first][start.second]) + "\n" + path;
}
int main() {
    cin >> n >> m;
    pair<int, int> start, end;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> labyrinth[i][j];
            dist[i][j] = -1;
            if (labyrinth[i][j] == 'A') {
                start = {i, j};
            } else if (labyrinth[i][j] == 'B') {
                end = {i, j};
            }
        }
    }
    bfs(start, end);
    cout << find_shortest_path(start, end) << endl;
    return 0;
}
#include <bits/stdc++.h>
using namespace std;

const int n = 1e5;
int visited[n];
int level[n];
int parent[n];
vector<int> adj_list[n];

void bfs(int src) {
    visited[src] = 1;
    level[src] = 1;
    
    parent[src]=-1;
    queue<int> q;
    q.push(src);

    while (!q.empty()) {
        int head = q.front();
        q.pop();
        for (int adj_node : adj_list[head]) {
            if (visited[adj_node] == 0) {
                parent[adj_node]=head;
                visited[adj_node] = 1;
                level[adj_node] = level[head] + 1;
                q.push(adj_node);
            }
        }
    }
}

int main() {
    int nodes, edges; // Changed variable name from "node" to "nodes" and "edge" to "edges".
    cin >> nodes >> edges;

    for (int i = 0; i < edges; i++) {
        int u, v;
        cin >> u >> v;
        adj_list[u].push_back(v);
        adj_list[v].push_back(u);
    }

    int src = 1;
    bfs(src);

    vector<int>path;
    int dst=node;
    if(visited[dst]==0)
    {
        cout<<"Impossible";
    }
    cout<<level[dst]<<"\n";
    int selected_node=dst;
    while(true)
    {
        path.push_back(selected_node);
        if(selected_node==src)
        {
            break;
        }
        selecte_node=parent[src];
    }
    reverse(path.begin(),path.end())
    for(int node:path)
    {
        cout<<node<<" ";
    }

    return 0;
}
//printing shortest path between two vertices of unweighted graph
using namespace std;
const int n = 1e5;
int parent[n], dist[n];
bool visited[n];
void addEdge(vector <int> adj[], int u, int v){
    adj[u].push_back(v);
    adj[v].push_back(u);
}
bool BFS(vector <int> adj[], int src, int dst, int parent[], int dist[], int node){
    list <int> queue;
    for(int i = 0; i < node; i++){
        visited[i] = false;
        parent[i] = -1;
        dist[i] = INT_MAX;
    }
    visited[src] = true;
    dist[src] = 0;
    queue.push_back(src);
    while (!queue.empty()) {
        int u = queue.front();
        queue.pop_front();

        for (int v : adj[u]) {
            if (!visited[v]) {
                visited[v] = true;
                dist[v] = dist[u] + 1;
                parent[v] = u;
                queue.push_back(v);

                if (v == dst)
                    return true;
            }
        }
    }
    return false;
}
void sortestDist(vector <int> adj[], int src, int dst, int node){
    if(!BFS(adj, src, dst, parent, dist, node)){
        clog << "Src & dest aren't connect";
        return;
    }
    vector <int> path;
    int val = dst;
    path.push_back(val);
    while(parent[val]!= -1){
        path.push_back(parent[val]);
        val = parent[val];
    }
    cout << "Sortest pth length is: " << dist[dst];
    for(int i = path.size() - 1; i >= 0; i--)
        cout << path[i] << " ";
}
int main(){
    int node, edge; cin >> node >> edge;
    vector <int> adj[node];
    for(int i = 0; i < edge; i++){
        int u, v; cin >> u >> v;
        addEdge(adj, u, v);
    }
    int src, dst; cin >> src >> dst;
    sortestDist(adj, src, dst, node);
}
using namespace std;
#define node 4
int Travelling(int graph[node][node], int src){
    vector <int> vertix;
    for(int i = 0; i < node; i++){
        if(i != src)
            vertix.push_back(i);
    }
    int minPath = INT_MAX;
    do{
        int curPathWeight = 0;
        int k = src;
        for(int i = 0; i < vertix.size(); i++){
            curPathWeight += graph[k][vertix[i]];
            k = vertix[i];
        }
        curPathweight += graph[k][src];
        minPath = min(minpath, curPathWeight);
    }while(next_permutation(vertix.begin(), vertix.end()));
    return minPath;
}
int main(){
    int graph[][node] { 
        { 0, 10, 15, 20 }, { 10, 0, 35, 25 },
    { 15, 35, 0, 30 }, { 20, 25, 30, 0 } };
    cout << Travelling(graph, 0);
}
#include<bits/stdc++.h>
using namespace std;
// circle of 14 people labeled 0 to 13.each round, count 2 people and remove the 2nd one, continuing until only one is left.
// find the 0-th Idx where josephus should stand to survive
void josephusCircle(int n, int k) {
    list <int> l;
    for(int i = 0; i < n; i++) l.push_back(i);
    auto it = l.begin();
    while(l.size() > 1) {
        for(int i = 1; i < k; ++i) {
            ++it;
            if(it == l.end()) it = l.begin();
        }
        it = l.erase(it);
        if(it == l.end()) it = l.begin();
    }
    return l.front();
}
// selects k best‑placement cities as centers so that no city is “too far” from a center,
//and the maximum distance to the nearest center is as small as possible
int maxIdx(int *dist, int n) {
    int idx = 0;
    for(int i = 0; i < n; i++) {
        if(dist[i] > dist[idx]) idx = i;
    } return idx;
}
void select(int n, int k, int grid[][4]) {
    int dist[n]; vector <int> center;
    for(int i = 0; i < n; i++) dist[i] = INT_MAX;
    // city with max distance to closest center
    int farst = 0;
    for(int rnd = 0; rnd < k; ++rnd) {
        center.push_back(farst);
        for(int j = 0; j < n; ++j)
            dist[j] = min(dist[j], grid[farst][j]);
        farst = maxIdx(dist, n);
    } 
    cout << dist[farst] << endl;
    for(auto c : center) cout << c << " ";
}
// find the maximum number of packets that can be sent in parallel (in one time slot) from the senders 
//to the receivers, satisfying the one‑packet‑per‑sender‑and‑receiver constraint?”
const int r = 3, c = 4;
bool ismatch(int table[r][c], int u, bool vis[c], int receiver[c]) {
    // returns true if sender u can be matched to some receiver
    for(int v = 0; v < c; ++v) {
        if(table[u][v] > 0 !vis[v]) {
            vis[v] = true;
            if(receiver[v] < 0 || ismatch(table, receiver[v], vis, receiver)) {
                receiver[v] = u; return true;
            }
        }
    } return false;
}
void maxpacket(int table[r][c]) {
// Returns max number of packets that can be sent in 1 time slot
    int receiver[c]; memset(receiver, -1, sizeof(receiver));
    int res = 0
    for(int u = 0; u < r; u++) {
        bool vis[r];
        memset(vis, 0, sizeof(vis));
        if(ismatch(table, u, vis, receiver)) res++;
    }
    cout << res << endl;
    for(int v = 0; v < c; v++) {
        if(receiver[v] != -1) cout << receiver[v] + 1 << " " << v + 1 << endl;
    }
}
//There has nd cities, and edg roads between them.goal is to reach from city 1 to n.Print "YES" if  goal is possible else "NO"
const int maxi = 1e3;
bool visited[maxi]; vector <int> adj[maxi];
void DFS(int u) {
    vis[u] = true;
    for(int v : adj[u]) {
        if(!vis[v]) DFS(v);
    }
}
void printpath(int nd, int edg) {
    for(int i = 0; i < edg; i++) {
        int u, v; cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    for(int i = 1; i <= nd; i++) vis[i] = false;
    DFS(1);
    if(vis[nd]) cout << "Yes";
    else cout << "No";
}
//Count rooms
const int dx[]{0, 0, -1, 1};
const int dy[]{-1, 1, 0, 0};
void DFS(int x, int y, vector <vector <char> > &mp, vector <vector <bool> > &visited){
    visited[x][y] = true;
    for(int dir = 0; dir < 4; dir++){
        int nx = x + dx[dir];
        int ny = y + dy[dir];
        if(nx >= 0 && nx < mp.size() && ny >= 0 && ny < mp[0].size() && !visited[nx][ny] && mp[nx][ny] == '.')
            DFS(nx, ny, mp, visited);
    }
}
int main(){
    int n, m; cin >> n >> m;
    vector <vector <char > > mp(n, vector <char> (m));
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++)
            cin >> mp[i][j];
    }
    int roomCnt = 0;
    vector <vector <bool> > visited(n, vector <bool> (m, false));
    for(int i = 0; i < mp.size(); i++){
        for(int j = 0; j < mp[0].size(); j++){
            if(mp[i][j] == '.' && !visited[i][j]){
                DFS(i, j, mp, visited);
                roomCnt++;
            }
        }
    }
    cout << roomCnt;
}
//count the number of rooms and the length of the longest room.
//length of the longest room means that room which contain maximum floor
int dx[]{0, 0, 1, -1};
int dy[]{1, -1, 0, 0};
int DFS(vector <vector <char > > &Building, int x, int y){
    if(x < 0 || x >= Building.size() || y < 0 || y >= Building[x].size() || Building[x][y] == '#')
        return 0;
    int size = 1;
    Building[x][y] = '#';
    for(int i = 0; i < 4; i++){
        int nx = x + dx[i];
        int ny = y + dy[i];
        size += DFS(Building, nx, ny);
    }
    return size;
}
int main(){
    int n, m; cin >> n >> m;
    vector <vector <char > >Building(n, vector <char>(m));
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++)
            cin >> Building[i][j];
    }
    int roomCnt = 0, LongestRoom = 0;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if(Building[i][j] == '.'){
                int roomSize = DFS(Building, i, j);
                roomCnt++;
                LongestRoom = max(LongestRoom, roomSize);
            }
        }
    }
    cout << roomCnt << " " << LongestRoom << '\n';
}
//count the number of connected components in an undirected graph
void addedg(vector <int> adj[], int u, int v) {
    adj[u].push_back(v); adj[v].push_back(u);
}
void DFS(vector <int> adj[], int u, vector <bool> vis) {
    vis[u] = true;
    for(int v = 0; v < adj[u].size(); v++) {
        if(!vis[adj[u][v]]) DFS(adj, adj[u][v], vis);
    }
}
void connected(int nd) {
    vector <int> adj[nd];
    addedg(adj, 0, 1); addedg(adj, 0, 2);
    addedg(adj, 0, 3); addedg(adj, 3, 4);
    vector <bool> vis(nd, false);
    int cnt = 0;
    for(int i = 0; i < nd; i++) {
        if(!vis[i]) {
            DFS(adj, i, vis); cnt++;
        }
    } cout << cnt;
}
//count the number of distinct clusters (connected components) of 1s in a 2D grid (forest)
typedef pair <int, int> pii;
void BFS(vector <vector <int>> forest, pii start, vector <vector <bool>> vis) {
    queue <pii> q; q.push(start);
    vis[start.first][start.second] = true;
    int dx[4] = {0, 0, -1, 1};
    int dy[4] = {-1, 1, 0, 0};
    while(!q.empty()) {
        auto[x, y] = q.front(); q.pop();
        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i], ny = y + dy[i];
            if (nx >= 0 && nx < forest.size() && ny >= 0 && ny < forest[0].size() &&
                forest[nx][ny] == 1 && !vis[nx][ny]) {
                vis[nx][ny] = true;
                q.push({nx, ny});
            }
        }
    }
}
void connect(vector <vector <int>> forest) { /*
    vector<vector<int>> forest = {
        {0,1,1,0,0}, {0,0,0,0,0},
        {0,0,0,0,0}, {0,0,0,0,1},
        {0,0,0,0,0}
    }; */
    int n = forest.size(), m = forest[0].size(), cnt = 0;
    vector <vector <bool>> vis(n, vector <bool> (m, false));
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            if(forest[i][j] == 1 && !vis[i][j]) {
                BFS(forest, {i, j}, vis); ++cnt;
            }
        }
    } cout << cnt;
}
// counts the number of separate rooms in a grid-based map
void cntroom(int r, int c) {
    int r, c; cin >> r >> c;
    vector <vector <int>> grid(r, vector <int> (c));
    for(int i = 0; i < r; i++) {
        string str; cin >> str;
        for(int j = 0; j < c; j++) 
            grid[i][j] = (str[j] == '#') ? -1 : 0;
    }
    vector<vector<bool>> vis(r, vector<bool>(c, false));
    int dx[4] = {-1,1,0,0}, dy[4] = {0,0,-1,1};
    int rooms = 0;
    auto bfs = [&](auto&& self, int x, int y) -> void {
        queue<pair<int,int>> q;
        q.push({x,y}); vis[x][y] = true;
        
        while (!q.empty()) {
            auto [cx, cy] = q.front(); q.pop();
            for (int d = 0; d < 4; d++) {
                int nx = cx + dx[d], ny = cy + dy[d];
                if (nx >= 0 && nx < r && ny >= 0 && ny < c && 
                    grid[nx][ny] != -1 && !vis[nx][ny]) {
                    vis[nx][ny] = true;
                    q.push({nx, ny});
                }
            }
        }
    };
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            if (grid[i][j] == 0 && !vis[i][j]) {
                bfs(bfs, i, j);
                rooms++;
            }
        }
    }
    cout << rooms << endl;
}
