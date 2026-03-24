//find a path from start to end. You can walk left, right, up and down. First print "YES", if there is a path, and "NO" otherwise.
//If there is a path, print the length of the shortest such path
#include <iostream>
#include <queue>
#include <vector>
#include <string>
using namespace std;
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
//find the length of the largest region in boolean 2D-matrix
#include <bits/stdc++.h>
using namespace std;
#define ROW 4
#define COL 5
// A function to check if a given cell (row, col) can be included in DFS
int isSafe(int M[][COL], int row, int col,bool visited[][COL])
{
    // row number is in range, column number is in range and value is 1 & not yet visited
    return (row >= 0) && (row < ROW) && (col >= 0)
           && (col < COL)
           && (M[row][col] && !visited[row][col]);
}
// DFS for a 2D boolean matrix. It only considers the 8 neighbours as adjacent vertices
void DFS(int M[][COL], int row, int col,bool visited[][COL], int& count)
{
    // These arrays are used to get row and column numbers of 8 neighbours of a given cell
    static int rowNbr[] = { -1, -1, -1, 0, 0, 1, 1, 1 };
    static int colNbr[] = { -1, 0, 1, -1, 1, -1, 0, 1 };
    // Mark this cell as visited
    visited[row][col] = true;
    // Recur for all connected neighbours
    for (int k = 0; k < 8; ++k) {
        if (isSafe(M, row + rowNbr[k], col + colNbr[k],visited)) {
            // Increment region length by one
            count++;
            DFS(M, row + rowNbr[k], col + colNbr[k],
                visited, count);
        }
    }
}
//returns largest  length region of a given boolean 2D matrix
int largestRegion(int M[][COL])
{
    // Make a bool array to mark visited cells. Initially all cells are unvisited
    bool visited[ROW][COL];
    memset(visited, 0, sizeof(visited));
    // Initialize result as 0 and travesle through the all cells of given matrix
    int result = INT_MIN;
    for (int i = 0; i < ROW; ++i) {
        for (int j = 0; j < COL; ++j) {
            // If a cell with value 1 is not
            if (M[i][j] && !visited[i][j]) {
                // visited yet, then new region found
                int count = 1;
                DFS(M, i, j, visited, count);
                // maximum region
                result = max(result, count);
            }
        }
    }
    return result;
}
int main()
{
    int M[][COL] = { { 0, 0, 1, 1, 0 },
     { 1, 0, 1, 1, 0 },
     { 0, 1, 0, 0, 0 },
     { 0, 0, 0, 0, 1 } };
    cout << largestRegion(M);
    return 0;
}
#include <bits/stdc++.h>
using namespace std;
//find unit area of the largest region of 1s.
int largestRegion(vector<vector<int> >& grid)
{
    int m = grid.size();
    int n = grid[0].size();
    // creating a queue that will help in bfs traversal
    queue<pair<int, int> > q;
    int area = 0;
    int ans = 0;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            // if the value at any particular cell is 1 then
            // from here we need to do the BFS traversal
            if (grid[i][j] == 1) {
                ans = 0;
                // pushing the pair<i,j> in the queue
                q.push(make_pair(i, j));
                // marking the value 1 to -1 so that we
                // don't again push this cell in the queue
                grid[i][j] = -1;
                while (!q.empty()) {
 
                    pair<int, int> t = q.front();
                    q.pop();
                    ans++;
                    int x = t.first;
                    int y = t.second;
                    // now we will check in all 8 directions
                    if (x + 1 < m) {
                        if (grid[x + 1][y] == 1) {
                            q.push(make_pair(x + 1, y));
                            grid[x + 1][y] = -1;
                        }
                    }
                    if (x - 1 >= 0) {
                        if (grid[x - 1][y] == 1) {
                            q.push(make_pair(x - 1, y));
                            grid[x - 1][y] = -1;
                        }
                    }
                    if (y + 1 < n) {
                        if (grid[x][y + 1] == 1) {
                            q.push(make_pair(x, y + 1));
                            grid[x][y + 1] = -1;
                        }
                    }
                    if (y - 1 >= 0) {
                        if (grid[x][y - 1] == 1) {
                            q.push(make_pair(x, y - 1));
                            grid[x][y - 1] = -1;
                        }
                    }
                    if (x + 1 < m && y + 1 < n) {
                        if (grid[x + 1][y + 1] == 1) {
                            q.push(make_pair(x + 1, y + 1));
                            grid[x + 1][y + 1] = -1;
                        }
                    }
                    if (x - 1 >= 0 && y + 1 < n) {
                        if (grid[x - 1][y + 1] == 1) {
                            q.push(make_pair(x - 1, y + 1));
                            grid[x - 1][y + 1] = -1;
                        }
                    }
                    if (x - 1 >= 0 && y - 1 >= 0) {
                        if (grid[x - 1][y - 1] == 1) {
                            q.push(make_pair(x - 1, y - 1));
                            grid[x - 1][y - 1] = -1;
                        }
                    }
                    if (x + 1 < m && y - 1 >= 0) {
                        if (grid[x + 1][y - 1] == 1) {
                            q.push(make_pair(x + 1, y - 1));
                            grid[x + 1][y - 1] = -1;
                        }
                    }
                }
 
                area = max(ans, area);
                ans = 0;
            }
        }
    }
    return area;
}
int main()
{
    vector<vector<int> > M = 
    { { 0, 0, 1, 1, 0 },{ 1, 0, 1, 1, 0 },
    { 0, 1, 0, 0, 0 },{ 0, 0, 0, 0, 1 } };
    cout << largestRegion(M);
    return 0;
}
#include <bits/stdc++.h>
using namespace std;

