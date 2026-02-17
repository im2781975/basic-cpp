// find shortest safe Route in the matrix with landmines
#include <bits/stdc++.h>
using namespace std;
#define R 12
#define C 10
// These arrays are used to get row and column numbers of 4 neighbours of a given cell
int rowNum[] = { -1, 0, 0, 1 };
int colNum[] = { 0, -1, 1, 0 };
 
// A function to check if a given cell (x, y) can be visited or not
bool isSafe(int mat[R][C], int visited[R][C],
            int x, int y)
{
    if (mat[x][y] == 0 || visited[x][y])
        return false;
 
    return true;
}
// A function to check if a given cell (x, y) is a valid cell or not
bool isValid(int x, int y)
{
    if (x < R && y < C && x >= 0 && y >= 0)
        return true;
    return false;
}
// A function to mark all adjacent cells of landmines as unsafe. Landmines are shown with number 0
void markUnsafeCells(int mat[R][C])
{
    for (int i = 0; i < R; i++)
    {
        for (int j = 0; j < C; j++)
        {
            // if a landmines is found
            if (mat[i][j] == 0)
            {
              // mark all adjacent cells
              for (int k = 0; k < 4; k++)
                if (isValid(i + rowNum[k], j + colNum[k]))
                    mat[i + rowNum[k]][j + colNum[k]] = -1;
            }
        }
    }
    // mark all found adjacent cells as unsafe
    for (int i = 0; i < R; i++)
    {
        for (int j = 0; j < C; j++)
        {
            if (mat[i][j] == -1)
                mat[i][j] = 0;
        }
    }
 
    // Uncomment below lines to print the path
    /*for (int i = 0; i < R; i++)
    {
        for (int j = 0; j < C; j++)
        {
            cout << std::setw(3) << mat[i][j];
        }
        cout << endl;
    }*/
}
// Function to find shortest safe Route in the matrix with landmines
// mat[][] - binary input matrix with safe cells marked as 1
// visited[][] - store info about cells already visited in current route
// (i, j) are coordinates of the current cell
// min_dist --> stores minimum cost of shortest path so far
// dist --> stores current path cost
void findShortestPathUtil(int mat[R][C], int visited[R][C],
                          int i, int j, int &min_dist, int dist)
{
    // if destination is reached
    if (j == C-1)
    {
        // update shortest path found so far
        min_dist = min(dist, min_dist);
        return;
    }
    // if current path cost exceeds minimum so far
    if (dist > min_dist)
        return;
    // include (i, j) in current path
    visited[i][j] = 1;
 
    // Recurse for all safe adjacent neighbours
    for (int k = 0; k < 4; k++)
    {
        if (isValid(i + rowNum[k], j + colNum[k]) &&
            isSafe(mat, visited, i + rowNum[k], j + colNum[k]))
        {
            findShortestPathUtil(mat, visited, i + rowNum[k],
                           j + colNum[k], min_dist, dist + 1);
        }
    }
    // Backtrack
    visited[i][j] = 0;
}
// A wrapper function over findshortestPathUtil()
void findShortestPath(int mat[R][C])
{
    // stores minimum cost of shortest path so far
    int min_dist = INT_MAX;
 
    // create a boolean matrix to store info about cells already visited in current route
    int visited[R][C];
    // mark adjacent cells of landmines as unsafe
    markUnsafeCells(mat);
    // start from first column and take minimum
    for (int i = 0; i < R; i++)
    {
        // if path is safe from current cell
        if (mat[i][0] == 1)
        {
            // initialize visited to false
            memset(visited, 0, sizeof visited);
 
            // find shortest route from (i, 0) to any cell of last column (x, C - 1) where 0 <= x < R
            findShortestPathUtil(mat, visited, i, 0, min_dist, 0);
            // if min distance is already found
            if(min_dist == C - 1)
                break;
        }
    }
    // if destination can be reached
    if (min_dist != INT_MAX)
        cout << "Length of shortest safe route is "
             << min_dist;
 
    else // if the destination is not reachable
        cout << "Destination not reachable from "
             << "given source";
}
int main()
{
    // input matrix with landmines shown with number 0
    int mat[R][C] =
    {
        { 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 },
        { 1, 0, 1, 1, 1, 1, 1, 1, 1, 1 },
        { 1, 1, 1, 0, 1, 1, 1, 1, 1, 1 },
        { 1, 1, 1, 1, 0, 1, 1, 1, 1, 1 },
        { 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 },
        { 1, 1, 1, 1, 1, 0, 1, 1, 1, 1 },
        { 1, 0, 1, 1, 1, 1, 1, 1, 0, 1 },
        { 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 },
        { 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 },
        { 0, 1, 1, 1, 1, 0, 1, 1, 1, 1 },
        { 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 },
        { 1, 1, 1, 0, 1, 1, 1, 1, 1, 1 }
    };
    findShortestPath(mat);
    return 0;
}
// find shortest safe Route in the matrix with landmines
#include <bits/stdc++.h>
using namespace std;
#define R 12 
#define C 10 
 
