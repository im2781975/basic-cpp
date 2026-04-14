#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    
    vector<string> names(1000);
    vector<int> scores(1000), totalTimes(1000);
    int studentCount = 0;
    
    // Read student data
    while (studentCount < 1000) {
        cin >> names[studentCount];
        int submissions = n;
        
        while (submissions--) {
            int time;
            cin >> time;
            if (time > 0) {
                scores[studentCount]++;
                totalTimes[studentCount] += time;
                
                // Check for bonus time
                char ch;
                if (getchar() == '(') {
                    int bonus;
                    cin >> bonus >> ch;
                    totalTimes[studentCount] += bonus * m;
                }
            }
        }
        studentCount++;
    }
    
    // Sort by score (desc), then total time (asc)
    vector<int> order(studentCount);
    iota(order.begin(), order.end(), 0);
    sort(order.begin(), order.end(), [&](int i, int j) {
        if (scores[i] != scores[j]) return scores[i] > scores[j];
        return totalTimes[i] < totalTimes[j];
    });
    
    // Output formatted results
    for (int idx : order) {
        cout << left << setw(10) << names[idx] 
             << " " << right << setw(2) << scores[idx]
             << " " << setw(4) << totalTimes[idx] << endl;
    }
    return 0;
}
