#include<bits/stdc++.h>
using namespace std;
// Function to convert an adjacency matrix to an adjacency list
vector <vector <int>> matrixToList(vector <vector <int>> matrix) {
    int n = matrix.size();
    vector <vector <int>> adjList(n);
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; i++) {
            if(matrix[i][j] == 1) {
                adjList[i].push_back(j);
                adjList[j].push_back(i);
            }
        }
    }
    return adjList;
}
// Function to convert an adjacency list to an adjacency matrix
vector <vector <int>> ListTomatrix(vector <vector <int>> adjList) {
    int n = adjList.size();
    vector <vector <int>> matrix(n, vector <int>(n, 0));
    for(int i = 0; i < n; i++) {
        for(int j : adjList[i]) {
            matrix[i][j] = 1; matrix[j][i] = 1;
        }
    }
    return matrix;
}
void grid(int n) {
    vector <vector <int>> vec(n, vector <int>(n));
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) vec[i][j] = i + j;
    }
    vector <int> tor[n];
    tor[1].push_back(12); tor[1].push_back(14);
    tor[1].push_back(16); tor[2].push_back(18);
    tor[2].push_back(20); tor[3].push_back(22);
    // tor[1] = {12, 14, 16}; tor[2] = {18, 20}; tor[3] = {22};
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < tor[i].size(); j++)
            cout << tor[i][j] << " ";
        cout << endl;
    }
}
void graph() {
    int nd, edg; cin >> nd >> edg;
    vector <int> adj[nd + 1];
    for(int i = 0; i < edg; i++) {
        int u, v; cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    for(int i = 0; i < nd; i++) {
        for(int j = 0; j < adj[i].size(); j++)
            cout << adj[i][j] << " ";
        cout << endl;
    }
}
void graph() {
    int node, edge; cin >> node >> edge;
    vector <pair<int, int> >adj[node];
    for(int i = 1; i <= edge; i++){
        int u, v, w; cin >> u >> v >> w;
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }
    for(int i = 1; i <= node; i++){
        for(int j = 1; j <= adj[i].size(); j++)
            cout << adj[i][j].first << " " << adj[i][j].second; << endl;
    }
}
void grid(int n) {
    vector <pair <int, int>> adj[n];
    adj[0] = {{1, 2}}; adj[1] = {{3, 4}};
    adj[2] = {{5, 6}}, adj[3] = {{7, 8}, {9, 10}};
    adj[0].push_back({11, 12});
    adj[1].push_back({13, 14});
    adj[2].push_back({15, 16});

    adjList[0] = {{1, 2}}; adjList[1] = {{3, 4}};
    adjList[2] = {{1, 7}, {2, 3}}; adjList[3] = {{9, 6}};
    /*
    vector <vector <pair <int, int>>> adj(n); 
    adj[0] = {{1, 2}}; adj[1] = {{3, 4}};
    adj[2] = {{1, 7}, {2, 3}}; adj[3] = {{9, 6}}; */
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < adj[i].size(); j++)
            cout << adj[i][j].first << " " << adj[i][j].second << endl;
    }
}
