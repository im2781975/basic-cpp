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
