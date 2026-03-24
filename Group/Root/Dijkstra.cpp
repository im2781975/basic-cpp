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
#include<bits/stdc++.h>
using namespace std;
const int n = 1e5 + 5;
bool visited[n];
int dist[n];
int node, edge;
vector <pair <int, int> >adj[n];
void Dijkstra(int src){
    for(int i = 1; i <= node; i++)
        dist[i] = INT_MAX;
    dist[src] = 0;
    for(int i = 0; i < node; i++){
        int select = -1;
        for(int j = 1; j <= node; j++){
            if(visited[j])
                continue;
            if(select == -1 || dist[select] > dist[j])
                select = j;
        }
        visited[select] = 1;
        for(auto u : adj[select]){
            int v = u.first;
            int w = u.second;
            if(dist[select] + w < dist[v])
                dist[v] = dist[select] + w;
        }
    }
}
int main(){
    cin >> node >> edge;
    for(int i = 0; i < edge; i++){
        int u, v, w; cin >> u >> v >> w;
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }
    Dijkstra(1);
    for(int i = 1; i <= node; i++)
        cout << dist[i] << " ";
}
/***/
using namespace std;
int minDist(vector <int> dist, vector <bool> visited, int node){
    int mini = INT_MAX, minidx;
    for(int i = 0; i < node; i++){
        if(!visited[i] && dist[i] <= mini){
            mini = dist[i];
            minidx = i;
        }
    }
    return minidx;
}
void Dijkstra(vector <vector <int> > &graph, int src, int node){
    vector <int> dist(node, INT_MAX);
    vector <bool> visited(node, false);
    dist[src] = 0;
    for(int i = 0; i < node - 1; i++){
        int u = minDist(dist, visited, node);
        visited[u] = true;
        for(int v = 0; v < node; v++){
            if(!visited[v] && graph[u][v] && dist[u] != INT_MAX && (dist[u] + graph[u][v]) < dist[v])
                dist[v] = dist[u] + graph[u][v];
        }
    }
    for(int i = 0; i < node; i++)
        cout << i << "\t" << dist[i] << "\n";
}
int main(){
    int node; cin >> node;
    vector <vector <int> >graph(node, vector <int>(node));
    for(int i = 0; i < node; i++){
        for(int j = 0; j < node; j++)
            cin >> graph[i][j];
    }
    int src; cin >> src;
    Dijkstra(graph, src, node);
}
/***/
using namespace std;
const int n = 1e5;
int node, edge;
bool visited[n]; int dist[n], parent[n];
vector <pair<int, int> >adj[n];
void Dijkstra(int src){
    for(int i = 1; i <= node; i++)
        dist[i] = INT_MAX;
    dist[src] = 0;
    priority_queue<pair <int, int> >pq;
    pq.push({0, src});
    while(!pq.empty()){
        pair<int, int> head = pq.top();
        pq.pop();
        int u = head.second;
        if(visited[u])
            continue;
        visited[u] = 1;
        for(pair <int, int> q: adj[u]){
            int v = q.first;
            int w = q.second;
            if(dist[u] + w < dist[v]){
                dist[v] = dist[u] + w;
                parent[v] = u;
                //priority_queue by default is a max-heap, meaning it orders elements such that the largest element is at the top (highest priority).
                //Dijkstra's algorithm requires the smallest distance (or the minimum element) to be processed first. To achieve this, the distances need to be treated in reverse order.
                //By pushing -dist[v] into the priority queue, the smallest distance (in the positive sense) will have the largest negative value, effectively putting the smallest distance at the top of the queue.
                pq.push({-dist[v], v});
            }
        }
    }
}
int main(){
    cin >> node >> edge;
    for(int i = 0; i < edge; i++){
        int u, v, w; cin >> u >> v >> w;
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }
    int src = 1;
    Dijkstra(src);
    if(!visited[node]){
        cout << "-1";
        return 0;
    }
    int cur = node;
    vector <int> path;
    while(true){
        path.push_back(cur);
        if(cur == src)
            break;
        cur = parent[cur];
    }
    reverse(path.begin(), path.end());
    for(auto node : path)
        cout << node << " ";
}
/***/
using namespace std;
#define node 9
int minDist(int dist[], bool visited[]){
    int mini = INT_MAX, minIdx;
    for(int i = 0; i < node; i++){
        if(!visited[i] && dist[i] <= mini){
            mini = dist[i];
            minIdx = i;
        }
    }
    return minIdx;
}
void print(int dist[node]){
    for(int i = 0; i < node; i++)
        cout << i << "\t" << dist[i] << "\n";
}
void Dijkstra(int graph[node][node], int src){
    int dist[node]; bool visited[node];
    for(int i = 0; i < node; i++){
        dist[i] =INT_MAX;
        visited[i] = false;
    }
    dist[src] = 0;
    for(int i = 0; i < node - 1; ++i){
        int u = minDist(dist, visited);
        visited[u] = true;
        for(int v = 0; v < node; v++){
            if(!visited[v] && graph[u][v] && dist[u] != INT_MAX && dist[u] + graph[u][v] <= dist[v])
                dist[v] = dist[u] + graph[u][v];
        }
    }
    print(dist);
}
int main(){
    int graph[node][node] ={
    { 0, 4, 0, 0, 0, 0, 0, 8, 0 }, { 4, 0, 8, 0, 0, 0, 0, 11, 0 },
    { 0, 8, 0, 7, 0, 4, 0, 0, 2 }, { 0, 0, 7, 0, 9, 14, 0, 0, 0 },
    { 0, 0, 0, 9, 0, 10, 0, 0, 0 }, { 0, 0, 4, 14, 10, 0, 2, 0, 0},
    { 0, 0, 0, 0, 0, 2, 0, 1, 6 }, { 8, 11, 0, 0, 0, 0, 1, 0, 7 },
    { 0, 0, 2, 0, 0, 0, 6, 7, 0 } };
    Dijkstra(graph, 0);
}