struct Key{
    int x,y;
    Key(int i,int j){ x=i;y=j;};
};
// These arrays are used to get row and column numbers of 4 neighbours of a given cell
int rowNum[] = { -1, 0, 0, 1 }; 
int colNum[] = { 0, -1, 1, 0 };
 
// A function to check if a given cell (x, y) is a valid cell or not
bool isValid(int x, int y) 
{ 
    if (x < R && y < C && x >= 0 && y >= 0) 
        return true; 
    return false; 
} 
// A function to mark all adjacent cells of landmines as unsafe. Landmines are shown with number 0
void findShortestPath(int mat[R][C]){
    int i,j;
 
    for (i = 0; i < R; i++) 
    { 
        for (j = 0; j < C; j++) 
        { 
            // if a landmines is found
            if (mat[i][j] == 0) 
            { 
            // mark all adjacent cells
            for (int k = 0; k < 4; k++) 
                if (isValid(i + rowNum[k], j + colNum[k])) 
                    mat[i + rowNum[k]][j + colNum[k]] = -1; 
            } 
        } 
    } 
// mark all found adjacent cells as unsafe
    for (i = 0; i < R; i++) 
    { 
        for (j = 0; j < C; j++) 
        { 
            if (mat[i][j] == -1) 
                mat[i][j] = 0; 
        } 
    } 
    int dist[R][C];
 
    for(i=0;i<R;i++){
        for(j=0;j<C;j++)
            dist[i][j] = -1;
    }
    queue<Key> q;
 
    for(i=0;i<R;i++){
        if(mat[i][0] == 1){
            q.push(Key(i,0));
            dist[i][0] = 0;
        }
    }
 
    while(!q.empty()){
        Key k = q.front();
        q.pop();
 
        int d = dist[k.x][k.y];
 
        int x = k.x;
        int y = k.y;
 
        for (int k = 0; k < 4; k++) {
            int xp = x + rowNum[k];
            int yp = y + colNum[k];
            if(isValid(xp,yp) && dist[xp][yp] == -1 && mat[xp][yp] == 1){
                dist[xp][yp] = d+1;
                q.push(Key(xp,yp));
            }
        }
    }
    // stores minimum cost of shortest path so far
    int ans = INT_MAX;
    // start from first column and take minimum
    for(i=0;i<R;i++){
        if(mat[i][C-1] == 1 && dist[i][C-1] != -1){
            ans = min(ans,dist[i][C-1]);
        }
    }
    // if destination can be reached
    if(ans == INT_MAX)
        cout << "NOT POSSIBLE\n";
         
    else// if the destination is not reachable
        cout << "Length of shortest safe route is " << ans << endl;
}
int main(){
     
    // input matrix with landmines shown with number 0
    int mat[R][C] = 
    { 
        { 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 }, 
        { 1, 0, 1, 1, 1, 1, 1, 1, 1, 1 }, 
        { 1, 1, 1, 0, 1, 1, 1, 1, 1, 1 }, 
        { 1, 1, 1, 1, 0, 1, 1, 1, 1, 1 }, 
        { 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 }, 
        { 1, 1, 1, 1, 1, 0, 1, 1, 1, 1 }, 
        { 1, 0, 1, 1, 1, 1, 1, 1, 0, 1 }, 
        { 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 }, 
        { 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 }, 
        { 0, 1, 1, 1, 1, 0, 1, 1, 1, 1 }, 
        { 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 }, 
        { 1, 1, 1, 0, 1, 1, 1, 1, 1, 1 } 
    }; 
    findShortestPath(mat); 
}
// find the shortest path between a given source cell to a destination cell.
#include <bits/stdc++.h>
using namespace std;
#define ROW 9
#define COL 10
//To store matrix cell coordinates
struct Point
{
    int x;
    int y;
};
// A Data Structure for queue used in BFS
struct queueNode
{
    Point pt;  // The coordinates of a cell
    int dist;  // cell's distance of from the source
};
// check whether given cell (row, col) is a valid cell or not.
bool isValid(int row, int col)
{
    // return true if row number and column number is in range
    return (row >= 0) && (row < ROW) &&
           (col >= 0) && (col < COL);
}
// These arrays are used to get row and column numbers of 4 neighbours of a given cell
int rowNum[] = {-1, 0, 0, 1};
int colNum[] = {0, -1, 1, 0};
// function to find the shortest path between a given source cell to a destination cell.
int BFS(int mat[][COL], Point src, Point dest)
{
    // check source and destination cell of the matrix have value 1
    if (!mat[src.x][src.y] || !mat[dest.x][dest.y])
        return -1;
 
    bool visited[ROW][COL];
    memset(visited, false, sizeof visited);
    // Mark the source cell as visited
    visited[src.x][src.y] = true;
    // Create a queue for BFS
    queue<queueNode> q;
    // Distance of source cell is 0
    queueNode s = {src, 0};
    q.push(s);  
    // Enqueue source cell
    // Do a BFS starting from source cell
    while (!q.empty())
    {
        queueNode curr = q.front();
        Point pt = curr.pt;
        // If we have reached the destination cell, we are done
        if (pt.x == dest.x && pt.y == dest.y)
            return curr.dist;
        // Otherwise dequeue the front cell in the queue and enqueue its adjacent cells
        q.pop();
        for (int i = 0; i < 4; i++)
        {
            int row = pt.x + rowNum[i];
            int col = pt.y + colNum[i];
             
            // if adjacent cell is valid, has path and not visited yet, enqueue it.
            if (isValid(row, col) && mat[row][col] && 
               !visited[row][col])
            {
                // mark cell as visited and enqueue it
                visited[row][col] = true;
                queueNode Adjcell = { {row, col},
                                      curr.dist + 1 };
                q.push(Adjcell);
            }
        }
    }
    // Return -1 if destination cannot be reached
    return -1;
}
int main()
{
    int mat[ROW][COL] =
    {
        { 1, 0, 1, 1, 1, 1, 0, 1, 1, 1 },
        { 1, 0, 1, 0, 1, 1, 1, 0, 1, 1 },
        { 1, 1, 1, 0, 1, 1, 0, 1, 0, 1 },
        { 0, 0, 0, 0, 1, 0, 0, 0, 0, 1 },
        { 1, 1, 1, 0, 1, 1, 1, 0, 1, 0 },
        { 1, 0, 1, 1, 1, 1, 0, 1, 0, 0 },
        { 1, 0, 0, 0, 0, 0, 0, 0, 0, 1 },
        { 1, 0, 1, 1, 1, 1, 0, 1, 1, 1 },
        { 1, 1, 0, 0, 0, 0, 1, 0, 0, 1 }
    };
    Point source = {0, 0};
    Point dest = {3, 4};
 
    int dist = BFS(mat, source, dest);
 
    if (dist != -1)
        cout << "Shortest Path is " << dist ;
    else
        cout << "Shortest Path doesn't exist";
    return 0;
}
//CSES
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=1e5;
const ll INF=(ll)1e9;
ll dist[maxn];
vector<pair<ll, ll> > adj[maxn];
vector<bool>visited(maxn);
void dijkstra(int src, int n)
{
    for(int i=1; i<=n; i++)
        dist[i]=INF;
    dist[src]=0;
    //Min heap
    priority_queue<pair<ll, ll>, vector<pair <ll, ll> >, greater<pair < ll, ll> > > pq;
    pq.push({ 0, src});
    while(!pq.empty())
    {
        int u=pq.top().second;
        ll cost=pq.top().first;
        pq.pop();
        
        if(visited[u])
            continue;
        visited[u]=true;
        for(auto child:adj[u])
        {
            int v=child.first;
            ll c=child.second;
            if((cost + c) < dist[v])
            {
                dist[v] = cost + c;
                pq.push({dist[v], v });
            }
        }
    }
}
int main()
{
    int e, n;
    cin >> n >> e;
    for(int i=1; i<=e; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back({v, w});
    }
    dijkstra(1, n);
    for(int i=1; i<=n; i++)
        cout << dist[i] << " ";
    cout << "\n";
}
#include <bits/stdc++.h>
using namespace std;

