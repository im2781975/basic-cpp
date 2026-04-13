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
    return find
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
