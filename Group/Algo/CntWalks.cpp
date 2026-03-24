#include <iostream>
#include <string.h>
#include <vector>
#define M 3
#define N 4
using namespace std;
// A Depth First Search based recursive function that returns true
// if a matching for vertex u is possible
bool bpm(int table[M][N], int u, bool seen[], int matchR[])
{
    //Try every receiver one by one
    for (int v = 0; v < N; v++)
    {
        //If sender u has packets to send to receiver v and
        // receiver v is not already mapped to any other sender
        // just check if the number of packets is greater than '0'
        // because only one packet can be sent in a time frame anyways
        if (table[u][v]>0 && !seen[v])
        {
            seen[v] = true;
            // If receiver 'v' is not assigned to any sender OR
            // previously assigned sender for receiver v (which is
            // matchR[v]) has an alternate receiver available. Since
            // v is marked as visited in the above line, matchR[v] in
            // the following recursive call will not get receiver 'v' again
            if (matchR[v] < 0 || bpm(table, matchR[v], seen, matchR))
            {
                matchR[v] = u;
                return true;
            }
        }
    }
    return false;
}
// Returns maximum number of packets that can be sent parallelly in 1
// time slot from sender to receiver
int maxBPM(int table[M][N])
{
    //An array to keep track of the receivers assigned to the senders. The value of matchR[i] is the sender ID assigned to receiver i.
    // the value -1 indicates nobody is assigned.
    int matchR[N];
    // Initially all receivers are not mapped to any senders
    memset(matchR, -1, sizeof(matchR));
    int result = 0; 
    // Count of receivers assigned to senders
    for (int u = 0; u < M; u++)
    {
        //Mark all receivers as not seen for next sender
        bool seen[N];
        memset(seen, 0, sizeof(seen));
 
        // Find if the sender 'u' can be assigned to the receiver
        if (bpm(table, u, seen, matchR))
            result++;
    }
    cout << "The number of maximum packets sent in the time slot is "
         << result << "\n";
 
    for (int x=0; x<N; x++)
        if (matchR[x]+1!=0)
            cout << "T" << matchR[x]+1 << "-> R" << x+1 << "\n";
    return result;
}
int main()
{
    int table[M][N] = {{0, 2, 0}, {3, 0, 1}, {2, 4, 0}};
    int max_flow = maxBPM(table);
    return 0;
}
//There has n cities, and m roads between them.goal is to reach from city 1 to n.Print "YES" if  goal is possible else "NO"
using namespace std;
const int maxi = 1e3;
bool visited[maxi];
vector <int> adj[maxi];
void DFS(int u){
    visited[u] = true;
    for(int v : adj[u]){
        if(!visited[v])
            DFS(v);
    }
}
int main(){
    int node, edge; cin >> node >> edge;
    for(int i = 0; i < edge; i++){
        int u, v; cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    for(int i = 1; i <= node; i++)
        visited[i] = false;
    DFS(1);
    if(visited[node])
        cout << "Yes";
    else
        cout << "No";
}
//Count rooms
#include<bits/stdc++.h>
using namespace std;
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
using namespace std;
int dx[]{0, 0, 1, -1};
int dy[]{1, -1, 0, 0};
int DFS(vector <vector <char > > &Building, int x, int y){
    if(x < 0 || x >= Building.size() || y < 0 || y >= Building[0].size() || Building[x][y] == '#')
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
//count the number of connected components in an undirected graph.
using namespace std;
void addEdge(vector <int> adj[], int u, int v){
    adj[u].push_back(v);
    adj[v].push_back(u);
}
void DFS(vector <int> adj[], int u, vector <bool> &visited){
    visited[u] = true;
    for(int v = 0; v < adj[u].size(); v++){
        if(!visited[adj[u][v]]){
            DFS(adj, adj[u][v], visited);
        }
    }
}
int main(){
    int node = 5;
    vector <int> adj[node];
    addEdge(adj, 0, 1);
    addEdge(adj, 0, 2);
    addEdge(adj, 0, 3);
    addEdge(adj, 3, 4);
    vector <bool> visited(node, false);
    int cnt = 0;
    for(int i = 0; i < node; i++){
        if(!visited[i]){
            DFS(adj, i, visited);
            cnt++;
        }
    }
    cout << cnt;
}
//count the number of distinct clusters (connected components) of 1s in a 2D grid (forest)
using namespace std;
typedef pair<int, int> node;
void BFS(vector <vector <int> >&forest, node st, vector <vector <bool> >&visited){
    queue <node> q; q.push(st);
    visited[st.first][st.second] = true;
    while(!q.empty()){
        node cur = q.front(); q.pop();
        int dx[]{0, 0, -1, 1};
        int dy[]{-1, 1, 0, 0};
        for(int i = 0; i < 4; i++){
            int nx = cur.first + dx[i];
            int ny = cur.second + dy[i];
            if(nx >= 0 && nx < forest.size() && ny >= 0 && ny < forest[0].size() && forest[nx][ny] == 1 && !visited[nx][ny]){
                q.push(make_pair(nx, ny));
                visited[nx][ny] = 1;
            }
        }
    }
}
int main(){
    vector <vector <int> > forest = {
    {0, 1, 1, 0, 0}, {0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0}, {0, 0, 0, 0, 1},
        {0, 0, 0, 0, 0}
    };
    int cnt = 0;
    int n = forest.size(), m = forest[0].size();
    vector <vector <bool> >visited(n, vector <bool> (m));
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if(forest[i][j] == 1 && !visited[i][j]){
                BFS(forest, make_pair(i, j), visited);
                cnt++;
            }
        }
    }
    cout << cnt;
}
using namespace std;
#define N 100
int arr[N][N], visited[N][N];
int row, col;
int dx[]{-1, 1, 0, 0};
int dy[]{0, 0, -1, 1};
bool IsInside(int x, int y){
    return (x >= 0 && x < row && y >= 0 && y < col);
}
bool IsForbidden(int x, int y){
    return (arr[x][y] == -1);
}
void BFS(pair <int, int> src){
    queue <pair <int, int> >q;
    visited[src.first][src.second] = 1;
    q.push(src);
    while(!q.empty()){
        pair <int, int> head = q.front();
        q.pop();
        int x = head.first, y = head.second;
        for(int i = 0; i < 4; i++){
            int newx = x + dx[i];
            int newy = y + dy[i];
            
            if(IsInside(newx, newy) && !IsForbidden(newx, newy) && !visited[newx][newy]){
                visited[newx][newy] = 1;
                q.push({newx, newy});
            }
        }
    }
}
pair <int, int> FindUnvisited(){
    for(int i = 0; i < row; i++){
        for(int j = 0; j < col; j++){
            if(arr[i][j] == 0 && visited[i][j] == 0)
                return {i, j};
        }
    }
    return {-1, -1};
}
int main(){
    cin >> row >> col;
    for(int i = 0; i < row; i++){
        string str; cin >> str;
        for(int j = 0; j < col; j++){
            if(str[j] == '#')
                arr[i][j] = -1;
            else
                arr[i][j] = 0;
                
        }
    }
    int roomCnt = 0;
    while(true){
        pair <int, int> unvisited = FindUnvisited();
        if(unvisited == pair <int, int> (-1, -1))
            break;
        BFS(unvisited);
        roomCnt++;
    }
    cout << roomCnt;
}
// count number of islands in a graph.
#include <bits/stdc++.h>
using namespace std;
// R x C matrix
#define R 5
#define C 5
// check if a given cell (u, v) can be included in DFS
bool isSafe(int mat[R][C], int i, int j, bool vis[R][C])
{
    return (i >= 0) && (i < R) && 
           (j >= 0) && (j < C) && 
           (mat[i][j] && !vis[i][j]);
}
void BFS(int mat[R][C], bool vis[R][C],
         int si, int sj)
{
    // These arrays are used to get row & column numbers of 8 neighbours of a given cell
    int row[] = { -1, -1, -1, 0, 0, 1, 1, 1 };
    int col[] = { -1, 0, 1, -1, 1, -1, 0, 1 };
    // Simple BFS first step, we enqueue source and mark it as visited
    queue<pair<int, int> > q;
    q.push(make_pair(si, sj));
    vis[si][sj] = true;
    // Next step of BFS. We take out items one by one from queue and enqueue their unvisited adjacent
    while (!q.empty()) {
 
        int i = q.front().first;
        int j = q.front().second;
        q.pop();
        // Go through all 8 adjacent
        for (int k = 0; k < 8; k++) {
            if (isSafe(mat, i + row[k],
                       j + col[k], vis)) {
             vis[i + row[k]][j + col[k]] = true;
             q.push(make_pair(i + row[k], j + col[k]));
            }
        }
    }
}
int countIslands(int mat[R][C])
{
    // Mark all cells as not visited
    bool vis[R][C];
    memset(vis, 0, sizeof(vis));
    // Call BFS for every unvisited vertex Whenever we see an univisted vertex, we increment res (number of islands) also.
    int res = 0;
    for (int i = 0; i < R; i++) {
        for (int j = 0; j < C; j++) {
            if (mat[i][j] && !vis[i][j]) {
                BFS(mat, vis, i, j);
                res++;
            }
        }
    }
    return res;
}
int main()
{
    int mat[][C] = { { 1, 1, 0, 0, 0 },
     { 0, 1, 0, 0, 1 },{ 1, 0, 0, 1, 1 },
    { 0, 0, 0, 0, 0 },{ 1, 0, 1, 0, 1 } };
    cout << countIslands(mat);
    return 0;
}
