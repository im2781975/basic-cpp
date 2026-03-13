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