int dfs(int x, int y, int M, int N, vector<vector<int>>& mat, vector<vector<int>>& dp) {
    if (dp[x][y] != -1)
        return dp[x][y];
    
    vector<vector<int>> dir = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
    int ans = 1;
    for (int i = 0; i < 4; i++) {
        int X = x + dir[i][0];
        int Y = y + dir[i][1];
        
        if (X < 0 || X >= N || Y < 0 || Y >= M)
            continue;
        if (mat[x][y] >= mat[X][Y])
            continue;
        ans = max(ans, 1 + dfs(X, Y, M, N, mat, dp));
    }
    return dp[x][y] = ans;
}

int LongestIncrPath(vector<vector<int>>& matrix) {
    int n = matrix.size();
    if (n == 0) return 0; 
    int m = matrix[0].size();
    vector<vector<int>> dp(n, vector<int>(m, -1));
    int ans = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++)
            ans = max(ans, dfs(i, j, m, n, matrix, dp));
    }
    return ans;
}

int main() {
    vector<vector<int>> matrix = {
        {9, 9, 4},
        {6, 6, 8},
        {2, 1, 1}
    };
    cout << "Length of the longest increasing path: " << LongestIncrPath(matrix) << endl;
    return 0;
}
//find longest lath in DAG.
#include <bits/stdc++.h>
using namespace std;
const int N = 1e5;
vector<int> parent_list[N];
int dp[N];

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
#include <iostream>
#include <vector>
#include <cstring>
using namespace std;
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
//Syrjälä's network has n computers and m connections. Your task is to find out if Uolevi can send a message to Maija, and if it is possible, what is the minimum number of computers on such a route.
//If it is possible to send a message, first print k: the minimum number of computers on a valid route. After this, print an example of such a route and path.print all valid solution.
//If there are no routes, print "IMPOSSIBLE".
#include <iostream>
#include <vector>
using namespace std;
const int MAXN = 1005;  
// Maximum number of computers
vector<int> graph[MAXN];
bool visited[MAXN];
vector<int> path;
bool found = false;
void dfs(int u, int destination) {
    if (found) return;
    visited[u] = true;
    path.push_back(u);

    if (u == destination) {
        found = true;
        cout << path.size() << " ";
        for (int i = 0; i < path.size(); i++) {
            cout << path[i] << " ";
        }
        cout << endl;
        return;
    }
    for (int v : graph[u]) {
        if (!visited[v]) {
            dfs(v, destination);
        }
    }
    path.pop_back();
}
int main() {
    int n, m, u, v;
    cin >> n >> m;
    // Build the graph
    for (int i = 0; i < m; i++) {
        cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }
    int Uolevi, Maija;
    cin >> Uolevi >> Maija;
    dfs(Uolevi, Maija);
    if (!found) {
        cout << "IMPOSSIBLE" << endl;
    }
    return 0;
}
#include <iostream>
#include <vector>
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
#include <bits/stdc++.h>
using namespace std;
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
int main() {
  int n1 = 5;
  vector<vector<int>> city1 = {{0, 1, 2, 3, 4},{1, 0, 5, 0, 7},
    {2, 5, 0, 6, 0},{3, 0, 6, 0, 0}, {4, 7, 0, 0, 0}};
  findcost(n1, city1);

  int n2 = 6;
  vector<vector<int>> city2 = {{0, 1, 1, 100, 0, 0}, 
  {1, 0, 1, 0, 0, 0},{1, 1, 0, 0, 0, 0},   
    {100, 0, 0, 0, 2, 2},{0, 0, 0, 2, 0, 2},  
    {0, 0, 0, 2, 2, 0}};
  findcost(n2, city2);
  return 0;
}
// finding minimum cut using Ford-Fulkerson
#include <iostream>
#include <limits.h>
#include <string.h>
#include <queue>
using namespace std;
#define V 6
//Returns true if there is a path from source 's' to sink 't' in residual graph. Also fills parent[] to store the path
int bfs(int rGraph[V][V], int s, int t, int parent[])
{
    // Create a visited array and mark all vertices as not visited
    bool visited[V];
    memset(visited, 0, sizeof(visited));
 
    // Create a queue, enqueue source vertex and mark source vertex as visited
    queue <int> q;
    q.push(s);
    visited[s] = true;
    parent[s] = -1;
    while (!q.empty())
    {
        int u = q.front();
        q.pop();
 
        for (int v=0; v<V; v++)
        {
            if (visited[v]==false && rGraph[u][v] > 0)
            {
                q.push(v);
                parent[v] = u;
                visited[v] = true;
            }
        }
    }
    // If we reached sink in BFS starting from source, then return true, else false
    return (visited[t] == true);
}
 
