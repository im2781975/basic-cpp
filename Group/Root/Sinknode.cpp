using namespace std;

using ll = long long;

int solve(int n, int m, vector<vector<char>>& grid, vector<vector<ll>>& dp) {
    if (n < 0 || m < 0 || grid[n][m] == '#') {
        return 0;
    }
    if (n == 0 && m == 0) {
        return 1;
    }
    if (dp[n][m] != -1) {
        return dp[n][m];
    }

    int ans = 0;
    if (n > 0) {
        ans += solve(n - 1, m, grid, dp);
    }
    if (m > 0) {
        ans += solve(n, m - 1, grid, dp);
    }

    dp[n][m] = ans;
    return dp[n][m];
}

int main() {
    int n, m;
    cin >> n >> m;
    vector<vector<char>> grid(n, vector<char>(m));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> grid[i][j];
        }
    }
    vector<vector<ll>> dp(n, vector<ll>(m, -1));

    cout << solve(n - 1, m - 1, grid, dp) << endl;
    return 0;
}
//find out minimum cost path to connect all the cities
// Function to find out minimum valued node among the nodes which are not yet included in MST
int minnode(int n, int keyval[], bool mstset[]) {
  int mini = numeric_limits<int>::max();
  int mini_index;
 
  // Loop through all the values of the nodes which are not yet included in MST and find
  // the minimum valued one.
    for (int i = 0; i < n; i++) {
        if (mstset[i] == false && keyval[i] < mini) {
            mini = keyval[i], mini_index = i;
        }
    }
  return mini_index;
}
// Function to find out the MST and the cost of the MST.
void findcost(int n, vector<vector<int>> city) {
 /* int n1 = 5;
  vector<vector<int>> city1 = {{0, 1, 2, 3, 4},{1, 0, 5, 0, 7},
    {2, 5, 0, 6, 0},{3, 0, 6, 0, 0}, {4, 7, 0, 0, 0}};
  findcost(n1, city1); */
    int parent[n];
    int keyval[n];
 
  // Boolean Array to hold bool values whether
  // a node is included in MST or not.
  bool mstset[n];
 
  // Set all the key values to infinite and none of the nodes is included in MST.
    for (int i = 0; i < n; i++) {
        keyval[i] = numeric_limits<int>::max();
        mstset[i] = false;
    }
 
    // Start to find the MST from node 0.Parent of node 0 is none so set -1.
    // key value or minimum cost to reach 0th node from 0th node is 0.
    parent[0] = -1;
    keyval[0] = 0;
 
    // Find the rest n-1 nodes of MST
    for (int i = 0; i < n - 1; i++)
    {
        // First find out the minimum node among the nodes which are not yet included in MST.
        int u = minnode(n, keyval, mstset);
 
        // Now the uth node is included in MST.
    mstset[u] = true;
 
        // Update the values of neighbor nodes of u which are not yet included in MST.
    for (int v = 0; v < n; v++) {
 
        if (city[u][v] && mstset[v] == false && city[u][v] < keyval[v]) 
        {
            keyval[v] = city[u][v];
            parent[v] = u;
        }
    }
  }
  // Find out the cost by adding
  // the edge values of MST.
    int cost = 0;
    for (int i = 1; i < n; i++)
        cost += city[parent[i]][i];
    cout << cost << endl;
}
using namespace std;
// find the minimum Groups
int dfsheight(int u, int *vis, vector <int> &adj) {
    vis[u] = 1; int maxht = 0;
    for(auto &v : adj[u]) {
        if(vis[v] == 0) maxht = max(maxht, 1 + dfsheight(v, vis, adj));
    }
    return maxht;
}
int mingrp(vector <int> adj[], int nd) {
    int vis[nd + 1] = {0};
    int grp = INT_MIN;
    for(int i = 1; i <= nd; i++) {
        if(vis[i] == 0) {
            int ht = dfsheight(i, vis, adj);
            grp = max(ht, grp);
        }
    }
    return grp;
}
int minGroups(int N, vector<vector<int>>& adj) {
    vector<bool> visited(N + 1, false);
    int maxHeight = 0;
    
    function<int(int)> dfsHeight = [&](int node) -> int {
        visited[node] = true;
        int height = 0;
        
        for(int child : adj[node]) {
            if(!visited[child]) {
                height = max(height, 1 + dfsHeight(child));
            }
        }
        return height;
    };
    for(int i = 1; i <= N; i++) {
        if(!visited[i]) {
            maxHeight = max(maxHeight, dfsHeight(i));
        }
    }
    return maxHeight;
}
// count walks from u to v with exactly k edges
#define nd 4
int countwalks(int graph[][nd], int u, int v, int k) {
    int count[nd][nd][k + 1];
    for (int e = 0; e <= k; e++) {
        for (int i = 0; i < nd; i++) {
            for (int j = 0; j < nd; j++) {
                count[i][j][e] = 0;
                if (e == 0 && i == j) count[i][j][e] = 1;
                if (e == 1 && graph[i][j])
                    count[i][j][e] = 1;
                if (e > 1) {
                    for (int a = 0; a < nd; a++)
                        if (graph[i][a])
                            count[i][j][e] += count[a][j][e - 1];
                }
            }
        }
    }
    return count[u][v][k];
}
int cntwalks(int graph[][nd], int u, int v, int k) {
    if(k == 0 && u == v) return 1;
    if(k == 1 && graph[u][v]) return 1;
    if(k <= 0) return 0;
    int cnt = 0;
    for(int i = 0; i < nd; i++) {
        if(graph[u][i] == 1) cnt += cntwalks(graph, i, v, k - 1);
    }
    return cnt;
}
//count walks from u to v with exactly k edges
int CountWalks(int graph[][node], int u, int v, int k){
    if(k == 0 && u == v)
        return 1;
    if(k == 1 && graph[u][v])
        return 1;
    if(k <= 0)
        return 0;
    int cnt = 0;
    for(int i = 0; i < node; i++){
        if(graph[u][i] == 1)
            cnt += CountWalks(graph,i, v, k - 1);
    }
    return cnt;
}
int main(){
    int graph[node][node] ={ { 0, 1, 1, 1 },{ 0, 0, 0, 1 },
    { 0, 0, 0, 1 },{ 0, 0, 0, 0 } };
    int u = 0, v = 3, k = 2;
    cout << CountWalks(graph, u, v, k);
}
//count walks from u to v with exactly k edges
using namespace std;
#define node 4
int CountWalks(int graph[][node], int u, int v, int k){
    // value count[i][j][e] will store count of possible walks from i to j with exactly k edges
    int cnt[node][node][k + 1];
    for(int e = 0; e <= k; e++){
        for(int i = 0; i < node; i++){
            for(int j = 0; j < node; j++){
                cnt[i][j][e] = 0;
                if(e == 0 && i == j)
                    cnt[i][j][e] = 1;
                if(e == 1 && graph[i][j])
                    cnt[i][j][e] = 1;
                if(e > 1){
                    // adjacent of source i
                    for(int a = 0; a < node; a++){
                        if(graph[i][a] == 1)
                        cnt[i][j][e] += cnt[a][j][e - 1];
                    }
                }
            }
        }
    }
    return cnt[u][v][k];
}
int main(){
    int graph[node][node] =
    { { 0, 1, 1, 1 },{ 0, 0, 0, 1 }
    ,{ 0, 0, 0, 1 }, { 0, 0, 0, 0 } };
    int u = 0, v = 3, k = 2;
    cout << CountWalks(graph, u, v , k);
}
// Check if Tree A is mirror image of Tree B
int mirrorTree(int *arr, int *ray) {
    int n = 3, e = 2;
    vector <stack <int>> st; vector <queue <int>> qe;
    for(int i = 0; i <= n; i++) {
        st.push(stack <int> ());
        queue <int> q; qe.push(q);
    }
    for(int i = 0; i < 2 * e; i += 2) {
        st[arr[i]].push(arr[i + 1]);
        qe[ray[i]].push(ray[i + 1]);
    }
    for(int i = 1; i <= n; i++) {
        while(!st[i].empty() && !qe[i].empty()) {
            int x = st[i].top(); st[i].pop();
            int y = qe[i].top(); qe[i].pop();
            if(x != y) return 0;
        }
    }
    return 1;
}
int mirrorTree(int *u1, int *v1, int *u2, int *v2) {
    int n = sizeof(u1) / sizeof(u1[0]);
    unordered_map <int, stack <int>> mp;
    for(int i = 0; i < n; i++) mp[u1[i]].push_back(v1[i]);
    for(int i = 0; i < n; i++) {
        if(mp[u2[i]].top() != v2[i]) return 0;
        mp[u2[i]].pop();
    }
    return 1;
}
// Minimum Knight Moves on chessboard
int minknightmove(int *start, int *target, int n) {
    vector <vector <bool>> vis(n + 1, vector <bool> (n + 1));
    queue <tuple <int, int, int>> q; // x, y, steps
    q.push({start[0], start[1], 0});
    vis[start[0]][start[1]] = 1;
    while(!q.empty()) {
        auto [x, y, steps] = q.front(); q.pop();
        if(x == target[0] && y == target[1]) return steps;
            
        for(int i = 0; i < 8; i++) {
            int nx = x + dx[i], ny = y + dy[i];
            if(nx >= 1 && nx <= N && ny >= 1 && ny <= N && !vis[nx][ny]) {
                vis[nx][ny] = true;
                q.push({nx, ny, steps + 1});
            }
        }
    }
    return -1;
}
// find the longest distance from source to destination with at most K intermediate nodes