vector<int> adj_list[1000];
vector<int> parent;
vector<bool> visited;

vector<int> find_path(int d){
    vector<int> path;
    int x = d;
    while(x != -1){
        path.push_back(x);
        x = parent[x];
    }
    reverse(path.begin(), path.end());
    return path;
}

vector<int> bfs(int src, int dest){
    queue<int> q;
    q.push(src);
    visited[src] = true;
    vector<int> path = {-1};
    while(!q.empty()){
        int p = q.front();
        q.pop();
        if(p == dest){
            path = find_path(dest);
            return path;
        }
        for(int i = 0; i < (int)adj_list[p].size(); i++){
            int child = adj_list[p][i];
            if(visited[child] == false){
                visited[child] = true;
                q.push(child);
                parent[child] = p;
            }
        }
    }
    return path;
}

int main() {
    int n, e;
    cin >> n >> e;
    visited.resize(n, false);
    parent.resize(n, -1);
    while(e--){
        int a, b;
        cin >> a >> b;
        adj_list[a].push_back(b);
        adj_list[b].push_back(a);
    }
    int src, dest;
    cin >> src >> dest;
    vector<int> path = bfs(src, dest);
    for(int x: path){
        cout << x << ' ';
    }
    return 0;
}
#include <iostream>
#include <vector>
#include <climits>
#include <cstring>
using namespace std;
  
