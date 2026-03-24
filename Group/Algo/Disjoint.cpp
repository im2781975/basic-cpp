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
#include<bits/stdc++.h>
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
//Finds the representative of the set that i is an element of
using namespace std;
const int maxn = 1005;
int parent[maxn];
int Find(int i){
    if(parent[i] == i)
        return i;
    return Find(parent[i]);
}
int main(){
    for(int i = 0; i < maxn; i++)
        parent[i] = i;
    int rep1 = Find(1);
    int rep2 = Find(2);
    if(rep1 != rep2)
        parent[rep1] = rep2;
    int val = 1;
    int rep = Find(val);
    cout << "The representative of element " << val << " is: " << rep;
}
#include <bits/stdc++.h>
using namespace std;
void dfs(int row, int col, vector<vector<int>>& image, int newColor, int oldColor, int n, int m) {
    if (row < 0 || row >= n || col < 0 || col >= m || 
        image[row][col] != oldColor || image[row][col] == newColor)
        return;
    
    // Change color
    image[row][col] = newColor;
    
    int dr[] = {-1, 0, 1, 0};
    int dc[] = {0, 1, 0, -1};
    
    for (int i = 0; i < 4; i++) {
        dfs(row + dr[i], col + dc[i], image, newColor, oldColor, n, m);
    }
}
vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
    /* int x = 1, y = 1, newC = 3;
    vector <vector <int>> res = floodFill(image, x, y, newC); */
    int n = image.size(), m = image[0].size();
    int oldColor = image[sr][sc];
    
    if (oldColor != newColor)
        dfs(sr, sc, image, newColor, oldColor, n, m);
    return image;
}
// Function that returns true if the given pixel is valid
bool isValid(int screen[][8], int m, int n, int x, int y,
             int prevC, int newC)
{
    if (x < 0 || x >= m || y < 0 || y >= n
        || screen[x][y] != prevC || screen[x][y] == newC)
        return false;
    return true;
}
void floodFill(int screen[][8], int x, int y, int prevC, int newC) {
   /* int m = screen.size(), n = screen[0].size();
    int x = 4, y = 4;
    int prevC = screen[x][y];
    // New color that has to be filled
    int newC = 3;
    floodFill(screen, m, n, x, y, prevC, newC); */
    queue<pair<int, int> > queue;
    pair<int, int> p(x, y);
    queue.push(p);
    // Color the pixel with the new color
    screen[x][y] = newC;
    while (queue.size() > 0) {
        pair<int, int> currPixel = queue.front();
        queue.pop();
 
        int posX = currPixel.first;
        int posY = currPixel.second;
        if (isValid(screen, m, n, posX + 1, posY, prevC,
                    newC)) {
            screen[posX + 1][posY] = newC;
            p.first = posX + 1;
            p.second = posY;
            queue.push(p);
        }
        if (isValid(screen, m, n, posX - 1, posY, prevC,
                    newC)) {
            screen[posX - 1][posY] = newC;
            p.first = posX - 1;
            p.second = posY;
            queue.push(p);
        }
        if (isValid(screen, m, n, posX, posY + 1, prevC,
                    newC)) {
            screen[posX][posY + 1] = newC;
            p.first = posX;
            p.second = posY + 1;
            queue.push(p);
        }
 
        if (isValid(screen, m, n, posX, posY - 1, prevC,
                    newC)) {
            screen[posX][posY - 1] = newC;
            p.first = posX;
            p.second = posY - 1;
            queue.push(p);
        }
    }
}
