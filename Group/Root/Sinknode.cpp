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