// Check if it is possible to go to (x, y) from the current position. The
// function returns false if the cell has value 0 or already visited
bool isSafe(vector<vector<int>> &mat, vector<vector<bool>> &visited, int x, int y)
{
    return (x >= 0 && x < mat.size() && y >= 0 && y < mat[0].size()) &&
            mat[x][y] == 1 && !visited[x][y];
}
  
  
void findShortestPath(vector<vector<int>> &mat, vector<vector<bool>> &visited,
                int i, int j, int x, int y, int &min_dist, int dist){
    if (i == x && j == y){
        min_dist = min(dist, min_dist);
        return;
    }
    // set (i, j) cell as visited
    visited[i][j] = true;
    // go to the bottom cell
    if (isSafe(mat, visited, i + 1, j)) {
        findShortestPath(mat, visited, i + 1, j, x, y, min_dist, dist + 1);
    }
    // go to the right cell
    if (isSafe(mat, visited, i, j + 1)) {
        findShortestPath(mat, visited, i, j + 1, x, y, min_dist, dist + 1);
    }
    // go to the top cell
    if (isSafe(mat, visited, i - 1, j)) {
        findShortestPath(mat, visited, i - 1, j, x, y, min_dist, dist + 1);
    }
    // go to the left cell
    if (isSafe(mat, visited, i, j - 1)) {
        findShortestPath(mat, visited, i, j - 1, x, y, min_dist, dist + 1);
    }
    // backtrack: remove (i, j) from the visited matrix
    visited[i][j] = false;
}
  
// Wrapper over findShortestPath() function
int findShortestPathLength(vector<vector<int>> &mat, pair<int, int> &src,
                    pair<int, int> &dest){
    if (mat.size() == 0 || mat[src.first][src.second] == 0 ||
            mat[dest.first][dest.second] == 0) 
        return -1;
     
    int row = mat.size();
    int col = mat[0].size();
    // construct an `M × N` matrix to keep track of visited cells
    vector<vector<bool>> visited;
    visited.resize(row, vector<bool>(col));
  
    int dist = INT_MAX;
    findShortestPath(mat, visited, src.first, src.second, dest.first, dest.second,
            dist, 0);
  
    if (dist != INT_MAX) 
        return dist;
    return -1;
}
  
int main()
{
    vector<vector<int>> mat =
    {{1, 0, 1, 1, 1, 1, 0, 1, 1, 1 },
                  {1, 0, 1, 0, 1, 1, 1, 0, 1, 1 },
                  {1, 1, 1, 0, 1, 1, 0, 1, 0, 1 },
                  {0, 0, 0, 0, 1, 0, 0, 0, 0, 1 },
                  {1, 1, 1, 0, 1, 1, 1, 0, 1, 0 },
                  {1, 0, 1, 1, 1, 1, 0, 1, 0, 0 },
                  {1, 0, 0, 0, 0, 0, 0, 0, 0, 1 },
                  {1, 0, 1, 1, 1, 1, 0, 1, 1, 1 },
                  {1, 1, 0, 0, 0, 0, 1, 0, 0, 1 }};
  
    pair<int, int> src = make_pair(0, 0);
    pair<int, int> dest = make_pair(3, 4);
    int dist = findShortestPathLength(mat, src, dest);
    if (dist != -1)
        cout << "Shortest Path is " << dist;
     
    else
        cout << "Shortest Path doesn't exist";
   
    return 0;
}