int longestpath(int n, vector <vector <int>> &edges, int src, int dst, int k) {
    vector <vector <pair <int, int>>> adj(n);
    for(auto &edges : edg) 
        adj[edg[0]].emplace_back(edg[1], edg[2]);
    queue <pair <int, int>> q; // {src, dist}
    unordered_map <int, int> dist;
    q.push({src, 0}), dist[src] = 0;
    int level = 0;
    while(!q.empty() && level <= k + 1) {
        int sz = q.size();
        for(int i = 0; i < sz; i++) {
            auto [u, d] = q.front(); q.pop();
            if(u == dst) {}
            for(auto [v, w] : adj[u]) {
                int newDist = d + w;
                if(dist.find(v) == dist.end() || newDist > dist[v]) {
                    dist[v] = newDist;
                    q.push({v, newDist});
                }
            }
        }
        level++;
    } 
    return dist[dst];
}
#define x 256
void firstunqalt() {
    int queue[x], front = -1, rear = -1, nextpos = 0;
    bool dup[x] = {false};
    string ing = "geeksforgeeksandgeeksquizfor";
    for(int i = 0; str[i]; i++) {
        char ch = str[i];
        if(!dup[ch]) {
            if(front == -1) front = rear = 0;
            else rear = (rear + 1) % x;
            queue[rear] = ch; dup[ch] = false;
        }
        else {
            int pos = (front + nextpos) % x;
            while(pos != (rear + 1) % x) {
                if(queue[pos] == ch) {
                    // shift val for remove
                    for(int j = pos; j != rear; j = (j + 1) % x)
                        queue[j] = queue[(j + 1) % x];
                    rear = (rear - 1 + x) % x;
                    break;
                }
                pos = (pos + 1) % x;
            }
        }
    }
    if (front != -1 && front <= rear)
            cout << queue[front] << endl;
    else
        cout << "No non-repeating character so far";
}
// printing Minimum Cost Simple Path between two given nodes
int mincostpath(int u, int dest, bool *vis, int graph[][nd]) {
    if(u == dest) return 0;
    vis[u] = 1; int res = INT_MAX;
    for(int i = 0; i < nd; i++) {
        if(graph[u][i] != INT_MAX && !vis[i]) {
            int curr = mincostpath(i, dest, vis, graph);
            if(curr < INT_MAX)
                res = min(res, graph[u][i] + curr)
        }
    }
    vis[u] = 0;
    return res;
}

