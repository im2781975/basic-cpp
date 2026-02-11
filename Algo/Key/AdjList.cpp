#include<bits/stdc++.h>
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
