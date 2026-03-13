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