int minCost = INT_MAX;
void findMinPath(unordered_map<int, vector<pair<int,int>>>& graph,
     vector<bool>& visited, vector<int>& required,
    int curr, int dest, int cost) {
    if(curr == dest) {
        bool allVisited = true;
        for(int node : required) {
            if(!visited[node]) {
                allVisited = false;
                break;
            }
        }
        if(allVisited) minCost = min(minCost, cost);
        return;
    }
    visited[curr] = true;
    for(auto [next, weight] : graph[curr]) {
        if(!visited[next]) {
            findMinPath(graph, visited, required, next, dest, cost + weight);
        }
    }
    visited[curr] = false; 
}
int main() {
    unordered_map<int, vector<pair<int,int>>> graph = {
        {0, {{1,2},{2,3},{3,2}}},
        {1, {{4,4},{0,1}}},
        {2, {{4,5},{5,6}}},
        {3, {{5,7},{0,1}}},
        {4, {{6,4}}},
        {5, {{6,2}}},
        {6, {{7,11}}}
    };
    int src = 0, dst = 6;
    vector<int> required = {2, 4};
    vector<bool> visited(8, false);
    findMinPath(graph, visited, required, src, dst, 0);
    cout << (minCost == INT_MAX ? -1 : minCost) << endl;
}
int minDistance(vector<string>& grid) {
    // vector<string> grid = {
        "0*s", "*0**", "0***", "d***" };
    int n = grid.size(), m = grid[0].size();
    vector<vector<bool>> visited(n, vector<bool>(m));
    queue<tuple<int,int,int>> q;  // r, c, dist
    
    // Find start position
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            if(grid[i][j] == 's') {
                q.push({i, j, 0});
                visited[i][j] = true;
            }
        }
    }
    
    int dr[] = {-1, 1, 0, 0};  // up, down, left, right
    int dc[] = {0, 0, -1, 1};
    
    while(!q.empty()) {
        auto [r, c, dist] = q.front(); q.pop();
        
        if(grid[r][c] == 'd') return dist;
        
        // 4 directions
        for(int d = 0; d < 4; d++) {
            int nr = r + dr[d], nc = c + dc[d];
            if(nr >= 0 && nr < n && nc >= 0 && nc < m && 
               grid[nr][nc] != '0' && !visited[nr][nc]) {
                visited[nr][nc] = true;
                q.push({nr, nc, dist + 1});
            }
        }
    }
    return -1;
}
#include<bits/stdc++.h>
using namespace std;
//find longest lath in DAG.
int max_distance(int node) {
    if (node == root) return 0;
    if (dp[node] != -1) return dp[node];

    int ans = 0;
    for (int parent : parent_list[node]) {
        int parent_dist = max_distance(parent);
        ans = max(ans, parent_dist);
    }
    ans++;
    dp[node] = ans;
    return dp[node];
}
int main() {
    int node, edge;
    cin >> node >> edge;
    for (int i = 0; i < edge; i++) {
        int u, v;
        cin >> u >> v;
        parent_list[v].push_back(u);
    }
    for (int i = 1; i <= node; i++) {
        dp[i] = -1;
    }
    int root, target_node; 
    cin >> root >> target_node;
    cout << max_distance(target_node);
    return 0;
}
//You play a game consisting of n rooms and m tunnels. Your initial score is 0, and each tunnel increases your score by x where x may be both positive or negative. You may go through a tunnel several times.
//Your task is to walk from room 1 to room n. What is the maximum score you can get?
const int MAX_N = 105;
const int INF = 1e9;
int n, m;
vector<pair<int, int>> tunnels[MAX_N];
int dp[MAX_N][MAX_N];

