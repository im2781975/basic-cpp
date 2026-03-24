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
//find shortest distance in a multistage graph.
#include<bits/stdc++.h>
using namespace std;
#define INF INT_MAX
#define N 8
int shortestDist(int graph[N][N]){
    int dist[N]; dist[N - 1] = 0;
    for(int i = N - 2; i >= 0; i--){
        dist[i] = INF;
        for(int j = i; j < N; j++){
            if(graph[i][j] == INF)
                continue;
            dist[i] = min(dist[i], graph[i][j] + dist[j]);
        }
    }
    return dist[0];
}
int main(){
    int graph[N][N] =
      {{INF, 1, 2, 5, INF, INF, INF, INF},
       {INF, INF, INF, INF, 4, 11, INF, INF},
       {INF, INF, INF, INF, 9, 5, 16, INF},
       {INF, INF, INF, INF, INF, INF, 2, INF},
       {INF, INF, INF, INF, INF, INF, INF, 18},
       {INF, INF, INF, INF, INF, INF, INF, 13},
       {INF, INF, INF, INF, INF, INF, INF, 2},
      {INF, INF, INF, INF, INF, INF, INF, INF}};
    cout << shortestDist(graph);
}
using namespace std;
//find the shortest path using multistage graph
using ump = pair <int, unordered_map<int, int> >;
int shortestPath(vector <ump> &graph, int src, int trg, int k){
    vector <int> dist(graph.size(), INT_MAX);
    dist[trg] = 0;
    //Loop over each stage from k-1 to 1
    for(int i = k - 1; i >= 0; i--){
        //Loop over all vertices in the current stage
        for(int u = 0; u < graph.size(); u++){
            if(graph[u].first != i)
                continue;
            for(const auto &v: graph[u].second){
                if(dist[v.first] != INT_MAX)
                     dist[u] = min(dist[u], v.second + dist[v.first]);
            }
        }
    }
    //Return the shortest path distance from source to target
    return dist[src];
}
int main(){
    //Each stage represented a level of nodes
    vector <ump> graph = {
        {0, {{1, 2}, {2, 9}}},
        {1, {{3, 6}, {4, 3}}},  
        {2, {{4, 1}}},          
        {3, {{5, 7}, {6, 2}}},  
        {4, {{5, 1}, {6, 5}}},  
        {5, {{7, 4}}},          
        {6, {{7, 6}}},          
        {7, {}}
    };
    cout << shortestPath(graph, 0, 7, 4) << " ";
}
