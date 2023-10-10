// unordered_set::erase() function
#include <iostream>
#include <string>
#include <unordered_set>

using namespace std;
int main()
{
    unordered_set<string>sampleSet ={"geeks1","for","geeks2"};
    
    sampleSet.erase("geeks1");
    cout << "Elements: ";
    for (auto it = sampleSet.begin(); it != sampleSet.end(); it++) {
        cout << *it << " ";
    }
    cout<<"\n";

    sampleSet.insert("geeks1");
    sampleSet.erase(sampleSet.find("for"), sampleSet.end());

    cout<<"After second removal set : ";
    for (auto it = sampleSet.begin(); it != sampleSet.end(); it++) {
        cout << *it << " ";
    }
    cout<<"\n";
    return 0;
}
