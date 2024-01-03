#include <iostream>
#include <set>
#include <vector>
using namespace std;

int main() {
    set<int> value = {6, 2, 7, 4, 10, 5, 1};
    
    cout << "Traversing the set with foreach using set's data type: ";
    for (int v : value) {
        cout << v << " ";
    }

    vector<int> vec{0, 1, 2, 3, 4};
    for_each(vec.begin(), vec.end(), [](int &i){ i += 2; });
    
    for_each(vec.begin(), vec.end(), [](int i){ cout << i << " "; });

    return 0;
}
