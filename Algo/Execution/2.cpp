#include <bits/stdc++.h>
using namespace std;
// find the longest distance from source to destination with at most K intermediate nodes
int findShortestPath(
    int n, vector<vector<int> >& edges,
    int src, int dst, int K)
{
    // Initialize the adjacency list
    vector<vector<pair<int, int> > > adjlist(
        n, vector<pair<int, int> >());
    // Initialize a queue to perform BFS
    queue<pair<int, int> > q;
    unordered_map<int, int> mp;
 
    // Store the maximum distance of every node from source vertex
    int ans = INT_MIN;
    // Initialize adjacency list
    for (int i = 0; i < edges.size(); i++) {
 
        auto edge = edges[i];
 
        adjlist[edge[0]].push_back(
            make_pair(edge[1], edge[2]));
    }
    // Push the first element into queue
    q.push({ src, 0 });
    int level = 0;
 
    // Iterate until the queue becomes empty and the number of nodes between src
    // and dst vertex is at most to K
    while (!q.empty() && level < K + 2) {
        // Current size of the queue
        int sz = q.size();
 
        for (int i = 0; i < sz; i++) {
            // Extract the front
            // element of the queue
            auto pr = q.front();
            // Pop the front element of the queue
            q.pop();
            // If the dst vertex is reached
            if (pr.first == dst)
                ans = max(ans, pr.second);
            // Traverse the adjacent nodes
            for (auto pr2 : adjlist[pr.first]) {
                // If the distance is greater than the current distance
                if (mp.find(pr2.first)
                        == mp.end()
                    || mp[pr2.first]
                           > pr.second
                                 + pr2.second) {
                    // Push it into the queue
                    q.push({ pr2.first,
                             pr.second
                                 + pr2.second });
                    mp[pr2.first] = pr.second
                                    + pr2.second;
                }
            }
        }
        // Increment the level by 1
        level++;
    }
    // Finally, return the maximum distance
    return ans != INT_MIN ? ans : -1;
}
int main()
{
    int n = 3, src = 0, dst = 2, k = 1;
    vector<vector<int> > edges
        = { { 0, 1, 100 },
            { 1, 2, 100 },
            { 0, 2, 500 } };
 
    cout << findShortestPath(n, edges, src, dst, k);
 
    return 0;
}
#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int minDiceThrows(vector<int>& moves, int N) {
    vector<bool> visited(N, false);
    queue<pair<int, int>> q;  // {position, moves}
    
    q.push({0, 0});           // Start at position 0, 0 moves
    visited[0] = true;
    
    while (!q.empty()) {
        auto [pos, movesCount] = q.front();
        q.pop();
        
        // Reached end
        if (pos == N - 1) return movesCount;
        
        // Try all 6 dice throws
        for (int dice = 1; dice <= 6 && pos + dice < N; dice++) {
            int nextPos = pos + dice;
            
            // Follow snake/ladder or stay
            nextPos = (moves[nextPos] != -1) ? moves[nextPos] : nextPos;
            
            if (!visited[nextPos]) {
                visited[nextPos] = true;
                q.push({nextPos, movesCount + 1});
            }
        }
    }
    return -1; // Unreachable board
}

int main() {
    int N = 30;
    vector<int> moves(N, -1);
    
    // Snakes & Ladders (same positions)
    moves[2] = 21; moves[4] = 7; moves[10] = 25; moves[19] = 28;
    moves[26] = 0; moves[20] = 8; moves[16] = 3; moves[18] = 6;
    
    cout << "Min dice throws: " << minDiceThrows(moves, N) << endl;  // Output: 3
    return 0;
}
#include <iostream>
#define MAX_CHAR 256
using namespace std;

void findFirstNonRepeatingAlt() {
    int queue[MAX_CHAR];      // Queue indices (stores char indices)
    int front = -1, rear = -1; // Queue pointers
    int nextAvailable = 0;     // Next position to place new char
    bool repeated[MAX_CHAR] = {false};
    
    char stream[] = "geeksforgeeksandgeeksquizfor";
    
    for (int i = 0; stream[i]; i++) {
        char x = stream[i];
        cout << "Reading " << x << " from stream
";
        
        if (!repeated[x]) {
            // If first time, add to queue
            if (front == -1) front = rear = 0;
            else rear = (rear + 1) % MAX_CHAR;
            
            queue[rear] = x;
            repeated[x] = false; // Still unique
        } else {
            // Remove from queue if it appears again
            // Find and remove x from queue
            int pos = (front + nextAvailable) % MAX_CHAR;
            while (pos != (rear + 1) % MAX_CHAR) {
                if (queue[pos] == x) {
                    // Shift elements to remove
                    for (int j = pos; j != rear; j = (j + 1) % MAX_CHAR) {
                        queue[j] = queue[(j + 1) % MAX_CHAR];
                    }
                    rear = (rear - 1 + MAX_CHAR) % MAX_CHAR;
                    break;
                }
                pos = (pos + 1) % MAX_CHAR;
            }
        }
        
        // Print first non-repeating
        if (front != -1 && front <= rear)
            cout << "First non-repeating character so far is " << queue[front] << endl;
        else
            cout << "No non-repeating character so far
";
    }
}
pair<int, int> getMinMax(int arr[], int n) {
    int mn = arr[0], mx = arr[0];
    for (int i = 1; i < n; i += 2) {
        if (i + 1 < n) {
            mn = min({mn, mx, arr[i], arr[i + 1]});
            mx = max({mx, mn, arr[i], arr[i + 1]});
        } else mn = min(mn, arr[i]);
    }
    return {mn, mx};
}
#include <bits/stdc++.h>
using namespace std;

pair<int,int> getMinMax(int arr[], int low, int high) {
    if (low == high) return {arr[low], arr[low]};
    if (low + 1 == high) return {min(arr[low], arr[high]), max(arr[low], arr[high])};
    
    auto [lmin, lmax] = getMinMax(arr, low, mid = (low + high)/2);
    auto [rmin, rmax] = getMinMax(arr, mid + 1, high);
    return {min(lmin, rmin), max(lmax, rmax)};
}

int main() {
    int arr[] = {1000, 11, 445, 1, 330, 3000};
    auto [minv, maxv] = getMinMax(arr, 0, 5);
    cout << "Min: " << minv << ", Max: " << maxv << endl;  // 1, 3000
}
