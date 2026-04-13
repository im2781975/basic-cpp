#include<bits/stdc++.h>
using namespace std;
// implements the Disjoint‑Set (Union‑Find) with path compression and union by rank
const int x = 1e5;
int parent[x], pos[x];
int find(int nd) {
    if(nd == parent[nd]) return nd;
    return parent[nd] = find(parent[nd]);
}
void unite(int a, int b) {
    /* int nd, edg; cin >> nd >> edg;
    for(int i = 1; i <= nd; i++) parent[i] = i;
    for(int i = 0; i < edg; i++) {
        int u, v; cin >> u >> v;
        unite(u, v);
    }
    for(int i = 1; i <= nd; i++) cout << pos[i] << " " << parent[i] << endl; */
    a = find(a); b = find(b);
    ;
    if(a == b) return;
    if(pos[a] < pos[b]) parent[a] = b;
    else if(pos[a] > pos[b]) parent[b] = a;
    else {
        parent[b] = a; pos[a]++;
    }
}
// implement a basic union‑find (disjoint‑set) structure to manage 
// groups of elements and check which group each element belongs to.
int parent[x];
int find(int x) {
    if(parent[x] == x) return x;
    return find(parent[x]);
}
void grpmanage() {
    for(int i = 0; i < x; i++) parent[i] = i;
    int rep1 = find(1), rep2 = find(2);
    if(rep1 != rep2) parent(rep1) = rep2;
    int val = 1; rep = find(val);
    cout << val << " " << rep << endl;
}
// given n nodes and q queries.each query, either merge two nodes or undo the last successful merge
// and after every query output the representative (root) of node 0 using a union–find structure with undo support
int parent[x];
stack <pair <int, int>> st; // idx, parent
int find(int x) {
    if(parent[x] == x) return x;
    return find(parent[x]);
}
bool merge(int x, int y) {
    int px = find(x), py = find(y);
    if(px == py) return false;
    st.push({px, parent[px]});
    parent[px] = py; return true;
}
void undo() {
    if(st.empty()) {
        cout << "No Operation To undo"; return;
    }
    int idx = st.top().first;
    int pt = st.top().second;
    st.pop();
    parent[idx] = pt;
}
void repr(int n, int q) {
    for(int i = 0; i < n; i++) parent[i] = i;
    while(q--) {
        int type; cin >> type;
        if(type == 1) {
            int u, v; cin >> u >> v;
            merge(u, v);
        }
        else if(type == 2) undo();
        cout << find(0);
    }
}
// detect whether an undirected graph has a cycle using the union–find (disjoint‑set) data structure.
int parent[x];
int find(int x) {
    if(parent[x] == x) return x;
    return find(parent[x]);
}
bool merge(int x, int y) {
    int px = find(x); int py = find(y);
    if(px == py) return false;
    parent[px] = py; return true;
}
void cyclic(int nd, int edg) {
    for(int i = 0; i < edg; i++) parent[i] = i;
    bool hascycle = false;
    for(int i = 0; i < edg; i++) {
        int u, v; cin >> u >> v;
        if(!merge(u, v)) {
            hascycle = true; break;
        }
    }
    cout << (hascycle) ? "contained cycle" : "no cycle";
}
// Is graph cyclic Or tree(forest)
vector <int> parent;
int find(int x) {
    return parent[x] == -1 ? x : parent[x] = find(parent[x]);
}
void unite(int a, int b) {
    parent[find(a)] = find(b);
}
void iscyclic(int nd, int edg) {
    parent.assign(nd, -1);
    bool hascycle = false;
    for(int i = 0; i < edg; i++) {
        int u, v; cin >> u >> v;
        if(find(u) == find(v)) {
            hascycle = true; break;
        }
        unite(u, v);
    } /*
    // is the graph is a tree
    if(edg != nd - 1) {
        cout << "NO"; return 0;
    }
    cout << (hascycle? "NO" : "YES"); */
    cout << (hascycle ? "Yes" : "NO");
}
// solves an incremental connectivity problem on an undirected graph, where edges 
// are added one by one and you must efficiently answer “are x and y connected yet? also count components
int parent[x], rank[x], components;
int root(int x) {
    while(parent[x] != x) x = parent[x] = parent[parent[x]];
    return x;
}
bool connected(int x, int y) { return root(x) == root(y); }
void unite(int x, int y) {
    int px = root(x), py = root(y);
    if(px == py) return;
    if(rank[px] < rank[py]) parent[px] = py;
    else if(rank[px] > rank[py]) parent[py] = px;
    else { parent[py] = px; rank[px]++; }
    components--; // two components become one
    
}
void redundantedg(int n = 7) {
    vector <int> parent(n), rank(n, 1);
    iota(parent.begin(), parent.end(), 0);
    /* 
    // Return the first edge (u,v) that creates a cycle (this is the redundant edge).
    vector <pair <int, int>> edg;
    for(int i = 0; i < n; i++) cin >> edg[i].first >> edg[i].second;
    vector <int> redundantedg;
    for(int i = 0; i < n; i++) {
        int u = edg[i].first, v = edg[i].second;
        if(connected(u, v)) {
            redundantedg = {u, v}; break;
        } unite(u, v);
    } 
    cout << redundantedg[0] << " " << redundantedg[1] << endl; */
    vector <pair <int, pair <int, int>>> op = {
        {1, {0, 1}}, {2, {0, 1}}, {2, {1, 2}}, 
        {1, {0, 2}}, {2, {0, 2}}, {2, {2, 3}}, 
        {2, {3, 4}}, {1, {0, 5}}, {2, {4, 5}}, 
        {2, {5, 6}}, {1, {2, 6}}
    }; // 1 = query (are x,y connected), 2=union (x,y)
    components = n; 
    for(auto &p : op) {
        int type = p.first, x = op.second.first, y = op.second.second;
        if(type == 1) cout << (connected(x, y) ? "YES " : "NO ") << components << endl;
        else unite(x, y);
    }
}
