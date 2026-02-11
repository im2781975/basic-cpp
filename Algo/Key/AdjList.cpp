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