// A DFS based function to find all reachable vertices from s.  The function
// marks visited[i] as true if i is reachable from s.  The initial values in
// visited[] must be false. We can also use BFS to find reachable vertices
void dfs(int rGraph[V][V], int s, bool visited[])
{
    visited[s] = true;
    for (int i = 0; i < V; i++)
       if (rGraph[s][i] && !visited[i])
           dfs(rGraph, i, visited);
}
// Prints the minimum s-t cut
void minCut(int graph[V][V], int s, int t)
{
    int u, v;
 
    // Create a residual graph and fill the residual graph with
    // given capacities in the original graph as residual capacities in residual graph
    int rGraph[V][V];
    // rGraph[i][j] indicates residual capacity of edge i-j
    for (u = 0; u < V; u++)
        for (v = 0; v < V; v++)
             rGraph[u][v] = graph[u][v];
 
    int parent[V]; 
    // This array is filled by BFS and to store path
 
    // Augment the flow while there is a path from source to sink
    while (bfs(rGraph, s, t, parent))
    {
        // Find minimum residual capacity of the edges along the
        // path filled by BFS. Or we can say find the maximum flow through the path found.
        int path_flow = INT_MAX;
        for (v=t; v!=s; v=parent[v])
        {
            u = parent[v];
            path_flow = min(path_flow, rGraph[u][v]);
        }
        // update residual capacities of the edges and reverse edges along the path
        for (v=t; v != s; v=parent[v])
        {
            u = parent[v];
            rGraph[u][v] -= path_flow;
            rGraph[v][u] += path_flow;
        }
    }
    // Flow is maximum now, find vertices reachable from s
    bool visited[V];
    memset(visited, false, sizeof(visited));
    dfs(rGraph, s, visited);
 
    // Print all edges that are from a reachable vertex to
    // non-reachable vertex in the original graph
    for (int i = 0; i < V; i++)
      for (int j = 0; j < V; j++)
         if (visited[i] && !visited[j] && graph[i][j])
              cout << i << " - " << j << endl;
 
    return;
}
int main()
{
    int graph[V][V] = { {0, 16, 13, 0, 0, 0},
    {0, 0, 10, 12, 0, 0},
    {0, 4, 0, 0, 14, 0},
    {0, 0, 9, 0, 0, 20},
    {0, 0, 0, 7, 0, 4},
    {0, 0, 0, 0, 0, 0}};
    minCut(graph, 0, 5);
    return 0;
}