int maxScore(int curRoom, int remainingRooms) {
    if (remainingRooms == 0) {
        if (curRoom == n) {
            return 0;
        } else {
            return -INF; // It's not possible to reach room n in the given number of moves.
        }
    }
    if (dp[curRoom][remainingRooms] != -1) {
        return dp[curRoom][remainingRooms];
    }
    int maxScore = -INF;
    for (auto tunnel : tunnels[curRoom]) {
        int nextRoom = tunnel.first;
        int score = tunnel.second;

        int result = maxScore(nextRoom, remainingRooms - 1);
        if (result != -INF) {
            maxScore = max(maxScore, result + score);
        }
    }
    return dp[curRoom][remainingRooms] = maxScore;
}
int main() {
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int u, v, x;
        cin >> u >> v >> x;
        tunnels[u].push_back({v, x});
    }
    memset(dp, -1, sizeof(dp));
    int result = maxScore(1, n);
    if (result == -INF) {
        cout << -1 << endl;
    } else {
        cout << result << endl;
    }
    return 0;
}
// sink node is a node with no outgoing edges.
int cntsinknode(int nd, int edg, int *src, int *dst) {
    int vis[nd] = {0}, cnt = 0;
    for(int i = 0; i < edg; i++) vis[src[i]] = 1;
    int cnt = 0;
    for(int i = 0; i < nd; i++) {
        if(!vis[i]) ++cnt;
    }
    /* int arr[node] = {0};
    for(int i = 0; i < node; i++) arr[src[i]] = 1;
    for(int i = 1; i <= node; i++){
        if(arr[i] == 0) cnt++;
    } */
    return cnt;
}
//find transpose of a graph.
using namespace std;
void addEdge(vector <int> adj[], int u, int v){
    adj[u].push_back(v);
}
void Display(vector <int> adj[], int node){
    for(int i = 0; i < node; i++){
        for(int j = 0; j < adj[i].size(); j++)
            cout << adj[i][j] << " ";
        cout << "\n";
    }
    cout << "\n";
}
void TransposeGraph(vector <int> transpose[], vector <int> adj[], int node){
    for(int i = 0; i < node; i++){
        for(int j = 0; j < adj[i].size(); j++)
            addEdge(transpose, adj[i][j], i);
    }
}
int main(){
    int node = 5;
    vector <int> adj[node];
    addEdge(adj, 0, 1);
    addEdge(adj, 0, 4);
    addEdge(adj, 0, 3);
    addEdge(adj, 2, 0);
    addEdge(adj, 3, 2);
    addEdge(adj, 4, 1);
    addEdge(adj, 4, 3);
    vector <int> transpose[node];
    
    TransposeGraph(transpose, adj, node);
    //Display(adj, node);
    Display(transpose, node);
}
#include<bits/stdc++.h>
using namespace std;
int main(){
    vector <vector <int>> edgeList(4);
    edgeList[0].push_back(0);
    edgeList[0].push_back(1);
    edgeList[1].push_back(2);
    edgeList[1].push_back(1);
    edgeList[2].push_back(1);
    edgeList[2].push_back(3);
    edgeList[3].push_back(2);
    edgeList[3].push_back(3);
    for(int i = 0; i < edgeList.size(); i++){
        for(int j = 0; j < edgeList[i].size(); j++)
            cout << edgeList[i][j] << " ";
        cout << "\n";
    }
}
using namespace std;
int main(){
    vector <vector <int> >edgeList 
    {{1, 2, 3}, {4, 5, 6}, 
    {7, 8, 9}, {10, 11, 12},};
    edgeList.push_back({13, 14, 15});
    for(int i = 0; i < edgeList.size(); i++){
        cout << edgeList[i][0] << " " << edgeList[i][1] << " " << edgeList[i][2] << " ";
        cout << "\n";
    }
}
using namespace std;
int main(){
    int node, edge; cin >> node >> edge;
    cout << "Maximum number of edges that can be added to maintain DAG is: " << (node * (node - 1) /2) - edge;
}
