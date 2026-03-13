#include <bits/stdc++.h>
using namespace std;
// find the longest distance from source to destination with at most K intermediate nodes
int findShortestPath(
    int n, vector<vector<int> >& edges,
    int src, int dst, int K)
{
    // Initialize the adjacency list
    vector<vector<pair<int, int> > > adjlist(
        n, vector<pair<int, int> >());
    // Initialize a queue to perform BFS
    queue<pair<int, int> > q;
    unordered_map<int, int> mp;
 
    // Store the maximum distance of every node from source vertex
    int ans = INT_MIN;
    // Initialize adjacency list
    for (int i = 0; i < edges.size(); i++) {
 
        auto edge = edges[i];
 
        adjlist[edge[0]].push_back(
            make_pair(edge[1], edge[2]));
    }
    // Push the first element into queue
    q.push({ src, 0 });
    int level = 0;
 
    // Iterate until the queue becomes empty and the number of nodes between src
    // and dst vertex is at most to K
    while (!q.empty() && level < K + 2) {
        // Current size of the queue
        int sz = q.size();
 
        for (int i = 0; i < sz; i++) {
            // Extract the front
            // element of the queue
            auto pr = q.front();
            // Pop the front element of the queue
            q.pop();
            // If the dst vertex is reached
            if (pr.first == dst)
                ans = max(ans, pr.second);
            // Traverse the adjacent nodes
            for (auto pr2 : adjlist[pr.first]) {
                // If the distance is greater than the current distance
                if (mp.find(pr2.first)
                        == mp.end()
                    || mp[pr2.first]
                           > pr.second
                                 + pr2.second) {
                    // Push it into the queue
                    q.push({ pr2.first,
                             pr.second
                                 + pr2.second });
                    mp[pr2.first] = pr.second
                                    + pr2.second;
                }
            }
        }
        // Increment the level by 1
        level++;
    }
    // Finally, return the maximum distance
    return ans != INT_MIN ? ans : -1;
}
int main()
{
    int n = 3, src = 0, dst = 2, k = 1;
    vector<vector<int> > edges
        = { { 0, 1, 100 },
            { 1, 2, 100 },
            { 0, 2, 500 } };
 
    cout << findShortestPath(n, edges, src, dst, k);
 
    return 0;
}
#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int minDiceThrows(vector<int>& moves, int N) {
    vector<bool> visited(N, false);
    queue<pair<int, int>> q;  // {position, moves}
    
    q.push({0, 0});           // Start at position 0, 0 moves
    visited[0] = true;
    
    while (!q.empty()) {
        auto [pos, movesCount] = q.front();
        q.pop();
        
        // Reached end
        if (pos == N - 1) return movesCount;
        
        // Try all 6 dice throws
        for (int dice = 1; dice <= 6 && pos + dice < N; dice++) {
            int nextPos = pos + dice;
            
            // Follow snake/ladder or stay
            nextPos = (moves[nextPos] != -1) ? moves[nextPos] : nextPos;
            
            if (!visited[nextPos]) {
                visited[nextPos] = true;
                q.push({nextPos, movesCount + 1});
            }
        }
    }
    return -1; // Unreachable board
}

int main() {
    int N = 30;
    vector<int> moves(N, -1);
    
    // Snakes & Ladders (same positions)
    moves[2] = 21; moves[4] = 7; moves[10] = 25; moves[19] = 28;
    moves[26] = 0; moves[20] = 8; moves[16] = 3; moves[18] = 6;
    
    cout << "Min dice throws: " << minDiceThrows(moves, N) << endl;  // Output: 3
    return 0;
}
#include <iostream>
#define MAX_CHAR 256
using namespace std;

void findFirstNonRepeatingAlt() {
    int queue[MAX_CHAR];      // Queue indices (stores char indices)
    int front = -1, rear = -1; // Queue pointers
    int nextAvailable = 0;     // Next position to place new char
    bool repeated[MAX_CHAR] = {false};
    
    char stream[] = "geeksforgeeksandgeeksquizfor";
    
    for (int i = 0; stream[i]; i++) {
        char x = stream[i];
        cout << "Reading " << x << " from stream
";
        
        if (!repeated[x]) {
            // If first time, add to queue
            if (front == -1) front = rear = 0;
            else rear = (rear + 1) % MAX_CHAR;
            
            queue[rear] = x;
            repeated[x] = false; // Still unique
        } else {
            // Remove from queue if it appears again
            // Find and remove x from queue
            int pos = (front + nextAvailable) % MAX_CHAR;
            while (pos != (rear + 1) % MAX_CHAR) {
                if (queue[pos] == x) {
                    // Shift elements to remove
                    for (int j = pos; j != rear; j = (j + 1) % MAX_CHAR) {
                        queue[j] = queue[(j + 1) % MAX_CHAR];
                    }
                    rear = (rear - 1 + MAX_CHAR) % MAX_CHAR;
                    break;
                }
                pos = (pos + 1) % MAX_CHAR;
            }
        }
        
        // Print first non-repeating
        if (front != -1 && front <= rear)
            cout << "First non-repeating character so far is " << queue[front] << endl;
        else
            cout << "No non-repeating character so far
";
    }
}
pair<int, int> getMinMax(int arr[], int n) {
    int mn = arr[0], mx = arr[0];
    for (int i = 1; i < n; i += 2) {
        if (i + 1 < n) {
            mn = min({mn, mx, arr[i], arr[i + 1]});
            mx = max({mx, mn, arr[i], arr[i + 1]});
        } else mn = min(mn, arr[i]);
    }
    return {mn, mx};
}
#include <bits/stdc++.h>
using namespace std;

