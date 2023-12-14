#include <iostream>
#include <vector>
using namespace std;

int main() {
    // Vector manipulation with insertion and deletion
    vector<int> v = {1, 2, 3};
    vector<int>::iterator i;

    for (i = v.begin(); i != v.end(); ++i) {
        if (i == v.begin()) {
            
            i = v.insert(i, 5);
        }
    }

    cout << "\nAfter insertion: ";
    for (i = v.begin(); i != v.end(); ++i) {
        cout << *i << " ";
    }

    for (i = v.begin(); i != v.end(); ++i) {
        if (i == v.begin() + 1) {
            // Deleting element at position 1
            i = v.erase(i);
        }
    }

    cout << "\nAfter deletion: ";
    for (i = v.begin(); i != v.end(); ++i) {
        cout << *i << " ";
    }

    //Another vector manipulation
    vector<int> a;

    for (int i = 0; i < 10; i++)
        a.push_back(i);

    cout << "\n\nAfter insertion: ";
    a.insert(a.begin() + 1, 100);

    for (int i = 0; i < a.size(); i++) {
        cout << " " << a[i];
    }

    cout << "\nAfter delete: ";
    a.erase(a.begin() + 2);

    for (int i = 0; i < a.size(); i++) {
        cout << " " << a[i];
    }

    return 0;
}
