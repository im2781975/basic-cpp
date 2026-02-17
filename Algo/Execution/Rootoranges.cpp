// rot all oranges when you can move in all the four direction from a rotten orange
#include <bits/stdc++.h>
using namespace std;
const int R = 3;
const int C = 5;
 
// Check if i, j is under the array limits of row and column
bool issafe(int i, int j)
{
    if (i >= 0 && i < R && j >= 0 && j < C)
        return true;
    return false;
}
int rotOranges(int v[R][C])
{
    bool changed = false;
    int no = 2;
    while (true) {
        for (int i = 0; i < R; i++) {
            for (int j = 0; j < C; j++) {
 
                // Rot all other oranges present at
                // (i+1, j), (i, j-1), (i, j+1), (i-1, j)
                if (v[i][j] == no) {
                    if (issafe(i + 1, j)
                        && v[i + 1][j] == 1) {
                        v[i + 1][j] = v[i][j] + 1;
                        changed = true;
                    }
                    if (issafe(i, j + 1)
                        && v[i][j + 1] == 1) {
                        v[i][j + 1] = v[i][j] + 1;
                        changed = true;
                    }
                    if (issafe(i - 1, j)
                        && v[i - 1][j] == 1) {
                        v[i - 1][j] = v[i][j] + 1;
                        changed = true;
                    }
                    if (issafe(i, j - 1)
                        && v[i][j - 1] == 1) {
                        v[i][j - 1] = v[i][j] + 1;
                        changed = true;
                    }
                }
            }
        }
        // if no rotten orange found it means all oranges rottened now
        if (!changed)
            break;
        changed = false;
        no++;
    }
 
    for (int i = 0; i < R; i++) {
        for (int j = 0; j < C; j++) {
            // if any orange is found to be not rotten then ans is not possible
            if (v[i][j] == 1)
                return -1;
        }
    }
    // Because initial value for a rotten orange was 2
    return no - 2;
}
int main()
{
 
    int v[R][C] = { { 2, 1, 0, 2, 1 },
    { 1, 0, 1, 2, 1 },{ 1, 0, 0, 2, 1 } };
    cout << "Max time incurred: " << rotOranges(v);
    return 0;
}
//  find minimum time required to make all oranges rotten
#include <bits/stdc++.h>
#define R 3
#define C 5
using namespace std;
// finds if it is possible to rot all oranges or not. If possible, then it returns minimum time required to rot all
int rotOranges(vector<vector<int> >& grid)
{
    int n = grid.size(); 
    // row size
    int m = grid[0].size(); 
    // column size
    // delrow and delcol are used to traverse in up,right,bottom and left respectively.
 
    int delrow[] = { -1, 0, 1, 0 };
    int delcol[] = { 0, 1, 0, -1 };
 
    // visited matrix to keep track of the visited cell.
    int vis[n][m];
    // queue stores rowIndex,colIndex and time taken to rot respectively.
 
    queue<pair<pair<int, int>, int> > q;
    // counter to keep track of fresh cells.
    int cntfresh = 0;
 
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (grid[i][j] == 2) {
                q.push({ { i, j },
                         0 });
                // already rotten hence 0
                //time to rot.
                vis[i][j]
                    = 2; 
                // visited cell marked as rotten.
            }
            else {
                vis[i][j] = 0; // unvisited
            }
            if (grid[i][j] == 1)
                cntfresh++; // maintaining count for fresh
                // oranges.
        }
    }
    int cnt = 0, tm = 0;
    while (!q.empty()) {
        int row = q.front().first.first; // row index
        int col = q.front().first.second; // col index
        int t = q.front().second; // time an orange at a
                                  // cell takes to rot.
        q.pop();
 
        tm = max(tm, t);
        // checking for adjacent nodes in 4 directions.
        for (int i = 0; i < 4; i++) {
            int nrow = row + delrow[i];
            int ncol = col + delcol[i];
 
            // checking the validity of a node and also vis[nrow][ncol] !=2
            if (nrow >= 0 && nrow < n && ncol >= 0
                && ncol < m && grid[nrow][ncol] == 1
                && vis[nrow][ncol] != 2) {
                vis[nrow][ncol] = 2; // adj orange is rotten
                q.push({ { nrow, ncol },
                         t + 1 }); // incrementing time for
               // that orange by 1
                cnt++;
            }
        }
    }
    return (cnt == cntfresh) ? tm : -1;
}
int main()
{
    vector<vector<int> > arr
        = { { 0, 1, 2 }, { 0, 1, 2 }, { 2, 1, 1 } };
    int ans = rotOranges(arr);
    if (ans == -1)
        cout << "All oranges cannot rotn";
    else
        cout << "Time required for all oranges to rot => "
             << ans << endl;
    return 0;
}