pair<int,int> getMinMax(int arr[], int low, int high) {
    if (low == high) return {arr[low], arr[low]};
    if (low + 1 == high) return {min(arr[low], arr[high]), max(arr[low], arr[high])};
    
    auto [lmin, lmax] = getMinMax(arr, low, mid = (low + high)/2);
    auto [rmin, rmax] = getMinMax(arr, mid + 1, high);
    return {min(lmin, rmin), max(lmax, rmax)};
}

int main() {
    int arr[] = {1000, 11, 445, 1, 330, 3000};
    auto [minv, maxv] = getMinMax(arr, 0, 5);
    cout << "Min: " << minv << ", Max: " << maxv << endl;  // 1, 3000
}
// printing Minimum Cost Simple Path between two given nodes
#include <bits/stdc++.h>
using namespace std;
#define V 5
#define INF INT_MAX
 
// Function to do DFS through the nodes
int minimumCostSimplePath(int u, int destination,
 bool visited[], int graph[][V])
{
    // check if we find the destination then further cost will be 0
    if (u == destination)
        return 0;
    // marking the current node as visited
    visited[u] = 1;
    int ans = INF;
    // traverse through all the adjacent nodes
    for (int i = 0; i < V; i++) {
        if (graph[u][i] != INF && !visited[i]) {
            // cost of the further path
            int curr = minimumCostSimplePath(i,
                        destination, visited, graph);
            // check if we have reached the destination
            if (curr < INF) {
                // Taking the minimum cost path
                ans = min(ans, graph[u][i] + curr);
            }
        }
    }
    // unmarking the current node to make it available for other simple paths
    visited[u] = 0;
    // returning the minimum cost
    return ans;
}
int main()
{
    // initialising the graph
    int graph[V][V];
    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            graph[i][j] = INF;
        }
    }
    // marking all nodes as unvisited
    bool visited[V] = { 0 };
    // initialising the edges;
    graph[0][1] = -1;
    graph[0][3] = 1;
    graph[1][2] = -2;
    graph[2][0] = -3;
    graph[3][2] = -1;
    graph[4][3] = 2;
 
    // source and destination
    int s = 0, t = 2;
    // marking the source as visited
    visited[s] = 1;
    cout << minimumCostSimplePath(s, t, 
    visited, graph);
 
    return 0;
}
#include <bits/stdc++.h>
using namespace std;
// Stores minimum-cost of path from source
int minSum = INT_MAX;
 
// Function to Perform BFS on graph g starting from vertex v
void getMinPathSum(unordered_map<int,vector<pair<int,
    int> > >& graph,vector<bool>& visited,
    vector<int> necessary,int src, int dest, int currSum)
{
    // If destination is reached
    if (src == dest) {
        // Set flag to true
        bool flag = true;
        // Visit all the intermediate nodes
        for (int i : necessary) {
 
            // If any intermediate node is not visited
            if (!visited[i]) {
                flag = false;
                break;
            }
        }
        // If all intermediate nodes are visited
        if (flag)
            // Update the minSum
            minSum = min(minSum, currSum);
        return;
    }
    else {
        // Mark the current node visited
        visited[src] = true;
        // Traverse adjacent nodes
        for (auto node : graph[src]) {
 
            if (!visited[node.first]) {
                // Mark the neighbour visited
                visited[node.first] = true;
                // Find minimum cost path considering the neighbour as the source
                getMinPathSum(graph, visited,    necessary, node.first,
                dest, currSum + node.second);
                // Mark the neighbour unvisited
                visited[node.first] = false;
            }
        }
        // Mark the source unvisited
        visited[src] = false;
    }
}
int main()
{
    // Stores the graph
    unordered_map<int, vector<pair<int,int> > > graph;
    graph[0] = { { 1, 2 }, { 2, 3 }, { 3, 2 } };
    graph[1] = { { 4, 4 }, { 0, 1 } };
    graph[2] = { { 4, 5 }, { 5, 6 } };
    graph[3] = { { 5, 7 }, { 0, 1 } };
    graph[4] = { { 6, 4 } };
    graph[5] = { { 6, 2 } };
    graph[6] = { { 7, 11 } };
 
    // Number of nodes
    int n = 7;
    // Source
    int source = 0;
    // Destination
    int dest = 6;
    // Keeps a check on visited and unvisited nodes
    vector<bool> visited(n, false);
    // Stores intermediate nodes
    vector<int> necessary{ 2, 4 };
    getMinPathSum(graph, visited, necessary,source, dest, 0);
 
    // If no path is found
    if (minSum == INT_MAX)
        cout << "-1\n";
    else
        cout << minSum << '\n';
    return 0;
}
#include <bits/stdc++.h>
using namespace std;

int minDistance(vector<string> grid) {
    int n = grid.size(), m = grid[0].size();
    vector<vector<bool>> visited(n, vector<bool>(m));
    queue<tuple<int,int,int>> q;  // row, col, dist
    
    // Find source
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            if (grid[i][j] == 's') {
                q.push({i, j, 0});
                visited[i][j] = true;
            }
    
    int dr[] = {-1,1,0,0};
    int dc[] = {0,0,-1,1};
    
    while (!q.empty()) {
        auto [r, c, dist] = q.front(); q.pop();
        if (grid[r][c] == 'd') return dist;
        
        for (int d = 0; d < 4; d++) {
            int nr = r + dr[d], nc = c + dc[d];
            if (nr >= 0 && nr < n && nc >= 0 && nc < m && 
                grid[nr][nc] != '0' && !visited[nr][nc]) {
                visited[nr][nc] = true;
                q.push({nr, nc, dist + 1});
            }
        }
    }
    return -1;
}

int main() {
    vector<string> grid = {
        "0*s", "*0**", "0***", "d***"
    };
    cout << minDistance(grid) << endl;  // Output: 6
}
