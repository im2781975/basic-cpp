#include <iostream>
#include <set>
using namespace std;
int main() {
    set<int> set1, set2, unionSet;
    
    set1.insert(1);
    set1.insert(2);
    set1.insert(3);

    set2.insert(2);
    set2.insert(3);
    set2.insert(4);
    // Find the union of the two sets
    for (int element : set1) {
        unionSet.insert(element);
    }
    for (int element : set2) {
        unionSet.insert(element);
    } 
    
    for (int element : unionSet) {
        cout << element << " ";
    }
    return 0;
}
